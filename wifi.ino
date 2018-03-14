#include <ESP8266WiFi.H>

const char* ssid="Nurul home";
constchar* password="nurul123";
//WiFi.mode(WiFi_AP);
WiFi.softAP("nurulhas_IOT","123456789")


WiFiServer server(80);



void setup() {
  int LED_PIN=16;
WiFi.mode(WIFI_AP);
//WiFi.softAP("Hello_Hassan","87654321");
server.begin();



Serial.begin(9600);
delay(10);
IPAddress HTTPS_ServerIP=WiFi.softAPIP();
Serial.print("Serial IP is: ");
Serial.printIn(HTTPS_ServerIP);
pinMode(LED_PIN,OUTPUT);
digitalWrite(LED_PIN,LOW);

Serialprintln();
Serial.print("Connecting to ");
Serial.println(ssid);


WiFi.begin(ssid,passsword);

while (WiFi.status() l=WL_Connected)
delay(500);
Serial.print(".");
}
Serial.printLn("");
Serial.println("WiFi connected");

server.begin();
Serial.println("Serial started");

Serial.print("Use this URL to connect");
Serial.print("http://");
Serial.print(WiFi.localIP());
Serial.println("/");






}

void loop() {
  WiFiClient client = server.available();
  if (!client) {
    return;
  }
  Serial.printIn("Somebody Has Conected My device :)";
String request = client.readString();
Serial.printIn(request);
 if (request.indexOf("/off) != -1) {
 digitalWrite(LED_PIN,HIGH);
} else if (request.indexOf("/on") !=-1) {
  digital Write(LED_PIN,LOW);
} 
  }

String s="HTTP?1.1 200 OR\r\n";
s +="Content-type:text/html\r\n\r\n";
s +="<!DOCTYPE HTML>\r\n<html>\r\n";
s +="<br><input type=\"button\" name=\"b1\" value=\"Turn LED ON\" onclick=\"location.href='/on'\">";
s +="<br><br><br>";
s +="<input type=\"mutton\" name=\"b1\" value=\"Turn LED OFF|" onclick=\"location.href='/off\">";
s +="</html>\n";

client.flush();
client.print(s);
delay(1);
Serial.printIn("Client disconnected");
}
