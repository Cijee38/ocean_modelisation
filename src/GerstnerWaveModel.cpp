#include<assert.h>
#include"GerstnerWaveModel.h"

GerstnerWaveModel::GerstnerWaveModel(GerstnerWave *gWave, double* windDirection, double alignement, double intensite, double waveLength, double ajustement){
    this->setWave(gWave);
    this->windDirection = windDirection;
    this->alignement = alignement;
    this->intensity = intensite;
    this->waveLength = waveLength;
    this->ajustement = ajustement;
    this->setType(0);
}

void GerstnerWaveModel::addGerstnerWave(GerstnerWave *gerstnerWave){
    if (this->getWave() == NULL){
	this->setWave(gerstnerWave);
    }else{
	Wave *cour = this->getWave();
	while(cour->getSuiv() != NULL){
	    cour = cour->getSuiv();
	}
	cour->setSuiv(gerstnerWave);
    }
}
