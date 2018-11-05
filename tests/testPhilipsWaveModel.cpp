#include<assert.h>
#include<iostream>
#include "../src/PhilipsWaveModel.h"

int main(){
  /**
     Programme de test de la premiere partie du lab 3
   */

  PhilipsWave *wave = new PhilipsWave(7, 8);
  PhilipsWave *wave1 = new PhilipsWave(2, 1);
  double windDirection[2];
  windDirection[0] = 5;
  windDirection[1] = 3;
  PhilipsWaveModel test(wave, windDirection, 1, 1, 1, 1);
  test.addPhilipsWave(wave1);
  Wave *wGerst = test.getWave();
  while(wGerst != NULL){
    cout << "Amplitude : " << wGerst->getAmplitude() << "\n";
    cout << "Hauteur max : " << ((PhilipsWave*)wGerst)->getMaxH() << "\n";
    wGerst = (PhilipsWave*)wGerst->getSuiv();
  }
  delete wGerst;
}
