#include<assert.h>
#include "Wave.h"
#include "GerstnerWave.h"

GerstnerWave::GerstnerWave(): frequence(1.0){
  this->setAmplitude(2.0);
  double* dir = new double[2];
  dir[0] = 1.0;
  dir[1] = 1.0;
  this->setDirection(dir);
}
GerstnerWave::GerstnerWave(double amp, double freq):frequence(freq){
  this->setAmplitude(amp);
  double* dir = new double[2];
  dir[0] = 1.0;
  dir[1] = 1.0;
  this->setDirection(dir);
}
GerstnerWave::GerstnerWave(double amp, double freq, double dir[2]):frequence(freq){
  this->setAmplitude(amp);
  this->setDirection(dir);
}
double GerstnerWave::getFrequence(){
  return this->frequence;
}
double GerstnerWave::getPhase(){
  return this->phase;
}
GerstnerWave& GerstnerWave::operator+=(GerstnerWave w){
  this->setAmplitude(this->getAmplitude() + w.getAmplitude());
  return *this;
};

GerstnerWave& GerstnerWave::operator-=(GerstnerWave w){
  this->setAmplitude(this->getAmplitude() - w.getAmplitude());
  return *this;
};
GerstnerWave& GerstnerWave::operator=(GerstnerWave& w){
  this->setAmplitude(w.getAmplitude());
    frequence = w.getFrequence();
    this->setDirection(w.getDirection());
    return *this;
};
double GerstnerWave::operator()(int x, int y, double t){
  double* dir = this->getDirection();
  return this->getAmplitude() * cos((dir[0] * x + dir[1] * y) - frequence * t + phase);
}
