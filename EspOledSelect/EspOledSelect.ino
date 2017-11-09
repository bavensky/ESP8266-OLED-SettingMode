#include <Wire.h>
#include "SSD1306.h"
SSD1306  display(0x3c, 4, 5);

#define BT0  0
#define BT13 13


unsigned long previousMillis = 0;

int bt0Read = 0;
int bt13Read = 0;
int count = 0;
int modeRun = 0;
boolean statBT = false;

void setup() {
  Serial.begin(9600);
  pinMode(BT0, INPUT_PULLUP);
  pinMode(BT13, INPUT_PULLUP);

  display.init();
  display.flipScreenVertically();
  display.setFont(ArialMT_Plain_10);
}

void loop() {
  if (digitalRead(BT0) == 0 && statBT == false) {
    Serial.print("active ");
    statBT = true;
    previousMillis = millis();
  }

  if (digitalRead(BT0) == 1) {
    statBT = false;
  }

  if (digitalRead(BT0) == 0 && statBT == true) {
    unsigned long currentMillis = millis();
    if (currentMillis - previousMillis >= 3000) {
      previousMillis = currentMillis;
      statBT = false;
      modeRun = 2;
    }
  }


  display.clear();
  display.setTextAlignment(TEXT_ALIGN_LEFT);
  display.setFont(ArialMT_Plain_16);
  display.drawString(0, 0, "Smart Farm");
  display.setFont(ArialMT_Plain_10);
  display.drawString(0, 16, "Temp");
  display.drawString(32, 16, "1234");
  display.drawString(0, 26, "Humid");
  display.drawString(0, 36, "Light");
  display.display();
  delay(200);



  while (modeRun == 2) {
    mode2();
  }
}

void mode2() {
  if (digitalRead(BT13) == 0 && statBT == false) {
    Serial.print("active ");
    statBT = true;
    previousMillis = millis();
  }

  if (digitalRead(BT13) == 1) {
    statBT = false;
  }

  if (digitalRead(BT13) == 0 && statBT == true) {
    unsigned long currentMillis = millis();
    if (currentMillis - previousMillis >= 3000) {
      previousMillis = currentMillis;
      statBT = false;
      modeRun = 0;
    }
  }



  if (digitalRead(BT0) == 0) {
    count -= 1;
  }
  if (digitalRead(BT13) == 0) {
    count += 1;
  }

  if (count < 0) {
    count = 2;
  }
  if (count > 2) {
    count = 0;
  }

  if (count == 0) {
    display.clear();
    display.setTextAlignment(TEXT_ALIGN_LEFT);
    display.setFont(ArialMT_Plain_16);
    display.drawString(0, 0, "Setting Mode...");
    display.setFont(ArialMT_Plain_10);
    display.drawString(0, 16, "--> Temp");
    display.drawString(0, 26, "     Humid");
    display.drawString(0, 36, "     Light");
    display.display();
  }

  if (count == 1) {
    display.clear();
    display.setTextAlignment(TEXT_ALIGN_LEFT);
    display.setFont(ArialMT_Plain_16);
    display.drawString(0, 0, "Setting Mode...");
    display.setFont(ArialMT_Plain_10);
    display.drawString(0, 16, "     Temp");
    display.drawString(0, 26, "--> Humid");
    display.drawString(0, 36, "     Light");
    display.display();
  }
  if (count == 2) {
    display.clear();
    display.setTextAlignment(TEXT_ALIGN_LEFT);
    display.setFont(ArialMT_Plain_16);
    display.drawString(0, 0, "Setting Mode...");
    display.setFont(ArialMT_Plain_10);
    display.drawString(0, 16, "     Temp");
    display.drawString(0, 26, "     Humid");
    display.drawString(0, 36, "--> Light");
    display.display();
  }
  delay(200);
}

