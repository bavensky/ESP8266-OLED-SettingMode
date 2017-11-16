void mode3() {
  Serial.println("set Humid avarible");
  delay(200);
  
//   hmdCount

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
}

