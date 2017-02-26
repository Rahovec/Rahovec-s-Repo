#include "NAxisMotion.h"        
#include <Wire.h>

NAxisMotion mySensor;          
unsigned long lastStreamTime = 0;     
const int streamPeriod = 20;          

void setup() //This code is executed once
{    
  //Peripheral Initialization
  Serial.begin(115200);           
  I2C.begin();                    
  //Sensor Initialization
  mySensor.initSensor();          
  mySensor.setOperationMode(OPERATION_MODE_NDOF);
  mySensor.setUpdateMode(MANUAL);  
}

void loop()
{
  if ((millis() - lastStreamTime) >= streamPeriod)
  {
    lastStreamTime = millis();    
    mySensor.updateEuler();
    mySensor.updateLinearAccel();
    mySensor.updateMag();
    mySensor.updateGyro();
    Serial.print("Time: ");
    Serial.print(lastStreamTime);
    Serial.print("ms ");

    Serial.print(" H: ");
    Serial.print(mySensor.readEulerHeading());
    Serial.print("deg ");

    Serial.print(" R: ");
    Serial.print(mySensor.readEulerRoll()); 
    Serial.print("deg");

    Serial.print(" P: ");
    Serial.print(mySensor.readEulerPitch());
    Serial.print("deg ");
    
    Serial.print(" AccelX: ");
    Serial.print(mySensor.readLinearAccelX());
    
    Serial.print(" AccelY: ");
    Serial.print(mySensor.readLinearAccelY());

    Serial.print(" AccelZ: ");
    Serial.print(mySensor.readLinearAccelZ());

    Serial.print(" MagX: ");
    Serial.print(mySensor.readMagX());

    Serial.print(" MagY: ");
    Serial.print(mySensor.readMagY());

    Serial.print(" MagZ: ");
    Serial.print(mySensor.readMagZ());
  
    Serial.print(" GyroX: ");
    Serial.print(mySensor.readGyroX());

    Serial.print(" GyroY: ");
    Serial.print(mySensor.readGyroY());
   
    Serial.print(" GyroZ: ");
    Serial.print(mySensor.readGyroZ());
 
    Serial.println();
  }
}
