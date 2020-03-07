#include <iarduino_RF433_Transmitter.h>

iarduino_RF433_Transmitter radio(2);
int data[2];

void setup() {
  radio.begin();
  radio.setDataRate(i433_1KBPS);
  radio.openWritingPipe(5);
}

void loop() {
  data[0] = analogRead(1);
  data[1] = analogRead(2);
  radio.write(&data, sizeof(data));
  delay(10);
}
