#include<assert.h>
#include "PhilipsWave.h"
#include <math.h>

PhilipsWave::PhilipsWave():maxH(2.0){
  this->setAmplitude(2.0);
  double* dir = new double[2];
  dir[0] = 1.0;
  dir[1] = 1.0;
  this->setDirection(dir);
}
PhilipsWave::PhilipsWave(double amp, double vent):maxH(vent*vent/9.81){
  this->setAmplitude(amp);
  double* dir = new double[2];
  dir[0] = 1.0;
  dir[1] = 1.0;
  this->setDirection(dir);
}
PhilipsWave::PhilipsWave(double amp, double vent, double dir[2]): maxH(vent*vent/9.81){
  this->setAmplitude(amp);
  this->setDirection(dir);
}
PhilipsWave::~PhilipsWave(){
  delete []this->getDirection();
  delete this->getSuiv();
}
double PhilipsWave::getMaxH(){
  return this->maxH;
}
PhilipsWave& PhilipsWave::operator+=(PhilipsWave w){
  this->setAmplitude(this->getAmplitude() + w.getAmplitude());
  maxH += w.maxH;
  return *this;
};

PhilipsWave& PhilipsWave::operator-=(PhilipsWave w){
  this->setAmplitude(this->getAmplitude() - w.getAmplitude());
  maxH -= w.maxH;
  return *this;
};
PhilipsWave& PhilipsWave::operator=(PhilipsWave& w){
  this->setAmplitude(this->getAmplitude() - w.getAmplitude());
  maxH = w.getMaxH();
  this->setDirection(w.getDirection());
  return *this;
};
double PhilipsWave::operator()(double x, double y){
  double k = sqrt(pow(this->getDirection()[0], 2) + pow(this->getDirection()[1], 2));
  double Ph = this->getAmplitude() * pow((x * this->getDirection()[0] + y * this->getDirection()[1]), 2) *exp(-1 / pow((k * maxH), 2)) / pow(k, 2);
  return Ph;
}
