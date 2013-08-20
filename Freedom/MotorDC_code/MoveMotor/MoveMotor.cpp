#include "MoveMotor.h"

    PwmOut speedPin(PTD4); //Pin Enable de ambos motores (puenteados)
    PwmOut motor1A(PTA12);
    PwmOut motor1B(PTA4);
    DigitalOut motor2A(PTD5);
    DigitalOut motor2B(PTD0);

/*void MoveMotor::MoveMotor(){
}*/

void MoveMotor::Stop(){
    speedPin=1.0;
    motor1A=0;
    motor1B=0;
    motor2A=0;
    motor2B=0;
}

void MoveMotor::Forward(){
    speedPin=1.0;
    motor1A=0;
    motor1B=1;
    motor2A=0;
    motor2B=1;
}

void MoveMotor::Backward(){
    speedPin=1.0;
    motor1A=1;
    motor1B=0;
    motor2A=1;
    motor2B=0;
}

void MoveMotor::TurnRight(){
    speedPin=1.0;
    motor1A=0;
    motor1B=1;
    motor2A=1;
    motor2B=0;
}

void MoveMotor::TurnLeft(){
    speedPin=1.0;
    motor1A=1;
    motor1B=0;
    motor2A=0;
    motor2B=1;
}
