#include"DVector.h"
#include<assert.h>
int main(){
    DVector *vect = new DVector(2, 3.1);
    assert(vect->size() == 2);
    stringstream str;
    stringstream str2;
    vect->display(str);
    assert(str.str() == "3.1\n3.1\n");
    vect->fillRandomly();
    assert(vect->size() == 2);
    vect->display(str);
    ofstream file("test.txt");
    file << str;
    DVector *v2 = new DVector("test.txt");
    v2->display(str2);
    assert(str.str() == str2.str());
    return 0;
}
