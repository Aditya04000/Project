 Use of IoT (Internet of Things) technology to control household devices remotely through the internet. It enhances convenience, security, and energy efficiency.
 ESP32/ESP8266 Microcontroller:

The ESP32/ESP8266 is a Wi-Fi-enabled microcontroller that connects to the Sinric Pro cloud.

It receives commands from Sinric Pro and controls the connected devices accordingly.

Sinric Pro Platform:

Sinric Pro is a cloud-based service that links devices to the internet, allowing remote control.

It acts as a bridge between the ESP32/ESP8266 and Google Assistant.

When a voice command is given, Sinric Pro sends the signal to the ESP32/ESP8266.

Google Assistant Integration:

The devices are linked to Google Assistant through Google Home.

You can control the devices using voice commands like:

"Hey Google, turn ON LED1"

"Hey Google, turn OFF LED2"

Procedure:
Step 1: Create a Sinric Pro Account
Go to https://sinric.pro and create an account.

Log in and click on “Add Device”.

Add three devices named:

LED1

LED2

LED3

Copy the Device IDs, App Key, and App Secret.

Step 2: Connect ESP32/ESP8266 to the LEDs
Place the ESP32/ESP8266 on the breadboard.

Connect:

LED1 Anode → GPIO 2

LED2 Anode → GPIO 4

LED3 Anode → GPIO 5

Cathodes of all LEDs → GND through 220Ω resistors.

Double-check all connections.

Step 3: Upload the Code
Open Arduino IDE.

Install the required libraries:

SinricPro

WiFi (or ESP8266WiFi if using ESP8266)

WebSocketsClient

Enter the Wi-Fi credentials, Sinric Pro App Key, App Secret, and Device IDs in the code.

Upload the code to ESP32/ESP8266.

Step 4: Test with Sinric Pro App
Open the Sinric Pro App on your phone.

Turn LED1, LED2, and LED3 ON/OFF manually to verify they are working correctly.

Step 5: Connect Sinric Pro to Google Assistant
Open Google Home App on your phone.

Tap the "+" button → Set up device → Works with Google.

Search for Sinric Pro and log in with your Sinric Pro account.

The three devices (LED1, LED2, LED3) will appear in Google Home.

Step 6: Use Voice Commands
Once the devices are recognized, you can control them using Google Assistant:

To turn ON a specific LED:

"Hey Google, turn ON LED1"

"Hey Google, turn ON LED2"

"Hey Google, turn ON LED3"

To turn OFF specific LEDs:

"Hey Google, turn OFF LED1"

"Hey Google, turn OFF LED2"

"Hey Google, turn OFF LED3"

To control all LEDs together:

"Hey Google, turn ON all LEDs"

"Hey Google, turn OFF all LEDs"
