#include<assert.h>
#include "../src/Dvector.h"

int main(){
    stringstream str2;
    Dvector<double> *v2 = new Dvector<double>("read.txt");
    v2->display(str2);
    str2 << "Resize (5, 2) :\n";
    v2->resize(5, 2);
    v2->display(str2);
    str2 << "Resize (3, 2) :\n";
    v2->resize(3, 2);
    v2->display(str2);
    ofstream file2("resize.txt");
    file2 << str2.str();
    file2.close();

    return 0;
}
