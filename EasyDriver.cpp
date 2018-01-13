#if defined(ARDUINO) && ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"
#endif

#include "EasyDriver.h"

EasyDriver::EasyDriver(int PIN, int MS1, int MS2, int DIR, double angle=1.8) {

    pinMode(PIN, OUTPUT);
    pinMode(MS1, OUTPUT);
    pinMode(MS2, OUTPUT);
    pinMode(DIR, OUTPUT);

    _MS1 = MS1;
    _MS2 = MS2;
    _DIR = DIR;
    STP_PIN = PIN;
    basic_step_angle = angle;

}

void EasyDriver::Motor_Drive_Time(int RPM, double Rotate_Time) {
    // To drive motor Designation times
    // Rotate_time need to second.

    int length = RPM * one_cycle_step;
    double delay_ms = (Rotate_Time * 1000) / (2 * length);

    if(delay_ms > 1){
        for(int i=0; i<length; i++){
            digitalWrite(STP_PIN, HIGH);
            delay(delay_ms);
            digitalWrite(STP_PIN, LOW);
            delay(delay_ms);
        }
    }

    else{
        double delay_us = delay_ms * 1000;
        for(int i=0; i<length; i++){
            digitalWrite(STP_PIN, HIGH);
            delayMicroseconds(delay_us);
            digitalWrite(STP_PIN, LOW);
            delayMicroseconds(delay_us);
        }
    }
}

void EasyDriver::Motor_Drive_Rotate(int RPM, int rotate_num) {

    int sum_of_step =  one_cycle_step * rotate_num;
    double Rotate_time = 60/ (RPM / (double)rotate_num);

    double delay_ms = (Rotate_time * 1000) / (2 * sum_of_step);

    if(delay_ms > 1){
        for(int i=0; i<sum_of_step; i++){
            digitalWrite(STP_PIN, HIGH);
            delay(delay_ms);
            digitalWrite(STP_PIN, LOW);
            delay(delay_ms);
        }
    }

    else{
        double delay_us = delay_ms * 1000;
        for(int i=0; i<sum_of_step; i++){
            digitalWrite(STP_PIN, HIGH);
            delayMicroseconds(delay_us);
            digitalWrite(STP_PIN, LOW);
            delayMicroseconds(delay_us);
        }
    }
}

void EasyDriver::Rotate_INV() {
    digitalWrite(_DIR, !digitalRead(_DIR));
}

void EasyDriver::set_microstep(bool MS1_state, bool MS2_state) {

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
    // Default Both Value is LOW.
    //

    if(MS1_state == 0 && MS2_state == 0) basic_step_angle = 7.5;
    if(MS1_state == 1 && MS2_state == 0) basic_step_angle = 3.75;
    if(MS1_state == 0 && MS2_state == 1) basic_step_angle = 1.8;
    if(MS1_state == 1 && MS2_state == 1) basic_step_angle = 0.72;

    one_cycle_step = 360 / basic_step_angle;

    digitalWrite(_MS1, MS1_state);
    digitalWrite(_MS2, MS2_state);
}
