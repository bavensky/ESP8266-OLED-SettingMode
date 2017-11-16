#include <Wire.h>
#include "SSD1306.h"
#include "DHT.h"

SSD1306  display(0x3c, 4, 5);

#define DHTPIN 12
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);

#define BT0  0
#define BT13 13


unsigned long previousMillis = 0;

int bt0Read = 0;
int bt13Read = 0;
int count = 1;
int modeRun = 0;
boolean statBT = false;

int t = 0, h = 0;
int tmpCount = 20, hmdCount = 50;

void setup() {
  Serial.begin(9600);

  pinMode(BT0, INPUT_PULLUP);
  pinMode(BT13, INPUT_PULLUP);

  dht.begin();

  display.init();
  display.flipScreenVertically();
  display.setFont(ArialMT_Plain_10);
}

void loop() {
  Serial.println("Main loop");
  
  if (digitalRead(BT13) == 0) {
    previousMillis = millis();
  }

  while (digitalRead(BT13) == 0) {
    unsigned long currentMillis = millis();
    if (currentMillis - previousMillis >= 1500) {
      previousMillis = currentMillis;
      modeRun = 1;
    }
  }

  t = dht.readTemperature();
  h = dht.readHumidity();

  display.clear();
  display.setTextAlignment(TEXT_ALIGN_LEFT);
  display.setFont(ArialMT_Plain_16);
  display.drawString(0, 0, "Smart Farm");
  display.setFont(ArialMT_Plain_10);
  display.drawString(0, 16, "Temp");
  display.drawString(35, 16, String(t));
  display.drawString(50, 16, "C");
  display.drawString(0, 26, "Humid");
  display.drawString(35, 26, String(h));
  display.drawString(50, 26, "%RH");
  display.drawString(0, 36, "Light");
  display.display();
  delay(200);



  while (modeRun == 1) {
    mode1();
  }
  while (modeRun == 2) {
    mode2();
  }
  while (modeRun == 3) {
    mode3();
  }
}


//  if (digitalRead(BT0) == 0 && statBT == false) {
//    Serial.print("active ");
//    statBT = true;
//    previousMillis = millis();
//  }
//
//  if (digitalRead(BT0) == 1) {
//    statBT = false;
//  }
//
//  if (digitalRead(BT0) == 0 && statBT == true) {
//    unsigned long currentMillis = millis();
//    if (currentMillis - previousMillis >= 3000) {
//      previousMillis = currentMillis;
//      statBT = false;
//      modeRun = 2;
//    }
//  }

