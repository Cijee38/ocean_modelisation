#include<assert.h>
#include "../src/Dvector.h"

int main(){
  Dvector<double> *vect = new Dvector<double>(2, 3.1);
  assert(vect->size() == 2);
    stringstream str;
    stringstream str2;
    vect->display(str);
    assert(str.str() == "3.1\n3.1\n");
    vect->fillRandomly();
    assert(vect->size() == 2);
    vect->display(str);
    delete vect;
    ofstream file("read.txt");
    file << str.str();
    cout << "str :" << str.str() << endl;
    file.close();
    Dvector<double> *v2 = new Dvector<double>("read.txt");
    v2->display(str2);
    assert(str.str() == str2.str());
    v2->display(cout);
}
