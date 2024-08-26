#include <SoftwareSerial.h>

SoftwareSerial miBT(6,7);

const int LED = 1;
const int BTPWR = 0;

void setup(){
  Serial.begin(9600);
  miBT.begin(9600);
}

void loop() {
  if (miBT.available())
    Serial.write(miBT.read());

  if (Serial.available())
  miBT.write(Serial.read());
}
