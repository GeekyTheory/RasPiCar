#include "mbed.h"

#ifndef MOVEMOTOR_H
#define MOVEMOTOR_H

class MoveMotor {

    public:
    MoveMotor(){}
    void Stop();
    void Forward();
    void Backward();
    void TurnRight();
    void TurnLeft();
};

#endif