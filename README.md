# Smart monitoring of the light condition at Chicken Farmhouse- egg laying and hatching
Design and development of a light intensity monitoring system for chicken farmhouses using Arduino to optimize egg laying and hatching conditions.


This project is an **Arduino-based smart system** designed to monitor and control light intensity in chicken farmhouses, ensuring optimal conditions for egg laying and hatching. The system provides **real-time alerts**, **LED indicators**, **buzzer alarms**, and **mobile notifications via Blynk IoT**, helping farmers improve hatch rates and overall poultry health.

---

## 📌 Project Overview

- **Objective:** Automate monitoring and control of light intensity in chicken farmhouses.  
- **Platform:** Arduino MKR WiFi 1010  
- **Sensors & Actuators:**
  - **Photoresistor (LDR):** Measures ambient light intensity.  
  - **LEDs:** Indicate low/high light levels.  
  - **Buzzer:** Provides immediate alarm signals for abnormal light conditions.  
- **Mobile Integration:** Uses **Blynk IoT** to send automatic notifications when light conditions are not optimal.  

---

## 🛠️ Components & Tools

- **Microcontroller:** Arduino MKR WiFi 1010  
- **Sensor:** LDR / Photoresistor  
- **Actuators:**  
  - LED1 → Low light indicator (< 300 intensity)  
  - LED2 → High light indicator (> 700 intensity)  
  - Buzzer → Alarm for low/high light conditions  
- **Resistors:** 220Ω for LEDs, 10kΩ for LDR voltage divider  
- **Software Tools:** Arduino IDE, Blynk App  
- **Libraries:** Wire.h, WiFiNINA, BlynkSimpleWiFiNINA  

---

## 🔌 Wiring Diagram

| Arduino Pin | Component         | Breadboard Connection |
|------------|-----------------|---------------------|
| A0         | LDR               | One leg → A0, other leg → GND through 10kΩ resistor (voltage divider with 5V) |
| 6          | LED1 (Low Light)  | LED anode (+) → Pin 6 through 220Ω resistor, cathode (–) → GND |
| 7          | LED2 (High Light) | LED anode (+) → Pin 7 through 220Ω resistor, cathode (–) → GND |
| 8          | Buzzer            | + pin → Pin 8, – pin → GND |
| 5V         | Breadboard Power  | Connect to + rail |
| GND        | Breadboard GND    | Connect to – rail |

> **Note:** LDR is non-polarized; either leg can go to 5V or GND.  

---

## ⚡ Features

1. **Real-time light monitoring:** Continuously measures light intensity via LDR.  
2. **Automatic alert system:**  
   - LED1 ON if light < 300  
   - LED2 ON if light > 700  
   - Buzzer sounds for abnormal conditions  
3. **Mobile notifications via Blynk IoT:** Sends alerts when light is too low or too high.  
4. **Adjustable thresholds:** LIGHT_LOW = 300, LIGHT_HIGH = 700 (can be modified in code).  

## Project Design Files

All design-related files are in the [`design/`](design/) folder:

- Breadboard and circuit screenshots
- Electrical design file (`.brd`)
- Tinkercad simulation link (`Tinkercad_link.txt`)
---

## 💻 Arduino Code

The **full Arduino sketch** is available in the `code/` folder:

[Chicken_Egg_Hatching_Monitor.ino](code/Chicken_Egg_Hatching_Monitor.ino)

**Snippet of main logic:**

```c
int lightValue = analogRead(LDR_PIN);

if (lightValue < LIGHT_LOW) {
    digitalWrite(LED1_PIN, HIGH);
    digitalWrite(LED2_PIN, LOW);
    digitalWrite(BUZZER_PIN, HIGH);
    Blynk.notify("⚠️ Light too LOW (<300)!");
} 
else if (lightValue > LIGHT_HIGH) {
    digitalWrite(LED1_PIN, LOW);
    digitalWrite(LED2_PIN, HIGH);
    digitalWrite(BUZZER_PIN, HIGH);
    Blynk.notify("⚠️ Light too HIGH (>700)!");
} 
else {
    digitalWrite(LED1_PIN, LOW);
    digitalWrite(LED2_PIN, LOW);
    digitalWrite(BUZZER_PIN, LOW);
}
