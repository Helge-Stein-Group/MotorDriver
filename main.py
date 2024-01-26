import serial
import time
from motor_driver import Motor


def main():
    motor = Motor('COM11', 9600, timeout=3) #add your specific com port here
    motor.move(100)
    motor.close()



if __name__ == '__main__':
    main()
