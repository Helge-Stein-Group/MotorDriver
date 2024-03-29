import serial
import time
import sys

class motorError(Exception):
    def __init__(self, message):
        super().__init__(message)

class Motor():
    def __init__(self,conf,baud,timeout):
        """ Initializes the serial connection. """
        self.conf = conf
        self.baud = baud
        self.timeout = timeout
        #try: 
        self.ser = serial.Serial(conf, baud, timeout=timeout)
        # except serial.SerialException:
        #     print('Unable to connect to the motor or motor is already connected. Check the com port and try again.')
        #     sys.exit(1) #Exiting the program if the motor is not connected.

    def close(self):
        """ Closes the serial connection. """
        self.ser.close()
    
    def send(self, command):
        """ Sends a command to the motor. Can be used to send custom commands."""
        self.ser.write((command+"\n").encode('utf-8'))
        
    def checkConnection(self):
        """ Checks if the motor is connected. """
        return self.ser.isOpen()
    
    def setSpeed(self, speed):
        """ Sets the speed of the motor. """
        if speed > 0 and speed < 1000:
            self.send("V" + str(speed))
        else:
            raise motorError('Speed must be between 0 and 1000')
        
    def setAcceleration(self, acceleration):
        """ Sets the acceleration of the motor. """
        if acceleration > 0 and acceleration < 1000:
            self.send("A" + str(acceleration))
        else:
            raise motorError('Acceleration must be between 0 and 1000')

    def move(self, steps):
        """ Moves the motor clockwise at the current speed for a set number of steps. """
        self.send("F" + str(steps))

''' def moveCounterClockwise(self, steps):
        """ Moves the motor counter-clockwise at the current speed for a set number of steps. """
        self.send("B" + str(steps) + "\n")'''
