#include "NAxisMotion.h"        
#include <Wire.h>

NAxisMotion mySensor;          
unsigned long lastStreamTime = 0;     
const int streamPeriod = 20;  

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
  // read from port 1, send to port 0:
  if (Serial1.available()) {
    int inByte = Serial1.read();
    if(inByte == '1'){
        mySensor.updateEuler();
        //Serial1.write("lmao");
        Serial1.print(mySensor.readEulerHeading());
      }
  }
}
