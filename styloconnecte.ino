
const int sensorPin = A0;                           //Capteur de temperature branché sur A0
const int sensorPin2 = A2;                          //Capteur de pression branché sur A2
int sensorVal = 0;
int sensorValue2 = 0;
float temperatureAmbiante = 0;

void setup() {
  Serial.begin(9600);                               //Ouvre un port serie
  sensorVal = analogRead(sensorPin);            //Put your main code here, to run repeatedly
  float voltage = (sensorVal / 1024.0) * 5.0;       //Converti la lecture du CAN en tension
  temperatureAmbiante = (voltage - 0.5) * 100;        //Converti la tension en temperature en degrés
}

void loop() {

  sensorVal = analogRead(sensorPin);            //Put your main code here, to run repeatedly
  float voltage = (sensorVal / 1024.0) * 5.0;       //Converti la lecture du CAN en tension
  float temperature = (voltage - 0.5) * 100;        //Converti la tension en temperature en degré
  sensorValue2 = analogRead( sensorPin2 );
  
  /*Affichage*/
  if ((sensorValue2 > 300) && (temperature >= temperatureAmbiante + 1)) {
    Serial.println("1");
  }else
  Serial.println("0");
  delay(1);
}

