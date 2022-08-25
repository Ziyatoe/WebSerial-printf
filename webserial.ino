/*
  from Ziyatoe,
  https://github.com/Ziyatoe/WebSerial-printf

  printf extension for the public WebSerial library

  This sketch is based on the WebSerial library example: ESP8266_Demo
  https://github.com/ayushsharma82/WebSerial
*/

#include <Arduino.h>
#include <ESP8266WiFi.h>
#include <ESPAsyncTCP.h>
#include <ESPAsyncWebServer.h>
#include <WebSerial.h>
#include "secrets.h"
#include "extendedWebSerial.h"

#define LED 2

AsyncWebServer WebServer(80);

void WebSerialRxMsg(uint8_t *data, size_t len){
 //-------------------------------------------------------------
 WebSerial.println("Received Data...");
 String rxData = "";
 for(int i=0; i < len; i++){
   rxData += char(data[i]);
 }
 WebSerial.print("WebSerial print Rx data: ");WebSerial.println(rxData);

 DEBUG_OUT.printf("WebSerial printf >> %4s %04.1f %06i 0x%02x\r\n",rxData, 12.3, 33344, 0x0f);

 if (d == "ON") digitalWrite(LED, LOW);
 if (d == "OFF")  digitalWrite(LED, HIGH);

}//-------------------------------------------------------------


void setup() {
//-------------------------------------------------------------
 Serial.begin(115200);
 pinMode(LED, OUTPUT);
 digitalWrite(LED, HIGH);
 WiFi.mode(WIFI_STA);
 WiFi.begin(ssid, password);
 if (WiFi.waitForConnectResult() != WL_CONNECTED) {
   Serial.printf("WiFi Failed!\r\n");
   return;
 }
 else Serial.printf("WiFi connected!\r\n");
 Serial.println("IP Address: ");
 Serial.println(WiFi.localIP());
 // WebSerial is accessible at "<IP Address>/webserial" in browser

 WebSerial.begin(&WebServer);
 WebSerial.msgCallback(WebSerialRxMsg);
 WebServer.begin();
 Serial.printf("WebSerial is accessible at <IP Address>/webserial in browser  \r\n");
}//----------------------------------------------------------------------------------------------------



void loop() {
//----------------------------------------------------------------------------------------------------
DEBUG_OUT.printf("type ON or OFF, to watch the LED and printf!\r\n");
delay(2000);
 }//----------------------------------------------------------------------------------------------------
