/*
   TUTORIAL SERVO PADA ARDUINO
   MENGGERAKKAN SERVO SESUAI POTENSIO

   Pinout  :
   Kabel coklat servo -> GND
   Kabel coklat merah -> VCC
   Kabel coklat kuning -> SDA (atau A4)

   Potensio pada A0
*/

#include <Servo.h>
#define PIN_POTENSIO A0

int servoPin = A4;
int derajat;

Servo servo;

void setup() {
  Serial.begin(115200); //memulai komunikasi serial pada baud rate 115200
  delay(100);
  Serial.println("Menggerakkan servo pada Arduino");
  servo.attach(servoPin);
  pinMode(PIN_POTENSIO, INPUT); //set A0 menjadi input (potensio)


}

void loop() {
  int nilaiPotensio = analogRead(PIN_POTENSIO);
  derajat = map(nilaiPotensio, 0, 1023, 0, 180);//memetakan nilai potensio yang memiliki range 0-1023 ke nilai derajat servo 0-180 derajat
  servo.write(derajat);
  Serial.println(derajat);
  delay(1);
}
