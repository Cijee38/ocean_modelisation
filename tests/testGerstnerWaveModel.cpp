#include<assert.h>
#include<iostream>
#include "../src/GerstnerWaveModel.h"

int main(){
  /**
     Programme de test de la premiere partie du lab 3
   */

  GerstnerWave *wave = new GerstnerWave(7, 8);
  GerstnerWave *wave1 = new GerstnerWave(2, 1);
  double windDirection[2];
  windDirection[0] = 5;
  windDirection[1] = 3;
  GerstnerWaveModel test(wave, windDirection, 1, 1, 1, 1);
  test.addGerstnerWave(wave1);
  Wave *wGerst = test.getWave();
  while(wGerst != NULL){
    cout << "Amplitude : " << wGerst->getAmplitude() << "\n";
    cout << "Fréquence : " << ((GerstnerWave*)wGerst)->getFrequence() << "\n";
    wGerst = (GerstnerWave*)wGerst->getSuiv();
  }
  delete wGerst;
}
