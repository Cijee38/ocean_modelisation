#include<assert.h>
#include"Dvector.h"
#include <math.h>
/**
Constructeurs : double puis complex
*/
template<>
Dvector<double>::Dvector(){
  sizeV = 1;
  values = new double[1];
  values[0] = 1.0;
}
template<>
Dvector<complex<double> >::Dvector(){
  sizeV = 1;
  values = new complex<double>[1];
  values[0].real(1.0);
  values[0].imag(1.0);
}
template<>
Dvector<double>::Dvector(int size){
  sizeV = size;
  values = new double[size];
  for (int i = 0; i < size; i++){
    values[i] = 1.0;
  }
}
template<>
Dvector<complex<double> >::Dvector(int size){
  sizeV = size;
  values = new complex<double>[1];
  for (int i = 0; i < size; i++){
    values[i] = complex<double>(1.0, 1.0);
  }
}

template<>
Dvector<double>::Dvector(int s, double value){
  sizeV = s;
  values = new double[s];
  for (int i = 0; i < s; i++){
    values[i] = value;
  }
}
template<>
Dvector<complex<double> >::Dvector(int s, complex<double> cpx){
  sizeV = s;
  values = new complex<double>[s];
  for (int i = 0; i < s; i++){
    values[i]= cpx;
  }
}

template<>
Dvector<complex<double> >::Dvector(string str){
  ifstream file(str.c_str());
  ifstream file2(str.c_str());
  if(file && file2){
    sizeV = 0;
    string line, line2;
    while(getline(file, line)){
      sizeV++;
    }
    file.close();
    assert(sizeV % 2 == 0);
    sizeV /= 2;
    values = new complex<double>[sizeV];
    int cpt = 0;
    while(getline(file2, line) && getline(file2, line2)){
	//values[cpt].real(2.8);
	//values[cpt].imag(8.2);
	values[cpt].real(stod(line, NULL));
	values[cpt].imag(stod(line2));
	cpt++;
    }
    file2.close();
  }else{
    cerr << "fichier non trouvé";
    sizeV = 0;
    values = NULL;
  }
}
template<>
Dvector<double>::Dvector(string str){
  ifstream file(str.c_str());
  ifstream file2(str.c_str());

  if(file && file2){
    sizeV = 0;
    string line;
    while(getline(file, line)){
      sizeV++;
    }
    file.close();
    values = new double[sizeV];
    int cpt = 0;
    while(getline(file2, line)){
	//values[cpt] = 8.8;
	values[cpt] = stod(line);
	cpt++;
    }
    file2.close();
  }else{
    cerr << "fichier non trouvé";
    sizeV = 0;
    values = NULL;
  }
}

template<>
Dvector<double>::~Dvector(){
  delete []values;
}
template<>
Dvector<complex<double> >::~Dvector(){
  delete []values;
}

template<>
void Dvector<double>::display(std::ostream& str){
  for(int i = 0; i < sizeV; i++){
    str << values[i] << '\n';
  }
}
template<>
void Dvector<complex<double> >::display(std::ostream& str){
  for(int i = 0; i < sizeV; i++){
    str << values[i].real() << '\n';
    str << values[i].imag() << '\n';
  }
}

template<>
int& Dvector<double>::size(){
  return this->sizeV;
}
template<>
int& Dvector<complex<double> >::size(){
  return this->sizeV;
}
template<>
double* Dvector<double>::getValues() const{
  return this->values;
}
template<>
complex<double>* Dvector<complex<double> >::getValues() const{
  return this->values;
}

template<typename T>
Dvector<T>::Dvector(Dvector<T>& dv){
  sizeV = dv.size();
  values = dv.getValues();
}
template<typename T>
void Dvector<T>::newValues(int l){
  this->values = new T[l];
}
/*
methode qui rempli le vecteur aléatoirement
*/
template<>
void Dvector<double>::fillRandomly(){
  for (int i = 0; i < sizeV; i++){
    values[i] = rand() / (double)RAND_MAX;
  }
}
template<>
void Dvector<complex<double> >::fillRandomly(){
  for (int i = 0; i < sizeV; i++){
    values[i].real(rand() / (double)RAND_MAX);
    values[i].imag(rand() / (double)RAND_MAX);
  }
}

template<typename T>
T& Dvector<T>::operator()(int pos) const{
  if(pos >= 0 && pos < sizeV){
    return values[pos];
  }else{
    cout << "Index error while accessing values" << pos << sizeV << endl;
    return values[pos];
  }
}

template<typename T>
Dvector<T>& Dvector<T>::operator=(Dvector<T>& v){
  sizeV = v.size();
  values = new T[sizeV];
  memcpy(values, v.getValues(), sizeV * sizeof(T));
  return *this;
}

template<typename T>
Dvector<T>& Dvector<T>::operator+=(T val){
  for (int i = 0; i < sizeV; i++){
    values[i] += val;
  }
  return *this;
}
template<typename T>
Dvector<T>& Dvector<T>::operator+=(Dvector<T> v){
  if(sizeV == v.size()){
    for (int i = 0; i < sizeV; i++){
      values[i] += v(i);
    }
  }else{
    cerr << "Addition de deux vecteurs de taille différentes" << endl;
  }
  return *this;
}

