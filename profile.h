#ifndef PROFILE_H_
#define PROFILE_H_

constexpr double kMaxVelocity = 1.0;
constexpr double kMaxAcceleration = 1.0;

class Profile {
public:
  struct ProfilePoint {
    double position = 0.0;
    double velocity = 0.0;
  };
  Profile(ProfilePoint current) {
    current_ = current;
  }
  void SetGoal(ProfilePoint goal) { goal_ = goal; }
  const double GetTime(bool ignore_max_velocity);
  ProfilePoint GetSetpoint(double t);

private:
  ProfilePoint current_;
  ProfilePoint goal_;

  double time_accelerating_;
  double time_constant_;
  double time_decelerating_;
  double time_total_;
};

#endif // PROFILE_H_
