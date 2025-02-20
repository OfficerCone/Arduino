#include<array>

const int SER = 0;
const int RCLK = 1;
const int SRCLK = 2;
const int CLEAR = 3;
const int TEST = 7;

std::array<int,16> start = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0}; // LED D6
std::array<int,16> stop = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}; // keine LED

void setup() {
 pinMode(0, OUTPUT); 
 pinMode(1, OUTPUT); 
 pinMode(2, OUTPUT); 
 pinMode(3, OUTPUT); 
 pinMode(7, OUTPUT);
}
void run() {
  digitalWrite(CLEAR, LOW);
  digitalWrite(CLEAR, HIGH);
  digitalWrite(RCLK, LOW);

  for (int i= 0; i < 16; i++) {
   digitalWrite(SRCLK, LOW);
   digitalWrite(SER, start[i]);
   digitalWrite(SRCLK, HIGH);
   }
  digitalWrite(RCLK, HIGH);
  delay(1000);
  
  digitalWrite(CLEAR, LOW);
  digitalWrite(CLEAR, HIGH);
  digitalWrite(RCLK, LOW);
  
  for (int i = 0; i < 16; i++) {
   digitalWrite(SRCLK, LOW);
   digitalWrite(SER, stop[i]);
   digitalWrite(SRCLK, HIGH);
  }
 
 
digitalWrite(RCLK, HIGH);
delay(1000);

}

void loop() {

run();
}
