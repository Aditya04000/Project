#include <WiFi.h>  // Use <ESP8266WiFi.h> for ESP8266
#include <SinricPro.h>
#include <SinricProSwitch.h>

#define WIFI_SSID     "your_wifi_ssid"
#define WIFI_PASS     "your_wifi_password"
#define APP_KEY       "your_app_key"
#define APP_SECRET    "your_app_secret"

#define DEVICE_ID_1   "your_device_id_1"  // Device ID for LED1
#define DEVICE_ID_2   "your_device_id_2"  // Device ID for LED2
#define DEVICE_ID_3   "your_device_id_3"  // Device ID for LED3

#define LED1_PIN 2   // GPIO2 (D2) - LED 1
#define LED2_PIN 4   // GPIO4 (D4) - LED 2
#define LED3_PIN 5   // GPIO5 (D5) - LED 3

bool onPowerState(String deviceId, bool state) {
    Serial.print("Device ");
    Serial.print(deviceId);
    Serial.print(" turned ");
    Serial.println(state ? "ON" : "OFF");

    if (deviceId == DEVICE_ID_1) {
        digitalWrite(LED1_PIN, state ? HIGH : LOW);  // Control LED1
    } 
    else if (deviceId == DEVICE_ID_2) {
        digitalWrite(LED2_PIN, state ? HIGH : LOW);  // Control LED2
    }
    else if (deviceId == DEVICE_ID_3) {
        digitalWrite(LED3_PIN, state ? HIGH : LOW);  // Control LED3
    }

    return true;
}

void setup() {
    Serial.begin(115200);
    pinMode(LED1_PIN, OUTPUT);
    pinMode(LED2_PIN, OUTPUT);
    pinMode(LED3_PIN, OUTPUT);
    WiFi.begin(WIFI_SSID, WIFI_PASS);

    while (WiFi.status() != WL_CONNECTED) {
        delay(1000);
        Serial.println("Connecting to WiFi...");
    }
    Serial.println("Connected to WiFi");

    // Create Sinric Pro devices
    SinricProSwitch &mySwitch1 = SinricPro[DEVICE_ID_1];
    mySwitch1.onPowerState(onPowerState);

    SinricProSwitch &mySwitch2 = SinricPro[DEVICE_ID_2];
    mySwitch2.onPowerState(onPowerState);

    SinricProSwitch &mySwitch3 = SinricPro[DEVICE_ID_3];
    mySwitch3.onPowerState(onPowerState);

    SinricPro.begin(APP_KEY, APP_SECRET);
}

void loop() {
    SinricPro.handle();
}
