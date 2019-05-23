#include "profile.h"
#include <cmath>

const double Profile::GetTime(bool ignore_max_velocity) {
  if (ignore_max_velocity) {
    return std::sqrt((2*goal_.position) / kMaxVelocity);
  } else {
    time_accelerating_ = (kMaxVelocity - current_.velocity) / kMaxAcceleration;
    time_decelerating_ = (kMaxVelocity + goal_.velocity) / kMaxAcceleration;
    time_constant_ = ((goal_.position - (0.5*(time_accelerating_ * kMaxVelocity) + 0.5*(time_decelerating_ * kMaxVelocity))) / kMaxVelocity);
    time_total_ = time_accelerating_ + time_constant_ + time_decelerating_;

    return time_total_;
  }
}

Profile::ProfilePoint Profile::GetSetpoint(double t) {
  ProfilePoint final;

  this->GetTime(false);

  if (t < time_accelerating_) {
    final.velocity = kMaxAcceleration * t;
    final.position = 0.5 * t * final.velocity;
  } else if (t > (time_total_ - time_decelerating_)) {
    double time_since_constant = (t - (time_constant_ + time_accelerating_));
    final.velocity = (-1 * kMaxAcceleration) * time_since_constant;
    final.position = (0.5 * time_accelerating_ * kMaxVelocity) + (kMaxVelocity * time_constant_) + (0.5 * (kMaxVelocity - final.velocity) * time_since_constant);
  } else {
    final.velocity = kMaxVelocity;
    final.position = (0.5 * time_accelerating_ * kMaxVelocity) + (kMaxVelocity * (t - time_accelerating_));
  }
  return final;
}
