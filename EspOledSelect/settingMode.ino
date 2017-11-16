void mode1() {
  if (digitalRead(BT13) == 0) {
    previousMillis = millis();
  }

  while (digitalRead(BT13) == 0) {
    unsigned long currentMillis = millis();
    if (currentMillis - previousMillis >= 2000 && count == 1) {
      previousMillis = currentMillis;
      modeRun = 2;
      Serial.println("setting temp");
      delay(2000);
    }
    if (currentMillis - previousMillis >= 2000 && count == 2) {
      previousMillis = currentMillis;
      modeRun = 3;
      Serial.println("setting humid");
      delay(2000);
    }
  }


  if (digitalRead(BT0) == 0) {
    count += 1;
  }

  if (count > 2) {
    count = 1;
  }

  if (count == 1) {
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

  if (count == 2) {
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
  delay(200);
  
//  if (count == 2) {
//    display.clear();
//    display.setTextAlignment(TEXT_ALIGN_LEFT);
//    display.setFont(ArialMT_Plain_16);
//    display.drawString(0, 0, "Setting Mode...");
//    display.setFont(ArialMT_Plain_10);
//    display.drawString(0, 16, "     Temp");
//    display.drawString(0, 26, "     Humid");
//    display.drawString(0, 36, "--> Light");
//    display.display();
//  }
}

  //  if (digitalRead(BT13) == 0 && statBT == false) {
  //    Serial.print("active ");
  //    statBT = true;
  //    previousMillis = millis();
  //  }
  //
  //  if (digitalRead(BT13) == 1) {
  //    statBT = false;
  //  }
  //
  //  if (digitalRead(BT13) == 0 && statBT == true) {
  //    unsigned long currentMillis = millis();
  //    if (currentMillis - previousMillis >= 3000) {
  //      previousMillis = currentMillis;
  //      statBT = false;
  //      modeRun = 0;
  //    }
  //  }
