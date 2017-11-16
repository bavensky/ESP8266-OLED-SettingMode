void mode2() {
  Serial.println("set Temp avarible");
  delay(200);

  if (digitalRead(BT0) == 0) {
    tmpCount += 1;
  }

  if (tmpCount > 30) {
    tmpCount = 20;
  }


  display.clear();
  display.setTextAlignment(TEXT_ALIGN_LEFT);
  display.setFont(ArialMT_Plain_16);
  display.drawString(0, 0, "Smart Farm");
  display.setFont(ArialMT_Plain_10);
  display.drawString(0, 16, "Temp");
  display.drawString(35, 16, String(tmpCount));
  display.drawString(50, 16, "C");
  display.display();
  delay(200);

  if (digitalRead(BT13) == 0) {
    previousMillis = millis();
  }

  while (digitalRead(BT13) == 0) {
    unsigned long currentMillis = millis();
    if (currentMillis - previousMillis >= 1500) {
      previousMillis = currentMillis;
      modeRun = 0;
    }
  }
}

