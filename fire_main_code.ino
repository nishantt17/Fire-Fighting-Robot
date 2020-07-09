#include<Servo.h>
Servo myservo;
#define flame1 4
#define flame2 5
#define flame3 9
#define m1 13
#define m2 12
#define m3 11
#define m4 10
#define pwm1 3
#define pwm2 8
#define echo 6 
#define trig 7
#define ma 
#define mb
#define pwm_ab
long duration;
long distance; 
long distance_R;
long distance_L;
void setup() {
  pinMode(echo,INPUT);
  pinMode(trig,OUTPUT);
  Serial.begin(9600);
  pinMode(flame1,INPUT);
  pinMode(flame2,INPUT);
  pinMode(flame3,INPUT);
  pinMode(m1,OUTPUT);
  pinMode(m2,OUTPUT);
  pinMode(m3,OUTPUT);
  pinMode(m4,OUTPUT);
  pinMode(pwm1, OUTPUT);
  pinMode(pwm2, OUTPUT);
  pinMode(ma,OUTPUT);
  pinMode(mb,OUTPUT);
  pinMode(pwm_ab,OUTPUT);
  myservo.attach(/*pin to which servo motor is connected*/ );
}

void obstacle(){

   digitalWrite(trig,LOW);
  delayMicroseconds(2);
  digitalWrite(trig,HIGH);
  delayMicroseconds(10);
  digitalWrite(trig,LOW);
  duration=pulseIn(echo,HIGH);
  distance=duration*0.034/2;
  Serial.println(distance);
  if(distance==15)
  {
  digitalWrite(m1,LOW);
  digitalWrite(m2,HIGH);
  analogWrite(pwm1,255);
  digitalWrite(m3, LOW);
  digitalWrite(m4, HIGH);
  analogWrite(pwm2,255);
  delay(500);
  //rotate servo motor to left and right
  myservo.write(120);//or 60
  delay(15);
  digitalWrite(trig,LOW);
  delayMicroseconds(2);
  digitalWrite(trig,HIGH);
  delayMicroseconds(10);
  digitalWrite(trig,LOW);
  duration=pulseIn(echo,HIGH);
  distance_R=duration*0.034/2;
   myservo.write(60);//or 120
   delay(15);
  digitalWrite(trig,LOW);
  delayMicroseconds(2);
  digitalWrite(trig,HIGH);
  delayMicroseconds(10);
  digitalWrite(trig,LOW);
  duration=pulseIn(echo,HIGH);
  distance_L=duration*0.034/2;
  if(distance_R>distance_L)
  {
  digitalWrite(trig,LOW);
  delayMicroseconds(2);
  digitalWrite(trig,HIGH);
  delayMicroseconds(10);
  digitalWrite(trig,LOW);
  duration=pulseIn(echo,HIGH);
  distance_R=duration*0.034/2;
  Serial.println(distance);
  digitalWrite(m1,LOW);//left motor
  digitalWrite(m2,LOW);
  analogWrite(pwm1,255);
  digitalWrite(m3, HIGH);//right motor
  digitalWrite(m4, LOW);
  analogWrite(pwm2,255);
  delay(500);
  digitalWrite (m1,HIGH);
  digitalWrite(m2,LOW );
  analogWrite(pwm1,255);
  digitalWrite(m3, HIGH);
  digitalWrite(m4, LOW);
 analogWrite(pwm2,255);
  delay(1000);
  }
  if(distance_L>distance_R)
  {
  digitalWrite(trig,LOW);
  delayMicroseconds(2);
  digitalWrite(trig,HIGH);
  delayMicroseconds(10);
  digitalWrite(trig,LOW);
  duration=pulseIn(echo,HIGH);
  distance_R=duration*0.034/2;
  Serial.println(distance);
  digitalWrite(m1,HIGH);//left motor
  digitalWrite(m2,LOW);
  analogWrite(pwm1,255);
  digitalWrite(m3, HIGH);//right motor
  digitalWrite(m4, LOW);
  analogWrite(pwm2,255);
  delay(500);
  digitalWrite (m1,HIGH);
  digitalWrite(m2,LOW );
  analogWrite(pwm1,255);
  digitalWrite(m3, HIGH);
  digitalWrite(m4, LOW);
 analogWrite(pwm2,255);
  delay(1000);
  }
  }
  else{
    digitalWrite (m1,HIGH);
  digitalWrite(m2,LOW );
  analogWrite(pwm1,255);
  digitalWrite(m3, HIGH);
  digitalWrite(m4, LOW);
 analogWrite(pwm2,255);
}
void extinguish()
{
 digitalWrite (ma,HIGH);//on the motor and extingusigh
  digitalWrite(mb,LOW);
  analogWrite(pwm_ab,255);
  delay(10000);
  
}
void left_turn(){
  Serial.println("BHAGOOOOOO____11111");
   //bot stops
    digitalWrite (m1,HIGH);//left motor stop
  digitalWrite(m2,HIGH);
  analogWrite(pwm1,255);
  digitalWrite(m3, HIGH);//right motor stop
  digitalWrite(m4, HIGH);
  analogWrite(pwm2,255);
  delay(500);
  digitalWrite (m1,HIGH);//left motor stop
  digitalWrite(m2,HIGH );
 analogWrite(pwm1,255);
 digitalWrite(m3, HIGH);//right motor on left turn
  digitalWrite(m4, LOW);
  analogWrite(pwm2,255);
  obstacle();
 
}
void go_straight(){
  Serial.println("BHAGOOOOOO___2222222");
    digitalWrite (m1,HIGH);//left motor stop
  digitalWrite(m2,HIGH);
  analogWrite(pwm1,255);
  digitalWrite(m3, HIGH);//right motor stop
  digitalWrite(m4, HIGH);
  analogWrite(pwm2,255);
  delay(500);
  digitalWrite (m1,HIGH);//left motor on straight
  digitalWrite(m2,LOW );
 analogWrite(pwm1,255);
 digitalWrite(m3, HIGH);//right motor on straight
  digitalWrite(m4, LOW);
  analogWrite(pwm2,255);
  obstacle();
 delay(1000);
}
void right_turn(){
  Serial.println("BHAGOOOOOO_____333333");
     digitalWrite (m1,HIGH);//left motor stop
  digitalWrite(m2,HIGH);
  analogWrite(pwm1,255);
  digitalWrite(m3, HIGH);//right motor stop
  digitalWrite(m4, HIGH);
  analogWrite(pwm2,255);
  delay(500);
  digitalWrite (m1,HIGH);//left motor on right turn
  digitalWrite(m2,LOW );
 analogWrite(pwm1,255);
 digitalWrite(m3, HIGH);//right motor stop
  digitalWrite(m4, HIGH);
  analogWrite(pwm2,255);
  obstacle();
 delay(1000);
}
void loop() {
  
 //fire gets detected
  int fire_L=digitalRead(flame1);
  int fire__0=digitalRead(flame2);
  int fire_R=digitalRead(flame3);
  /*digitalWrite (m1,HIGH);
  digitalWrite(m2,LOW );
  analogWrite(pwm1,255);
  digitalWrite(m3, HIGH);
  digitalWrite(m4, LOW);
  analogWrite(pwm2,255);
  delay(100);*/
  if(fire_L==LOW)
  {
    left_turn();
    
  }
  else if(fire__0==LOW)
  {
   go_straight();
  }
  
  else if(fire_R==LOW)
  {
    right_turn();
  }
  else
  {
    //square_trace
    digitalWrite (m1,HIGH);
  digitalWrite(m2,LOW );
  analogWrite(pwm1,255);
  digitalWrite(m3, HIGH);
  digitalWrite(m4, LOW);
 analogWrite(pwm2,255);
  delay(1000);
  digitalWrite(m1, HIGH);
  digitalWrite(m2, LOW);
  analogWrite(pwm1,255);
  digitalWrite(m3, HIGH);
  digitalWrite(m4, HIGH);
  analogWrite(pwm2,255);
  delay(200);
  digitalWrite(m1,HIGH);
  digitalWrite(m2,LOW );
  analogWrite(pwm1,255);
  digitalWrite(m3, HIGH);
  digitalWrite(m4, LOW);
  analogWrite(pwm2,255);
  delay(1000);
  digitalWrite(m1, HIGH);
  digitalWrite(m2, LOW);
  analogWrite(pwm1,255);
  digitalWrite(m3, HIGH);
  digitalWrite(m4, HIGH);
  analogWrite(pwm2,255);
  delay(200);
  digitalWrite(m1,HIGH);
  digitalWrite(m2,LOW );
  analogWrite(pwm1,255);
  digitalWrite(m3, HIGH);
  digitalWrite(m4, LOW);
  analogWrite(pwm2,255);
  delay(1000);
   digitalWrite(m1, HIGH);
  digitalWrite(m2, LOW);
  analogWrite(pwm1,255);
  digitalWrite(m3, HIGH);
  digitalWrite(m4, HIGH);
  analogWrite(pwm2,255);
 delay(200);
  digitalWrite(m1,HIGH);
  digitalWrite(m2,LOW );
  analogWrite(pwm1,255);
  digitalWrite(m3, HIGH);
  digitalWrite(m4, LOW);
  analogWrite(pwm2,255);
  delay(1000);
  }
  
}
