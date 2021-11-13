#include "auton.h"

void auton_left() {
  bool isFrontRaised = false;
  bool isBackRaised = true;

  // calibrating
  // float clawAngle = frontarmpot.angle(degrees);
  claw.setPosition(0, degrees); // calibrate claw: starting pos = 0 deg
  frontarms.setPosition(0, degrees); // calibrate arms: starting pos = 0 deg;
  Drivetrain.setStopping(brake);

  lowerBack(isBackRaised);
  
  Drivetrain.driveFor(reverse, 45, inches, false); // drive forward
  wait(1000, msec);
  claw.spinFor(forward, .6, turns, false); // lower claw while driving (frontarms already start lowered)
  // Drivetrain.stop(); // stop with arms under goal

  raiseBack(isBackRaised);

  Drivetrain.turnFor(left, .25, turns); // turn the robot to face the position from which it came
  Drivetrain.driveFor(forward, 45, inches); // drive directly backwards to starting position
  // Drivetrain.stop(); // stop with goal in front arms

  // set down goal in home field
  raiseFront(isFrontRaised);
}
void auton_right() {
  bool isFrontRaised = false;
  bool isBackRaised = true;

  // calibrating
  // float clawAngle = frontarmpot.angle(degrees);
  claw.setPosition(0, degrees); // calibrate claw: starting pos = 0 deg
  frontarms.setPosition(0, degrees); // calibrate arms: starting pos = 0 deg;
  Drivetrain.setStopping(brake);

  lowerBack(isBackRaised);
  
  Drivetrain.driveFor(reverse, 45, inches, false); // drive forward
  wait(1000, msec);
  claw.spinFor(forward, .6, turns, false); // lower claw while driving (frontarms already start lowered)
  // Drivetrain.stop(); // stop with arms under goal

  raiseBack(isBackRaised);

  Drivetrain.turnFor(left, .25, turns); // turn the robot to face the position from which it came
  Drivetrain.driveFor(forward, 12, inches); // drive directly backwards to starting position
  // Drivetrain.stop(); // stop with goal in front arms

  raiseFront(isFrontRaised);

  // take goal in home field
  Drivetrain.turnFor(right, .1, turns);
  Drivetrain.turnFor(right, .25, turns);
  Drivetrain.driveFor(forward, 24, inches);
}