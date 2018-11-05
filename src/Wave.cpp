#include<assert.h>
#include "Wave.h"

double Wave::getAmplitude(){
  return amplitude;
}
double* Wave::getDirection(){
  return direction;
}
Wave* Wave::getSuiv(){
  return this->suiv;
}
void Wave::setSuiv(Wave *w){
  this->suiv = w;
}
void Wave::setAmplitude(double a){
  this->amplitude = a;
}
void Wave::setDirection(double* d){
  this->direction = d;
}
