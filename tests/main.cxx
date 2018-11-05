#include <cstdlib>
#include <ctime>
#include <iostream>

/** @todo Inclure les fichiers de définition du problème */

#include "../src/window.hxx"
#include "../src/Ocean.h"
#include "../src/Wave.h"
Ocean *ocean;
int mainwindow;
int main(int argc, char** argv) {
  PhilipsWave *pwave1 = new PhilipsWave(20, 1.8);
  PhilipsWave *pwave2 = new PhilipsWave(10, 1.6);
  double dir[2] = {1, 2};

  PhilipsWaveModel *pmodel = new PhilipsWaveModel(pwave1, dir, 1, 1, 1, 1);
  pmodel->addPhilipsWave(pwave2);
  ocean = new Ocean(150,150, 64, 64, 1, pmodel, 10.0);


  /* Initialisation de la fenêtre d'affichage */
  Window::init(WIDTH, HEIGHT, "Houle", argc, argv, "AZERTY", 50, 1);

  /* Execute la simulation */
  Window::launch();

  /* Libère la mémoire */

  Window::quit();
  return 0;

}
