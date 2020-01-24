# Bit And brush (Bit Device)

## About
In this manual the user will learn how to set up his own node server and controlling the led strips with the use of an array.
The idea behind this is that we can simulate where the user didnt brush his or her teeth well enough from a web server.

## Requirements
* Arduino code editor (https://www.arduino.cc/en/Main/Software)
* Arduino esp8266
* 2 led strips
* Laptop/Pc
* Ngrok server Port (https://ngrok.com/)
* Npm (https://www.npmjs.com/)

## Setup arduino
Install the following libraries from the library manager:
* Adafruit_NeoPixel
* ESP8266WiFi
* ESP8266HTTPClient
  
Plug in the led strips for the upper teeth in pin D5 and the lower teeth in pin D2.  
Plug the 3V in the 5V and the GND in the GND on the arduino.  

## How to use
Follow this guide step by step to make the device and server work and connected to eachother.  

# Server setup
The server runs on a nodeJs server and we will need to port that server to the web in order for the device to connect and use the given array.

**1. Import Npm Package from git**
First import this package from github and open terminal in the root folder.
Then type "npm install" in the terminal and the packages should be installed.

**2. Run Npm package**
Now type "Nodemon index.js" in the same terminal and open up a web browser of your choice.
![Nodemon](https://github.com/Sanderoost/files/blob/master/Schermafbeelding%202020-01-24%20om%2010.49.15.png")


In the url bar naigate to "Localhost:2000"
If everything is in order the page should show:
![Nodemon](https://github.com/Sanderoost/files/blob/master/Schermafbeelding%202020-01-24%20om%2010.53.32.png")
These are the 2 arrays we are going to pass through the ported server to the nodeMCU.


**3. Porting the server**
Now we want the server to be available for the nodemcu.
We will be using Ngrok for that and after its installed navigate to the root folder where ngrok is installed.
Type "./ngrok http localhost:2000" in the terminal and it should return the following:
![ngrok](https://github.com/Sanderoost/files/blob/master/Schermafbeelding%202020-01-24%20om%2011.01.59.png")
Keep the window open because we need the url later on.

**4. Testing ngrok port**
We need to check if the server is online so navigate to the ported server and see if it responds.
In my example the server is: http://576a23d2.ngrok.io 

# Arduino setup
The arduino needs to be connected to the internet and be able to retrieve the array from the ported server

**1. Set up the connection variables**  
Open up the arduino code editor and select the file that is located in this repository.  
The device uses an internet connection so you need to connect it to your router.  
An ssid and password are found on the back of the router and fill them in the vars.  
```
const char* ssid = "examplessid";         
const char* password = "examplepassword";    
```
**2. Check wifi connection**  
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


**3. Check wifi connection**  
Fill in the string server gained from the ngrok server port.  
```
String server = "http://576a23d2.ngrok.io";
```
That is my example string from the first steps.

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

Note: If the serial monitor is not displaying any data or the light are not working properly then it could be there is a server issue from ngrok(They update the servers a lot)

**Array changes**
At the moment the array represents which color the led light will show and the number is written in the arduino code.
If you wish to change the value of a number, edit the rgb color code from the following code:
```
// het instellen van de kleuren
void setLed(int ledNumber, int state, String led) {
  switch(state){
    case 1:
      strip.setPixelColor(ledNumber, led.Color(0, 102, 255 ));
      break;
    case 2:
      strip.setPixelColor(ledNumber, led.Color(153, 204, 255)); 
      break;    
    case 3:
      strip.setPixelColor(ledNumber, led.Color(255, 255, 204));  
      break;
    case 4:
      strip.setPixelColor(ledNumber, led.Color(255, 204, 102));  
      break;
    case 5:  
      strip.setPixelColor(ledNumber, led.Color(255, 0, 0));  
      break;    
  }
```

Keep in mind that the array always has to have 16 numbers otherwise the program will fail to run.
