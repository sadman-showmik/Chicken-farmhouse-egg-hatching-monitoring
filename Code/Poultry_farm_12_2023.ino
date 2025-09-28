#define BLYNK_TEMPLATE_ID "TMPL4S7XRlP1z"   
#define BLYNK_TEMPLATE_NAME "Chicken Egg Hatching Monitor"
#define BLYNK_AUTH_TOKEN "qNbAnRFwCXbBAn_D3CU-wBo4Vc3pf3Qy"  

#include <Wire.h>
#include <WiFiNINA.h>
#include <BlynkSimpleWiFiNINA.h>

// WiFi credentials
const char* ssid = "AIoT-5GmmWave_IoT";
const char* password = "AIoT-2024";

// Pin definitions
#define LDR_PIN A0
#define BUZZER_PIN 8
#define LED1_PIN 6  // Low light indicator
#define LED2_PIN 7  // High light indicator

// Light intensity thresholds
#define LIGHT_LOW 300
#define LIGHT_HIGH 700

void setup() {
    pinMode(BUZZER_PIN, OUTPUT);
    pinMode(LED1_PIN, OUTPUT);
    pinMode(LED2_PIN, OUTPUT);

    digitalWrite(LED1_PIN, LOW);
    digitalWrite(LED2_PIN, LOW);
    digitalWrite(BUZZER_PIN, LOW);

    Serial.begin(9600);

    // Connect to Blynk IoT
    Blynk.begin(BLYNK_AUTH_TOKEN, ssid, password);
}

void loop() {
    int lightValue = analogRead(LDR_PIN);
    Serial.print("Light Intensity: ");
    Serial.println(lightValue);

    // LED logic
    if (lightValue < LIGHT_LOW) { // Low light
        digitalWrite(LED1_PIN, HIGH); // LED1 ON
        digitalWrite(LED2_PIN, LOW);  // LED2 OFF
        Blynk.notify("⚠️ Light too LOW (<300)!");
    }
    else if (lightValue > LIGHT_HIGH) { // High light
        digitalWrite(LED1_PIN, LOW);   // LED1 OFF
        digitalWrite(LED2_PIN, HIGH);  // LED2 ON
        Blynk.notify("⚠️ Light too HIGH (>700)!");
    }
    else { // Optimal light
        digitalWrite(LED1_PIN, LOW);
        digitalWrite(LED2_PIN, LOW);
    }

    delay(2000);  // 2-second interval
    Blynk.run();  // Keep Blynk connected
}
