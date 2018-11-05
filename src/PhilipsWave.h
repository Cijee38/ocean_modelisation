#ifndef PHILIPS
#define PHILIPS

#include<string>
#include "Dvector.h"
#include <math.h>
#include "Wave.h"
#include <cmath>

class PhilipsWave :public Wave {
 public:
  PhilipsWave();
  ~PhilipsWave();
  PhilipsWave(double amp, double vent, double direction[2]);
  PhilipsWave(double amp, double vent);
  double getMaxH();
  PhilipsWave& operator=(PhilipsWave& w);
  PhilipsWave& operator+=(PhilipsWave w);
  PhilipsWave& operator-=(PhilipsWave w);
  double operator()(double x, double y);
  private :
  double maxH;
};

#endif
