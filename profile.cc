#include "profile.h"
#include <cmath>

const double Profile::GetTime(bool ignore_max_velocity) {
  if (ignore_max_velocity) {
    return std::sqrt((2*goal_.position) / kMaxVelocity);
  } else {
    double time_accelerating = (kMaxVelocity + current_.velocity) / kMaxAcceleration;
    double time_decelerating = (kMaxVelocity + goal_.velocity) / kMaxAcceleration;
    double time_constant = ((goal_.position - (0.5*(time_accelerating * kMaxVelocity) + 0.5*(time_decelerating * kMaxVelocity))) / kMaxVelocity);
    return time_accelerating + time_constant + time_decelerating;
  }
}
