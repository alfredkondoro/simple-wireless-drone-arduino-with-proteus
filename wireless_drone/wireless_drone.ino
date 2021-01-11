#define motor1pin1 13
#define motor1pin2 12
#define motor1pin3 11

#define motor2pin1 A0
#define motor2pin2 A1
#define motor2pin3 A2

#define motor3pin1 10
#define motor3pin2 9
#define motor3pin3 8

#define motor4pin1 A3
#define motor4pin2 A4
#define motor4pin3 A5

//#define ustrigger 40
//#define usecho 41

char incomingByte = 0;

void setup() {
  pinMode(motor1pin1, OUTPUT);
  pinMode(motor1pin2, OUTPUT);
  pinMode(motor1pin3, OUTPUT);
  pinMode(motor2pin1, OUTPUT);
  pinMode(motor2pin2, OUTPUT);
  pinMode(motor2pin3, OUTPUT);
  pinMode(motor3pin1, OUTPUT);
  pinMode(motor3pin2, OUTPUT);
  pinMode(motor3pin3, OUTPUT);
  pinMode(motor4pin1, OUTPUT);
  pinMode(motor4pin2, OUTPUT);
  pinMode(motor4pin3, OUTPUT);
  Serial.begin(9600);
}

void motorone(){
  digitalWrite(motor1pin1, LOW);
  digitalWrite(motor1pin2, HIGH);
  digitalWrite(motor1pin3, HIGH);
}

void motortwo(){
  digitalWrite(motor2pin1, LOW);
  digitalWrite(motor2pin2, HIGH);
  digitalWrite(motor2pin3, HIGH);
}

void motorthree(){
  digitalWrite(motor3pin1, HIGH);
  digitalWrite(motor3pin2, HIGH);
  digitalWrite(motor3pin3, LOW);
}

void motorfour(){
  digitalWrite(motor4pin1, HIGH);
  digitalWrite(motor4pin2, HIGH);
  digitalWrite(motor4pin3, LOW);
}

void loop() {
if(Serial.available()>0){
    incomingByte = Serial.read();
    if(incomingByte == 1){
//    To raise the motor up
       motorone();
       motortwo();
       motorthree();
       motorfour(); 
      }      
     else if(incomingByte == 2){
//   To roll left
      motortwo();
      motorfour();
     }
     else if(incomingByte == 3){
//   To roll right 
      motorone();
      motorthree();
     }
     else if(incomingByte == 4){
//   To pitch forward
      motorthree();
      motorfour();
     }
     else if(incomingByte == 5){
//   To pitch backward 
      motorone();
      motortwo();
     }
     else if(incomingByte == 6){
//   To yaw clockwise
      motortwo();
      motorthree();
     }
     else if(incomingByte == 7){
//   To yaw anticlockwise 
      motorone();
      motorfour();
     }     
   }
}   
