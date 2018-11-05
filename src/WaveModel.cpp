#include<assert.h>
#include"WaveModel.h"

WaveModel::~WaveModel(){
    delete this->getWave();
}
double* WaveModel::getWind(){
    return windDirection;
}
double WaveModel::getAlignement() const{
  return alignement;
}
double WaveModel::getIntensity() const{
    return intensity;
}
double WaveModel::getWaveLength() const{
    return waveLength;
}
double WaveModel::getAjust() const{
    return ajustement;
}
Wave* WaveModel::getWave() const{
  return this->wave;
}
void WaveModel::setWave(Wave* w){
  this->wave = w;
}

void WaveModel::setType(int type){
  //if type == 0 => gerstner else => philips
  this->type = type;
}
WaveModel& WaveModel::operator+=(WaveModel w){
  windDirection[0] = (windDirection[0] + w.windDirection[0])/2;
  windDirection[1] = (windDirection[1] + w.windDirection[1])/2;
  alignement = (alignement + w.alignement)/2;
  intensity += w.intensity;
  //Discuter avec le prof pour waveLength et ajustement
  return *this;
};

int WaveModel::getType(){
  return type;
}
//La méthode -= est-elle pertinente ?
