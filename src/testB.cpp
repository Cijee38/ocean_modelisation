#include<assert.h>
#include "Dvector.h"

int main(){
  complex<double> cpx = complex<double>(3.1, 3.1);
  complex<double> cpx1 = complex<double>(4.1, 4.1);
  complex<double> cpx2 = complex<double>(5.1, 5.1);
  Dvector<complex<double> >* even = new Dvector<complex<double> >(4, cpx);
  Dvector<complex<double> >* odd = new Dvector<complex<double> >(4, cpx1);
  Dvector<complex<double> >* main = new Dvector<complex<double> >(4, cpx2);
  for(int s = 0; s < 2; s++){
    cout << s << ":\n";
    (*even)(s) = (*main)(s * 2);
    (*odd)(s) = (*main)(s * 2 + 1);
    odd->display(cout);
    cout << "\n";
    even->display(cout);
  }
}
  
