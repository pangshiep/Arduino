#include <SoftwareSerial.h>

SoftwareSerial LoRaUART(10, 11); // to TX, to RX
const int variable = A2;
const int led = 9;

void setup() {
  Serial.begin(9600);
  while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB port only
  }
  Serial.println("Serial Ready");

  LoRaUART.begin(9600);
  LoRaUART.println("AT");

  while (!LoRaUART.available()) {
    ;
  }
  Serial.println("LoRa Serial Ready");
}

void loop() {
  int sensorValue = analogRead(variable);
  String sensorData;
  sensorData = String(sensorValue,4);
  Serial.println(sensorData);
  LoRaUART.println("AT+DTX=" + String(sensorData.length()) + ",\"" + sensorData + "\"");
  //LoRaUART.println("AT+DTX=6,\"abcdef\"");
  //LoRaUART.println("AT+DTX=10,1234567890");
  //Serial.println("ATDTX 1234567890");
  //LoRaUART.println("AT+DTX=16,1234567890abcdef");
  
  delay(3*1000);
}
