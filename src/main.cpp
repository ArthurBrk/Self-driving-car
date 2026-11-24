#include <Arduino.h>
#include "config.h"
#include "fahren.h" // funktionsaufruf

int BackwardsLeft = 4;  // Rückwärts hinten links
int ForwardsLeft = 5;   // Vorwärts vorne links
int ForwardsRight = 6;  // Vorwärts vorne rechts
int BackwardsRight = 7; // Rückwärts hinten rechts

int button_ein = 2;
int button_aus = 3;

int var = 0;

uint8_t Zustand;
uint8_t Zustand_next;

void setup()
{
  Serial.begin(9600);
  pinMode(BackwardsLeft, OUTPUT);
  pinMode(ForwardsLeft, OUTPUT);
  pinMode(ForwardsRight, OUTPUT);
  pinMode(BackwardsRight, OUTPUT);

  pinMode(button_ein, INPUT_PULLUP);
  pinMode(button_aus, INPUT_PULLUP);
  Zustand = Forward;
}

void loop()
{
  read_sensors(); // funktions deklaration

  if (digitalRead(button_aus) == LOW)
  {
    Zustand_next = Stop;
  }

  if (digitalRead(button_ein) == LOW)
  {
    Zustand_next = Forward;
  }
  Zustand = Zustand_next;

  switch (Zustand)
  {
  case Stop:
    stop();
    break;

  case Forward:
    forward();
    if (ir_sensor_right_new > 60 && ir_sensor_front_new < 95)
    {
      Zustand_next = Turn_Right;
      break;
    }

    if (ir_sensor_left_new > 60 && ir_sensor_front_new < 95)
    {
      Zustand_next = Turn_Left;
      var++;
      break;
    }

    if (ir_sensor_left_new > 60 && ir_sensor_front_new < 95 && var == 2) 
    {
      Zustand_next = crazy_left;
    }
    break;

  case crazy_left: 
    turn_left();
    if (ir_sensor_left_new < 40)
    {
      Zustand_next = Forward;
    }
    break;

  case Turn_Left:
    turn_left();
    if (ir_sensor_left_new < 40)
    {
      Zustand_next = Forward;
    }
    break;

  case Turn_Right:
    turn_right();
    if (ir_sensor_right_new < 40)
    {
      Zustand_next = Forward;
    }
    break;

  case Backward:
    backward();
    break;
  }
}