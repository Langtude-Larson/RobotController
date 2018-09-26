const int IN1 = 7;
const int IN2 = 6;
const int IN3 = 5;
const int IN4 = 4;
const int ENA = 9;
const int ENB = 3;
const int L1 = A0;
const int L2 = A1;
float sort = 0;

void setup() {
  pinMode (IN1, OUTPUT);
  pinMode (IN2, OUTPUT);
  pinMode (IN3, OUTPUT);
  pinMode (IN4, OUTPUT);
  pinMode (ENA, OUTPUT);
  pinMode (ENB, OUTPUT);

  pinMode (L1, INPUT);
  pinMode (L2, INPUT);

  Serial.begin(9600);
}

void loop(){
  
}

void DrejTilHoejre(float tid){
  SetRetning(false, true);
  Koer(100, 100);
  Pause(tid);
}

void DrejTilVenstre(float tid){
  SetRetning(true, false);
  Koer(100, 100);
  Pause(tid);
}

void KoerFremad(float tid){
  SetRetning(true, true);
  Koer(255, 255);
  Pause(tid);
}

void KoerBagud(float tid){
  SetRetning(false, false);
  Koer(255, 255);
  Pause(tid);
}

void Stop(){
  analogWrite(ENA, 0); //Hastighed på motor A
  analogWrite(ENB, 0); //Hastighed på motor B
}

void SetRetning(bool motorA, bool motorB){
  digitalWrite(IN1, motorA);
  digitalWrite(IN2, !motorA);

  //Direction motor B
  digitalWrite(IN3, motorB);
  digitalWrite(IN4, !motorB);
}

void Koer(float hastighedA, float hastighedB){
  analogWrite(ENA, hastighedA); //Hastighed på motor A
  analogWrite(ENB, hastighedB); //Hastighed på motor B
}

void Pause(float tid){
  delay((tid * 1000));
}

void TankController(float retning){

  SetRetning(true, true);
  analogWrite(ENA, retning); //Hastighed på motor A
  analogWrite(ENB, 255 - retning); //Hastighed på motor B
}

void KalibrerLys(int light1, int light2){
  sort = (analogRead(light1) + analogRead(light2)) / 2;
}

