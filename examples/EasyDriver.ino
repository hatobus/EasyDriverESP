#include <EasyDriver.h>

#define stp 2
#define dir 15
#define MS1 4
#define MS2 5

EasyDriver ed(stp, MS1, MS2, dir, 1.8);

void setup() {
  // put your setup code here, to run once:

  // MS1_state and MS2_state pin is to set motor step angle
    //  +------+------+--------------------------+
    //  | MS1_state  | MS2_state  | Resolution               |
    //  +------+------+--------------------------+
    //  | LOW  | LOW  | Full step (1/1 Step)     |
    //  +------+------+--------------------------+
    //  | HIGH | LOW  | Half step (1/2 Step)     |
    //  +------+------+--------------------------+
    //  | LOW  | HIGH | Quarter step (1/4 Step)  |
    //  +------+------+--------------------------+
    //  | HIGH | HIGH | Eight step (1/8 Step)    |
    //  +------+------+--------------------------+

    // From Official Web Page.
    // Default Both Value is HIGH.
    //

    ed.set_microstep(LOW, LOW);
}

void loop() {
  // put your main code here, to run repeatedly:
  // Rotate 5sec 120 rpm
    ed.Motor_Drive_Time(120, 5.0);

  delay(3000);

  // Rotate 5 times 120 rpm
  ed.Motor_Drive_Rotate(120, 5.0);

  // Inverse rotate direction 
  ed.Rotate_INV();

  ed.Motor_Drive_Time(120, 5.0);

  delay(3000);
  
}
