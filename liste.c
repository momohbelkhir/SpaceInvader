#include"struct.h"




void initialisation (l_deplacement *liste){
    liste->debut = NULL;
    liste->fin = NULL;
    liste->taille = 0;
}


/* insertion dans une liste vide */
int ins_liste_circ_vide(l_deplacement * liste, int donnee){
    Element *nouveau_element;
    if ((nouveau_element = (Element *) malloc (sizeof (Element)))
          == NULL)
      return -1;       
   
     nouveau_element->direction = donnee ;

    nouveau_element->suivant = nouveau_element;
    liste->debut = nouveau_element;
    liste->fin = nouveau_element;
    liste->taille++;
    return 0;
}


/* insertion dans une liste non vide */
int ins_liste_circ(l_deplacement * liste, Element *courant, int donnee){
    Element *nouveau_element;
    if ((nouveau_element = (Element *) malloc (sizeof (Element)))
            == NULL)
        return -1;       
    
   nouveau_element->direction = donnee ;

    if(courant != liste->fin)
        return -1;
  
    nouveau_element->suivant = courant->suivant;// = liste->debut
    courant->suivant = nouveau_element;//liste->fin->suivant =
    liste->fin = nouveau_element;
    liste->taille++;
    return 0;
}









void creer_liste(char *line,vaisseau v){
	
	v->move = malloc(sizeof(l_deplacement));
	l_deplacement *liste = v->move;
	
	initialisation (liste);
	int val,i;
  
	if(line[0] != '-')
		val = line[0] - 48;
	else{
		line++;
		val = -1;
	}
	line +=2;
	if(ins_liste_circ_vide(liste, val) == -1)
		printf("sa a foire \n");
	
	for(i = 0 ; line[i] != '\0' ; i+=2){
		
		if(line[i] != '-')
			val = line[i] - 48;
		else{
			i++;
			val = -1;
		}
		ins_liste_circ(liste,liste->fin, val);
	}
}



void afficherListe(l_deplacement *liste,int t)

{
    if (liste == NULL)
 {
     exit(EXIT_FAILURE);

    }
   Element *actuel = liste->debut;
  while (actuel != NULL && t<24)

    {
        printf("%d -> ", actuel->direction);
        actuel = actuel->suivant;
     t++;
    }

    printf("NULL\n");

}





