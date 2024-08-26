int UNO = 9;
int DOS = 10;
int TRES = 11;

void setup() {
  pinMode(UNO, OUTPUT);
  pinMode(DOS, OUTPUT);
  pinMode(TRES, OUTPUT);
}

void loop() {
  digitalWrite(TRES, LOW);
  digitalWrite(UNO, HIGH);
  delay(500);
  digitalWrite(UNO, LOW);
  digitalWrite(DOS, HIGH);
  delay(500);
  digitalWrite(DOS, LOW);
  digitalWrite(TRES, HIGH);
  delay(500);
}
