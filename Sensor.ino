#define CLEAR 3
#define Trig 18
#define Echo 19

int distance[0];

void setup() {

pinMode(Trig, OUTPUT);
pinMode(Echo, INPUT);

digitalWrite(CLEAR, LOW);
digitalWrite(CLEAR, HIGH);

Serial.begin(115200);


}



void loop() {

delay(1000);

digitalWrite(Trig, HIGH);
for (int i=0; i<40; i++){
distance[i] = analogRead(Echo);
Serial.println();
digitalWrite(Trig, LOW);
}
}