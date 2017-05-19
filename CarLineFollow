int motor11 = 12; int motor12 = 13; int motor21 = 8; int motor22 = 9; int sens1 = A5; int sens2 = A0; int led1 = 6; int led2 = 7; int speker = 5;
float s1 = 0; float s2 = 0;
float black = 500;
void setup() {
  Serial.begin(9600);
  pinMode(motor11,OUTPUT);
  pinMode(motor12,OUTPUT);
  pinMode(motor21,OUTPUT);
  pinMode(motor22,OUTPUT);
  pinMode(led1,OUTPUT);
  pinMode(led2,OUTPUT);
  pinMode(speker,OUTPUT);
}

void loop() { 
  s1 = analogRead(sens1);
  s2 = analogRead(sens2);
  Serial.print(s1);
  Serial.print(" ");
  Serial.print(s2);
  Serial.println();
  if(s1 > black && s2>black){
    tone(speker,200,100);
    threesixty();
  }
  else if(s1 > black){
    angleleft();    
  }
  else if(s2 > black){
    angleright();
  }
  else{
    moveforth();
  }

}                                                                                                                                                                                                                 
void moveforth(){
  digitalWrite(motor11,HIGH);
  digitalWrite(motor12,LOW);
  digitalWrite(motor21,HIGH);
  digitalWrite(motor22,LOW);
  digitalWrite(led1,HIGH);
  digitalWrite(led2,HIGH);
}
void moveback(){
  digitalWrite(motor11,LOW);
  digitalWrite(motor12,HIGH);
  digitalWrite(motor21,LOW);
  digitalWrite(motor22,HIGH);
  digitalWrite(led1,LOW);
  digitalWrite(led2,LOW);
}
void angleleft(){
  digitalWrite(motor11,HIGH);
  digitalWrite(motor12,LOW);
  digitalWrite(motor21,LOW);
  digitalWrite(motor22,HIGH);
  digitalWrite(led1,HIGH);
  digitalWrite(led2,LOW);
}
void angleright(){
  digitalWrite(motor11,LOW);
  digitalWrite(motor12,HIGH);
  digitalWrite(motor21,HIGH);
  digitalWrite(motor22,LOW);
  digitalWrite(led1,LOW);
  digitalWrite(led2,HIGH);
}

void threesixty(){
  digitalWrite(motor11,LOW);
  digitalWrite(motor12,HIGH);
  digitalWrite(motor21,HIGH);
  digitalWrite(motor22,LOW);
  delay(1250);
}
