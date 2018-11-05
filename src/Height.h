#ifndef HEIGHTH
#define HEIGHTH

#include <string>
#include "Dvector.h"

class Height : public Dvector<complex<double> >{
  public:
    //Constructeur
    Height(int lx, int ly, int nx, int ny);
    Height(int lx, int ly, int nx, int ny, complex<double> val);
    ~Height();
    //getter
    int getLx() const;
    int getLy() const;
    int getNx() const;
    int getNy() const;
    //operateur
    complex<double>& operator()(int x, int y) const;
    complex<double>& operator()(int pos) const;
  private:
    int lx, ly, nx, ny;
};

#endif
