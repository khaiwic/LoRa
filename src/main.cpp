#include <Arduino.h>
#include <SPI.h>
#include <LoRa.h>

#define SCK_PIN 12 // Chân xung nhịp SPI Clock
#define MISO_PIN 13 // Chân Master Input Slave Output
#define MOSI_PIN 11 //Chân Master Output slave input
#define NSS_CS_PIN 10 // Chân chip Select(NSS)
#define RST_PIN 9 //Chân reset cứng
#define DID0_PIN 14 // Chân ngắt (Bắt buộc cho truyền/ nhận)

//Cấu hình tần số hoạt động của SX1278 = 433MHz
#define BAND 433E6

unsigned int packetCounter = 0;

void setup(){
  //Start Serial
  Serial.begin(115200);
  while(!Serial) {
    delay(10); // Đợi cổng Serial trên ESP32-S3 khởi tạo xong
  }
  Serial.println("---START---");

  //LoRa(sx1278) config
  SPI.begin(SCK_PIN, MISO_PIN, MOSI_PIN, NSS_CS_PIN);
  LoRa.setPins(NSS_CS_PIN, RST_PIN, DID0_PIN);

  if(!LoRa.begin(BAND)){
    Serial.println("Start false");
    while(1);
  }
  Serial.println("Start Successfully");

  //
  LoRa.setTxPower(20); // 20dBm
  Serial.println("Config successfully: Max(20dBm)");

  //
  LoRa.setSpreadingFactor(12);
  Serial.println("Config successfully Spreading Factor: SF12(Max)");

  //
  LoRa.setSignalBandwidth(125E3); // 125MHz
  Serial.println("Config successfully BrandWidth: 125 kHz");

  //
  LoRa.setCodingRate4(5);
  Serial.println("Config coding Rate: 4/5");

  Serial.println(".........................................");
  Serial.println("Perfect!");
  delay(200);
}
void loop(){
  Serial.println("Dang bat dau dong goi va phat goi tin hieu so");
  Serial.println(packetCounter);
  
  LoRa.beginPacket();;
  
  //
  LoRa.print("ESP32-S3 NODE; Pkt:"); // ghi du lieu dang chuoi chuan IoT vao bo dem FIFO
  LoRa.print(packetCounter);

  LoRa.endPacket();

  Serial.println("Da gui xong goi tin ra khong gian");

  packetCounter++;
  
  delay(3000);
}