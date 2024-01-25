import serial
import time

motor = serial.Serial('COM9',9600,timeout=3)

motor.write("A10\n".encode('utf-8')) #steps per second per second
time.sleep(10)
motor.write("V200\n".encode('utf-8')) #steps per second
time.sleep(10)
motor.write("F1000\n".encode('utf-8'))



time.sleep(10)
motor.write("R\n".encode('utf-8'))

motor.write("F150\n".encode('utf-8'))



motor.readline()
motor.readline()
motor.readline()
motor.readline()
motor.readline()
motor.readline()
motor.readline()




ser.close()

stepsToMove = 400
motor.write('F400'.encode('utf-8'))
motor.write(stepsToMove.encode('utf-8'))

motor.write('R'.encode('utf-8'))
