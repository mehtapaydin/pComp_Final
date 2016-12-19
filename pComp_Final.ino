
#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>

// called this way, it uses the default address 0x40
Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();
// you can also call it with a different address you want
//Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver(0x41);

// Depending on your servo make, the pulse width min and max may vary, you 
// want these to be as small/large as possible without hitting the hard stop
// for max range. You'll have to tweak them as necessary to match the servos you
// have!
#define SERVOMIN  150 // this is the 'minimum' pulse length count (out of 4096)
#define SERVOMAX  600 // this is the 'maximum' pulse length count (out of 4096)

int count = 0;
boolean replay = true;
int test = 0;
int mode = 2;
int angle = 0;
int waitTime = 100;
bool movementState = true;
//unsigned long lastBlinkTime = 0;
//long previousMillis = 0;
//long interval = 1000;    

uint8_t servonum = 11;
uint8_t servonum1 = 1;
uint8_t servonum2 = 2;
uint8_t servonum3 = 3;
uint8_t servonum4 = 4;
uint8_t servonum5 = 5;
uint8_t servonum6 = 6;
uint8_t servonum7 = 7;
uint8_t servonum8 = 8;
uint8_t servonum9 = 9;
uint8_t servonum10 = 10;
uint8_t servonum11 = 13;


void rotate(int pin, int angle) {
  pwm.setPWM(pin, 0, map(angle, 0, 180, SERVOMIN, SERVOMAX));
}

void idle() {
  delay(100);
}

void setup() {
  Serial.begin(9600);
 // Serial.println("16 channel Servo test!");

  pwm.begin();
  
  pwm.setPWMFreq(60);  // Analog servos run at ~60 Hz update

    for (int a = 0; a <= 15; a++) {
    rotate(a, 90);
  }


}



void shape0() {

        
        rotate(servonum, 0);
        rotate(servonum1, 0);  
        rotate(servonum2, 0);  
        rotate(servonum3, 0);  
        rotate(servonum4, 0);  
        rotate(servonum5, 0);  
        rotate(servonum6, 0);  
        rotate(servonum7, 0);
        rotate(servonum8, 0);    
        rotate(servonum9, 0);   
        rotate(servonum10, 0);  
        rotate(servonum11, 0);  

        mode = 0;
}

void shape1() {
  
    test++;
        mode = 1;
        rotate(servonum, 0);
        rotate(servonum1,0);  
        rotate(servonum2, 0); 
         
        delay (20);
        count ++;
        rotate(servonum3, test%180);  
        rotate(servonum4, test%180);  
        delay (20);
        count ++;
        
        rotate(servonum5, 0);  
        rotate(servonum6, 0);  
        rotate(servonum7, 0);
        rotate(servonum8, 0);    
        rotate(servonum9, 0);   
        rotate(servonum10, 0);  
        rotate(servonum11, 0); 

          if(count>90){
          mode = 1;
          count = 0;
        }
  }

void shape2() {
  
    test++  ;
    
        rotate(servonum, 0);
        rotate(servonum1,0);  
        rotate(servonum2, 0);  
        rotate(servonum3, 0);  
        delay(20);
        count ++;
      
        rotate(servonum4, test%180);  
        rotate(servonum5, test%180);  
        rotate(servonum6, test%180);  
        rotate(servonum7, test%180);

        delay (20);
        count ++;
        
        rotate(servonum8,test%180);    
        rotate(servonum9, test%180);   
        rotate(servonum10, test%180);  
        rotate(servonum11,test%180); 
        delay(20);

        if(count>200){
          mode = 2;
          count = 0;
        }
  }

void shape3() {
  
    test++  ;

        rotate(servonum, test%180);
        rotate(servonum1,0);  
        rotate(servonum2, 0);  
        rotate(servonum3, 0);  
        rotate(servonum4, 0);  
        rotate(servonum5, 0);  
        rotate(servonum6, 0);  
        rotate(servonum7, 0);
        
        delay (20);
        count ++;
        
        rotate(servonum8, test%180);    
        rotate(servonum9, test%180);   
        rotate(servonum10,test%180);  
        rotate(servonum11,test%180); 
        
        delay (20);
        count ++;

        if(count>150){
          mode = 3;
          count = 0;
        }
        
  }
  

void loop() {

 Serial.println(count);

/*mode ++;
  if (mode >3) {
    shape0(); 
  }*/
  
  switch (mode) {
    case 0:
      shape1();
      Serial.println("0");
      break;
      
    case 1:
      shape2();
      Serial.println("1");
      break;
     
    case 2:
      shape3();
      Serial.println("2");
      break;

    case 3:
    shape0();
    Serial.println("3");
    break;
  } 

  delay(20);
    
}


