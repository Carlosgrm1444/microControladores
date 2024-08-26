void setup() {
  pinMode(2, INPUT);
  pinMode(3, OUTPUT);
}

void loop() {
  if(digitalRead(2) == HIGH){
    digitalWrite(3, HIGH);
    delay(1000);
    digitalWrite(3, LOW);
    delay(100);
  }
  else{
    digitalWrite(3, LOW);
  }
}
