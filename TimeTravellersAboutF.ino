#include <Adafruit_MPU6050.h>
#include <Adafruit_Sensor.h>
#include <Wire.h>

Adafruit_MPU6050 mpu;

#include <SoftwareSerial.h>
#define ARDUINO_RX 4//should connect to TX of the Serial MP3 Player module
#define ARDUINO_TX 3//connect to RX of the module
SoftwareSerial myMP3(ARDUINO_RX, ARDUINO_TX);

byte sendBuffer[10]; //buffer that will be used to store commands before sending

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println("UARTSerialV2");
  myMP3.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  playFolderFile(1, 10);
  delay(1000);

  playFolderFile(1, 11);
  delay(1000);

  playFolderFile(1, 12);
  delay(1000);

  playFolderFile(1, 13);
  delay(1000);

  playFolderFile(1, 14);
  delay(4000);

  playFolderFile(1, 1);
  delay(145000);

  playFolderFile(1, 2);
  delay(41000);

  playFolderFile(1, 3);
  delay(44000);

  playFolderFile(1, 4);
  delay(31000);

  playFolderFile(1, 5);
  delay(58000);

  playFolderFile(1, 6);
  delay(44000);

  playFolderFile(1, 9);
  delay(44000);

  playFolderFile(1, 8);
  delay(44000);
}

