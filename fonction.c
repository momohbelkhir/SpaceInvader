#include "struct.h"


extern int l;

extern int **tab;
extern vaisseau tabv;

char* ligne(char buf[]){
	
        int i=0;
	
        char *s=malloc(300);
        while(buf[l] !='\n'){
        s[i]=buf[l];
	      l++;
        i++;
        } 
      l++;          
   return s;
 } 

void ligne1(char buf[],vaisseau v){
        int i=0;
        char *s1=malloc(300);
     

        while(buf[0] !=' '){
       		s1[i]=buf[0];
       		i++;
		buf++;
        } 
	buf++;
        s1[i]='\0';
      
        v->dim[0]=atoi(s1);
        v->dim[1]=atoi(buf); 
                 
        
 }

char* dessin(char buf[], vaisseau  v){
        int i=0;
        char *s= malloc(v->dim[0] * v->dim[1]);

        while(i< (v->dim[0] * v->dim[1])){
          if(buf[l]=='\n')
            l++;

        s[i]=buf[l];
	      l++;
        i++;
        } 
         l++;          
   return s;
 } 
 
 ///////////////////////////////////////////////////////////////////////
 void creer_liste_deplace(char* line ,vaisseau v ) {
     l_deplacement *liste=malloc(sizeof(l_deplacement));
	int val,i;
	if(line[0] != '-')
		val = line[0] - 48;
	else{
		line++;
		val = -1;
	}
	line +=2;
	if(ins_liste_circ_vide(liste, val) == -1)
		printf("probleme d'initialisation \n");
	
	for(i = 0 ; line[i] != '\0' ; i+=2){
		
		if(line[i] != '-')
			val = line[i] - 48;
		else{
			i++;
			val = -1;
		}
		ins_liste_circ(liste,liste->fin, val);
	}
	/////////////
	
	

    if (liste == NULL)
 {
     exit(EXIT_FAILURE);

    }
   Element *actuel1 = liste->debut;
   Element *actuel2 = v->move->debut;
   int t=0;
  while (actuel1 != NULL && t<24){ 
      
        if( actuel1->direction ==0 && actuel2->direction==1){
            actuel2->direction=1;
        actuel1 = actuel1->suivant;
        actuel2 = actuel2->suivant;
     
    }else if( actuel1->direction == -1 && actuel2->direction==0){
            actuel2->direction= 2;
        actuel1 = actuel1->suivant;
        actuel2 = actuel2->suivant;
    }else if ( actuel1->direction == 0 && actuel2->direction==-1){
        actuel2->direction= -1;
        actuel1 = actuel1->suivant;
        actuel2 = actuel2->suivant;
        
    }else{
      actuel2->direction= 0; // c pr le vaisseau stable
    }
    t++;
  
}
	printf("NULL\n");
/////////////////	
}
     
     
/////////////////////////////////////////////////////////////////////////////
 void charger_v (int fd,int nb){	
	l = 0;	
vaisseau v1 = malloc(sizeof(vaisseau));
	char *buf = malloc(1024);
	read(fd , buf,1024);


	char *s=ligne(buf); //ligne 1
	
   ligne1(s,v1);
   printf("%d %d\n",v1->dim[0],v1->dim[1]);

      s=ligne(buf);    //ligne 2
      v1->nb_move = atoi(s);
      printf("%d\n",v1->nb_move);

      s = ligne(buf);   //ligne 3
      creer_liste(s,v1);
     afficherListe(v1->move,v1->nb_move);
      s=ligne(buf);   //ligne 4
    creer_liste_deplace(s,v1);
   afficherListe(v1->move,v1->nb_move);

      s=ligne(buf);   //ligne 5
      v1->u_vie = atoi(s);
      printf("%d\n",v1->u_vie);

      s=ligne(buf);   //ligne 6
      v1->freq = atof(s);
      printf("%g\n",v1->freq);

      s=ligne(buf);   //ligne 7
      v1->v_tir = atoi(s);
      printf("%d\n",v1->v_tir);

      s=ligne(buf);   //ligne 8
      v1->p_tir = atoi(s);
      printf("%d\n",v1->p_tir);

      s=ligne(buf);   //ligne 9
      v1->s_tir =s[0];
      printf("%c\n",v1->s_tir);
     
      v1->arme = dessin(buf,v1);
      printf("%s ",v1->arme);
      printf("termine\n");    
      tabv[nb] = *v1;
      printf("%d\n",tabv[nb].nb_move);    
//	free(buf);
}



int charger_n(int t,char *li,char * buf){
    int k = 0 ;
    printf("%d  ->",t);
    tab[t] = malloc(4 *sizeof(int));
    
    li = ligne(buf);
    while (li[k] != '\0'){
        if(li[k] == ' ')
            li[k]= '\0';
        k++;
    }
    for (int j= 0 ; j<4 ; j++){
        tab[t][j]=atoi(li);
        while(li[0] != '\0')
            li++;
        printf("%d  ",tab[t][j])	;		
        li++;
    }
    printf("\n");
    return 1;
}

void charge_niveau(int fd)
{	
    l=0;	
    char *line = malloc(25 );
    int i,k;
    char *buf = malloc(1024);
    read(fd , buf,1024);
    line = ligne(buf);
    k = atoi(line);
    
    tab = malloc((k+1)*sizeof(int*));
    printf("ici %d \n",k);
    for(i = 0; i < k;i++)
        charger_n(i,line,buf);
    printf("\n");	
    
    tab[k] = NULL;
    
}



  

