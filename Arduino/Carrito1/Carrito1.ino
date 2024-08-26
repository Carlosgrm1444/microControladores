#include <Arduino.h>

int enb = 2;
int in4 = 3;
int in3 = 4;
int in2 = 5;
int in1 = 6;
int ena = 7;
int led = 8;
int buz = 9;

int push1 = 10;
int push2 = 11;
int push3 = 2;
int push4 = 1;

void luz();
void claxon();
void noClaxon();
void adelante();
void noAdelante();
void atras();
void derecha();
void noDerecha();
void izquierda();

void setup()
{
  pinMode(enb, OUTPUT);
  pinMode(in4, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(ena, OUTPUT);
  pinMode(led, OUTPUT);

  pinMode(push1, INPUT);
  pinMode(push2, INPUT);
  pinMode(push3, INPUT);
  pinMode(push4, INPUT);
}

void loop()
{
  if (digitalRead(push1) == HIGH)
  {
    adelante();
  }
  else if (digitalRead(push2) == HIGH)
  {
    atras();
  }
  else
  {
    noAdelante();
  }

  if (digitalRead(push3) == HIGH)
  {
    izquierda();
  }
  else if (digitalRead(push4) == HIGH)
  {
    derecha();
  }
  else
  {
    noDerecha();
  }
  luz();
}

void luz()
{
  digitalWrite(led, HIGH);
}

void claxon()
{
  analogWrite(buz, 150);
}

void noClaxon()
{
  analogWrite(buz, LOW);
}

void adelante()
{
  digitalWrite(ena, HIGH);
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
}
void noAdelante()
{
  digitalWrite(ena, LOW);
}
void atras()
{
  digitalWrite(ena, HIGH);
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
}

void derecha()
{
  digitalWrite(enb, HIGH);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
}
void noDerecha()
{
  digitalWrite(enb, LOW);
}
void izquierda()
{
  digitalWrite(enb, HIGH);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
}

