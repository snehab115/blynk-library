/**************************************************************
 * Blynk is a platform with iOS and Android apps to control
 * Arduino, Raspberry Pi and the likes over the Internet.
 * You can easily build graphic interfaces for all your
 * projects by simply dragging and dropping widgets.
 *
 *   Downloads, docs, tutorials: http://www.blynk.cc
 *   Blynk community:            http://community.blynk.cc
 *   Social networks:            http://www.fb.com/blynkapp
 *                               http://twitter.com/blynk_app
 *
 * Blynk library is licensed under MIT license
 * This example code is in public domain.
 *
 **************************************************************
 * This example runs directly on ESP8266 chip.
 *
 * WARNING! ESP8266 SSL support is still experimental.
 *          More info here: https://github.com/esp8266/Arduino/issues/43
 *
 * Note: This requires ESP8266 support package:
 *   https://github.com/esp8266/Arduino
 *
 * Please be sure to select the right ESP8266 module
 * in the Tools -> Board menu!
 *
 **************************************************************/

#define BLYNK_PRINT Serial    // Comment this out to disable prints and save space
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

// You should get Auth Token in the Blynk App.
// Go to the Project Settings (nut icon).
char auth[] = "YourAuthToken";

// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "YourNetworkName";
char pass[] = "YourPassword";


// Mac address should be different for each device in your LAN
byte arduino_mac[] = { 0xDE, 0xED, 0xBA, 0xFE, 0xFE, 0xED };
IPAddress device_ip  (192, 168,   0,  80);
IPAddress dns_ip     (  8,   8,   8,   8);
IPAddress gateway_ip (192, 168,   0,   1);
IPAddress subnet_mask(255, 255, 255,   0);

void setup()
{
  Serial.begin(9600);

  // Setup WiFi network
  WiFi.config(device_ip, gateway_ip, subnet_mask);
  WiFi.begin(ssid, pass);

  // Setup Blynk
  Blynk.config(auth);
  while (Blynk.connect() == false) {
  }

}

void loop()
{
  Blynk.run();
}

