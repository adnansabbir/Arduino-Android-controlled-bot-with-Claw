#include <SoftwareSerial.h>
#include <Servo.h>
Servo myServo;
int servoPosition = 0;
byte rightWheelSpeed =0;       // Speed of the right Motor
byte leftWheelSpeed =0;       // Speed of the Left Motor

SoftwareSerial bluetooth(10, 11);      // Connection pins for bluetooth RX & TX

void setup() {
  pinMode(13,OUTPUT);
  Serial.begin(9600);
  bluetooth.begin(9600);
  digitalWrite(13,0);
  
  myServo.attach(9);  // attaches the servo on pin 9 to the servo object 

}

int recieved;

void loop() {
  myServo.write(servoPosition);              // tell servo to go to position in variable 'pos'.

  while (bluetooth.available()) {            // Recieves Data from bluetooth and stores in recieved variable
recieved = bluetooth.read();

//Serial.println(recieved);
//delay(50); 
    }

    if(recieved==0)
    {
      recieved=0;
      }
      else if(recieved==1)
      {
        digitalWrite(13,1);
        moveForward();
        }
        else if(recieved==2)
      {
        moveRight();
        }
        else if(recieved==3)
      {
        moveBack();
        }
        else if(recieved==4)
      {
        moveLeft();
        }
        else if(recieved==5)
      {
        if(servoPosition<180)
          {
            servoPosition++;
            clawOpen();
          }
        }
        else if(recieved==6)
      {
        if(servoPosition>0)
          {
            servoPosition--;
            clawClose();
          }
          
        }else if(recieved>6 && recieved<107)
      {
        rightWheelSpeed=recieved;
        leftWheelSpeed=recieved;
        Serial.println(recieved);
          
        }

}

                                                    //This method moves the bot forward
void moveForward()
{
  Serial.println("Moving Forward");
  }


                                                    //This method moves the bot Right
void moveRight()
{
  Serial.println("Moving Right");
  }


                                                    //This method moves the bot Backward
void moveBack()
{
  Serial.println("Moving Back");
  }

  
                                                    //This method moves the bot Left
void moveLeft()
{
  Serial.println("Moving Left");
  }


void clawClose()
{
  Serial.println("Closing servo");
  myServo.write(servoPosition);
  delay(300);
  }

void clawOpen()
{
  Serial.println("Opening servo");
  myServo.write(servoPosition);
  delay(300);
  }
