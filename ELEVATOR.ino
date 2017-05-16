#include <LiquidCrystal.h>
#include <Servo.h>
Servo servo;
LiquidCrystal lcd(11, 10, 9, 8, 7, 6);
int p1 =5; int p2 = 2; int p3 = 3; int p4 =4; int floor1Button = A2; int floor2Button = A1; int floor3Button = A3; int servopos = 0; int speker = 12;
int floorvalues[] = {0,105,210};
int curfloor = 0;
int pos = 0;
bool mov = false;
String flor = "";
void setup() {
  servo.attach(13);
  servo.write(90);
  delay(100);
  lcd.begin(16,2);
  lcd.print("First Floor");
  Serial.begin(9600);
  pinMode(p1,OUTPUT);pinMode(p2,OUTPUT);pinMode(p3,OUTPUT);pinMode(p4,OUTPUT);pinMode(floor1Button,INPUT);pinMode(floor2Button,INPUT);pinMode(floor3Button,INPUT);
}

void loop() {
  if(digitalRead(floor1Button)){curfloor = 0;lcd.clear(); lcd.print( "First Floor");}
  if(digitalRead(floor2Button)){curfloor = 1;lcd.clear(); lcd.print( "Second Floor");}
  if(digitalRead(floor3Button)){curfloor = 2;lcd.clear(); lcd.print( "Fourth Floor");}
  while(pos != floorvalues[curfloor]){
    mov = true;
    turn((floorvalues[curfloor] - pos )/ abs(floorvalues[curfloor] - pos ),5);
  }
  if(mov){
    for(int i = 1; i <= curfloor+1; i++){
      Serial.println(curfloor+1);
      tone(speker,800,50);
      delay(250);
    }
    toggleDoor();

    mov = false;
  }


}

void turn(int x,int del){
   
  if (x == 1){
    pos += 1;
  digitalWrite(p1,1);digitalWrite(p2,1);digitalWrite(p3,0);digitalWrite(p4,0);delay(del);
  digitalWrite(p1,0);digitalWrite(p2,1);digitalWrite(p3,1);digitalWrite(p4,0);delay(del);
  digitalWrite(p1,0);digitalWrite(p2,0);digitalWrite(p3,1);digitalWrite(p4,1);delay(del);
  digitalWrite(p1,1);digitalWrite(p2,0);digitalWrite(p3,0);digitalWrite(p4,1);delay(del);
  }else{
    pos -= 1;
  digitalWrite(p1,1);digitalWrite(p2,1);digitalWrite(p3,0);digitalWrite(p4,0);delay(del);
  digitalWrite(p1,1);digitalWrite(p2,0);digitalWrite(p3,0);digitalWrite(p4,1);delay(del);
  digitalWrite(p1,0);digitalWrite(p2,0);digitalWrite(p3,1);digitalWrite(p4,1);delay(del);
  digitalWrite(p1,0);digitalWrite(p2,1);digitalWrite(p3,1);digitalWrite(p4,0);delay(del);
  }

}
void toggleDoor(){
  for(int i = 90; i >= 0; i--){
    servo.write(i);
    delay(15);
  }
  delay(300);
    for(int i = 0; i <=90; i++){
    servo.write(i);
    delay(15);
  }
}

