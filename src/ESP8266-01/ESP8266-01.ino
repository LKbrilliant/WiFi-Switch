/*  
  Code by   :   Anuradha Gunawardhana
  date      :   02-Jun-2019
  version   :   1.0.020619

*/


#define relay 3   // relay is on GPIO 3 
#define led 1     //On board LED

#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>

#include "index.h"                        // HTML webpage contents with javascripts

// Your WiFi credentials
const char* ssid = "YOUR_SSID";
const char* password = "YOUR_PASSWORD";

String current_relay_state = "0";  

ESP8266WebServer server(80);              //Server on port 80

IPAddress staticIP(192, 168, 1, 90);      // ESP static ip
IPAddress gateway(192, 168, 1, 1);        // IP Address of WiFi Router (Gateway)
IPAddress subnet(255, 255, 255, 0);       // Subnet mask
IPAddress dns(8, 8, 8, 8);                // DNS

void setup(){  
  pinMode(relay, OUTPUT);
  digitalWrite(relay, LOW);
  pinMode(led, OUTPUT);
  digitalWrite(led, HIGH);                         // On board LED Active LOW
  
  WiFi.begin(ssid, password);                     //Connect to your WiFi router
  WiFi.config(staticIP, gateway, subnet, dns);
  
  while (WiFi.status() != WL_CONNECTED) {         // Wait for connection
    delay(500);
  }
 
  server.on("/", handleRoot);                     //Which routine to handle at root location. This is display page
  server.on("/setRelay", relayHandle);
  server.on("/getRelayState", GetRelayStateHandle);
  server.begin();                                 //Start the server
}

void loop(){
  server.handleClient();                          //Handle client requests
}

void handleRoot() {
 String s = MAIN_page;              //Read HTML contents
 server.send(200, "text/html", s);  //Send web page
}

void relayHandle() {
 String relayState = "OFF";
 String t_state = server.arg("relayState"); //Refer  xhttp.open("GET", "setRelay?relayState="+state, true);

 if(t_state == "1"){
  digitalWrite(relay,HIGH);   //Relay ON
  digitalWrite(led,LOW);      // onboard LED Ative LOW
  relayState = "ON";          //Feedback parameter

  current_relay_state = "1";
 }
 else{
  digitalWrite(relay,LOW);    //Relay OFF
  digitalWrite(led,HIGH);     // onboard LED Ative LOW
  relayState = "OFF";         //Feedback parameter  

  current_relay_state="0";
 }
 
 server.send(200, "text/plane", relayState); //Send web page
}

void GetRelayStateHandle() {
 server.send(200, "text/plane", current_relay_state); //Send web page
}
