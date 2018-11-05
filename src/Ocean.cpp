#include<assert.h>
#include "Ocean.h"
#include <random>
#include <math.h>
#include <typeinfo>
#include <string>

Ocean::Ocean(int lx, int ly, int nx, int ny, double time, WaveModel* model, double hauteur): Height(lx, ly, nx, ny), time(time), hauteur(hauteur)
{
  this->model = model;
}
Ocean::~Ocean(){
  delete model;
}
double Ocean::getTime() {
  return time;
}
void Ocean::setTime(double time) {
  this->time = time;
}

WaveModel* Ocean::getModel(){
  return model;
}
double Ocean::getHauteur(){
  return hauteur;
}

/*
Methode de transformé de Fourrier suivant la direction X
*/
void Ocean::fft1(int y){
    Dvector<complex<double> > *cour = new Dvector<complex<double> >(this->getNx(), complex<double>(1.0, 2.0));
  for(int i = 0; i < this->getNx(); i++){
    (*cour)(i) = (*this)(this->getNx() * y + i);
  }
  cour->ifftcl();
  for(int i = 0; i < this->getNx(); i++){
    (*this)(this->getNx() * y + i) = (*cour)(i);
  }
  delete cour;
}

/*
Methode de transformé de Fourrier suivant la direction Y
*/
void Ocean::fft2(int x){
    Dvector<complex<double> > *cour = new Dvector<complex<double> >(this->getNy(), complex<double>(1.0, 2.0));
  for(int i = 0; i < this->getNy(); i++){
    (*cour)(i) = (*this)(this->getNx() * i + x);
  }
  cour->ifftcl();
  for(int i = 0; i < this->getNy(); i++){
    (*this)(this->getNx() * i + x) = (*cour)(i);
  }
  delete cour;
}

void Ocean::compute(){
  /*
  Methode permettant de calculer a tout instant t la hauteur de la houle,
  mets a jour le champ de vecteur
  */

  double x, y, xp, yp, ph, ph2, epsI, epsR, wk;
  complex<double> cpx1, cpx2, cpx3, cpx4, h, g;
  //initialisation du champ de hauteurs
  g.imag(0);
  Wave *cour;
  std::default_random_engine generator;
  std::normal_distribution<double> distribution(0.0, 1.0);
  double t = this->getTime();
  for(int i = 0; i  < this->getNx(); i++){
    x = i * this->getLx() / this->getNx();
    xp = (this->getNx() - i) * this->getLx() / this->getNx();
    for(int k = 0; k < this->getNy(); k++){
      h = 0.0;
      cour = this->getModel()->getWave();
      yp = (this->getNy() - k) * this->getLy() / this->getNy();
      y = k * this->getLy() / this->getNy();
      while(cour != NULL){
        if((this->getModel())->getType() == 1){
          PhilipsWave* pcour = (PhilipsWave*)cour;
          wk = sqrt(9.81 * sqrt(pow(cour->getDirection()[0],2) + pow(cour->getDirection()[1],2)));
          epsR = distribution(generator);
          epsI = distribution(generator);
          cpx1 = complex<double>(epsR, epsI);
          cpx2 = complex<double>(epsR, -epsI);
          cpx3 = complex<double>(cos(wk * t), sin(wk * t));
          cpx4 = complex<double>(cos(wk* t), -sin(wk * t));
          ph = (*pcour)(x, y);
          ph2 = (*pcour)(xp, yp);
          h += (1 / sqrt(2)) * (cpx1 * cpx3 * sqrt(ph) + cpx2 * cpx4 * sqrt(ph2));
        }else{
          GerstnerWave* gcour = (GerstnerWave*)cour;
          g.real((*gcour)(x, y, t));
          h += g;
        }
        cour = cour->getSuiv();
      }
      (*this)(i + k * this->getNx()) = h;
    }
  }
  if((this->getModel())->getType() == 1){
    // Transformée de Fourier dans la direction 1 : x
    for(int m = 0; m  < this->getNy(); m++){
      this->fft1(m);
    }
    // Transformée de Fourier dans la direction 2 : y
    for(int n = 0; n < this->getNx(); n++){
      this->fft2(n);
    }
    this->setTime(t + 0.03);
  }
  else{
   this->setTime(t + 0.3);
  }   
  // On obtient le champ de hauteur (Height) dans l'espace réel
  /*for(int i = 0; i < this->getNy() * this->getNy(); i++){
    (*this)(i) = (*this)(i).real();
    }*/

}

/** Initialise la grille dans la direction x
*  param[in]   y        abscisse de la colonne à parcourir
*  param[out]  vertices buffer contenant les coordonnées des noeuds
*/
void Ocean::init_gl_VertexArrayX(const int y, double* const vertices) {
  for(int x=0 ; x<getNx() ; x++) {
    vertices[3*x]   = (getLx()/getNx())*x;
    vertices[3*x+2] = (getLy()/getNy())*y;
  }
  vertices[3*getNx()]   = getLx();
  vertices[3*getNx()+2] = (getLy()/getNy())*y;
}

/** Initialise la grille dans la direction y
*  param[in]   x        abscisse de la ligne à parcourir
*  param[out]  vertices buffer contenant les coordonnées des noeuds
*/
void Ocean::init_gl_VertexArrayY(const int x, double* const vertices) {
  for(int y=0 ; y<getNy() ; y++) {
    vertices[3*y]   = (getLx()/getNx())*x;
    vertices[3*y+2] = (getLy()/getNy())*y;
  }
  vertices[3*getNy()]   = (getLx()/getNx())*x;
  vertices[3*getNy()+2] = getLy();
}

/** Convertit le champs de hauteur en tabeau directement utilisable
*  par OpenGL pour un y donné
*  param[in]   y        abscisse de la colonne à parcourir
*  param[out]  vertices buffer contenant les valeurs aux noeuds
*/
void Ocean::gl_VertexArrayX(const int y, double* const vertices)  {
  for(int x=0 ; x<getNx() ; x++) {
    vertices[3*x+1] = pow(-1, x+y)*(*this)(y,x).real();
  }
  vertices[3*getNx()+1] = pow(-1, getNx()+y)*(*this)(y,0).real();
}

/** Convertit le champs de hauteur en tabeau directement utilisable
*  par OpenGL pour un x donné
*  param[in]   x        abscisse de la ligne à parcourir
*  param[out]  vertices buffer contenant les valeurs aux noeuds
*/
void Ocean::gl_VertexArrayY(const int x, double* const vertices) {
  for(int y=0 ; y<getNy() ; y++) {
    vertices[3*y+1] =(*this)(y,x).real();
  }
  vertices[3*getNy()+1]  = (*this)(0,x).real();
}
