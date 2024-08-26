#include <Arduino.h>
#include <SoftwareSerial.h>

SoftwareSerial miBT(14, 15);
char dato = 0;

byte enb = 3;
byte in4 = 2;
byte in3 = 4;
byte in2 = 6;
byte in1 = 7;
byte ena = 5;

int vel = 255;

void adelante();
void atras();
void noVertical();
void derecha();
void izquierda();
void noLateral();

void setup()
{
  for (byte i = 2; i < 12; i++)
  {
    pinMode(i, OUTPUT);
  }

  Serial.begin(9600);
  Serial.println("Listo");
  miBT.begin(38400);

  vel = 100;
}

void loop()
{
  
  //digitalWrite(panelFrontal, HIGH);
  //digitalWrite(8, HIGH);
  if (miBT.available())
  {
    Serial.write(miBT.read());
    dato = miBT.read();
  }
  switch (dato)
  {
  case 'S':
    noVertical();
    noLateral();
    break;
  case 'F':
    adelante();
    noLateral();
    break;
  case 'B':
    atras();
    noLateral();
    break;
  case 'L':
    izquierda();
    noVertical();
    break;
  case 'R':
    derecha();
    noVertical();
    break;
  case 'G':
    adelante();
    izquierda();
    break;
  case 'I':
    adelante();
    derecha();
    break;
  case 'H':
    atras();
    izquierda();
    break;
  case 'J':
    atras();
    derecha();
    break;
    case 'X':
    vel = 255;
    break;
    case 'x':
    vel = 100;
    break;
  }

  if (Serial.available())
  {
    miBT.write(Serial.read());
  }
}

void adelante()
{
  analogWrite(ena, vel);
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
}
void atras()
{
  analogWrite(ena, vel);
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
}
void noVertical()
{
  digitalWrite(ena, LOW);
}

void derecha()
{
  digitalWrite(enb, HIGH);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
}
void izquierda()
{
  digitalWrite(enb, HIGH);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
}
void noLateral()
{
  digitalWrite(enb, LOW);
}


// #include <Arduino.h>
/*
byte enb = 2;
byte in4 = 3;
byte in3 = 4;
byte in2 = 5;
byte in1 = 6;
byte ena = 7;
byte led = 8;
byte buz = 9;

byte push1 = 10;
byte push2 = 11;
byte push3 = 2;
byte push4 = 1;

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

*/



// #include <Arduino.h>
// #include <SoftwareSerial.h>

// SoftwareSerial miBT(14, 15);
// char dato = 0;

// int enb = 2;
// int in4 = 3;
// int in3 = 4;
// int in2 = 5;
// int in1 = 6;
// int ena = 7;
// void adelante();
// void atras();
// void noVertical();
// void derecha();
// void izquierda();
// void noLateral();

// void setup()
// {
//   for (int i = 2; i < 7; i++)
//   {
//     pinMode(i, OUTPUT);
//   }

//   Serial.begin(9600);
//   Serial.println("Listo");
//   miBT.begin(38400);
// }

// void loop()
// {
//   if (miBT.available())
//   {
//     Serial.write(miBT.read());
//     dato = miBT.read();
//     switch (dato)
//     {
//     case 'S':
//       noVertical();
//       noLateral();
//       break;
//     case 'F':
//       adelante();
//       noLateral();
//       break;
//     case 'B':
//       atras();
//       noLateral();
//       break;
//     case 'L':
//       izquierda();
//       noVertical();
//       break;
//     case 'R':
//       derecha();
//       noVertical();
//       break;
//     case 'G':
//       adelante();
//       izquierda();
//       break;
//     case 'I':
//       adelante();
//       derecha();
//       break;
//     case 'H':
//       atras();
//       izquierda();
//       break;
//     case 'J':
//       atras();
//       derecha();
//       break;
//     default:
//       break;
//     }
//   }
//   if (Serial.available())
//   {
//     miBT.write(Serial.read());
//   }
// }

// void adelante()
// {
//   digitalWrite(ena, HIGH);
//   digitalWrite(in1, HIGH);
//   digitalWrite(in2, LOW);
// }
// void atras()
// {
//   digitalWrite(ena, HIGH);
//   digitalWrite(in1, LOW);
//   digitalWrite(in2, HIGH);
// }
// void noVertical()
// {
//   digitalWrite(ena, LOW);
// }

// void derecha()
// {
//   digitalWrite(enb, HIGH);
//   digitalWrite(in3, HIGH);
//   digitalWrite(in4, LOW);
// }
// void izquierda()
// {
//   digitalWrite(enb, HIGH);
//   digitalWrite(in3, LOW);
//   digitalWrite(in4, HIGH);
// }
// void noLateral()
// {
//   digitalWrite(enb, LOW);
// }

// // #include <Arduino.h>
// /*
// int enb = 2;
// int in4 = 3;
// int in3 = 4;
// int in2 = 5;
// int in1 = 6;
// int ena = 7;
// int led = 8;
// int buz = 9;

// int push1 = 10;
// int push2 = 11;
// int push3 = 2;
// int push4 = 1;

// void luz();
// void claxon();
// void noClaxon();
// void adelante();
// void noAdelante();
// void atras();
// void derecha();
// void noDerecha();
// void izquierda();

// void setup()
// {
//   pinMode(enb, OUTPUT);
//   pinMode(in4, OUTPUT);
//   pinMode(in3, OUTPUT);
//   pinMode(in2, OUTPUT);
//   pinMode(in1, OUTPUT);
//   pinMode(ena, OUTPUT);
//   pinMode(led, OUTPUT);

//   pinMode(push1, INPUT);
//   pinMode(push2, INPUT);
//   pinMode(push3, INPUT);
//   pinMode(push4, INPUT);
// }

// void loop()
// {
//   if (digitalRead(push1) == HIGH)
//   {
//     adelante();
//   }
//   else if (digitalRead(push2) == HIGH)
//   {
//     atras();
//   }
//   else
//   {
//     noAdelante();
//   }

//   if (digitalRead(push3) == HIGH)
//   {
//     izquierda();
//   }
//   else if (digitalRead(push4) == HIGH)
//   {
//     derecha();
//   }
//   else
//   {
//     noDerecha();
//   }
//   luz();
// }

// void luz()
// {
//   digitalWrite(led, HIGH);
// }

// void claxon()
// {
//   analogWrite(buz, 150);
// }

// void noClaxon()
// {
//   analogWrite(buz, LOW);
// }

// void adelante()
// {
//   digitalWrite(ena, HIGH);
//   digitalWrite(in1, HIGH);
//   digitalWrite(in2, LOW);
// }
// void noAdelante()
// {
//   digitalWrite(ena, LOW);
// }
// void atras()
// {
//   digitalWrite(ena, HIGH);
//   digitalWrite(in1, LOW);
//   digitalWrite(in2, HIGH);
// }

// void derecha()
// {
//   digitalWrite(enb, HIGH);
//   digitalWrite(in3, HIGH);
//   digitalWrite(in4, LOW);
// }
// void noDerecha()
// {
//   digitalWrite(enb, LOW);
// }
// void izquierda()
// {
//   digitalWrite(enb, HIGH);
//   digitalWrite(in3, LOW);
//   digitalWrite(in4, HIGH);
// }

// */