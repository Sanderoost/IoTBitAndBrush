# Bit And brush (Bit Device)

## About
This is a manual about how you can create the bit device of the project Bit and Brush.
The main goal of the product is to simulate the brushing habit of a specific user, by showing that the dentist can easily spot the bad brushed spots.
The data is collected from tooth brush which comes with the bit device and is stored on the website Bitandbrush.com

## Requirements
* A bit and brush account (www.bitandbrush.com)
* Arduino code editor (https://www.arduino.cc/en/Main/Software)
* Arduino esp8266
* 3d Model of teeth
* 2 led strips

## Setup arduino
Install the following libraries from the library manager:
* Adafruit_NeoPixel
* ESP8266WiFi
* ESP8266HTTPClient

Plug in the led strips for the upper teeth in pin D5 and the lower teeth in pin D2.
Plug the 3V in the 5V and the GND in the GND on the arduino.

## How to
Follow this guide step by step to make the device work.

1. Create an account at our website www.bitandbrush.com and copy your user id "sanderOost" for example

2. Set up the global variables 
