#include "functions.h"
#include <iostream>

void raiseFront(bool &isFrontRaised) {
  std::cout << "FRONT UP: " << isFrontRaised;
  if(!isFrontRaised) {
    std::cout << " 1 ";
    claw.spinFor(reverse, .25, turns); // raise claw slightly to pick up goal
    frontarms.spinFor(reverse, .5, turns); // raise arms to support claw in picking up goal
    std::cout << " 2";

    isFrontRaised = !isFrontRaised;
  }
  std::cout << std::endl;
}
void lowerFront(bool &isFrontRaised) {
  std::cout << "FRONT DOWN: " << isFrontRaised;
  if(isFrontRaised) {
    std::cout << " 1 ";
    claw.spinFor(forward, .25, turns); // lower claw slightly to put down goal
    frontarms.spinFor(forward, .5, turns); // lower frontarms to support claw in putting down goal
    std::cout << " 2";

    isFrontRaised = !isFrontRaised;
  }
  std::cout << std::endl;
}
void raiseBack(bool &isBackRaised) {
  std::cout << "BACK UP: " << isBackRaised;
  if(!isBackRaised) {
    std::cout << " 1 ";
    backarm.spinFor(forward, .6, turns); // raise back slightly arm
    std::cout << " 2";

    isBackRaised = !isBackRaised;
  }
  std::cout << std::endl;
}
void lowerBack(bool &isBackRaised) {
  std::cout << "BACK DOWN: " << isBackRaised;
  if(isBackRaised) {
  std::cout << " 1 ";
  backarm.spinFor(reverse, 1, turns, false); // lower backarm all the way
  std::cout << " 2";

  isBackRaised = !isBackRaised;
  }
  std::cout << std::endl;
}
bool moveClawToAngle(float currentAngle, float toAngle) {
  bool result = false;
  if(currentAngle > toAngle) {
    claw.spin(reverse);
  } else if(currentAngle < toAngle) {
    claw.spin(forward);
  } else {
    claw.stop(hold);
    result = true;
  }

  return result;
}
