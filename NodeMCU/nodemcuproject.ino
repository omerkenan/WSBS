#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>
#include "index.h"
#include <ArduinoJson.h>

/* Put your SSID & Password */
const char* ssid = "Omerkenan";    // Wifi adınız
const char* password = "stm32deneme";  // Wifi şifreniz

ESP8266WebServer server(80); // 80 portunu kullanarak bir web server nesnesi oluşturduk

float GeneralData = 1.0; // Başlangıç değeri, 1'den başlayacak
float pitch1 = 30.0;
float pitch2 = 60.0;
float roll1 = 15.0;
float roll2 = 45.0;
float FlexVoltage1 = 1.5;
float FlexVoltage2 = 1.6;
float FlexVoltage3 = 1.7;
float FlexVoltage4 = 1.8;
float FlexVoltage5 = 1.9;
float FlexAngle1 = 10.0;
float FlexAngle2 = 15.0;
float FlexAngle3 = 20.0;
float FlexAngle4 = 25.0;
float FlexAngle5 = 30.0;

String buttonState;

void setup() {
  Serial.begin(9600);
  delay(100);

  Serial.println("WiFi'ya bağlanılıyor");
  Serial.println(ssid);

  // Yerel ağınıza bağlanmanız için gerekli komut
  WiFi.begin(ssid, password);

  // Bağlantı gerçekleştiğini kontrol ediyoruz
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.print("."); // Bağlantı sağlanana kadar ekranda "." çıkmasını sağlıyoruz (Loading gibi)
  }
  Serial.println("");
  Serial.println("WiFi Bağlandı..!");
  Serial.print("IP Adresiniz: ");
  Serial.println(WiFi.localIP());

  server.on("/", handle_OnConnect);
  server.on("/pitchData", handle_PitchData);
  server.on("/buttondata", handle_ButtonState);
  server.on("/data", handle_data);
  server.onNotFound(handle_NotFound);

  server.begin();
  Serial.println("HTTP Sunucusu Başladı");
}

void loop() {
  // Analog değeri okuyoruz ve flexVol değişkenine atıyoruz

  //Buton yollama ya da yollamama durumu kontrolü ve yollama
  
      if (Serial.available() > 0) { // Check if there is data available to read
        String receivedData = Serial.readString(); // Read the data as a string
        GeneralData = receivedData.toFloat(); // Convert the received string to a float
        pitch1 = receivedData.substring(0,8).toFloat();
        pitch2 = receivedData.substring(21,29).toFloat();
        roll1 = receivedData.substring(42,50).toFloat();
        roll2 = receivedData.substring(63,71).toFloat();
        FlexVoltage1 = receivedData.substring(84,92).toFloat();
        FlexAngle1 = receivedData.substring(105,113).toFloat();
        FlexVoltage2 = receivedData.substring(126,134).toFloat();
        FlexAngle2 = receivedData.substring(147,155).toFloat();
        FlexVoltage3 = receivedData.substring(168,176).toFloat();
        FlexAngle3 = receivedData.substring(189,197).toFloat();
        FlexVoltage4 = receivedData.substring(210,218).toFloat();
        FlexAngle4 = receivedData.substring(231,239).toFloat();
        FlexVoltage5 = receivedData.substring(252,260).toFloat();
        FlexAngle5 = receivedData.substring(273,281).toFloat();
        //Serial.print("Received Data: "); // Print the received data
        //Serial.println(receivedData); // Print the received string
  

      }

  server.handleClient();
}
void handle_data(){
  StaticJsonDocument<256> jsonDoc;
  const unsigned long timestamp = millis();
  // JSON objesine verileri ekliyoruz
  jsonDoc["pitch1"] = pitch1;
  jsonDoc["pitch2"] = pitch2;
  jsonDoc["roll1"] = roll1;
  jsonDoc["roll2"] = roll2;
  jsonDoc["flexVoltage1"] = FlexVoltage1;
  jsonDoc["flexAngle1"] = FlexAngle1;
  jsonDoc["flexVoltage2"] = FlexVoltage2;
  jsonDoc["flexAngle2"] = FlexAngle2;
  jsonDoc["flexVoltage3"] = FlexVoltage3;
  jsonDoc["flexAngle3"] = FlexAngle3;
  jsonDoc["flexVoltage4"] = FlexVoltage4;
  jsonDoc["flexAngle4"] = FlexAngle4;
  jsonDoc["flexVoltage5"] = FlexVoltage5;
  jsonDoc["flexAngle5"] = FlexAngle5;
  jsonDoc["timestamp"] = timestamp;
  // Diğer verileri de eklemelisiniz

  // JSON verisini bir String'e çeviriyoruz
  String jsonData;
  serializeJson(jsonDoc, jsonData);

  // JSON verisini gönderiyoruz
  server.send(200, "application/json", jsonData);
}
void handle_OnConnect() {
  String s = webpage;
  server.send(200, "text/html", s);
}

void handle_PitchData() {
  String pitchData = String(pitch1, 2) + " " + String(pitch2, 2) + " " + String(roll1, 2) + " " + String(roll2, 2) + " " + String(FlexVoltage1, 2) + " " + String(FlexAngle1, 2) + " " + String(FlexVoltage2, 2) + " " + String(FlexAngle2, 2) + " " + String(FlexVoltage3, 2) + " " + String(FlexAngle3, 2) + " " + String(FlexVoltage4, 2) + " " + String(FlexAngle4, 2) + " " + String(FlexVoltage5, 2) + " " + String(FlexAngle5, 2); // Combine the data
  server.send(200, "text/plain", pitchData);
}

void handle_ButtonState(){
  buttonState = server.arg("plain"); // Get the value sent in the "data" parameter of the request
  if(buttonState == "Kalibrasyon"){
    buttonState = " ";
    uint8_t start = 6;
    Serial.write(start);
  }
  //Serial.println("Data received from website: " + buttonState);
}

void handle_NotFound() {
  server.send(404, "text/plain", "Not found");
}
