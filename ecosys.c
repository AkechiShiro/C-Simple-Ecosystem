#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include "ecosys.h"

Animal *creer_animal(int x, int y, float energie) {
  Animal *na = (Animal *)malloc(sizeof(Animal));
  assert(na);
  na->x = x;
  na->y = y;
  na->energie = energie;
  na->dir[0] = rand() % 3 - 1;
  na->dir[1] = rand() % 3 - 1;
  na->suivant = NULL;
  return na;
}

void afficherListe(Animal *liste)
{
    if (liste == NULL)
    {
        exit(EXIT_FAILURE);
    }

    Animal *actuel = liste->suivant;

    while (actuel != NULL)
    {
        printf("postition (%d,%d) -> ", actuel->x, actuel->y);
        actuel = actuel->suivant;
    }
}

Animal* ajouter_en_tete_animal(Animal *liste, Animal *animal) {
  assert(animal);
  assert(!animal->suivant);
  animal->suivant = liste; // Animal contient un champ suivant : on retourne animal, qui est le pointer "suivant" qui pointe  sur la "liste".
  return animal;
}



void ajouter_animal(int x, int y, Animal** liste_animal) {
 	assert(liste_animal);
 	Animal* nouvel_animal = creer_animal(x,y,energie);
 	assert(nouvel_animal);
 	if (x < SIZE_X && y < SIZE_Y  && x >= 0 && y >= 0) { // *liste_animal->suivant != NULL ||
      *liste_animal = ajouter_en_tete_animal(*liste_animal, nouvel_animal);
    } else {
 	    return ;
 	}
}


void enlever_animal(Animal **liste, Animal *animal) {
  assert(liste);
  assert(animal);

  Animal *preced=*liste;
  if (animal !=*liste ){
    /* Trouver le précédent*/
    while(preced->suivant != animal )
      preced=preced->suivant;
    /* refaire le chainage */
    preced->suivant=animal->suivant;
  }else /* ou sinon, changer la tete*/
    *liste=animal->suivant;


  free(animal);
  return ;
}


Animal* liberer_liste_animaux(Animal *liste) {
  Animal* tmp = liste;
  while (liste->suivant != NULL) {
    tmp = liste->suivant;
    free(liste);
    liste = tmp;
  }
  free(tmp);
  free(liste);
  return NULL;
}

unsigned int compte_animal_rec(Animal *la) {
  if (!la) return 0;
  return 1 + compte_animal_rec(la->suivant);
}


unsigned int compte_animal_it(Animal *la) {
  int cpt=0;
  while (la) {
    ++cpt;
    la = la->suivant;
  }
  return cpt;
}


void bouger_animaux(Animal *la) {
  float random;
  while (la != NULL) {
    random=(1.0*rand() / RAND_MAX);
    la->x = (la->x + la->dir[0] + SIZE_X) % SIZE_X;
    la->y = (la->y + la->dir[1] + SIZE_Y) % SIZE_Y;
    if (random < p_ch_dir) {
      la->dir[0] = rand()%3-1;
      la->dir[1] = rand()%3-1;
    }
    la = la->suivant;
  }
 /* A COMPLETER */
}


void reproduce(Animal **liste_animal) {
  Animal *liste=*liste_animal;
  float random;
  Animal* ani;
  while (liste!=NULL) {
    random=(1.0*rand())/RAND_MAX;
    if (random < p_reproduce) {
      ani = creer_animal(liste->x,liste->y,energie);
      *liste_animal=ajouter_en_tete_animal(*liste_animal,ani);
    }
    liste=liste->suivant;
  }
}


void rafraichir_proies(Animal **liste_proie) {
  assert(liste_proie); // liste_proie != NULL
  //printf("J'ai passé l'épreuve du assert\n");
  Animal* copie_p=*liste_proie;
  bouger_animaux(*liste_proie);
  //printf("Je suis la\n");
  while (copie_p !=NULL) {
    copie_p->energie -= d_proie;
    if (copie_p->energie < 0) {
      //printf("Je suis bientôt mort\n");
       enlever_animal(liste_proie,copie_p); // A corriger copie_p est free donc ce code marche pas.
    }
    copie_p = copie_p->suivant;
  }
  reproduce(liste_proie);
  /* deplacement et mise a jour de l'energie */
  /* gestion de la reproduction */

}


