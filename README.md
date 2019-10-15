# Bit And brush (Bit Device)

## About
This is a manual about how you can create the bit device of the project Bit and Brush.  
The main goal of the product is to simulate the brushing habit of a specific user, by showing that the dentist can easily spot the bad brushed spots.  
The data is collected from tooth brush which comes with the bit device and is stored on the website Bitandbrush.com  

## Requirements
* A bit and brush account (www.bitandbrush.com)
* Arduino code editor (https://www.arduino.cc/en/Main/Software)
* Arduino esp8266
* 2 led strips
* Bonus: * 3d Model of teeth

## Setup arduino
Install the following libraries from the library manager:
* Adafruit_NeoPixel
* ESP8266WiFi
* ESP8266HTTPClient
  
Plug in the led strips for the upper teeth in pin D5 and the lower teeth in pin D2.  
Plug the 3V in the 5V and the GND in the GND on the arduino.  

## How to
Follow this guide step by step to make the device work.  

**1. Account setup**  
Create an account at our website www.bitandbrush.com and copy your user id "sanderOost" for example.  

**2. Set up the global variables**  
Open up the arduino code editor and select the file that is located in this repository.  
The device uses an internet connection so you need to connect it to your router.  
An ssid and password are found on the back of the router and fill them in the vars.  
```
const char* ssid = "examplessid";         
const char* password = "examplepassword";    
```

Fill in the string user with the user id gained from step 1.  
```
String server = "http://www.bitandbrush.com";
String user = "?=sanderOost";

```

**3. Check wifi connection**  
First we need to check if the wifi connection works otherwise the product will not function.  
Delete the function call "getData()" in the loop.  
```
void loop() {
  getData();
}
```
Now run the code and check the serial monitor.  
It should say "Wifi connected" and then we are ready to move to the nex step.  
If it says that it keeps trying to connect you should check the ssid and password.  

**4. Displaying data**  
Now that we have a stable connection, we can try getting data from the server.  
All we have to do is add the getData() function in the loop again and then rerun the code.  
```
void loop() {
  getData();
}
```
Open up the serial monitor and check if it says "HTTP OK".  
If so, the arduino device has made a succesful call to the api and will begin displaying data in the serial monitor.  
All the monitor should show is number from 1-32 and after that a random number from 1-5.  
If the leds are plugged in the right way they should also be showing colors now.  

The setup is finished and the device should now be working properly!  

Note: If the serial monitor is not displaying any data or the light are not working properly then it could be there is not enought data collected yet from the server.  
This should be resolved by using the brush a couple times.  

## Bonus
The leds are a simulation of teeth and to put this product to full use you can attach the leds to a 3d printed model of a set of teeth.  
Download and print this model:  
https://sketchfab.com/3d-models/human-teeth-c4c569f0e08948e2a572007a7a5726f2

Use glue to attatch the led strip and wait for it to dry.  
