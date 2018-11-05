#ifndef GERSTNER
#define GERSTNER

#include<string>
#include "Dvector.h"
#include "Wave.h"
#include <math.h>

class GerstnerWave :public Wave{
 public:
  GerstnerWave();
  GerstnerWave(double amp, double frequence, double direction[2]);
  GerstnerWave(double amp, double frequence);
  double getFrequence();
  double getPhase();
  GerstnerWave& operator=(GerstnerWave& w);
  GerstnerWave& operator+=(GerstnerWave w);
  GerstnerWave& operator-=(GerstnerWave w);
  double operator()(int x, int y, double t);
  private :
  double const phase = M_PI / 9;
  double frequence;
};

#endif
