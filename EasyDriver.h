#ifndef EASYDRIVEESP_EASYDRIVER_H
#define EASYDRIVEESP_EASYDRIVER_H

#if defined(ARDUINO) && ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"
#endif

class EasyDriver {
public:
    EasyDriver(int PIN, bool MS1, bool MS2, bool DIR, double step_angle);
    void Rotate_INV();
    void Motor_Drive_Rotate(int RPM, int rotate_num);
    void Motor_Drive_Time(int RPM, double rotate_time);
    int Make_Step_Rotate(double Rotate);
    void set_microstep(int MS1_state, int MS2_state);

private:

    bool _MS1, _MS2;

    bool _DIR;

    int STP_PIN;

    double one_cycle_step, basic_step_angle;

};
#endif //EASYDRIVEESP_EASYDRIVER_H
