#include <SoftwareSerial.h>
#define ARDUINO_RX 4//should connect to TX of the Serial MP3 Player module
#define ARDUINO_TX 3//connect to RX of the module
SoftwareSerial myMP3(ARDUINO_RX, ARDUINO_TX);

byte sendBuffer[10]; //buffer that will be used to store commands before sending

void setupSound() {
    myMP3.begin(9600);
}

// Play a song from a folder
void playFolderFile(byte folder, byte file) {

  sendBuffer[2] = 0x06; // size
  sendBuffer[3] = 0x0F; // cmd
  sendBuffer[4] = 0x00; // response
  sendBuffer[5] = folder; // data high
  sendBuffer[6] = file; // data low

  sendUARTCommand("playFolderFile");
}

// Play the default or last song
void play() {
  sendBuffer[2] = 0x06;
  sendBuffer[3] = 0x0D;
  sendBuffer[4] = 0x00;
  sendBuffer[5] = 0x00;
  sendBuffer[6] = 0x00;
  sendUARTCommand("play");
}

void stop() {

  sendBuffer[2] = 0x06; // size
  sendBuffer[3] = 0x16; // cmd
  sendBuffer[4] = 0x00; // response
  sendBuffer[5] = 0x00; // data high
  sendBuffer[6] = 0x00; // data low

  sendUARTCommand("stop");
}




// Add the start byte, version, calculate the checksum, add the checksum and the stop byte to the buffer and send it
void sendUARTCommand(String dbg) {

  sendBuffer[0] = 0x7E; // Start byte
  sendBuffer[1] = 0xFF; // Version

  int size = sendBuffer[2];

  // Calculate the ckecksum
  int16_t checksum = 0;
  for (int q = 0; q < size; q++) {
    checksum -= sendBuffer[q + 1];
  }

  // Write the checksum in the buffer
  sendBuffer[size + 1] = checksum >> 8; // sum high
  sendBuffer[size + 2] = checksum; // sum low

  // add the stop byte
  sendBuffer[size + 3] = 0xEF;


  // Send the buffer to the module
  for (int q = 0; q < sendBuffer[2] + 4; q++) {
    myMP3.write(sendBuffer[q]);
  }

  // Dumpt the buffer to serial port
  Serial.print("Commands Sent: ");
  for (int q = 0; q < sendBuffer[2] + 4; q++) {
    Serial.print(sendBuffer[q], HEX);
    Serial.print(" ");
  }
  Serial.print(dbg);
  Serial.println();

  delay(25);//stops odd commands being missed
}
