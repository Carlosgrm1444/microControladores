
int Led1 = 9;
int Led2 = 10;
int Led3 = 11;
int Brillo1;
int Brillo2;
int Brillo3;
int Pot1 = 0;
int Pot2 = 1;
int Pot3 = 2;

void setup() {
  pinMode(Led1, OUTPUT);
  pinMode(Led2, OUTPUT);
  pinMode(Led3, OUTPUT);
}

void loop() {
  Brillo1 =analogRead(Pot1) / 4;
  analogWrite(Led1, Brillo1);
  Brillo2 =analogRead(Pot2) / 4;
  analogWrite(Led2, Brillo2);
  Brillo3 =analogRead(Pot3) / 4;
  analogWrite(Led3, Brillo3);
}
