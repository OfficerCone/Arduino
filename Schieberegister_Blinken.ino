//Schiebregister Pins
#define SHIFT_REGISTER_DATA_PIN 0 
#define SHIFT_REGISTER_DATA_SHIFT_PIN 1
#define SHIFT_REGISTER_DATA_CLOCK_PIN 2
#define SHIFT_REGISTER_MASTER_RECLEAR_PIN 3
#define TOTAL_SHIFT_PINS 8
bool ledVals[] = {0, 0, 0, 0, 0, 0, 0, 0};
char d6_index = 4;
char d5_index = 3;
char d3_index = 1;
char d2_index = 0;
bool d6_on = true;
bool d3_on = true;
/* ledVals_Pinbelegungen[] = {D2, D3, D4, D5, D6, D1/_2, D10/_2, D12/_2}; */

#define DC_MOTOR_PIN_1 6
#define DC_MOTOR_PIN_2 4


void setup() {
  // Definieren der Pins des ESP32
  pinMode(SHIFT_REGISTER_DATA_PIN, OUTPUT);
  pinMode(SHIFT_REGISTER_DATA_SHIFT_PIN, OUTPUT);
  pinMode(SHIFT_REGISTER_DATA_CLOCK_PIN, OUTPUT);
  pinMode(SHIFT_REGISTER_MASTER_RECLEAR_PIN, OUTPUT);

  pinMode(DC_MOTOR_PIN_1, OUTPUT);
  digitalWrite(DC_MOTOR_PIN_1, LOW);
  pinMode(DC_MOTOR_PIN_2, OUTPUT);
  digitalWrite(DC_MOTOR_PIN_2, LOW);
}

void loop() {
  ledVals[d6_index] = d6_on;
  ledVals[d5_index] = !d6_on;
  ledVals[d3_index] = d3_on;
  ledVals[d2_index] = !d3_on;
  updateLEDs();
  d6_on = !d6_on;
  d3_on = !d3_on;
  delay(1000);
}

void updateLEDs() {
  digitalWrite(SHIFT_REGISTER_MASTER_RECLEAR_PIN, LOW);
  digitalWrite(SHIFT_REGISTER_MASTER_RECLEAR_PIN, HIGH);
  digitalWrite(SHIFT_REGISTER_DATA_SHIFT_PIN, LOW);
  for (int i = 0; i < TOTAL_SHIFT_PINS; i++) {
    digitalWrite(SHIFT_REGISTER_DATA_CLOCK_PIN, LOW); // Wait-Value for Shift Pin
    digitalWrite(SHIFT_REGISTER_DATA_PIN, ledVals[i]); // Write LED Value
    digitalWrite(SHIFT_REGISTER_DATA_CLOCK_PIN, HIGH); // Shift data in register
  }
  digitalWrite(SHIFT_REGISTER_DATA_SHIFT_PIN, HIGH);
}