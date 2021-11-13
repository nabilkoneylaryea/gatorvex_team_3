#include "functions.h"
#include <iostream>
void pickUpGoalFront(bool &frontStateUp) {
  std::cout << "FRONT UP: " << frontStateUp;
  if(!frontStateUp) {
    std::cout << " 1 ";
    claw.spinFor(reverse, .25, turns); // raise claw slightly to pick up goal
    frontarms.spinFor(reverse, .5, turns); // raise arms to support claw in picking up goal
    std::cout << " 2";

    frontStateUp = !frontStateUp;
  }
  std::cout << std::endl;
}
void putDownGoalFront(bool &frontStateUp) {
  std::cout << "FRONT DOWN: " << frontStateUp;
  if(frontStateUp) {
    std::cout << " 1 ";
    claw.spinFor(forward, .25, turns); // lower claw slightly to put down goal
    frontarms.spinFor(forward, .5, turns); // lower frontarms to support claw in putting down goal
    std::cout << " 2";

    frontStateUp = !frontStateUp;
  }
  std::cout << std::endl;
}
void pickUpGoalBack(bool &backStateUp) {
  std::cout << "BACK UP: " << backStateUp;
  if(!backStateUp) {
    std::cout << " 1 ";
    backarm.spinFor(forward, .6, turns); // raise arms to support claw in picking up goal
    std::cout << " 2";

    backStateUp = !backStateUp;
  }
  std::cout << std::endl;
}
void putDownGoalBack(bool &backStateUp) {
  std::cout << "BACK DOWN: " << backStateUp;
  if(backStateUp) {
  std::cout << " 1 ";
  backarm.spinFor(reverse, 1, turns); // lower frontarms to support claw in putting down goal
  std::cout << " 2";

  backStateUp = !backStateUp;
  }
  std::cout << std::endl;
}

void moveToAngle(float currentAngle, float toAngle) {

}
