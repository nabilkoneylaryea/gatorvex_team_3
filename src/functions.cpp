#include "functions.h"

void pickUpGoalFront() {
  claw.spinFor(reverse, .25, turns); // raise claw slightly to pick up goal
  frontarms.spinFor(reverse, .5, turns); // raise arms to support claw in picking up goal
}
void putDownGoalFront() {
  claw.spinFor(forward, .25, turns); // lower claw slightly to put down goal
  frontarms.spinFor(forward, .5, turns); // lower frontarms to support claw in putting down goal
}
void pickUpGoalBack() {
  
}
void putDownGoalBack() {
  
}
