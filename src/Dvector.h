#ifndef DvectorH
#define DvectorH
#include<iostream>
#include<cstring>
#include<sstream>
#include<cstdlib>
#include<fstream>
#include <complex>
#include <stdlib.h>
#include<string>

using namespace std;

template <class T = double>
class Dvector {
  public:
//Constructeurs
    Dvector();
    Dvector(int s);
    Dvector(int s, T value);
    Dvector(Dvector& dv);
    Dvector(string str);
    ~Dvector();
    //Methodes
    void display(std::ostream& str);
    int& size();
    T* getValues() const;
    void newValues(int l);
    void fillRandomly();
    void resize(int size, T val);
  void fftcl();
  void ifftcl();
  void conjugue();
    //Operateurs
    T& operator()(int pos) const;
    Dvector<T>& operator=(Dvector<T>& v);
    Dvector<T>& operator+=(T val);
    Dvector<T>& operator+=(Dvector<T> v);
    Dvector<T>& operator-=(T val);
  Dvector<T>& operator-=(Dvector<T> v);
    Dvector<T>& operator*=(T val);
    Dvector<T>& operator/=(T val);
    bool operator==(Dvector<T> &v);
  private:
    int sizeV;
    T *values;
};
template <class T = double>
Dvector<T> operator+(Dvector<T>& v, T val);
template <class T>
Dvector<T> operator-(Dvector<T>& v, T val);
template <class T>
Dvector<T> operator*(Dvector<T>& v, T val);
template <class T>
Dvector<T> operator/(Dvector<T>& v, T val);
template <class T>
Dvector<T> operator+(Dvector<T>& v1, Dvector<T>& v2);
template <class T>
Dvector<T> operator-(Dvector<T>& v1, Dvector<T>& v2);
template <class T>
Dvector<T> operator-(Dvector<T>& v);
template <class T>
ostream& operator<<(ostream & out, Dvector<T> &v);
template <class T>
istream& operator>>(istream & in, Dvector<T> &v);
#endif
