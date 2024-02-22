// Include the AccelStepper Library
#include <AccelStepper.h>

//Defining the amount of steppers
const int stepperAmount = 6;

// Define pin connections
const int dirPin1 = 2;
const int stepPin1 = 3;
const int dirPin2 = 4;
const int stepPin2 = 5;
const int dirPin3 = 6;
const int stepPin3 = 7;
const int dirPin4 = 8;
const int stepPin4 = 9;
const int dirPin5 = 10;
const int stepPin5 = 11;
const int dirPin6 = 12;
const int stepPin6 = 13;

String inputString = "";
boolean stringComplete = false;
int stepNum = 0;


// Define motor interface type
#define motorInterfaceType 1


// Creates an instance

AccelStepper Stepper1(motorInterfaceType, stepPin1, dirPin1);
AccelStepper Stepper2(motorInterfaceType, stepPin2, dirPin2);
AccelStepper Stepper3(motorInterfaceType, stepPin3, dirPin3);
AccelStepper Stepper4(motorInterfaceType, stepPin4, dirPin4);
AccelStepper Stepper5(motorInterfaceType, stepPin5, dirPin5);
AccelStepper Stepper6(motorInterfaceType, stepPin6, dirPin6);


AccelStepper* steppers[stepperAmount] ={
    
    &Stepper1,
    &Stepper2,
    &Stepper3,
    &Stepper4,
    &Stepper5,
    &Stepper6
};

void setup() {
	// set the maximum speed, acceleration factor,
	// initial speed and the target position
      for(int stepperNumber = 0; stepperNumber < stepperAmount; stepperNumber++){

        steppers[stepperNumber]->setMaxSpeed(10);
        steppers[stepperNumber]->setAcceleration(10);
        steppers[stepperNumber]->setSpeed(10);
        steppers[stepperNumber]->setCurrentPosition(0);
    }

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
    stepNum = inputString.substring(0,2).toInt();
    inputString = inputString.substring(1);
    if (inputString.startsWith("F")) {
      int stepsToMove = inputString.substring(1).toInt();
      steppers[stepNum]->moveTo(stepsToMove);
      steppers[stepNum]->runToPosition();
      steppers[stepNum]->setCurrentPosition(0);
    } else if (inputString.startsWith("S")) {
      steppers[stepNum]->stop();

    } else if (inputString.startsWith("R")) {
      //Serial.print("InsideR");
      steppers[stepNum]->moveTo(200);
      steppers[stepNum]->runToPosition();
      steppers[stepNum]->setCurrentPosition(0);

    } else if (inputString.startsWith("V")) {
      int speedStepper = inputString.substring(1).toInt();
      steppers[stepNum]->setSpeed(speedStepper);
      steppers[stepNum]->setMaxSpeed(speedStepper);
	    steppers[stepNum]->setAcceleration(speedStepper);
    } 

    inputString = "";
    stringComplete = false;
  }
  inputString = "";
  stringComplete = false;
}
