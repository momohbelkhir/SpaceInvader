 


#ifndef STRUCT_H
#define STRUCT_H
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#include <sys/types.h>
#include <unistd.h>
#include <limits.h> 
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/wait.h>


typedef struct Element Element ;

struct Element{ 
    int direction ; 
    struct Element  * suivant ;
};


typedef struct ListeRepere {
    Element *debut;
    Element *fin;
    int taille;
}l_deplacement;

typedef struct petit{

	int identite;
	int pv;
	char chr;
} pet;

typedef struct v{

  int dim[2]; //hauteur ^ , largeur >
  int nb_move;     //nb deplacement
  //int move[12];
  l_deplacement *move;

  int u_vie;     // unité de vie

  double freq ;// la freq

  int v_tir;  // vitesse du tir , case/s
  int p_tir;  // puissance du tir en unité de vie
  char s_tir;  // symbole du tir
  char *arme; // dessin du vaisseau
   
} v;

  typedef struct v* vaisseau ;

void ligne1(char buf[],vaisseau v);
char* ligne(char buf[]);
char* dessin(char buf[], vaisseau  v);
void charger_v ();
void creer_liste(char *line,vaisseau v);
void creer_liste_deplace(char *line,vaisseau v);
void afficherListe(l_deplacement *liste,int t);
int ins_liste_circ(l_deplacement * liste, Element *courant, int donnee);
int ins_liste_circ_vide(l_deplacement * liste, int donnee);
void charge_niveau();
void affiche();
void ajout(int *tat);
void apparition(int temp);
void deplace(int i,int j,int type);
void deplacement();
void niv1();
void niv2();
void niv3();
void init();



#endif
