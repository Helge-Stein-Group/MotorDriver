import serial
import time
from motor_driver import Motor

motor = Motor('COM11', 9600, timeout=3) #add your specific com port here
print('The motor is connected: ', motor.checkConnection())
motor.move(100)
motor.setAcceleration(10)
motor.setSpeed(100)
motor.move(100)

