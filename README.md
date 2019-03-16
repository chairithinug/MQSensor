# MQSensor

## Overview
This project measures the air quality and the presence of some gasses in my room at Madison, WI, USA.
The data is collected by an Arduino connected to MQ sensors and seriall transfered to a Raspberry Pi.
The Raspberry Pi then processes and posts them to Thingspeak.com and the log of data can be seen.

## Components used
1. Arduino Uno
2. Raspberry Pi 3 Model B
3. MQ sensors (2 CO-Methane, 3 Alcohol, 7 Combustible Gas, 135 Air Quality)

## Software used
1. Arduino IDE
2. Python
