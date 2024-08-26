#include <Arduino.h>
#include <BleGamepad.h>

BleGamepad bleGamepad;

const int joystickPinX = 2;  // Pin del eje X del joystick izquierdo
const int joystickPinY = 4;  // Pin del eje Y del joystick izquierdo
const int buttonAPin = 15;   // Pin del botón A

void setup() {
  Serial.begin(115200);
  Serial.println("Starting BLE work!");
  bleGamepad.begin();
}

void loop() {
  if (bleGamepad.isConnected()) {
    // Lectura de los valores de los ejes del joystick
    int value1 = map(analogRead(joystickPinX), 0, 4095, 0, 32737);
    int value2 = map(analogRead(joystickPinY), 0, 4095, 32737, 0);
    bleGamepad.setLeftThumb(value1, value2);

    // Lectura del estado del botón A
    int buttonStateA = digitalRead(buttonAPin);

    // Si el botón A está presionado, lo marcamos como presionado en el gamepad
    if (buttonStateA == HIGH) {
      bleGamepad.release(BUTTON_1);
    } else {
      bleGamepad.press(BUTTON_1);
    }

    // Retardo pequeño para evitar saturar la conexión BLE
    bleGamepad.sendReport();
    delay(1);
  }
}
