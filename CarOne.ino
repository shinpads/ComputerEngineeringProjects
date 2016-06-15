boolean start;
int offset = 0;
int num = 200;
int spin = 200;
int lorr = 1;
void setup(){
  Serial.begin(9600);
 tone(11,1000,300);
 pinMode(3,OUTPUT); 
 pinMode(4,INPUT);
 pinMode(5,INPUT);
 pinMode(6,OUTPUT);
 pinMode(7,OUTPUT);
 pinMode(8,OUTPUT); 
 pinMode(12,INPUT);
 pinMode(13,INPUT);
 
}
void loop(){
tryMotion(0,0);
}

void tryMotion(int target, int actual){
if(target != actual){
if(lorr < 0){
rotateRight();
}
else{
rotateLeft();
}
delay(num);
lorr *= -1;
num+=spin;
motionNone();
}
delay(40);
while(digitalRead(12)==LOW && digitalRead(13)==LOW){
  motionForward();
  offset+=1;
  Serial.println(offset); 
  if(offset>800){
  motionNone();
  while(true){
 tone(11,1,10);
 delay(10);
 tone(11,1000,10);
 
  }
}
}
tone(11,1,50);
offset/=1.13;
while(offset!=0){
  Serial.println(offset);
 motionBackward();
  offset-=1; 
}
tryMotion(target+1,actual);

 }
void motionBackward(){
  digitalWrite(7,HIGH);
  digitalWrite(8,LOW);
  digitalWrite(9,LOW);
  digitalWrite(10,HIGH); 
}
void motionForward(){
  digitalWrite(7,LOW);
  digitalWrite(8,HIGH);
  digitalWrite(9,HIGH);
  digitalWrite(10,LOW);
}
void motionRight(){
  digitalWrite(7,LOW);
  digitalWrite(8,LOW);
  digitalWrite(9,HIGH);
  digitalWrite(10,LOW);  
}
void motionLeft(){
   digitalWrite(7,LOW);
  digitalWrite(8,HIGH);
  digitalWrite(9,LOW);
  digitalWrite(10,LOW); 
}
void motionNone(){
   digitalWrite(7,LOW);
  digitalWrite(8,LOW);
  digitalWrite(9,LOW);
  digitalWrite(10,LOW);  
}
void rotateLeft(){
   digitalWrite(7,LOW);
  digitalWrite(8,HIGH);
  digitalWrite(9,LOW);
  digitalWrite(10,HIGH); 
}
void rotateRight(){
   digitalWrite(7,HIGH);
  digitalWrite(8,LOW);
  digitalWrite(9,HIGH);
  digitalWrite(10,LOW); 
}
