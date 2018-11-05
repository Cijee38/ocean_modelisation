#include<assert.h>
#include"Height.h"
#include"Dvector.h"


Height::Height(int lx, int ly, int nx, int ny, complex<double> val): Dvector(ny * nx, val), lx(lx), ly(ly), nx(nx), ny(ny)
{
}
Height::Height(int lx, int ly, int nx, int ny): Dvector(ny * nx, complex<double>(1.0, 2.0)), lx(lx), ly(ly), nx(nx), ny(ny)
{
}
Height::~Height(){
}
int Height::getLx() const{
    return lx;
}
int Height::getLy() const{
    return this->ly;
}
int Height::getNx() const{
    return this->nx;
}
int Height::getNy() const{
    return this->ny;
}
complex<double>& Height::operator()(int x, int y) const{
    return (*this)(nx * y + x - 1);
}
complex<double>& Height::operator()(int pos) const{
    return getValues()[pos];
}