template<typename T>
Dvector<T>& Dvector<T>::operator-=(T val){
  for (int i = 0; i < sizeV; i++){
    values[i] -= val;
  }
  return *this;
}
template<typename T>
Dvector<T>& Dvector<T>::operator-=(Dvector<T> v){
  if(sizeV == v.size()){
    for (int i = 0; i < sizeV; i++){
      values[i] -= v(i);
    }
  }else{
    cerr << "Addition de deux vecteurs de taille différentes" << endl;
  }
  return *this;
}
template<typename T>
Dvector<T>& Dvector<T>::operator*=(T val){
  for (int i = 0; i < sizeV; i++){
    values[i] *= val;
  }
  return *this;
}

template<typename T>
Dvector<T>& Dvector<T>::operator/=(T val){
  for (int i = 0; i < sizeV; i++){
    values[i] /= val;
  }
  return *this;
}
template<typename T>
bool Dvector<T>::operator==(Dvector<T> &v){
  if(sizeV == v.size()){
    for(int i = 0; i < sizeV; i++){
      if(values[i] != v(i)) { return false;}
    }
    return true;
  }else{
    return false;
  }
}
template<>
void Dvector<complex<double> >::fftcl(){
  /*
  FFT Cooley-Tukey pour les vecteurs de complex
  */
  int n = this->size();
  int s = this->size();
  if(s <= 1){return;}
  while(s != 1){
    assert(s % 2 == 0);
    s /= 2;
  }
  Dvector<complex<double> >* even = new Dvector<complex<double> >(n/2, complex<double>(1,1));
  Dvector<complex<double> >* odd = new Dvector<complex<double> >(n/2, complex<double>(1,1));
  for(s = 0; s < n / 2; s++){
    (*even)(s) = (*this)(s * 2);
    (*odd)(s) = (*this)(s * 2 + 1);
  }
  even->fftcl();
  odd->fftcl();
  for(s = 0; s < n / 2 ; s++){
    complex<double> expo = complex<double>(cos(-2 * M_PI * s / n), sin(-2 * M_PI * s / n));
    complex<double> t = (*odd)(s) * expo;
    (*this)(s) = (*even)(s) + t;
    (*this)(s + n / 2) = (*even)(s) - t;
  }
  delete even;
  delete odd;
  return;
}

template<>
void Dvector<complex<double> >::conjugue(){
  int n = this->size();
  for (int i = 0; i<n ; i++){
    (*this)(i) = conj((*this)(i));
  }
}

template<>
void Dvector<complex<double> >::ifftcl(){
  /*
  IFFT Cooley-Tukey pour les vecteurs de complexe
  */
  int n = this->size();
  if (n<=1){
    return;
  }
  this->conjugue();
  this->fftcl();
  this->conjugue();
  (*this)/=n;


}

template<typename T>
void Dvector<T>::resize(int size, T val){
  T *newVal = new T[size];
  if(size > sizeV){
    int i;
    for(i = 0; i < sizeV; i++){
      newVal[i] = values[i];
    }
    for(i = sizeV; i < size; i++){
      newVal[i] = val;
    }
  }else{
    for(int i = 0; i < size; i++){
      newVal[i] = values[i];
    }
  }
  delete[] values;
  values = newVal;
  sizeV = size;
}
template<typename T>
Dvector<T> operator+(Dvector<T>& v, T val){
  Dvector<T> result(v);
  result += val;
  return result;
}
template<typename T>
Dvector<T> operator-(Dvector<T>& v, T val){
  Dvector<T> result(v);
  result -= val;
  return result;
}
template<typename T>
Dvector<T> operator*(Dvector<T>& v, T val){
  Dvector<T> result(v);
  result *= val;
  return result;
}
template<typename T>
Dvector<T> operator/(Dvector<T>& v, T val){
  Dvector<T> result(v);
  result /= val;
  return result;
}

template<typename T>
Dvector<T> operator+(Dvector<T>& v1, Dvector<T>& v2){
  Dvector<T> result(v1);
  result += v2;
  return result;
}
template<typename T>
Dvector<T> operator-(Dvector<T>& v1, Dvector<T>& v2){
  Dvector<T> result(v1);
  result -= v2;
  return result;
}
template<typename T>
Dvector<T> operator-(Dvector<T>& v){
  Dvector<T> result(v);
  for (int i = 0; i < 4; i++){
    (result)(i) = -(v)(i);
  }
  return result;
}
template<typename T>
ostream& operator<<(ostream& out, Dvector<T> &v){
  out << "Dvector : ";
  for(int i = 0; i < v.size(); i++){
    out << (v)(i) << " ";
  }
  out << endl;
  return out;
}
template<typename T>
istream& operator>>(istream& in, Dvector<T> &v){
  for(int i = 0; i < v.size(); i++){
    in >> (v)(i);
  }
  return in;
}
