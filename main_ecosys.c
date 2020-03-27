#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "ecosys.h"

#define NB_PROIES 20
#define NB_PREDATEURS 20
#define T_WAIT 40000


  /* Parametres globaux de l'ecosysteme (externes dans le ecosys.h)*/
float p_ch_dir=0.01;
float d_proie=1;
float d_predateur=1;
float p_manger=0.2;
float p_reproduce=0.01;
float energie=50;


int main(void) {
  srand(time(NULL));
  Animal *liste_proie = NULL;
  Animal *liste_predateur = NULL;
  int nb_proies = 0, nb_predateurs = 0;
  for (int i = 0 ; i < 10; i++) {
    ajouter_animal(rand() % SIZE_X, rand() % SIZE_Y, &liste_predateur);
  }
  for (int i = 0 ; i < 10; i++) {
    ajouter_animal(rand() % SIZE_X, rand() % SIZE_Y, &liste_proie);
  }
  while (1) {
    afficher_ecosys(liste_proie,liste_predateur);
    rafraichir_proies(&liste_proie);
    rafraichir_predateurs(&liste_predateur, &liste_proie);
    usleep(T_WAIT);
  }
	/* Ecrire     usleep(T_WAIT); pour ralentir l'affichage*/

  return 0;
}
