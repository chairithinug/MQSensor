# !/usr/bin/python

# Serial connection from Arduino to Raspberry Pi
import serial
ser = serial.Serial('/dev/ttyACM0', 115200)
ser.flushInput()

# URL library used to push update to Thingspeak
import urllib.request
Thingspeak_writeAPI = '5T0607D7ERBT89F8'
Thingspeak_url = 'https://api.thingspeak.com/update?api_key=%s' %Thingspeak_writeAPI

def MQ_data():
    line = ser.readline()
    # keep spining until there is a line
    while line == None:
        pass
        
    decoded_line = str(line[0:len(line)-2].decode("utf-8"))
    mq2, mq3, mq7, mq135, temp = decoded_line.split(',')
    return mq2, mq3, mq7, mq135, temp

def Thingspeak_post():
    mq2, mq3, mq7, mq135, temp = MQ_data()
    # Send to Thingspeak
    conn = urllib.request.urlopen(Thingspeak_url+'&field1=%s&field2=%s&field3=%s&field4=%s&field5=%s' % (mq2, mq3, mq7, mq135, temp))
    print(conn.read())
    conn.close()
    return

# main forever loop
while True:
    try:
        Thingspeak_post()
    except:
        pass