#include "profile.h"
#include <iostream>

int main() {
  Profile::ProfilePoint current;
  Profile::ProfilePoint goal;
  {
    goal.position = 1.0;
    goal.velocity = 0.0;
  }
  Profile profile(current);
  profile.SetGoal(goal);
  std::cout << profile.GetTime(true) << std::endl;
  std::cout << profile.GetTime(false) << std::endl;

  current = profile.GetSetpoint(0.5);
  std::cout << current.position << "\n" << current.velocity << std::endl;
  current = profile.GetSetpoint(1.5);
  std::cout << current.position << "\n" << current.velocity << std::endl;
}
