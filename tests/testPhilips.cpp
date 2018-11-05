#include<assert.h>
#include "../src/PhilipsWave.h"

int main(){
  /**
     Programme de test de la premiere partie du lab 3
   */
  
  PhilipsWave *wave = new PhilipsWave(20, 10);
  stringstream str;
  complex<double> val;
  val = (*wave)(2, 3);
  str << "Hauteur au point (2, 3) : " << val << endl;
  ofstream file("PhilipsWave.txt");
  file << str.str();
  file.close();
}
