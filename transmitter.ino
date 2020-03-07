#include <iarduino_RF433_Transmitter.h>

#define DEBUG true
#define LEFT_STICK_X 2
#define LEFT_STICK_Y 1
#define RIGHT_STICK_X 3

iarduino_RF433_Transmitter radio(2);
byte data[3] = {0, 0, 0};

void setup() {
  Serial.begin(9600);
  radio.begin();
  radio.setDataRate(i433_1KBPS);
  radio.openWritingPipe(1);
}

void loop() {
  data[0] = map(analogRead(LEFT_STICK_X), 0, 1024, 0, 256);
  data[1] = map(analogRead(LEFT_STICK_Y), 0, 1024, 0, 256);
  data[2] = map(analogRead(RIGHT_STICK_X), 0, 1024, 0, 256);
#if DEBUG
  Serial.print("Sending: ");
  Serial.print(data[0]);
  Serial.print(", ");
  Serial.print(data[1]);
  Serial.print(", ");
  Serial.print(data[2]);
  Serial.println();
#endif
  radio.write(&data, sizeof(data));
  delay(10);
}