# ESP32 LoRa Monitoring Node

An ESP32-based embedded IoT project for wireless sensor data transmission using an SX1278 LoRa module.

## Features

- ESP32-based monitoring node
- SX1278 LoRa communication
- Wireless telemetry transmission
- Analog sensor interfacing
- SPI communication
- Serial Monitor debugging
- Structured sensor data packets

## Hardware

- ESP32
- SX1278 LoRa Module
- Analog Sensor / Potentiometer
- Jumper wires

## Technologies

- Embedded C/C++
- ESP32
- LoRa
- SX1278
- SPI
- GPIO
- Sensor Interfacing

## LoRa Pin Configuration

| SX1278 | ESP32 |
|---|---|
| SCK | GPIO 18 |
| MISO | GPIO 19 |
| MOSI | GPIO 23 |
| NSS/CS | GPIO 5 |
| RESET | GPIO 14 |
| DIO0 | GPIO 26 |

## Serial Monitor Output

LoRa monitoring node started

Packet sent: NODE=01,TEMP=27.5,HUM=60.2,ADC=1840,SEQ=0

Packet sent: NODE=01,TEMP=27.6,HUM=60.3,ADC=1852,SEQ=1

Packet sent: NODE=01,TEMP=27.4,HUM=59.9,ADC=1817,SEQ=2

Packet sent: NODE=01,TEMP=27.7,HUM=60.5,ADC=1875,SEQ=3

Data Format

NODE=01,TEMP=27.5,HUM=60.2,ADC=1840,SEQ=0

Where:

NODE → Node ID

TEMP → Temperature value

HUM → Humidity value

ADC → Analog sensor reading

SEQ → Packet sequence number
