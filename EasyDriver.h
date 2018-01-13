#ifndef EASYDRIVEESP_EASYDRIVER_H
#define EASYDRIVEESP_EASYDRIVER_H

#if defined(ARDUINO) && ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"
#endif

class EasyDriver {
public:
    EasyDriver(int PIN, int MS1, int MS2, int DIR, double step_angle);
    void Rotate_INV();
    void Motor_Drive_Rotate(int RPM, int rotate_num);
    void Motor_Drive_Time(int RPM, double rotate_time);
    void set_microstep(bool MS1_state, bool MS2_state);

private:

    bool _MS1, _MS2;
    bool _DIR;
    int STP_PIN;
    int one_cycle_step;
    double basic_step_angle;

};
#endif //EASYDRIVEESP_EASYDRIVER_H
