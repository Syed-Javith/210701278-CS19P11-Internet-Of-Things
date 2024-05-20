#define ledC1 8
#define ledC2 9
#define ledC3 10

int c1, c2 ;

void setup() {
  Serial.begin(9600);

  pinMode(ledC1, OUTPUT);
  pinMode(ledC2, OUTPUT);
  pinMode(ledC3, OUTPUT);
}

void loop() {
  readSensor();

  if (c1 == 1 ) {
    roadCopen();
  } else {
    roadClose();
  }
}

void readSensor() {
  c1 = analogRead(A1);
  c2 = analogRead(A0);
  Serial.print(c1);
  Serial.print("\t");
  Serial.print(c2);
  Serial.println("\t");
  if (c1 < 400) { c1 = 1; } else c1 = 0;
  Serial.print(c1);
  Serial.print("\t");
  Serial.print(c2);
  Serial.println("\t");
}

void roadCopen() {
  digitalWrite(ledC3, LOW);
  digitalWrite(ledC1, LOW);
  digitalWrite(ledC2, HIGH);
  delay(2000);
  digitalWrite(ledC2, LOW);
  digitalWrite(ledC1, HIGH);
  delay(2000);
  readSensor();
}

void roadClose() {
  Serial.println("ROAD STOP");
  digitalWrite(ledC3, HIGH);
  digitalWrite(ledC1, LOW);
  digitalWrite(ledC2, LOW);
  delay(15000);
  digitalWrite(ledC3, LOW);
  digitalWrite(ledC2, HIGH);
  delay(1000);
  digitalWrite(ledC2, LOW);
  delay(1000);
  digitalWrite(ledC1, HIGH);
  delay(5000);
  digitalWrite(ledC1, LOW);
  readSensor();
}
