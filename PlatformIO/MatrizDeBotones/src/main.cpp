#include <Arduino.h>


int pinInicial = 2;
const int cantidadY = 2;
const int cantidadX = cantidadY;
int buttonPinY[cantidadY];
int buttonPinX[cantidadX];
int buttonState[cantidadY][cantidadX];

void setup()
{
  Serial.begin(9600);

  for (int i = 0; i < cantidadY; i++)
  {
    buttonPinY[i] = pinInicial + i;
    pinMode(buttonPinY[i], OUTPUT);
  }

  for (int i = 0; i < cantidadX; i++)
  {
    buttonPinX[i] = pinInicial + i + cantidadY;
    pinMode(buttonPinX[i], INPUT);
  }
  for (int y = 0; y < cantidadY; y++)
  {
    for (int x = 0; x < cantidadX; x++)
    {
      buttonState[y][x] = digitalRead(buttonPinX[x]) && digitalRead(buttonPinY[y]);
    }
  }
}

void loop()
{
  for (int y = 0; y < cantidadY; y++)
  {
    digitalWrite(y + pinInicial, HIGH);
    for (int x = 0; x < cantidadX; x++)
    {
      //int currentState = digitalRead(buttonPinX[x + pinInicial + cantidadY]) && digitalRead(y + pinInicial);
      int currentState = digitalRead(buttonPinX[x]) && digitalRead(buttonPinY[y]);
      
      if (currentState != buttonState[y][x])
      {
        if (currentState == HIGH)
        {
          Serial.print("Pulso ");
          Serial.print(y);
          Serial.print(x);
          Serial.println(" encendido");
        }
        else
        {
          Serial.print("Pulso ");
          Serial.print(y);
          Serial.print(x);
          Serial.println(" apagado");
        }
		buttonState[y][x] = currentState;
      }
    }
    digitalWrite(y+ pinInicial, LOW);
  }
}
/*int pinInicial = 2;
const int cantidadY = 2;
const int cantidadX = cantidadY;
int buttonPinY[cantidadY];
int buttonPinX[cantidadX];
int buttonState[cantidadY][cantidadX];

void setup()
{
  Serial.begin(9600);

  for (int i = 0; i < cantidadY; i++)
  {
    buttonPinY[i] = pinInicial + i;
    pinMode(buttonPinY[i], OUTPUT);
  }

  for (int i = 0; i < cantidadX; i++)
  {
    buttonPinX[i] = pinInicial + i + cantidadY;
    pinMode(buttonPinX[i], INPUT_PULLUP);
  }
  for (int y = 0; y < cantidadY; y++)
  {
    for (int x = 0; x < cantidadX; x++)
    {
      buttonState[y][x] = digitalRead(buttonPinX[x]) && digitalRead(buttonPinY[y]);
    }
  }
}

void loop()
{
  for (int y = 0; y < cantidadY; y++)
  {
    digitalWrite(y + pinInicial, HIGH);
    delay(500);
    for (int x = 0; x < cantidadX; x++)
    {
      int currentState = digitalRead(buttonPinX[x]) && digitalRead(buttonPinY[y]);

      if (currentState != buttonState[y][x])
      {
        if (currentState == HIGH)
        {
          Serial.print("Pulso ");
          Serial.print(y);
          Serial.print(x);
          Serial.println(" encendido");
        }
        else
        {
          Serial.print("Pulso ");
          Serial.print(y);
          Serial.print(x);
          Serial.println(" apagado");
        }
        buttonState[y][x] = currentState;
      }
    }
    digitalWrite(y + pinInicial, LOW);
  }
}*/