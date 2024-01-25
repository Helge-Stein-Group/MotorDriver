#Motor_Test
#For this to work the motor must start with the flat head pointing strait up. This will be saved as position 200.

import serial
import time

motor = serial.Serial('COM4',9600,timeout=3)


motor.write("F300\n".encode('utf-8')) #Moves to dispense the salt.
time.sleep(7)
motor.write("R\n".encode('utf-8')) #Moves to the original upright position to collect salt.
time.sleep(7)
motor.write("F100\n".encode('utf-8')) #Moves to dispense the salt.
time.sleep(7)
motor.write("R\n".encode('utf-8')) #Moves to the original upright position to collect salt.