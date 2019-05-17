#include "profile.h"
#include <cmath>

const double Profile::GetTime(bool ignore_max_velocity) {
  if (ignore_max_velocity) {
    return std::sqrt((2*goal_.position) / kMaxVelocity);
  } else {
    int time_accelerating = (kMaxVelocity + current_.velocity) / kMaxAcceleration;
    int time_constant = ((goal_.position - (time_accelerating * kMaxVelocity)) / kMaxVelocity);
    return (2 * time_accelerating) + time_constant;
  }
}
