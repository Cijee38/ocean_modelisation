#include<assert.h>
#include "../src/Dvector.h"

int main(){
  complex<double> cpx = complex<double>(3.1, 3.1);
  Dvector<complex<double> > *vect = new Dvector<complex<double> >(2, cpx);
  assert(vect->size() == 2);
  stringstream str;
  stringstream str2;
  vect->display(str);
  assert(str.str() == "3.1\n3.1\n3.1\n3.1\n");
  vect->fillRandomly();
  assert(vect->size() == 2);
  vect->display(str);
  delete vect;
  ofstream file("read.txt");
  file << str.str();
  cout << "str :" << str.str() << endl;
  file.close();
  Dvector<complex<double> > *v2 = new Dvector<complex<double> >("read.txt");
  v2->display(str2);
  assert(str.str() == str2.str());
  v2->display(cout);
}
