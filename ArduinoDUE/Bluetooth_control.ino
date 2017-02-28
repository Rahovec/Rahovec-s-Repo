#include "NAxisMotion.h"        
#include <Wire.h>

NAxisMotion mySensor;

void setup() {
  // initialize both serial ports:
  Serial.begin(9600);
  Serial1.begin(9600);
  //Peripheral Initialization
  I2C.begin();
  //Sensor Initialization
  mySensor.initSensor();
  mySensor.setOperationMode(OPERATION_MODE_NDOF);
  mySensor.setUpdateMode(MANUAL);
}

void loop() {
  
  if (Serial1.available()) {
    int inByte = Serial1.read();
    if(inByte == '1'){
        mySensor.updateEuler();
        //Serial1.write("lmao");
        Serial1.print(mySensor.readEulerHeading());
      }
  }
}
