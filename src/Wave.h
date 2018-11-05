#ifndef WAVE
#define WAVE

#include<string>
#include "Dvector.h"

class Wave{
 public:
  double getAmplitude();
  void setAmplitude(double a);
  void setDirection(double* dir);
  double* getDirection();
  Wave* getSuiv();
  void setSuiv(Wave *w);
  double operator()(int x, int y, int t);
  double operator()(int x, int y);
 private :
  double amplitude;
  double* direction;
  Wave *suiv;
};

#endif
