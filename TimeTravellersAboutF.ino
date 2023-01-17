
// Need to install "Vector Datatype" library by RCmags

#include <vector_type.h>


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println("UARTSerialV2");
  
  setupSound();
  
  setupAccelerometer();

}

void loop() {
  // put your main code here, to run repeatedly:
  playFolderFile(1, 10);
  // delay(1000);

  waitForMove();

  playFolderFile(1, 11);
  delay(1000);

  playFolderFile(1, 12);
  delay(1000);

  playFolderFile(1, 13);
  delay(1000);

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

