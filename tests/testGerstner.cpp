#include<assert.h>
#include "../src/GerstnerWave.h"

int main(){
  /**
     Programme de test de la premiere partie du lab 3
   */
  
  GerstnerWave *wave = new GerstnerWave(2, 1);
  stringstream str;
  double val;
  for (int i =0; i < 10; i++){
    val = (*wave)(2, 3, i);
    str << "Hauteur au point (2, 3) au temps 2 : " << val << endl;
  }
  ofstream file("GerstnerWave.txt");
  file << str.str();
  file.close();
}
