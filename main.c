
#include <sys/wait.h>
#include "struct.h"

 //menu
#include <math.h>
#include "menu.h"


#define couleur(param) printf("\033[%sm",param)


bool cont = true;

 void quit() {
   
  cont = false;
  
}
  menu_t* menu ; 

  int l;
  int **tab;
  int nb_vai; 
  vaisseau tabv;
  pet **carte;
  pet **carte2;
  int lig=43;
  int col=143; 
  int id=0; 

  int fd=1;
  char *c ;
	
  int  i = 0;
  int k = 0;





  int main(){    
	
      

      
      
      
      
      
      
   carte  = malloc(sizeof(*carte)*lig+1); 
   carte2 = malloc(sizeof(*carte2)*lig+1); 
   for(int i  = 0 ; i < lig ; i++  ){
	carte[i] = malloc(sizeof(**carte)*col);
	carte2[i] =malloc(sizeof(**carte2)*col);
	}
   for(int i = 0 ; i < lig ; i++)
	for(int j = 0 ; j < col; j++){
		carte[i][j].identite = 0;
		carte2[i][j].identite = 0;
		carte[i][j].pv = 0;
		carte2[i][j].pv = 0;
		carte[i][j].chr = ' ';
		carte2[i][j].chr = ' ';
	}
	carte[lig] = NULL;
	carte2[lig] = NULL;
		

	l = 0;

    tabv = malloc(50 * sizeof(*tabv));
   
   printf("Mon vaisseau %s!\n",c);
	
 

 //////menu
    couleur("36");
  menu_t *m1,*m2;

   menu=createMenu("Main menu");

  m1=createMenu("Jouer");
  addMenuAction(m1,"Niveau 1",niv1);
  addMenuAction(m1,"Niveau 2",niv2);
  addMenuAction(m1,"Niveau 3",niv3);
  addMenuAction(m1,"Quitter",quit);
  addSubMenu(menu,m1);
  
  m2=createMenu("Score");
  addMenuAction(m2,"Score final",f);
  addMenuAction(m2,"Meilleur score",f); //decouper
  addMenuAction(m2,"Retour",retour); //
  addSubMenu(menu,m2);

  
  addMenuAction(menu,"Quitter",quit);
  
               couleur("36");
  while(cont) launchMenu(menu);
                
               couleur("32");
               printf("   GAME OVER!\n\n"); 
               deleteMenu(menu);



return 0;
     
 
}














