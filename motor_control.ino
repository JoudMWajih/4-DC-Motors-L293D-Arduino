// Left motors
int L1 = 2;
int L2 = 3;

// Right motors
int R1 = 4;
int R2 = 5;

void setup() {
  pinMode(L1, OUTPUT);
  pinMode(L2, OUTPUT);
  pinMode(R1, OUTPUT);
  pinMode(R2, OUTPUT);
}

void forward() {
  digitalWrite(L1, HIGH);
  digitalWrite(L2, LOW);

  digitalWrite(R1, HIGH);
  digitalWrite(R2, LOW);
}

void backward() {
  digitalWrite(L1, LOW);
  digitalWrite(L2, HIGH);

  digitalWrite(R1, LOW);
  digitalWrite(R2, HIGH);
}

void right() {
  // Left side forward
  digitalWrite(L1, HIGH);
  digitalWrite(L2, LOW);

  // Right side backward
  digitalWrite(R1, LOW);
  digitalWrite(R2, HIGH);
}

void left() {
  // Left side backward
  digitalWrite(L1, LOW);
  digitalWrite(L2, HIGH);

  // Right side forward
  digitalWrite(R1, HIGH);
  digitalWrite(R2, LOW);
}

void stopMotors() {
  digitalWrite(L1, LOW);
  digitalWrite(L2, LOW);
  digitalWrite(R1, LOW);
  digitalWrite(R2, LOW);
}

void loop() {

  // 1- Forward for 30 seconds
  forward();
  delay(30000);

  stopMotors();
  delay(1000);

  // 2- Backward for 1 minute
  backward();
  delay(60000);

  stopMotors();
  delay(1000);

  // 3- Right and left alternately for 1 minute
  // 10 sec right + 10 sec left × 3 = 60 sec
  for (int i = 0; i < 3; i++) {

    right();
    delay(10000);

    left();
    delay(10000);
  }

  stopMotors();

  // Stop here when sequence finishes
  while (true) {
  }
}
