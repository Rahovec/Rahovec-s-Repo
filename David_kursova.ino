  int sensorPin = A0; // select the input pin for the potentiometer
  int sensorValue = 0; // variable to store the value coming from the sensor
  int ledPin = 13; // select the pin for the LED
  int PplCounter = 0;
void setup (){
  pinMode (ledPin, OUTPUT);
  Serial.begin (9600);
}
 
void loop () 
{
  sensorValue = analogRead (sensorPin);
  
  digitalWrite (ledPin, HIGH);
  if(sensorValue >= 100 ){
      PplCounter += 1;
      digitalWrite (ledPin, LOW);
    }
  Serial.println (sensorValue, DEC);
  Serial.print (PplCounter);
  Serial.println(" people passed");

  delay(2000);
}


/* -----------------------------------

kafqva - pin 13
bqla - A0
4ervena - Vcc
4erna - GND
----------------------------------- */
