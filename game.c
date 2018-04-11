#include"struct.h"

extern int id; 
extern int nb_vai; 
extern int lig;
extern int col;
extern int **tab;
extern pet **carte;
extern pet **carte2;
extern vaisseau tabv;


void affiche(){
for(int i = 0;i< lig ; i++)
                for(int j = 0; j< col;j++)
                {
                        if(carte[i][j].identite == 0) 
                             
                               write(1," ",1);
                        
                        
                        
                        else
                               
                        write(1,&carte[i][j].chr,1);
                }
	
}



void ajout(int *tat)
{
	int k = 0;
	int l = -1;
	int c  = 0;
        
	while(tabv[tat[0] - 1].arme[k])	{

          if(k % tabv[tat[0] - 1].dim[0] == 0){	
                  l++;    
                  c = 0;
       	  }
       	 
	carte[((tat[3] * lig)/100) + l][((tat[2]*col)/100)+c].identite = tat[0]*1000 + id;
	carte[((tat[3] * lig)/100) + l][((tat[2]*col)/100)+c].pv  = tabv[tat[0] - 1].u_vie;
	carte[((tat[3] * lig)/100) + l][((tat[2]*col)/100)+c].chr = tabv[tat[0] - 1].arme[k];
        k++;
        c++;
         }printf("\n");
}


void apparition(int temp)
{
    //affiche();
		
	for(int i = 0 ; tab[i] !=NULL ; i++)
	{
		if(tab[i][1] == temp)
		{
			id ++;
			ajout(tab[i]);
		}
	}
	
}

void deplace(int i,int j,int type)
{
 
	if(tabv[type - 1].move->debut->direction == -1){

	carte2[i][j-1].identite = carte[i][j].identite;
	carte2[i][j-1].pv = carte[i][j].pv; 
	carte2[i][j-1].chr = carte[i][j].chr; 
	}else if(tabv[type - 1].move->debut->direction == 2){

	carte2[i+1][j].identite = carte[i][j].identite; 
	carte2[i+1][j].pv = carte[i][j].pv; 
	carte2[i+1][j].chr = carte[i][j].chr; 
	}
	else if(tabv[type - 1].move->debut->direction == 1){

		carte2[i][j+1].identite = carte[i][j].identite;
	    carte2[i][j+1].pv = carte[i][j].pv; 
	    carte2[i][j+1].chr = carte[i][j].chr; 
   }else if(tabv[type - 1].move->debut->direction == 0){

   	carte2[i][j].identite = carte[i][j].identite;
	carte2[i][j].pv = carte[i][j].pv; 
	carte2[i][j].chr = carte[i][j].chr; 
   }
}
int cmp=1;

void deplacement(){

	while(1){
pet **swap;

	for(int i = 0; i < lig ; i++)
	{
		for(int j = 0 ; j <col ;j++)
		{
			if(carte[i][j].identite > 1000)
				 deplace(i,j,carte[i][j].identite/1000); // de carte a carte2
		}

	}

//affiche();
	for( int i = 0 ; i < lig ;i++){
		for(int j = 0 ; j < col ; j++)  
                	carte[i][j].identite = 0;
	}
	
	swap = carte;
	carte = carte2;
	carte2 = swap;
	
        cmp++;
        
        
	for(int i = 0; i<4;i++){
              
		tabv[i].move->debut = tabv[i].move->debut->suivant;
                
	}
sleep(1);
affiche();

        }
}

