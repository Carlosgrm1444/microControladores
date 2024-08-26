#include <Servo.h>

Servo motor1;

int PinServo = 2;
int PulsoMin = 1000;
int PulsoMax = 2000;
int ValorPot;
int Angulo;
int Pot = 0;

void setup() {
  motor1.attach(PinServo, PulsoMin, PulsoMax);
}

void loop() {
  ValorPot = analogRead(Pot);
  Angulo = map(ValorPot, 0, 1023, 0, 180);
  motor1.write(Angulo);
  delay(20);
}
