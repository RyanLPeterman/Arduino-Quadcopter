#include "Configuration.h"
#include <Math.h>
#include <PID_v1.h>
#include <PinChangeInt.h>
#include <Servo.h> 
#include <Wire.h>

int i = 0;
char buf[5];

// Angles
float angleX,angleY,angleZ = 0.0;

// RX Signals
int throttle=THROTTLE_RMIN;
volatile int rx_values[4]; // ROLL, PITCH, THROTTLE, YAW
volatile int bt_throttle;

// PID variables
double pid_roll_in,   pid_roll_out,   pid_roll_setpoint = 0;
double pid_pitch_in,  pid_pitch_out,  pid_pitch_setpoint = 0;
double pid_yaw_in,    pid_yaw_out,    pid_yaw_setpoint = 0;
  
// Motors
int m0, m1, m2, m3; // Front, Right, Back, Left

// Track loop time.
unsigned long prev_time = 0;

//#define RxD 0
//#define TxD 1
//SoftwareSerial mySerial(0, 1);

void setup() 
{  
  Serial.begin(115200);
//  #ifdef DEBUG_OUTPUT
//    Serial.begin(115200);
//    while(!Serial);
//    Serial.println("Debug Output ON");
//  #endif
  
  motors_initialize();
//  leds_initialize();
//  rx_initialize();
  imu_setup();
  pid_initialize();
  motors_arm();
  update_motors(55,55,55,55);
  //wait for IMU YAW  to settle before beginning??? ~20s
}

void loop() 
{
  imu_update();
  control_update();

//  #ifdef DEBUG_OUTPUT
//    debug_process();
//  #endif
  prev_time = micros();

//  boolean isValidInput; 
//  do { 
//    int t; // get the next character from the bluetooth serial port
//    while (!Serial.available());
//    //t = mySerial.read(); // Execute the option based on the character recieved
//    Serial.print(t);
//    if (t > 40 && t < 60) {
//      isValidInput = true;
//    }else{
//      isValidInput = false;
//    }
//    update_motors(t, t, t, t);
//  } while ( isValidInput == true );
//  
//   if (Serial.available()>0){
////    Serial.println("CHECK");
//    buf[i]= Serial.read(); 
//   
//    if (int(buf[i])==13 || int(buf[i])==11 ){  //If Carriage return has been reached
////      Serial.println(buf);
//      int result=atoi(buf);
//      Serial.print("angle: ");    
//      Serial.println(result);     //print the converted char ar
//      if(result<=130 && result>=40){
//          bt_throttle = result;
//      }
//        
//      for(int x=0;x<=5;x++){
//      buf[x]=' ';
//      }
//    
//    i=0;  //start over again
//    } //if enter
//   i++; 
//} //IF Serial.available
}
