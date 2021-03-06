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
  /** @todo Initialiser des paramètres de simulation */

  /** @todo Initialiser du modèle*/

  /** @todo Initialiser du champ de hauteur */

  /** @todo Initialiser de l'océan */
  GerstnerWave *gwave1 = new GerstnerWave(1, 0.1);
  GerstnerWave *gwave2 = new GerstnerWave(2.5, 0.2);
  double dir[2] = {1, 2};

  GerstnerWaveModel *gmodel = new GerstnerWaveModel(gwave1, dir, 1, 1, 1, 1);
  gmodel->addGerstnerWave(gwave2);
  ocean = new Ocean(200,200, 64, 64, 1, gmodel, 8.0);


  /* Initialisation de la fenêtre d'affichage */
  Window::init(WIDTH, HEIGHT, "Houle", argc, argv, "AZERTY", 50, 1);

  /* Execute la simulation */
  Window::launch();

  /* Libère la mémoire */

  Window::quit();
  return 0;

}