Animal *animal_en_XY(Animal *l, int x, int y) {
  while (l !=NULL) {
      if(l->x == x && l->y == y)
        return l;
      l = l->suivant;
  }
  return NULL;
}


void rafraichir_predateurs(Animal **liste_predateur, Animal **liste_proie) {
   //assert(liste_predateur); // liste_proie != NULL
   Animal* copie_p=*liste_predateur;
   float random;
   bouger_animaux(*liste_predateur);
   if (copie_p != NULL && animal_en_XY(*liste_proie, copie_p->x, copie_p->y) != NULL) {
     random = 1.0*rand()/RAND_MAX;
     //printf("Je suis random : %f\n",random);
     if(random < p_manger)
      enlever_animal(liste_proie, animal_en_XY(*liste_proie, copie_p->x, copie_p->y));
   }
   while (copie_p !=NULL) {
     copie_p->energie -= d_predateur;
     if (copie_p->energie < 0) {
        enlever_animal(liste_predateur,copie_p); // copie_p Attention.
     }
     copie_p = copie_p->suivant;
   }
   reproduce(liste_predateur);
}



void afficher_ecosys(Animal *liste_proie, Animal *liste_predateur) {
  static int cpt = 0;  /* Compteurs d'appels a la fonction */
  unsigned int i, j;
  char ecosys[SIZE_X][SIZE_Y];
  int nbpred=0,nbproie=0;
  Animal *pa=NULL;

  /* on initialise le tableau */
  for (i = 0; i < SIZE_X; ++i) {
    for (j = 0; j < SIZE_Y; ++j) {
      ecosys[i][j]=' ';
    }
  }

  /* on ajoute les proies */
  pa = liste_proie;
  while (pa) {
    ++nbproie;
    if (pa->x >= 0 && pa->x < SIZE_X && pa->y >= 0 && pa->y < SIZE_Y) {
      ecosys[pa->x][pa->y] = '*';
    } else {
      printf("Avertissement : Une proie avec energie %f est hors l'ecosysteme a (%d, %d).\n",
             pa->energie, pa->x, pa->y);
    }
    pa=pa->suivant;
  }

  /* on ajoute les predateurs */
  pa = liste_predateur;
  while (pa) {
    ++nbpred;
    if (pa->x >= 0 && pa->x < SIZE_X && pa->y >= 0 && pa->y < SIZE_Y) {
      if ((ecosys[pa->x][pa->y] == '@') || (ecosys[pa->x][pa->y] == '*')) { /* proies aussi present */
        ecosys[pa->x][pa->y] = '@';
      } else {
        ecosys[pa->x][pa->y] = 'O';
      }
    } else {
      printf("Avertissement : Un predateur avec energie %f est hors l'ecosysteme a (%d, %d).\n",
             pa->energie, pa->x, pa->y);
    }
    pa = pa->suivant;
  }

  /* on affiche le tableau */
  printf("+");
  for (j = 0; j < SIZE_Y; ++j) {
    printf("-");
  }
  printf("+\n");
  for (i = 0; i < SIZE_X; ++i) {
    printf("|");
    for (j = 0; j < SIZE_Y; ++j) {
      putchar(ecosys[i][j]);
    }
    printf("|\n");
  }
  printf("+");
  for (j = 0; j<SIZE_Y; ++j) {
    printf("-");
  }
  printf("+\n");
  printf("Cpt : %5d\tNb prey : %5d\tNb predators : %5d\n", cpt, nbproie, nbpred);
  ++cpt;
}


void clear_screen() {
  printf("\x1b[2J\x1b[1;1H");  /* code ANSI X3.4 pour effacer l'ecran */
}
