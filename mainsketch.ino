/*Copyright 2024 M. Algazel Faizun, Miguel Knoch, Azel Mika D, Nathan H, Anamuto Eza, Hafidz Naufal

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

enum Directions { FORWARD, LEFT, RIGHT, BACKWARDS }

const int LMF = 5;
const int LMB = 4;
const int RMF = 3;
const int RMB = 2;

int[4] outputs = [LMF, LMB, RMF, RMB];

#define TRIG_PIN A3
#define ECHO_PIN A2

const int maxDistance = 200;

bool goingForward = false;

int dist = 100;

void setup() {

  for (int i  = 0; i < outputs.length; i++) {
    pinMode(outputs[i], OUTPUT);
  }
}

void loop() {
  move(Directions.FORWARD);
}

bool move(Directions directions) {

  switch (directions){
    case Directions.FORWARD:
      //Handle forward
      // Handle GPWS (anti collission)
      break;
    case Directions.LEFT:
      //Handle left
      break;
    case Directions.RIGHT:
      //Handle right
      break;
    case Directions.BACKWARDS:
      //Handle backward
      break;
    default:
      throw "do your wiki speedrun prompt"
  }
  return true;
}

bool handleCollission() {
  
}
