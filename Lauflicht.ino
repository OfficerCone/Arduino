
#include<array>

#define SER 0
#define RCLK 1
#define SRCLK 2
#define CLEAR 3
#define TEST 7

int direction = 0;


std::array<int,8> state_1 = {1, 0, 0, 0, 0, 0, 0, 0}; // LED D2
std::array<int,8> state_2 = {0, 1, 0, 0, 0, 0, 0, 0}; // LED D3
std::array<int,8> state_3 = {0, 0, 1, 0, 0, 0, 0, 0}; // LED D4
std::array<int,8> state_4 = {0, 0, 0, 1, 0, 0, 0, 0}; // LED D5
std::array<int,8> state_5 = {0, 0, 0, 0, 1, 0, 0, 0}; // LED D6

void setup() {
 pinMode(SER, OUTPUT); 
 pinMode(RCLK, OUTPUT); 
 pinMode(SRCLK, OUTPUT); 
 pinMode(CLEAR, OUTPUT); 
 pinMode(TEST, OUTPUT);
 updateLEDs();

}

void updateLEDs() {
  digitalWrite(CLEAR, LOW);
  digitalWrite(CLEAR, HIGH);
  digitalWrite(RCLK, LOW);

  for (int i= 0; i < 8; i++) {
   digitalWrite(SRCLK, LOW);
   digitalWrite(SER, state_1[i]);
   digitalWrite(SRCLK, HIGH);
   }
  digitalWrite(RCLK, HIGH);
  

}

void loop() {

  for (int i= 0; i < 8; i++) {
   digitalWrite(SRCLK, LOW);
   digitalWrite(SER, state_1[i]);
   digitalWrite(SRCLK, HIGH);
   }
  digitalWrite(RCLK, HIGH);
  delay(200);
  updateLEDs();


} 
