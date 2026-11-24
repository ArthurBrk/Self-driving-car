#ifndef sensors
#define sensors
    #define IR_SENSOR_RIGHT A2
    #define IR_SENSOR_LEFT  A3
    #define IR_SENSOR_FRONT A0
#endif

#ifndef controls
#define controls
    #define Forward     0
    #define Backward    1
    #define Turn_Left   2
    #define Turn_Right  3
    #define Stop        4
    #define Max_Speed   255
    #define Min_Speed   80
    #define Turn_Speed  120
    #define crazy_left  5
#endif

    extern int BackwardsLeft;   //Rückwärts Links
    extern int ForwardsLeft;    //Vorwärts  Links
    extern int ForwardsRight;   //Vorwärts  Rechts  
    extern int BackwardsRight;  //Rückwärts Rechts   

    extern int button_ein;
    extern int button_aus;

    extern uint8_t Zustand;

    extern uint16_t ir_sensor_right_raw;
    extern uint16_t ir_sensor_right_new;

    extern uint16_t ir_sensor_left_raw;
    extern uint16_t ir_sensor_left_new;

    extern uint16_t ir_sensor_front_raw;
    extern uint16_t ir_sensor_front_new;
    
void read_sensors();    
