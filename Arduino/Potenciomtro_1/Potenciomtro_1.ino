int Led = 3;
int Brillo;

void setup() {
  pinMode(Led, OUTPUT);
}

void loop() {
  for(Brillo = 0;  Brillo < 256; Brillo++){
  analogWrite(Led, Brillo);
  delay(15);
  }
  for(Brillo = 255;  Brillo >= 0; Brillo--){
  analogWrite(Led, Brillo);
  delay(15);
  }
}
