#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

const int sensorPin = A0;
const float Vref = 5.0;

// ===== Degree Symbol =====
byte degreeSymbol[8] = {
  B00111,
  B00101,
  B00111,
  B00000,
  B00000,
  B00000,
  B00000,
  B00000
};

// ===== Timer variables =====
unsigned long previousMillis = 0;
const unsigned long interval = 1000;   // 1 second update

void setup() {
  lcd.begin(16, 2);
  lcd.createChar(0, degreeSymbol);   // store degree symbol in slot 0
  
  lcd.print("LM335 Sensor");
  delay(1500);
  lcd.clear();
}

void loop() {

  // ===== TIMER INSTEAD OF DELAY =====
  unsigned long currentMillis = millis();

  if (currentMillis - previousMillis >= interval) {
    previousMillis = currentMillis;

    long sum = 0;

    // ===== 16 SAMPLES =====
    for (int i = 0; i < 16; i++) {
      sum += analogRead(sensorPin);
    }

    // ===== SHIFT INSTEAD OF DIVIDE =====
    float adcAvg = sum >> 4;   // divide by 16

    // Convert to voltage
    float voltage = adcAvg * (Vref / 1023.0);

    // ===== LOCK TO 0.01V STEP =====
    float lockedVoltage = round(voltage * 100.0) / 100.0;

    // Convert to temperature (LM335 gives Kelvin)
    float tempC = (lockedVoltage * 100.0) - 273.0;

    // ===== DISPLAY =====
    lcd.setCursor(0, 0);
    lcd.print("Temp:");
    lcd.print(tempC, 0);
    lcd.write(byte(0));   // degree symbol
    lcd.print("C   ");

    lcd.setCursor(0, 1);
    lcd.print("Volt:");
    lcd.print(lockedVoltage, 2);
    lcd.print("V   ");
  }
}