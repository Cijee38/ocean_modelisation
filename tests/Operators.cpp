#include<assert.h>
#include "../src/Dvector.h"

int main(){
    stringstream str2;
    Dvector<double> *v2 = new Dvector<double>("read.txt");
    str2 << "plus 2.0 : \n";
    *v2 += 2.0;
    v2->display(str2);
    str2 << "moins 1.0 : \n";
    *v2-=1.0;
    v2->display(str2);
    str2 << "fois 2.0 : \n";
    (*v2) *= 2.0;
    v2->display(str2);
    str2 << "divisé pas 2.0 : \n";
    *v2/=2.0;
    v2->display(str2);
    str2 << "addition avec 1 \n";
    (*v2 + 1.0).display(str2);
    ofstream file2("lab2.txt");
    file2 << str2.str();
    file2.close();
    return 0;
}
