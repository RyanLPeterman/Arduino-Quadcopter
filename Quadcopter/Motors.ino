Servo motor0;
Servo motor1;
Servo motor2;
Servo motor3;

void motors_initialize(){
  motor0.attach(PIN_MOTOR0);
  motor1.attach(PIN_MOTOR1);
  motor2.attach(PIN_MOTOR2);
  motor3.attach(PIN_MOTOR3);
  motor0.write(MOTOR_ZERO_LEVEL);
  motor1.write(MOTOR_ZERO_LEVEL);
  motor2.write(MOTOR_ZERO_LEVEL);
  motor3.write(MOTOR_ZERO_LEVEL);
}

void motors_arm(){
  motor0.write(MOTOR_ARM_START);
  motor1.write(MOTOR_ARM_START);
  motor2.write(MOTOR_ARM_START);
  motor3.write(MOTOR_ARM_START);
}

void update_motors(int m0, int m1, int m2, int m3)
{
  motor0.write(m0);
  motor1.write(m1);
  motor2.write(m2);
  motor3.write(m3);
}

