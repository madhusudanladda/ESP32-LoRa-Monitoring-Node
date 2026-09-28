#include <SPI.h>
#include <LoRa.h>

#define LORA_SCK 18
#define LORA_MISO 19
#define LORA_MOSI 23
#define LORA_SS 5
#define LORA_RST 14
#define LORA_DIO0 26

#define SENSOR_PIN 34

const long LORA_FREQUENCY = 433E6;

unsigned long packetCounter = 0;

void setup() {
  Serial.begin(115200);
  delay(1000);

  pinMode(SENSOR_PIN, INPUT);

  SPI.begin(LORA_SCK, LORA_MISO, LORA_MOSI, LORA_SS);
  LoRa.setPins(LORA_SS, LORA_RST, LORA_DIO0);

  if (!LoRa.begin(LORA_FREQUENCY)) {
    Serial.println("LoRa initialization failed");
    while (true) delay(1000);
  }

  Serial.println("LoRa monitoring node started");
}

void loop() {
  int adc = analogRead(SENSOR_PIN);

  float demoTemperature = 25.0f + (adc / 4095.0f) * 5.0f;
  float demoHumidity = 50.0f + (adc / 4095.0f) * 20.0f;

  String packet = "NODE=01";
  packet += ",TEMP=" + String(demoTemperature, 1);
  packet += ",HUM=" + String(demoHumidity, 1);
  packet += ",ADC=" + String(adc);
  packet += ",SEQ=" + String(packetCounter++);

  LoRa.beginPacket();
  LoRa.print(packet);
  LoRa.endPacket();

  Serial.print("Packet sent: ");
  Serial.println(packet);

  delay(5000);
}
