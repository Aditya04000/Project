#include <WiFi.h>  // Use <ESP8266WiFi.h> for ESP8266
#include <SinricPro.h>
#include <SinricProSwitch.h>

#define WIFI_SSID     "IOT"
#define WIFI_PASS     "12345678"
#define APP_KEY       "67af8ef0-e34f-427e-90d4-36175963b50e"
#define APP_SECRET    "626a9cea-cc1f-4ad3-8dbb-a3d15ff2c021-b843b0cb-394c-4e12-b037-bd33ba0ae4b2"

#define DEVICE_ID_1   "67d1d0bdbce795b1eeb8678b"  // Device ID for LED1
#define DEVICE_ID_2   "67cdaf99bce795b1eeb516fe"  // Device ID for LED2
#define DEVICE_ID_3   "67d1d00dbce795b1eeb8664d"  // Device ID for LED3

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
