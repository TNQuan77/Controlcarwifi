/*
    This sketch establishes a TCP connection to a "quote of the day" service.
    It sends a "hello" message, and then prints received data.
*/
#include <string.h>
#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>

using namespace std;
#ifndef STASSID
#define STASSID "Mi 9T"
#define STAPSK "12345678"
#endif

const char *ssid = STASSID;
const char *password = STAPSK;

const char *host = "djxmmx.net";
const uint16_t port = 17;

ESP8266WebServer server(80);

void PAGEHOME()
{
  String s = server.arg("s");
  String d = server.arg("d");

  // Speed
  if (s == "slow")
  {
    Serial.print("\n5");
  }
  else if (s == "normal")
  {
    Serial.print("\n8");
  }
  else if (s == "fast")
  {
    Serial.print("\nq");
  }
  else
    Serial.print("\n0");
  // Direction
  if (d == "up")
  {
    Serial.print("\nF");
  }
  else if (d == "down")
  {
    Serial.print("\nB");
  }
  else if (d == "left")
  {
    Serial.print("\nL");
  }
  else if (d == "right")
  {
    Serial.print("\nR");
  }

  server.send(200, "text/html", "coi dt di");
}

void setup()
{
  delay(1000);
  Serial.begin(9600);

  server.on("/", PAGEHOME);
  server.begin();
  Serial.println("\nHTTP server started");

  // We start by connecting to a WiFi network
  connectWiFi();
}

void loop()
{
  server.handleClient();
}

void connectWiFi()
{
  // We start by connecting to a WiFi network

  Serial.println();
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);

  /* Explicitly set the ESP8266 to be a WiFi-client, otherwise, it by default,
     would try to act as both a client and an access-point and could cause
     network-issues with your other WiFi-devices on your WiFi-network. */
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED)
  {
    delay(500);
    Serial.print(".");
  }

  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
}
