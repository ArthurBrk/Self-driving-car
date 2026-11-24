#include <Arduino.h>
#include "fahren.h"
#include "config.h"

void forward(){
  analogWrite(BackwardsLeft, 0);
  analogWrite(ForwardsLeft, Max_Speed);
  analogWrite(ForwardsRight, Max_Speed);
  analogWrite(BackwardsRight, 0);
}

void stop(){
  analogWrite(BackwardsLeft, 0);
  analogWrite(ForwardsLeft, 0);
  analogWrite(ForwardsRight, 0);
  analogWrite(BackwardsRight, 0);
}

void turn_left(){
  analogWrite(BackwardsLeft, Turn_Speed);
  analogWrite(ForwardsLeft, 0);
  analogWrite(ForwardsRight, Min_Speed);
  analogWrite(BackwardsRight, 0);
  // debugging
  //Serial.print(ir_sensor_left_new);
}

void turn_right(){
  analogWrite(BackwardsLeft, 0);
  analogWrite(ForwardsLeft, Turn_Speed);
  analogWrite(ForwardsRight, 0);
  analogWrite(BackwardsRight, Min_Speed);
  // debugging
  //Serial.print(ir_sensor_right_new);
}

void backward(){
  analogWrite(BackwardsLeft, Min_Speed);
  analogWrite(ForwardsLeft, 0);
  analogWrite(ForwardsRight, 0);
  analogWrite(BackwardsRight, Min_Speed);
}
