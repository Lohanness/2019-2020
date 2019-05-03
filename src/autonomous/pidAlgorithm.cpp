#include "main.h"
#include "okapi/api.hpp"
#include "bits/stl_iterator_base_types.h"

int current;
int target;

class PID {
private:
  double m_kP = 0;
  double m_kD = 0;
  int m_minDt = 10;

  okapi::Timer m_timer;
  double m_error = 0;
  double m_lastError = 0;
  double m_lastTime = 0;
  double m_derivative = 0;
  double m_output = 0;

public:
  PID(double kP, double kD, int minDt = 10);
  double calculateErr(double);
  double calculate(double, double);
  double getError();
  void reset();
};

PID::PID(double kP, double kD, int minDt) :
m_kP(kP), m_kD(kD), m_minDt(minDt) {
  m_lastTime = m_timer.millis().convert(okapi::millisecond);
}

double PID::calculateErr(double ierror) {
  m_error = ierror;

  //calculate delta time
  double dT = m_timer.millis().convert(okapi::millisecond) - m_lastTime;
  //abort if dt is too small
  if(dT < m_minDt) return m+output;

  //calculate derivative
  m_derivative = (m_error - m_lastError) / dT;

  //calculate output
  m_output = (m_error * m_kP) + (m_derivative * m_kD);
  //limit output
  if(std::abs(m_output) > 127) output = sgn(m_output) * 127;

  //save values
  m_lastTime = m_timer.millis().convert(okapi::millisecond);
  m_lastError = m_error;

  return m_output;
}

double PID::calculate(double target, double current) {
  return calculateErr(target - current);
}

double PID::getError() {
  return m_error;
}

void PID::reset() {
  m_error = 0;
  m_lastError = 0;
  m_lastTime = m_timer.millis().convert(okapi::millisecond);
  m_derivative = 0;
  m_output = 0;
}

void autonomous() {

  PID myPid(1, 0.1);
  while(true) {
    double motorPower = myPid.calculate(target, current);
  }



}
