#include<assert.h>
#include "../src/Dvector.h"

int main(){
  complex<double> cpx = complex<double>(3.1, 3.1);
  complex<double> cpx2 = complex<double>(2.5, 13.1);
  Dvector<complex<double> > *vect = new Dvector<complex<double> >(8, cpx);
  (*vect)(2) = cpx2;
  stringstream str;
  vect->display(str);
  vect->fftcl();
  str << "\nAfter fft : \n";
  vect->display(str);
  vect->ifftcl();
  str << "\nAfter ifft : \n";
  vect->display(str);
  ofstream file("fftcl.txt");
  file << str.str();
  file.close();
}
