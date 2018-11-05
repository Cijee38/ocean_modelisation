#ifndef GERSTNERWAVEMODELH
#define GERSTNERWAVEMODELH

#include<string>
#include"WaveModel.h"
#include "GerstnerWave.h"

class GerstnerWaveModel : public WaveModel{
public:
  //Constructeur
  GerstnerWaveModel(GerstnerWave *gWave, double* windDirection, double alignement, double intensite, double waveLength, double ajustement);
  void addGerstnerWave(GerstnerWave *gWave);
private:
  double* windDirection;
  double alignement; //Le type double est à discuter ? est-ce un angle ?
  double intensity;
  double waveLength;
  double ajustement;

};

#endif
