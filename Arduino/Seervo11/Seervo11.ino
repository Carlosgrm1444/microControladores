#include <Servo.h>

Servo motor1;

int PinServo = 2;
int PulsoMin = 500;
int PulsoMax = 2500;

void setup() {
  motor1.attach(PinServo, PulsoMin, PulsoMax);
}

void loop() {
  motor1.write(180);
  delay(1000);
  motor1.write(0);
  delay(1000);
}
