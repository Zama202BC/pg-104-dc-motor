const int controlPin1 = 2;
const int controlPin2 = 3;
const int enablePin = 9;
const int directionSwitchPin = 4;
const int OFSSSP = 5;
const int potPin = A0;

int OFSS = 0;
int previousOFSS = 0;
int directionSS = 0;
int previousDirectionSS = 0;

int motorEnabled = 0;
int motorSpeed = 0;
int motorDirection = 1;

void setup(){
  pinMode(directionSwitchPin, INPUT);
  pinMode(OFSSSP, INPUT);
  pinMode(controlPin1, OUTPUT);
  pinMode(controlPin2, OUTPUT);
  pinMode(enablePin, OUTPUT);
  digitalWrite(enablePin, LOW);
}

void loop(){
  OFSS = digitalRead(OFSSSP);
  delay(1);
  directionSS = digitalRead(directionSwitchPin);
  motorSpeed = analogRead(potPin)/4;
  if (OFSS != previousOFSS){
    if (OFSS == HIGH){
      motorEnabled = !motorEnabled;
    }
  }
  if (directionSS != previousDirectionSS){
    if (directionSS == HIGH){
      motorDirection = !motorDirection;
    }
  }
  if (motorDirection == 1){
    digitalWrite(controlPin1, HIGH);
    digitalWrite(controlPin2, HIGH);
  }
  else{
    digitalWrite(controlPin1, LOW);
    digitalWrite(controlPin2, HIGH);
  }
  if (motorEnabled == 1){
    analogWrite(enablePin, motorSpeed);
  }
  else{
    analogWrite(enablePin, 0);
  }
  previousDirectionSS = directionSS;
  previousOFSS = OFSS;
}
