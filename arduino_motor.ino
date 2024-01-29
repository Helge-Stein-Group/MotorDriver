// Include the AccelStepper Library
#include <AccelStepper.h>

// Define pin connections
const int dirPin = 2;
const int stepPin = 3;

String inputString = "";
boolean stringComplete = false;


// Define motor interface type
#define motorInterfaceType 1

// Creates an instance
AccelStepper myStepper(motorInterfaceType, stepPin, dirPin);

void setup() {
	// set the maximum speed, acceleration factor,
	// initial speed and the target position
	myStepper.setMaxSpeed(10);
	myStepper.setAcceleration(10);
	myStepper.setSpeed(10);
  myStepper.setCurrentPosition(0); //This defines the current position the motor is in to be 200.

  Serial.begin(9600);
}

void loop() {
  
//I commented out all the print statments we used for testing.

while (Serial.available() > 0 ) {
    char command = Serial.read();
    inputString += command;
    //Serial.print(command);
    if (command == '\n') {
      stringComplete = true;
      //Serial.print("Complete");
    }
    delay(1000);
  }


  if (stringComplete) {
    //Serial.print("InsideComplete!");
    //Serial.print(inputString);
    if (inputString.startsWith("F")) {
      int stepsToMove = inputString.substring(1).toInt();
      myStepper.moveTo(stepsToMove);
      myStepper.runToPosition();
      myStepper.setCurrentPosition(0);
    } else if (inputString.startsWith("S")) {
      
    } else if (inputString.startsWith("R")) {
      //Serial.print("InsideR");
      myStepper.moveTo(200);
      myStepper.runToPosition();
      myStepper.setCurrentPosition(0);

    } else if (inputString.startsWith("V")) {
      int speedStepper = inputString.substring(1).toInt();
      myStepper.setSpeed(speedStepper);
      myStepper.setMaxSpeed(speedStepper);
	    myStepper.setAcceleration(speedStepper);
    } 

    inputString = "";
    stringComplete = false;
  }
  inputString = "";
  stringComplete = false;
}
