import serial
import time
from motor_driver import Motor

motor = Motor('0','COM4', 9600, timeout=3) #add your specific com port here
print('The motor is connected: ', motor.checkConnection())
motor.setSpeed(200)
time.sleep(2)
motor.move(100)
time.sleep(2)
motor.moveUp(400)
time.sleep(2)
motor.moveDown(400)
time.sleep(2)

