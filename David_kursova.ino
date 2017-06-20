  int sensorPin = A0; // select the input pin for the potentiometer
  int sensorValue = 0; // variable to store the value coming from the sensor
  int ledPin = 13; // select the pin for the LED
  int PplCounter = 0;
  int MovementCounter = 0; 
void setup (){
  pinMode (ledPin, OUTPUT);
  Serial.begin (9600);
}
 
void loop () 
{
  sensorValue = analogRead (sensorPin);
  while (MovementCounter == 0){
    digitalWrite (ledPin, HIGH);
    if(sensorValue >= 100 ){
        PplCounter += 1;
        digitalWrite (ledPin, LOW);
        MovementCounter = 1;
      }
    Serial.println (sensorValue, DEC);
    Serial.print (PplCounter);
    Serial.println(" people passed");
    
    delay(500);
  }
  if(sensorValue >= 100 ){
      MovementCounter = 0;
  }
  delay(500);
}


/* -----------------------------------

kafqva - pin 13
bqla - A0
4ervena - Vcc
4erna - GND
----------------------------------- */
