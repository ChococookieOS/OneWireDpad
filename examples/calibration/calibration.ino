#include <OneWireDpad.h>

//Configure Analog input to your pin
#define ANALOG_PIN A0


void setup() {
  pinMode(ANALOG_PIN, INPUT);
  Serial.begin(9600);
  Serial.println("Analog calibration of OneWireDpad");
  Serial.println("*********************************");
  Serial.println("This process has to be done only once per voltage source");
  Serial.println("If you get inconsisten results in the future you may need to");
  Serial.println("recalibrate again.");
  Serial.println("Prepare yourself to press the buttons");
  Serial.println("Press Enter to start");
  while(Serial.read() == -1){}
  
  Serial.println("Press and HOLD the UPWARDS button (the side with the cable)");
  delay(4000);
  int uVal = getAverageInput();
  Serial.println("Release");
  delay(1000);
  
  Serial.println("Press and HOLD the LEFT button");
  delay(4000);
  int lVal = getAverageInput();
  Serial.println("Release");
  delay(1000);

  Serial.println("Press and HOLD the RIGHT button");
  delay(4000);
  int rVal = getAverageInput();
  Serial.println("Release");
  delay(1000);

  Serial.println("Press and HOLD the DOWN button");
  delay(4000);
  int dVal = getAverageInput();
  Serial.println("Release");
  delay(1000);

  Serial.println("Use this Dpad object in your project sketch:");
  Serial.print("Dpad myDpad(");
  Serial.print(String(ANALOG_PIN));
  Serial.print(", ");
  Serial.print(uVal);
  Serial.print(", ");
  Serial.print(lVal);
  Serial.print(", ");
  Serial.print(rVal);
  Serial.print(", ");
  Serial.print(dVal);
  Serial.println(");");
  
  
}


int getAverageInput(){
  int tmp = 0;
  for(int i = 0; i < 20; i++){
    tmp += analogRead(ANALOG_PIN);
    delay(50);
  }
  tmp /= 20;
  return tmp;
  
}

void loop() {
 
}
