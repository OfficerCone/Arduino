#include<array>

#define SER 0
#define SCLK 1
#define SRCLK 2
#define CLEAR 3
#define MOTOR_PIN_2 4
#define MOTOR_PIN_1 6
#define Trig 18
#define Echo 19
#define max_dist 400

int states 

std::array<int,8> sixty = {0,1,1,1,0,0,0,0};
std::array<int,8> forty = {0,1,1,0,0,0,0,0};
std::array<int,8> twenty = {0,1,0,0,0,0,0,0};


int duration = 0;
int distance = 0;

void setup() {
pinMode(SER, OUTPUT);
pinMode(SCLK, OUTPUT);
pinMode(SRCLK, OUTPUT);
pinMode(CLEAR, OUTPUT);
pinMode(MOTOR_PIN_1, OUTPUT);
pinMode(MOTOR_PIN_2, OUTPUT);
pinMode(Trig, OUTPUT);
pinMode(Echo, INPUT);


digitalWrite(CLEAR, LOW);
digitalWrite(CLEAR, HIGH);
Serial.begin(9600);
}

void loop() {

delay(1000);
digitalWrite(Trig, LOW);  
delayMicroseconds(2);  
digitalWrite(Trig, HIGH); 
delay(20);
digitalWrite(Trig, LOW);  
duration = pulseIn(Echo, HIGH);

distance = (duration/2) * 0.03432;

if (distance >= 400) {
Serial.println("No data");
}
else {
Serial.print(distance);
Serial.println("cm");
distance_LED();
}

}


void distance_LED() {

if (distance >= 60) {
 for (int i = 0; i < 8; i++) {
   digitalWrite(SRCLK, LOW);
   digitalWrite(SER, sixty[i]);
   digitalWrite(SRCLK, HIGH);
 }
}
else if (distance >= 40) {
 for (int i = 0; i < 8; i++) {
   digitalWrite(SRCLK, LOW);
   digitalWrite(SER, forty[i]);
   digitalWrite(SRCLK, HIGH);
 }
}
else if (distance >= 20) {
 for (int i = 0; i < 8; i++) {
   digitalWrite(SRCLK, LOW);
   digitalWrite(SER, twenty[i]);
   digitalWrite(SRCLK, HIGH);
 }
}
}