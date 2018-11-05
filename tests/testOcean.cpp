#include<assert.h>
#include "../src/Ocean.h"
#include <iostream>

int main(){
  /**
     Programme de test dun ocean
   */
  PhilipsWave *wave2 = new PhilipsWave(5, 5);
  GerstnerWave *wave = new GerstnerWave(2, 10);
  double* dir = new double[2];
  dir[0] = 1.0;
  dir[1] = 1.0;
  //cout << "bpnjou";
  stringstream str, str1;
  PhilipsWaveModel *model = new PhilipsWaveModel(wave2, dir, 1.0, 2.0, 5.0, 10.0);
  GerstnerWaveModel *gmodel = new GerstnerWaveModel(wave, dir, 1, 1, 1, 1);
  Ocean *ocean = new Ocean(100, 100, 8, 8, 1, model, 10.0);
  Ocean *gocean = new Ocean(100, 100, 8, 8, 1, gmodel, 10.0);
  for (int t=0; t<3; t++){
      ocean->compute();
      gocean->compute();
      for(int x = 0; x < ocean->getNx(); x++){
	  for(int y = 0; y < ocean->getNy(); y++){
	      str << "Hauteur au point (" << x <<", "<<y <<") au temps " << ocean->getTime() << " : " << (*ocean)(x,y).real() << "\n";
	      str1 << "Hauteur au point (" << x <<", "<<y <<") au temps " << gocean->getTime() << " : " << (*gocean)(x,y).real() << "\n";
	  }
      }
  }
  ofstream file("gersnterOcean.txt");
  ofstream file2("philipsOcean.txt");
  file << str.str();
  file2 << str1.str();
  file.close();
  file2.close();

  delete wave;
  delete ocean;
  return 1;
};
