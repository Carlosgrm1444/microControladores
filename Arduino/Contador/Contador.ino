int e = 2 ;
int d = 3 ;
int c = 4 ;
int p = 5 ;
int b = 6 ;
int a = 7 ;
int f = 8 ;
int g = 9 ;

void setup()
{
  for(int i = 2; i < 10; i++)
  {
  	pinMode(i, OUTPUT);
  }
  delay(1000);
  allLow();
  delay(1000);
}

void loop()
{
  zero();
  delay(1000);
  allLow();
  one();
  delay(1000);
  allLow();
  two();
  delay(1000);
  allLow();
  three();
  delay(1000);
  allLow();
  four();
  delay(1000);
  allLow();
  five();
  delay(1000);
  allLow();
  six();
  delay(1000);
  allLow();
  seven();
  delay(1000);
  allLow();
  eight();
  delay(1000);
  allLow();
  nine();
  delay(1000);
  allLow();
}

void zero()
{
  digitalWrite(a, LOW);
  digitalWrite(b, LOW);
  digitalWrite(c, LOW);
  digitalWrite(d, LOW);
  digitalWrite(e, LOW);
  digitalWrite(f, LOW);

}
void one ()
{
  digitalWrite(b, LOW);
  digitalWrite(c, LOW);
}
void two()
{
  digitalWrite(a, LOW);
  digitalWrite(b, LOW);
  digitalWrite(g, LOW);
  digitalWrite(e, LOW);
  digitalWrite(d, LOW);
}
void three()
{
  digitalWrite(a, LOW);
  digitalWrite(b, LOW);
  digitalWrite(g, LOW);
  digitalWrite(c, LOW);
  digitalWrite(d, LOW);
}
void four()
{
  digitalWrite(f, LOW);
  digitalWrite(b, LOW);
  digitalWrite(g, LOW);
  digitalWrite(c, LOW);
}
void five()
{
  digitalWrite(a, LOW);
  digitalWrite(f, LOW);
  digitalWrite(g, LOW);
  digitalWrite(c, LOW);
  digitalWrite(d, LOW);   
}
void six()
{
  digitalWrite(a, LOW);
  digitalWrite(f, LOW);
  digitalWrite(g, LOW);
  digitalWrite(c, LOW);
  digitalWrite(d, LOW);   
  digitalWrite(e, LOW);
}
void seven()
{
  digitalWrite(a, LOW);
  digitalWrite(b, LOW);
  digitalWrite(c, LOW);
}
void eight()
{
  digitalWrite(g, LOW);
  digitalWrite(a, LOW);
  digitalWrite(b, LOW);
  digitalWrite(c, LOW);
  digitalWrite(d, LOW);
  digitalWrite(e, LOW);
  digitalWrite(f, LOW);
}
void nine()
{
  digitalWrite(g, LOW);
  digitalWrite(a, LOW);
  digitalWrite(b, LOW);
  digitalWrite(c, LOW);
  digitalWrite(d, LOW);
  digitalWrite(f, LOW);
}
void allLow()
{
  for(int i = 2; i < 10; i++)
  {
  	digitalWrite(i, HIGH);
  }
}