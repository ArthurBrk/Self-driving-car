#include <Arduino.h>
#include "config.h"

    uint16_t ir_sensor_right_raw;
    uint16_t ir_sensor_right_new;

    uint16_t ir_sensor_left_raw;
    uint16_t ir_sensor_left_new;

    uint16_t ir_sensor_front_raw;
    uint16_t ir_sensor_front_new;

    void read_sensors(){
    ir_sensor_right_raw = analogRead(IR_SENSOR_RIGHT);
    ir_sensor_right_new = (uint16_t) (4790.634 / (ir_sensor_right_raw - 34.378)) + 0.1;

        if(ir_sensor_right_new > 80)
        {
            ir_sensor_right_new = 81;
        }
        else if(ir_sensor_right_new < 10)
        {
            ir_sensor_right_new = 9;
        }

    ir_sensor_left_raw = analogRead(IR_SENSOR_LEFT);
    ir_sensor_left_new = (uint16_t) (5244 / (ir_sensor_left_raw - 22)) -1;

        if(ir_sensor_left_new > 80)
        {
            ir_sensor_left_new = 81;
        }
        else if(ir_sensor_left_new < 10)
        {
            ir_sensor_left_new = 9;
        }
        
    ir_sensor_front_raw = analogRead(IR_SENSOR_FRONT);
    ir_sensor_front_new = (uint16_t) (17790.41 / (ir_sensor_front_raw + 28.975)) - 13.5;

        if(ir_sensor_front_new > 150)
        {
            ir_sensor_front_new = 151;
        }
        else if(ir_sensor_front_new < 20)
        {
            ir_sensor_front_new = 19;
        }

        // debugging
    /*Serial.print(" Rechts: ");
    Serial.print(ir_sensor_right_new);
    Serial.print("cm ");
    Serial.print(ir_sensor_right_raw);
    Serial.print(" Links: ");
    Serial.print(ir_sensor_left_new);
    Serial.print("cm ");
    Serial.print(ir_sensor_left_raw);
    Serial.print(" Vorne: ");
    Serial.print(ir_sensor_front_new);
    Serial.print("cm ");
    Serial.println(ir_sensor_front_raw);
    delay(100);*/
}