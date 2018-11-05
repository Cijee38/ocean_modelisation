#ifndef WAVEMODELH
#define WAVEMODELH

#include <string>
#include "PhilipsWave.h"

class WaveModel{
  public:
  virtual double* getWind();
    virtual double getAlignement() const;
    virtual double getIntensity() const;
    virtual double getWaveLength() const;
    virtual double getAjust() const;
    int getType();
    Wave* getWave() const;
    void setWave(Wave* wave);
    WaveModel& operator+=(WaveModel w);
    void setType(int type);
    virtual ~WaveModel();
  private:
    double windDirection[2];
    double alignement; //Le type double est à discuter ? est-ce un angle ?
    double intensity;
    double waveLength;
    double ajustement; //pas bien compris ce que c'était demander au prof
    Wave* wave;
    int type; // 0 => gerstner / 1=> Philips
};


#endif
