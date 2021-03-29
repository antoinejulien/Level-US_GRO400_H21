#include <stdio.h>
#include "anglePlaqueToAngleMoteur.h"
#include "anglePlaqueToAngleMoteur_initialize.h"
#include "anglePlaqueToAngleMoteur_terminate.h"
#include "getAngles.h"




void getAngles(double anglex,double angley,double hauteur,double angles[3]){
	printf("in the function \n");
	printf("%lf \n",anglex);
	printf("%lf \n",angley);
	printf("%lf \n",hauteur);
	anglePlaqueToAngleMoteur_initialize();
	printf("after initialize\n");
	printf("%lf \n",anglex);
	printf("%lf \n",angley);
	printf("%lf \n",hauteur);

	anglePlaqueToAngleMoteur(anglex,angley,hauteur,angles);
	printf("after funtion \n");
	printf("%lf \n",anglex);
	printf("%lf \n",angley);
	printf("%lf \n",hauteur);
	
	//printf("%lf \n",angles[0]);
	//printf("%lf \n",angles[1]);
	//printf("%lf \n",angles[2]);
	anglePlaqueToAngleMoteur_terminate();
}
