/*If temp is 25 or higher and humidity is more than 30 % green led turns on if its otherwise red turns on
//
// github.com/yodakole1
*/ 


#include <DHT.h>


//Declaration
int sensor_pin = 8;
int crvena_lampica = 6;
int zelena_lampica = 7;

DHT dht11(sensor_pin, DHT11);
float temp = 0;
float vlaznost = 0;


void setup() {
  Serial.begin(9600);
  dht11.begin(); 
  pinMode(zelena_lampica, OUTPUT);
  pinMode(crvena_lampica, OUTPUT);
}

void loop() {

  //Delay for better optimization
  delay(4000);

  temp = dht11.readTemperature();;
  vlaznost = dht11.readHumidity();
  

  if (temp >= 25 && vlaznost >30) {
    digitalWrite(zelena_lampica, HIGH);
    delay(2000);
    digitalWrite(zelena_lampica, LOW);
  } else {
    digitalWrite(crvena_lampica, HIGH);
    delay(2000);
    digitalWrite(crvena_lampica, LOW);
  }
}
