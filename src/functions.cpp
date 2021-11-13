#include "functions.h"
#include <iostream>
void pickUpGoalFront(bool &frontStateUp) {
  if(!frontStateUp) {
    claw.spinFor(reverse, .25, turns); // raise claw slightly to pick up goal
    frontarms.spinFor(reverse, .5, turns); // raise arms to support claw in picking up goal
    frontStateUp = !frontStateUp;
  }
}
void putDownGoalFront(bool &frontStateUp) {
  if(frontStateUp) {
    claw.spinFor(forward, .25, turns); // lower claw slightly to put down goal
    frontarms.spinFor(forward, .5, turns); // lower frontarms to support claw in putting down goal
    frontStateUp = !frontStateUp;
  }
}
void pickUpGoalBack(bool &backStateUp) {
  std::cout << "UP: " << backStateUp << std::endl;
  if(!backStateUp) {
      std::cout << "1 " << std::endl;

    backarm.spinFor(forward, .6, turns);
      std::cout << "2" << std::endl;
 // raise arms to support claw in picking up goal
    backStateUp = !backStateUp;
  }
}
void putDownGoalBack(bool &backStateUp) {
  std::cout << "DOWN: " << backStateUp << std::endl;
  if(backStateUp) {
    std::cout << "1 " << std::endl;
    backarm.spinFor(reverse, 1, turns); // lower frontarms to support claw in putting down goal
    std::cout << "2" << std::endl;

    backStateUp = !backStateUp;
  }
}
