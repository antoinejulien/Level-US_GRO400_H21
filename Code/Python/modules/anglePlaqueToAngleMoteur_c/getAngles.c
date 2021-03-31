#include <stdio.h>
#include "anglePlaqueToAngleMoteur.h"
#include "anglePlaqueToAngleMoteur_initialize.h"
#include "anglePlaqueToAngleMoteur_terminate.h"
#include "getAngles.h"




void getAngles(double anglex,double angley,double hauteur,double angles[3]){
	/*printf("in the function \n");
	printf("angle x :%lf degres\n",anglex);
	printf("angle y :%lf degres\n",angley);
	printf("hauteur :%lf mm\n",hauteur);*/
	anglePlaqueToAngleMoteur_initialize();


	anglePlaqueToAngleMoteur(anglex,angley,hauteur,angles);

	
	//printf("%lf \n",angles[0]);
	//printf("%lf \n",angles[1]);
	//printf("%lf \n",angles[2]);
	anglePlaqueToAngleMoteur_terminate();
}
