To create a home automation system that controls multiple devices (LEDs) remotely using ESP32/ESP8266, Sinric Pro, and Google Assistant.

 Components Required:
ESP32 / ESP8266

LEDs (3x)

220Ω Resistors (3x)

Breadboard & Jumper Wires

Wi-Fi Connection

Sinric Pro Account

Google Home App

Circuit Diagram:
LED1 → GPIO 2

LED2 → GPIO 4

LED3 → GPIO 5

Cathodes → GND through 220Ω resistors

Procedure:
Create a Sinric Pro Account:

Add three devices (LED1, LED2, LED3) and copy their Device IDs.

Connect ESP32/ESP8266 to LEDs as per the circuit diagram.

Upload the Code:

Enter Wi-Fi credentials, Sinric Pro App Key, App Secret, and Device IDs.

Test with Sinric Pro App:

Control the LEDs manually.

Connect to Google Assistant:

Open Google Home App → Set up device → Sinric Pro → Log in.

Use Voice Commands:

"Hey Google, turn ON LED1"

"Hey Google, turn OFF LED2"

"Hey Google, turn ON all LEDs"

 Observations:
LEDs respond accurately to voice commands.

Devices can be controlled remotely via the Sinric Pro App.

The system works smoothly over the internet.

 Conclusion:
The home automation system was successfully implemented, allowing remote control of multiple devices using Google Assistant and Sinric Pro.
