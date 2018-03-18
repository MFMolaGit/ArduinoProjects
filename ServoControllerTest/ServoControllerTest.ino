#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>

Adafruit_PWMServoDriver servos = Adafruit_PWMServoDriver(0x40);


#define SERVOMIN 172
#define SERVOMAX 565
unsigned int pos0=0; // 172 ancho de pulso en cuentas para pocicion 0° 262
unsigned int pos180=180; // 565 ancho de pulso en cuentas para la pocicion 180° 488
unsigned int pulselength;

void setup() {
  servos.begin();  
  servos.setPWMFreq(60); //Frecuecia PWM de 60Hz o T=16,66ms
}


void loop() {
  
  for (int degrees = pos0; degrees < pos180; degrees=degrees+10) {
    for(int n=0;n<16;n++)
    {
      pulselength = map(degrees, 0, 180, SERVOMIN, SERVOMAX);
      servos.setPWM(n,0,pulselength);
    }
  }
  delay(1000);
  for (int degrees = pos180; degrees > pos0; degrees=degrees-10) {
    for(int n=0;n<16;n++)
    {
      pulselength = map(degrees, 0, 180, SERVOMIN, SERVOMAX);
      servos.setPWM(n,0,pulselength);
    }
  }
  delay(2000);
}
