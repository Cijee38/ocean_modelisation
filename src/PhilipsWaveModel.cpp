#include<assert.h>
#include"PhilipsWaveModel.h"

PhilipsWaveModel::PhilipsWaveModel(PhilipsWave *pWave, double* windDirection, double alignement, double intensite, double waveLength, double ajustement){
  this->setWave(pWave);
  this->windDirection = windDirection;
  this->alignement = alignement;
  this->intensity = intensite;
  this->waveLength = waveLength;
  this->ajustement = ajustement;
  this->setType(1);
}

void PhilipsWaveModel::addPhilipsWave(PhilipsWave *philipsWave){
    if (this->getWave() == NULL){
	this->setWave(philipsWave);
    }else{
	Wave *cour = this->getWave();
	while(cour->getSuiv() != NULL){
	    cour = cour->getSuiv();
	}
	cour->setSuiv(philipsWave);
    }
}
