#include <Adafruit_NeoPixel.h>
#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>

const char* ssid = "";         
const char* password = "";    

String server = "ngrokString";


//Leds aansluiting benoemen
#define UPPER_PIN    D5
#define UPPER_COUNT 16

#define LOWER_PIN    D2
#define LOWER_COUNT 16

int upperTeeth[] = {};
int lowerTeeth[] = {}

Adafruit_NeoPixel upper(UPPER_COUNT, UPPER_PIN, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel lower(LOWER_COUNT, LOWER_PIN, NEO_GRB + NEO_KHZ800);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  
  Serial.println();  Serial.println();  Serial.print("Connecting to "); Serial.println(ssid);

  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print("."); // geeft puntjes in de serial monitor tijdens inloggen
  }
  Serial.println("");
  Serial.println("WiFi connected");

  // De led strip laten oplichten
  upper.begin();           
  lower.begin();
  upper.show();           
  lower.show();

}

void loop() {
  getData();
}

void getData() {
  String url = server;
  Serial.println("Loading: " + url);

  HTTPClient http;
  http.begin(url); //HTTP
  int httpCode = http.GET();
  if (httpCode > 0) {
    if (httpCode == HTTP_CODE_OK) {
      Serial.println("HTTP OK");
      String payload = http.getString();
      extractDataFromAPI(payload);
      delay(1000);
      return;
    }
  } else {
    Serial.printf("[HTTP] GET... failed, error: %s\n", http.errorToString(httpCode).c_str());
    http.end();
    delay(1000);
    return;
  }
  
  for(int i=0; i < UPPER_COUNT; i++){
    setLed(i, upperTeeth[i], upper);
    Serial.println(upperTeeth[i]);
    delay(500);
  }
  
  for(int i=0; i < LOWER_COUNT; i++){
    setLed(i, lowerTeeth[i], lower);
    Serial.println(lowerTeeth[i]);
    delay(500);
  }
}

void extractDataFromAPI(String data) {
  int upper = 16;
  for (int i = 0; i < upper; i++ ) {
    int subStringStart = i * 11;
    int subStringEnd = i * 11 + 3;
    upperTeeth[i] = data.substring(subStringStart, subStringEnd).toInt();
  }
  int lower = 16;
  for (int i = 0; i < upper; i++ ) {
    int subStringStart = i * 11;
    int subStringEnd = i * 11 + 3;
    upperTeeth[i] = data.substring(subStringStart, subStringEnd).toInt();
  }
}

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
  led.show(); 
}
