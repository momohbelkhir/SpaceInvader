#include "struct.h"


extern int l;
extern char* c;
extern int **tab;
extern vaisseau tabv;
extern int k;
extern int i;
extern int fd;

 void init(){
 	 c = malloc(2);
		c[0] = '0';
	    c[1] = '1';
while(fd > 0){
		
		fd = open(c,O_RDONLY);

	  	if(fd > 0){
			charger_v(fd,k);
			close(fd);
			k++;
		}
		i ++;
		c[1] ++;
	}
	
    // affiche();


     l = 0; //pour charge_n
 }

//fonc menu
   void niv1(){
   	   init();

    fd=open("niveau",O_RDONLY);
    charge_niveau(fd);
    close(fd);
	apparition(0);
	//affiche();
	
	deplacement();
	

}
 void niv2(){
		init();
    fd=open("niveau2",O_RDONLY);
    charge_niveau(fd);
    close(fd);

	apparition(0);
	//affiche();

	
	deplacement();
	



}
 void niv3(){
   	    init();
    fd=open("niveau3",O_RDONLY);
    charge_niveau(fd);
    close(fd);
 
	apparition(0);
	//affiche();
	
	
	deplacement();
	



}
