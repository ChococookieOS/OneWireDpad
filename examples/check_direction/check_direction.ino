#include <OneWireDpad.h>

//Configure Analog input to your pin
#define ANALOG_PIN A0

Dpad myDpad(ANALOG_PIN, 862, 521, 776, 681);

void setup() {
  Serial.begin(9600);

}

void loop() {
  Serial.print("Current direction: ");
  switch(myDpad.getButtonInput()){
    case Dpad::UP:
      Serial.println("UP");
      break;
    case Dpad::LEFT:
      Serial.println("LEFT");
      break;
    case Dpad::RIGHT:
      Serial.println("RIGHT");
      break;
    case Dpad::DOWN:
      Serial.println("DOWN");
      break;
    default :
      Serial.println("NONE");
  }
  delay(250);
}
