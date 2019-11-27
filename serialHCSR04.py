import serial #module needed for serial communication

ser = serial.Serial('COM6', baudrate = 9600, timeout = 1) #opening serial communication, port->COM6, baudrate->9600, timeout->1

#function if we want to capture HCSR04 readings
def getValues():
    ser.write(b'g')
    arduinoData = ser.readline().decode('ascii')
    return arduinoData

while (1):

    userInput = input('Get data point?y/n\n')

    if userInput == 'y':
        print(getValues())
