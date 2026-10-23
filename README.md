# LM335 Temperature Monitoring System Using Arduino

## 📌 Project Overview

This project measures temperature using an **LM335 temperature sensor** connected to an Arduino Uno. The measured temperature and corresponding sensor voltage are displayed on a 16×2 LCD.

The Arduino reads the analog sensor output, averages multiple ADC samples to reduce measurement fluctuations, converts the voltage into temperature in Celsius, and updates the LCD every second.

## 🎯 Objectives

- Measure temperature using the LM335 analog temperature sensor.
- Process analog sensor readings using the Arduino ADC.
- Reduce measurement fluctuations by averaging 16 samples.
- Display temperature and sensor voltage on a 16×2 LCD.
- Update the display at one-second intervals using `millis()`.

## 🧰 Hardware Requirements

| Component | Purpose |
|---|---|
| Arduino Uno | Main controller |
| LM335 temperature sensor | Temperature measurement |
| 16×2 LCD | Display temperature and voltage |
| Breadboard | Circuit assembly |
| Jumper wires | Electrical connections |
| Potentiometer (if required by your LCD) | LCD contrast adjustment |

## 💻 Software Requirements

- Arduino IDE
- Arduino Uno board support
- `LiquidCrystal` library (included with the standard Arduino IDE)

## 🔌 Pin Connections

### LM335 Sensor

| LM335 connection | Arduino connection |
|---|---|
| Sensor output | A0 |
| Supply and ground | According to the LM335 datasheet and the selected circuit |

**Note:** The LM335 requires an appropriate bias current and circuit configuration. Verify its pinout and wiring using the datasheet before powering the circuit.

### 16×2 LCD (4-bit mode)

| LCD pin | Arduino Uno pin |
|---|---|
| RS | 12 |
| E | 11 |
| D4 | 5 |
| D5 | 4 |
| D6 | 3 |
| D7 | 2 |
| VSS | GND |
| VDD | 5V |
| V0 | Contrast adjustment |
| RW | GND |

Connect the LCD backlight pins according to the module datasheet, using current limiting if required.

## ⚙️ Working Principle

1. The LM335 produces an output voltage proportional to absolute temperature in Kelvin, approximately 10 mV/K.
2. The Arduino reads the analog voltage through pin A0.
3. Sixteen ADC readings are collected and averaged.
4. The average ADC value is converted into voltage using a 5 V reference.
5. The voltage is rounded to 0.01 V increments.
6. The temperature is calculated in Celsius.
7. The LCD displays the temperature and sensor voltage, updating every second.

## 🧮 Temperature Calculation

The Arduino code uses the following calculations.

**ADC voltage:**

`Voltage = ADC Average × (Vref / 1023)`

**Temperature in Celsius:**

`Temperature (°C) ≈ Voltage × 100 − 273`

Here, `Vref = 5.0 V`, as configured in the code.

The voltage rounding step can affect the displayed temperature resolution. Actual accuracy depends on the sensor, calibration, ADC reference, and circuit.

## 📟 Expected Output

The LCD displays two lines similar to:

```text
Temp: 27°C
Volt: 3.00V
```

These are illustrative values; actual readings depend on the sensor output and ambient temperature.

## 🚀 How to Run

1. Connect the LM335 sensor and 16×2 LCD according to the pin tables.
2. Open the Arduino IDE.
3. Open the Arduino source file in this repository.
4. Select **Tools → Board → Arduino Uno**.
5. Select the correct COM port under **Tools → Port**.
6. Upload the code to the Arduino Uno.
7. Observe the temperature and voltage displayed on the LCD.

## 📂 Project Structure

```text
Arduino-Temperature-Monitoring/
├── temp.ino
└── README.md
```

## 🔮 Possible Future Improvements

- Calibrate sensor readings against a reference thermometer.
- Improve ADC filtering and temperature resolution.
- Add serial monitoring or data logging.
- Send readings to a web dashboard using an ESP32.
- Add high-temperature alerts.

## 👩‍💻 Author

**Namana P Chowdri**

## 📄 License

This project is available for educational and learning purposes. Add a specific open-source license if you want to define permissions for reuse and distribution.
