#include<assert.h>
#include "../src/Dvector.h"
#include "../src/Height.h"

int main(){
  /**
     Programme de test de la premiere partie du lab 3
   */
    Height *vect = new Height(2, 3, 2, 2);
    assert(vect->size() == 4);
    stringstream str;
    vect->display(str);
    str << "lx : " << vect->getLx() << endl;
    str << "Val pos 3 : " << (*vect)(2, 1) << endl;
    ofstream file("height.txt");
    file << str.str();
    file.close();
}
