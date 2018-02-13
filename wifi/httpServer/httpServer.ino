extern "C" {
  #include "user_interface.h"  // Required for wifi_station_connect() to work
}

#include <Arduino.h>
#include <ESP8266WiFi.h>

#define MAX_TRIALS_DHT  20  // Aprox. 4 seg.
#define DELAY_WIFI      200
#define MAX_TRIALS_WIFI 40  // Aprox. 8 seg.
#define SLEEP_TIME      300 // 5 minutos
#define FPM_SLEEP_MAX_TIME 0xFFFFFFF


const int ledPIN = 13;
const char *ssid     = "XXXXX";
const char *password = "XXXXX";

WiFiServer server(80);

void WiFiOn();
void WiFiOff();

void setup() {
  Serial.begin(9600);
  delay(10);
  pinMode(ledPIN , OUTPUT);
  Serial.println();
  connectToWiFi();
  Serial.println();
}

bool connectToWiFi() {
  WiFiOn();
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);
  WiFi.setAutoConnect(false);
  WiFi.setAutoReconnect(false);
  Serial.print ( "Connecting to WIFI" );
  int numTrials = 0;
  while ( WiFi.status() != WL_CONNECTED ) {
    delay ( DELAY_WIFI );
    Serial.print ( "." );
    numTrials++;
    if (numTrials == MAX_TRIALS_WIFI) {
      Serial.println("Could not connect to WIFI. Aborting");
      return false;
    }
  }
  Serial.println();
  digitalWrite(ledPIN , HIGH);
  server.begin();
  Serial.println(WiFi.localIP());
  return true;
}

void loop() {
  WiFiClient client = server.available();
  if (!client) {
    delay(100);
    return;
  }

  Serial.println("new client");
  while(!client.available())
     delay(100);

  int req = readRequest(client);
  digitalWrite(ledPIN , req);
}

int readRequest(WiFiClient client) {
  String req = client.readStringUntil('\r');
  Serial.println(req);
  client.flush();  
  int val;
  if ( req.indexOf("/led/on") != -1)
     val = HIGH;
  else 
      val = LOW;

  String s = "HTTP/1.1 200 OK\r\nContent-Type: text/html\r\n\r\n<!DOCTYPE HTML>\r\n<html>\r\nLED is now ";
  s += (val== HIGH)?"high":"low";
  s += "</html>\n";
  client.print(s);                    
  delay(1);
  return val;
}
void WiFiOn() {
  wifi_fpm_do_wakeup();
  wifi_fpm_close();
  digitalWrite(ledPIN , HIGH);
}


void WiFiOff() {
  digitalWrite(ledPIN , LOW); 
  wifi_station_disconnect();
  wifi_set_opmode(NULL_MODE);
  wifi_set_sleep_type(MODEM_SLEEP_T);
  wifi_fpm_open();
  wifi_fpm_do_sleep(FPM_SLEEP_MAX_TIME);

}
