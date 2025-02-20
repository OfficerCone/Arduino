#include<array>

const int SER = 0;
const int RCLK = 1;
const int SRCLK = 2;
const int CLEAR = 3;
const int TEST = 7;

std::array<int,16> state_1 = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0}; // LEDs D6 und D5
std::array<int,16> state_2 = {0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0}; //LEDs D3 und D2


void setup() {
 pinMode(0, OUTPUT); 
 pinMode(1, OUTPUT); 
 pinMode(2, OUTPUT); 
 pinMode(3, OUTPUT); 
 pinMode(7, OUTPUT);

}
void light() {
 digitalWrite(CLEAR, LOW);
 digitalWrite(CLEAR, HIGH);
 digitalWrite(RCLK, LOW);

 for (int i = 0; i < 16; i++) {
   digitalWrite(SRCLK, LOW);
   digitalWrite(SER, state_1[i]);
   digitalWrite(SRCLK, HIGH);
 }
 digitalWrite(RCLK, HIGH);
 delay(1000);
  
  digitalWrite(CLEAR, LOW);
  digitalWrite(CLEAR, HIGH);
  digitalWrite(RCLK, LOW);
  
  for (int i = 0; i < 16; i++) {
   digitalWrite(SRCLK, LOW);
   digitalWrite(SER, state_2[i]);
   digitalWrite(SRCLK, HIGH);
  }
 
 
digitalWrite(RCLK, HIGH);
delay(1000);

}

void loop() {

light();
}


