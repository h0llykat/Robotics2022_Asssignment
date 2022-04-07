int trigR = 3;  
int echoR = 2;

int trigL = 12;
int echoL = 11;

int ledPin1 = 10;
int ledPin2 = 8;

unsigned long distance;
unsigned long duration;

int disR, disL;

void setup() {
  pinMode(trigR, OUTPUT);
  pinMode(echoR, INPUT);

  pinMode(trigL, OUTPUT);
  pinMode(echoL, INPUT);

  pinMode(ledPin1, OUTPUT);
  pinMode(ledPin2, OUTPUT);

  Serial.begin(9600);
}

void loop() {
  disR = ping(trigR, echoR);
  disL = ping(trigL, echoL);

  if (disR >= (disL - 5) && disR <= (disL + 5)) {
    digitalWrite(ledPin1, HIGH);
    digitalWrite(ledPin2, HIGH);
  }
  else {
    digitalWrite(ledPin1, LOW);
    digitalWrite(ledPin2, LOW);
  }
}

unsigned long ping(int t, int e) {
  digitalWrite(t, LOW);
  delayMicroseconds(2);

  digitalWrite(t, HIGH);
  delayMicroseconds(10);
  digitalWrite(t, LOW);

  duration = pulseIn(e, HIGH);
  
  distance = duration * 0.034 / 2;
  return distance;
}