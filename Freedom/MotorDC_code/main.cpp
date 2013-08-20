#include "mbed.h"
#include "MoveMotor.h"
#include "Commands.h"

//Object declaration
MoveMotor move;
Serial serial(USBTX,USBRX);

// Variable initialization

// A pair of varibles to help parse serial commands (thanks Fergs)
int arg = 0;
int _index = 0;

// Variable to hold an input character
char chr;

// Variable to hold the current single-character command
char cmd;

// Character arrays to hold the first and second arguments
char argv1[70];
char argv2[70];
char argv3[70];

// The arguments converted to integers
long arg1;
long arg2;
long arg3;

// Functions
void resetCommand()
{
    cmd = NULL;
    memset(argv1, 0, sizeof(argv1));
    memset(argv2, 0, sizeof(argv2));
    memset(argv3, 0, sizeof(argv3));
    arg1 = 0;
    arg2 = 0;
    arg3 = 0;
    arg = 0;
    _index = 0;
}

int runCommand()
{
    arg1 = atoi(argv1);
    arg2 = atoi(argv2);
    arg3 = atoi(argv3);

    switch(cmd) {
  
        case FORWARD:
            move.Forward();
        break;
        
        case BACKWARD:
            move.Backward();
        break;
        
        case TURNLEFT:
            move.TurnLeft();
        break;
        
        case TURNRIGHT:
            move.TurnRight();
        break;
            
        case STOP:
            move.Stop();
        break;
        
    }
    
    return 0;
}

int main()
{
    serial.printf("READY FOR COMMANDS\n");
    move.Stop();
    for(;;) {
        if (serial.readable()) {
        
        //serial.printf(serial.getc()+"");
            unsigned char chr = serial.getc();
            if (chr == 10) {
                if (arg == 1) argv1[_index] = NULL;
                else if (arg == 2) argv2[_index] = NULL;
                runCommand();
                resetCommand();
            }
            // Use spaces to delimit parts of the command
            else if (chr == ' ') {
                // Step through the arguments
                if (arg == 0) arg = 1;
                else if (arg == 1)  {
                    argv1[_index] = NULL;
                    arg = 2;
                    _index = 0;
                }
                continue;
            } else {
                if (arg == 0) {
                    // The first arg is the single-letter command
                   
                    cmd = chr;
                } else if (arg == 1) {
                    // Subsequent arguments can be more than one character
                    argv1[_index] = chr;
                    _index++;
                } else if (arg == 2) {
                    argv2[_index] = chr;
                    _index++;
                }else if (arg == 3) {
                    argv3[_index] = chr;
                    _index++;
                }
            }
        }
    }

}
/*int main() {
    move.Stop();    
    while(1) {
        move.Forward();
        wait(1);
        move.Backward();
        wait(1);
        move.TurnRight();
        wait(1);
        move.TurnLeft();
        wait(1);
        move.Stop();
        wait(1);
    }
    
}*/
