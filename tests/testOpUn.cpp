#include<assert.h>
#include "../src/Dvector.h"

int main(){
    stringstream str2;
    Dvector<double> *v2 = new Dvector<double>("read.txt");
    v2->display(str2);
    str2 << "Op unaire - :\n";
    (-(*v2)).display(str2);
    ofstream file2("lab2.txt");
    file2 << str2.str();
    file2.close();
    return 0;
}
