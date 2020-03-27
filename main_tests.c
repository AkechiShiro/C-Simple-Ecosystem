#include <assert.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "ecosys.h"

#define NB_PROIES 20
#define NB_PREDATEURS 20
#define T_WAIT 100000

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
  ajouter_animal(0,0,&liste_proie);
  afficher_ecosys(liste_proie,liste_predateur);
	liste_proie->x = (liste_proie->x + 1 + SIZE_X) % SIZE_X; // Vérification du déplacement sur l'axe verticale
	liste_proie->y = (liste_proie->y - 1 + SIZE_Y) % SIZE_Y; // Vérification de la toricité du monde
//	bouger_animaux(*liste_proie);
	afficher_ecosys(liste_proie,liste_predateur); // Afficher l'écosystème après déplacement de l'unique proie.

  return 0;
}
