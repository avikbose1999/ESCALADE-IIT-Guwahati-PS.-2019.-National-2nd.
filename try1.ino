#include <Servo.h>
int s0=0;
int s1=0;
int s2=0;
int s3=0;
int s4=0;
int s5=0;
int s6=0;
int s7=0;

int c=0;
int c2=0;
int c3=0;
const int lmf=11;
const int lmb=10;
const int rmf=6;
const int rmb=9;
Servo myservo;
void setup()
{
// put your setup code here, to run once:
pinMode(2,INPUT);//S7
pinMode(3,INPUT);//S6
pinMode(4,INPUT);//S5
pinMode(5,INPUT);//S4
pinMode(7,INPUT);//S3
pinMode(8,INPUT);//S2
pinMode(12,INPUT);//S1
pinMode(13,INPUT);//S0
myservo.attach(A0,600,2300);
myservo.write(0);
pinMode(lmf,OUTPUT);
pinMode(lmb,OUTPUT);
pinMode(rmf,OUTPUT);
pinMode(rmb,OUTPUT);
Serial.begin(9600);
}
void loop(){
s0=digitalRead(13);
s1=digitalRead(12);
s2=digitalRead(8);
s3=digitalRead(7);
s4=digitalRead(5);
s5=digitalRead(4);
s6=digitalRead(3);
s7=digitalRead(2);

/*if(s0==1&&s1==1&&s2==1&&s3==1&&s4==1&&s5==1&&s6==1&&s7==1&&c==0)//first all white for traversing total black path
{
  c=c+1;
analogWrite(rmf, 0);
analogWrite(rmb, 0);
analogWrite(lmf, 255);
analogWrite(lmb, 0);
delay(650);
//right turn with measured delay
analogWrite(rmf, 200);
analogWrite(rmb, 0);
analogWrite(lmf, 200);
analogWrite(lmb, 0);
delay(1700);
//forward with measured delay
}
/*
else if(s0==1&&s1==1&&s2==1&&s3==1&&s4==1&&s5==1&&s6==1&&s7==1&&c!=1)
{
analogWrite(rmf, 0);
analogWrite(rmb, 0);
analogWrite(lmf, 0);
analogWrite(lmb, 0);
delay(2000);
//servo code
analogWrite(rmf, 0);
analogWrite(rmb, 0);
analogWrite(lmf, 0);
analogWrite(lmb, 0);
delay(10000);
}*/
if(s0==0&&s1==0&&s2==0&&s3==0&&s4==0&&s5==0&&s6==0&&s7==0&&c2==0)//all black for right turn
{
c2=c2+1;
analogWrite(rmf, 0);
analogWrite(rmb, 150);
analogWrite(lmf, 0);
analogWrite(lmb, 150);
delay(20);
analogWrite(rmf, 0);
analogWrite(rmb, 100);
analogWrite(lmf, 255);
analogWrite(lmb, 0);
delay(300);
}
else if(s0==1&&s1==1&&s2==1&&s3==1&&s4==1&&s5==1&&s6==1&&s7==1&&c==0)
{
  c=c+1;
analogWrite(rmf, 255);
analogWrite(rmb, 0);
analogWrite(lmf, 0);
analogWrite(lmb, 0);
delay(720);
analogWrite(rmf, 255);
analogWrite(rmb, 0);
analogWrite(lmf, 255);
analogWrite(lmb, 0);
delay(2080);
analogWrite(rmf, 255);
analogWrite(rmb, 0);
analogWrite(lmf, 0);
analogWrite(lmb, 0);
delay(825);
analogWrite(rmf, 255);
analogWrite(rmb, 0);
analogWrite(lmf, 255);
analogWrite(lmb, 0);
delay(745);

}
else if(s0==1&&s1==1&&s2==1&&s3==1&&s4==1&&s5==1&&s6==1&&s7==1&&c!=0)
{
  c=c+1;
analogWrite(rmf, 0);
analogWrite(rmb, 0);
analogWrite(lmf, 0);
analogWrite(lmb, 0);
delay(500);
//servo code
for(int i=1;i<=90;i++)
{
  myservo.write(i);
  delay(1);
 }
analogWrite(rmf, 0);
analogWrite(rmb, 0);
analogWrite(lmf, 0);
analogWrite(lmb, 0);
delay(100000);

}
 else if((s3==s6)&&(s7==s2)&&(s3!=s7))//smooth right
{
analogWrite(rmf, 0);
analogWrite(rmb, 0);
analogWrite(lmf, 140);
analogWrite(lmb, 0);
delay(15);
}
else if((s1==s4)&&(s0==s5)&&(s4!=s0))//smooth left
{
analogWrite(rmf, 150);
analogWrite(rmb, 0);
analogWrite(lmf, 0);
analogWrite(lmb, 0);
delay(15);
}

else if( (s3==s6)&&(s3==s7)&&(s4!=s0))//hard right
{
  
analogWrite(rmf, 0);
analogWrite(rmb, 135);
analogWrite(lmf, 200);
analogWrite(lmb, 0);
delay(30);

}
else if((s4==s1)&&(s4==s0)&&(s3!=s7))//hard left
{
  
analogWrite(rmf, 200);
analogWrite(rmb, 0);
analogWrite(lmf, 0);
analogWrite(lmb, 100);
delay(180);
//if(s0==1&&s1==1&&s2==1&&s3==1&&s4==1&&s5==1&&s6==1&&s7==1&&c3==0)
//{
//  c3=c3+1;
//analogWrite(rmf, 255);
//analogWrite(rmb, 0);
//analogWrite(lmf, 0);
//analogWrite(lmb, 50);
//delay(200);
//}
}
else if(((s0==s7)&&((s3!=s0)||(s4!=s7))))//forward
{
analogWrite(rmf, 200);
analogWrite(rmb, 0);
analogWrite(lmf, 200);
analogWrite(lmb, 0);
delay(5);
}
}
