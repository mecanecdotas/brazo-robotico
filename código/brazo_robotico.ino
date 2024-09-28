#include <Servo.h>

int pos = 0;
int sensorValue = 0;
int i = 0;

Servo servo_9;

void setup()
{
  servo_9.attach(9);
  pinMode(A0, INPUT);
}

void loop()
{
   sensorValue = analogRead(A0); // Lee el valor del sensor
   pos = map(sensorValue, 0, 1023, 0, 180);  // Mapea el valor a 0-180 grados
   
   Serial.print("sensorValue: ");
   Serial.println(sensorValue);
   Serial.print("pos: ");
   Serial.println(pos);

   // Mueve el servo al valor calculado 'pos'
   servo_9.write(pos);  
   
   delay(30);  // Aumentar este valor si el servo no responde correctamente
}