
#include <Servo.h>
int btA = 2;
int btB = 3;
int btC = 4;
int btD = 5;
int potA0 = 0;
int potA1 = 0;
int incremento = 0;
char escolha = "";

int angBase = 90;
int angDir = 90;
int angEsq = 90;
int angGuarra = 90;

Servo servo_9;
Servo servo_10;
Servo servo_11;
Servo servo_12;
void setup() {

pinMode(btA, INPUT);
pinMode(btB, INPUT);
pinMode(btC, INPUT);
pinMode(btD, INPUT);

servo_9.attach(9);
servo_10.attach(10);
servo_11.attach(11);
servo_12.attach(12);

servo_9.write(90);
servo_10.write(90);
servo_11.write(90);
servo_12.write(90);
}
void loop() {

potA0 = analogRead(A0);
potA1 = analogRead(A1);

if (digitalRead(btA) == 0) {
 escolha = 'A';
}
if (digitalRead(btB) == 0) {
 escolha = 'B';
}
if (digitalRead(btC) == 0) {
 escolha = 'C';
}
if (digitalRead(btD) == 0) {
 escolha = 'D';
}

switch (escolha) {
 case 'A':
 
 if (potA0 > 700 && angGuarra < 100) {
 servo_12.write(angGuarra);
 angGuarra = angGuarra + 1;
 delay(0);
 }
 
 if (potA0 < 300 && angGuarra > 60) {
 servo_12.write(angGuarra);
 angGuarra = angGuarra - 1;
 delay(0);
 }
 break;
 case 'B':

 if (potA1 > 700 && angDir < 180) {
 servo_10.write(angDir);
 angDir = angDir + 1;
 delay(0);
 }
 
 if (potA1 < 300 && angDir > 50) {
 servo_10.write(angDir);
 angDir = angDir - 1;
 delay(0);
 }
 break;
 case 'C':

 if (potA0 < 300 && angBase < 180) {
 servo_9.write(angBase);
 angBase = angBase + 1;
 delay(0);
 }
 
 if (potA0 > 700 && angBase > 0) {
 servo_9.write(angBase);
 angBase = angBase - 1;
 delay(0);
 }
 break;
 case 'D':
 
 if (potA1 > 700 && angEsq < 180) {
 servo_11.write(angEsq);
 angEsq = angEsq + 1;
 delay(0);
 }

 if (potA1 < 300 && angEsq > 90) {
 servo_11.write(angEsq);
 angEsq = angEsq - 1;
 delay(0);
 }
 break;
}
}
