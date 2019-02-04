// https://www.teachmemicro.com/web-server-nodemcu-websocket/
// https://github.com/Links2004/arduinoWebSockets
// INI HARUS DOWNLOAD LIBLARY WEBSOCKETS UNTUK REALTIME


#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>
#include <WebSocketsServer.h>
#include <Hash.h>

// Replace with your network credentials
const char* ssid = "NB-MMR88120544 5059";
const char* password = "!rul12345";

WebSocketsServer webSocket = WebSocketsServer(81);
ESP8266WebServer server(80);   //instantiate server at port 80 (http port)

String page = "";
int LEDPin = D1;
int valEmergency = 0;

void setup(void) {
  pinMode(LEDPin, INPUT);
  

  Serial.begin(115200);
  WiFi.begin(ssid, password); //begin WiFi connection
  Serial.println("");

  // Wait for connection
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("");
  Serial.print("Connected to ");
  Serial.println(ssid);
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());

  server.on("/", []() {
    server.send(200, "text/html", page);
    delay(200);
  });

  // server.on("/LEDOn", [](){
  //    server.send(200, "text/html", page);
  //digitalWrite(LEDPin, HIGH);
  ///delay(1000);
  // });

  // server.on("/LEDOff", [](){
  //    server.send(200, "text/html", page);
  //    digitalWrite(LEDPin, LOW);
  //    delay(1000);
  // });

  server.begin();
  webSocket.begin();
  webSocket.onEvent(webSocketEvent);

  Serial.println("Web server started!");
}

void loop(void) {
  valEmergency = digitalRead(LEDPin);
  webSocket.loop();
  server.handleClient();
  if (Serial.available() > 0) {
    char c[] = {(char)Serial.read()};
    webSocket.broadcastTXT(c, sizeof(c));
  }
  if (valEmergency == 1) {
    page = "<h1 align='center'>Simple NodeMCU Web Server</h1><p><br><h1 align='center'><font color='red'>EMERGENCY</font></h1>";
  }
  else {
    page = "<h1 align='center'>Simple NodeMCU Web Server</h1><p><br><h1 align='center'><h1 align='center'><font color='yellow'>STANBY</font></h1>";
  }
}

void webSocketEvent(uint8_t num, WStype_t type, uint8_t * payload, size_t length) {
  if (type == WStype_TEXT) {
    for (int i = 0; i < length; i++) Serial.print((char) payload[i]);
    Serial.println();
  }
}
