#include <Arduino.h>
#include <MIDIUSB.h>

byte pinInicial = 2;
const byte cantidadY = 6;
const byte cantidadX = cantidadY;
byte buttonPinY[cantidadY];
byte buttonPinX[cantidadX];
byte buttonState[cantidadY][cantidadX];

byte defaultChannel = 1;
byte defaultPitch = 59;
//byte defaultVelocity = 64;
byte defaultVelocity = 127;

void noteOn(byte channel, byte pitch, byte velocity);
void noteOff(byte channel, byte pitch, byte velocity);

void setup()
{
  Serial.begin(9600);

  for (byte i = 0; i < cantidadY; i++)
  {
    buttonPinY[i] = pinInicial + i;
    pinMode(buttonPinY[i], OUTPUT);
  }

  for (byte i = 0; i < cantidadX; i++)
  {
    buttonPinX[i] = pinInicial + i + cantidadY;
    pinMode(buttonPinX[i], INPUT);
  }
  for (byte y = 0; y < cantidadY; y++)
  {
    for (byte x = 0; x < cantidadX; x++)
    {
      buttonState[y][x] = digitalRead(buttonPinX[x]) && digitalRead(buttonPinY[y]);
    }
  }
}

void loop()
{
  for (byte y = 0; y < cantidadY; y++)
  {
    digitalWrite(y + pinInicial, HIGH);
    for (byte x = 0; x < cantidadX; x++)
    {
      // byte currentState = digitalRead(buttonPinX[x + pinInicial + cantidadY]) && digitalRead(y + pinInicial);
      byte currentState = digitalRead(buttonPinX[x]) && digitalRead(buttonPinY[y]);
      //delay(10);
      if (currentState != buttonState[y][x])
      {
        if (currentState == HIGH)
        {
          noteOn(defaultChannel, defaultPitch + (y * cantidadY) + x, defaultVelocity);
          MidiUSB.flush();
          Serial.print("Pulso ");
          Serial.print(y);
          Serial.print(x);
          Serial.println(" encendido");
          //delay(1);
        }
        else
        {
          noteOff(defaultChannel, defaultPitch + (y * cantidadY) + x, defaultVelocity);
          MidiUSB.flush();
          Serial.print("Pulso ");
          Serial.print(y);
          Serial.print(x);
          Serial.println(" apagado");
          //delay(1);
        }
        buttonState[y][x] = currentState;
      }
    }
    digitalWrite(y + pinInicial, LOW);
  }
}

// ! channel 0 - 15
// ! notas La(0)21 - Do(8)108
// ! velocity 0 - 127
void noteOn(byte channel, byte pitch, byte velocity)
{
  midiEventPacket_t noteOn = {0x09, static_cast<uint8_t>(0x90 | channel), pitch, velocity};
  MidiUSB.sendMIDI(noteOn);
}

void noteOff(byte channel, byte pitch, byte velocity)
{
  midiEventPacket_t noteOff = {0x08, static_cast<uint8_t>(0x80 | channel), pitch, velocity};
  MidiUSB.sendMIDI(noteOff);
}
