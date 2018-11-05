#ifndef PHILIPSWAVEMODELH
#define PHILIPSWAVEMODELH

#include<string>
#include"WaveModel.h"
#include "PhilipsWave.h"

class PhilipsWaveModel : public WaveModel{
public:
  //Constructeur
  PhilipsWaveModel(PhilipsWave *gWave, double* windDirection, double alignement, double intensite, double waveLength, double ajustement);
  void addPhilipsWave(PhilipsWave *gWave);
private:
  double* windDirection;
  double alignement; //Le type double est à discuter ? est-ce un angle ?
  double intensity;
  double waveLength;
  double ajustement;

};

#endif
