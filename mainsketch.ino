/*Copyright 2024 M. Algazel Faizun, Miguel Knoch, Axel Mika D, Nathan H, Anamuto Eza, Hafidz Naufal

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

    http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License. */


#include <Servo.h>
#include <NewPing.h>

enum Directions { FORWARD = 0, LEFT = 1, RIGHT = 2, BACKWARDS = 3 };

const int LMF = 5;
const int LMB = 4;
const int RMF = 3;
const int RMB = 2;

int outputs[4] = {LMF, LMB, RMF, RMB};

#define TRIG_PIN A3
#define ECHO_PIN A2

#define MAXIMUM_DISTANCE 200

// SONAR
NewPing sonar(TRIG_PIN, ECHO_PIN, MAXIMUM_DISTANCE);

// const int maxDistance = 200;

bool goingForward = false;

int dist = 100;

void setup() {

  for (int i  = 0; i < sizeof(outputs); i++) {
    pinMode(outputs[i], OUTPUT);
  }
}

void loop() {
  move(FORWARD, 1000);
}

bool move(Directions directions, int time) {

  switch (directions){
    case FORWARD:
      //  Handle forward
      digitalWrite(RMF, HIGH);
      digitalWrite(LMF, HIGH);
      delay(time);
      // Handle GPWS (anti collission)
      if(readPing() <= 20) {
        handleCollission();
      }
      break;
    case LEFT:
      //Handle left
      digitalWrite(RMF, HIGH);
      digitalWrite(LMB, HIGH);
      delay(time);
      break;
    case RIGHT:
      //Handle right
      digitalWrite(RMB, HIGH);
      digitalWrite(LMF, HIGH);
      delay(time);
      break;
    case BACKWARDS:
      //Handle backward
      
      digitalWrite(RMB, HIGH);
      digitalWrite(LMB, HIGH);
      break;
    default:
      return false;
  }

  for (int i = 0; i < sizeof(outputs); i++) {
    digitalWrite(outputs[i], LOW);
  }
  return true;
}

bool handleCollission() {
  int distLeft = 0;
  int distLeft = 0;
  //TODO: IMPLEMENT
}

int readPing() {
  int cm = sonar.ping_cm();
  return cm;
  
}
