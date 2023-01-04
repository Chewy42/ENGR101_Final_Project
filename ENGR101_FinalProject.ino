//C++ Libraries
#include <Servo.h>
#include <LiquidCrystal.h>

int PIRpin = 5; // PIR Motion Sensor Pin
int SERVOpin = 13; // Servo Motor Pin
bool doorIsOpen = false; // Door is open boolean

// parameters
int startingAngle = 0;
int endingAngle = 180;

Servo myservo; // initiate Servo class
LiquidCrystal lcd(7, 8, 9, 10, 11, 12); // initiate LiquidCrystal (lcd) class

void setup() { // initial setup
  Serial.begin(9600);
  pinMode(PIRpin, INPUT); // set pir motion detector to input
  myservo.attach(SERVOpin); // attach servo motor pin to servo class
  myservo.write(0); // set servo rotation to 0
  lcd.begin(13, 2); // initialize lcd screen w x h
  lcd.noDisplay(); // turn off display
  lcd.print("WELCOME HOME!"); // set display text to welcome home text
  delay(1000); // create 1 second delay before starting loop
}

void loop(){ // main loop
  if(digitalRead(PIRpin) == HIGH && doorIsOpen == false){ //check if motion is detected and door is not already open
    Serial.println("DETECTED!");
    doorIsOpen = true; //set door to open
    //lcd.display(); // turn on display
    myservo.write(endingAngle); // rotate servo to open door
    delay(1000); // wait five seconds
    //lcd.noDisplay(); // turn off display
    myservo.write(startingAngle); // rotate servo to close door
    doorIsOpen = false; // set door to not open
  }
}
