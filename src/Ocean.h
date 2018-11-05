#ifndef OCEANH
#define OCEANH

#include"Height.h"
#include "GerstnerWaveModel.h"
#include "GerstnerWave.h"
#include "PhilipsWaveModel.h"
#include "PhilipsWave.h"
#include "Wave.h"
#include <math.h>

class Ocean : public Height{
  public:
    //Constructeur
    Ocean(int lx, int ly, int nx, int ny, double time, WaveModel* model, double hauteur);
    ~Ocean();
    //Getteurs
    double getTime();
    WaveModel* getModel();
    double getHauteur();
    void fft1(int y);
    void fft2(int x);
    void setTime(double time);
    //Methodes
    void compute();
    void init_gl_VertexArrayX(const int y, double* const vertices) ;
    void init_gl_VertexArrayY(const int x, double* const vertices) ;
    void gl_VertexArrayX(const int y, double* const vertices) ;
    void gl_VertexArrayY(const int x, double* const vertices) ;


  private:
    double time;
    WaveModel* model;
    double hauteur;
};

#endif
