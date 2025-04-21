#include <stdio.h>
#include <string.h>
#include "funciones_embalses.h" 

float porcentaje_embalse (int anyo, int mes, int num_cuenca, int vector2[], int num_embalse, int i, linea vector[], linea vector1[]){

float dato, fecha, porcentaje;


switch(anyo){
	case(2012):
		for (i=vector2[num_cuenca-1]+(num_embalse-1)*12;i<vector2[num_cuenca-1]+(num_embalse)*12;i++){
			fecha =  vector[mes-1].dosmildoce;
			dato = vector1[num_embalse-1].etotal;
			//comprobación
			//printf("dato:%f\n", vector[i].dosmildoce);
			//printf("linea:%i\n",i);
		}
		porcentaje = fecha*100/dato;
		printf ("%f\n",porcentaje);	

	case(2013):
		for (i=vector2[num_cuenca-1]+(num_embalse-1)*12;i<vector2[num_cuenca-1]+(num_embalse)*12;i++){
			fecha =  vector[mes-1].dosmiltrece;
			dato = vector1[num_embalse-1].etotal;
				
			//comprobación
			//printf("dato:%f\n", cuenca[i].dosmiltrece);
			//printf("linea:%i\n",i);
		}
		porcentaje = fecha*100/dato;
		printf ("%f\n",porcentaje);	
	
	case(2014):
		for (i=vector2[num_cuenca-1]+(num_embalse-1)*12;i<vector2[num_cuenca-1]+(num_embalse)*12;i++){
			fecha =  vector[mes-1].dosmilcatorce;
			dato = vector1[num_embalse-1].etotal;
				
			//comprobación
			//printf("dato:%f\n", cuenca[i].dosmilcatorce);
			//printf("linea:%i\n",i);
		}
		porcentaje = fecha*100/dato;
		printf ("%f\n",porcentaje);	
		
	case(2015):
		for (i=vector2[num_cuenca-1]+(num_embalse-1)*12;i<vector2[num_cuenca-1]+(num_embalse)*12;i++){
			fecha =  vector[mes-1].dosmilquince;
			dato = vector1[num_embalse-1].etotal;
				
			//comprobación
			//printf("dato:%f\n", cuenca[i].dosmilquince);
			//printf("linea:%i\n",i);
		}
		porcentaje = fecha*100/dato;
		printf ("%f\n",porcentaje);	
		
	case(2016):
		for (i=vector2[num_cuenca-1]+(num_embalse-1)*12;i<vector2[num_cuenca-1]+(num_embalse)*12;i++){
			fecha =  vector[mes-1].dosmildieciseis;
			dato = vector1[num_embalse-1].etotal;
				
			//comprobación
			//printf("dato:%f\n", cuenca[i].dosmildieciseis);
			//printf("linea:%i\n",i);
		}
		porcentaje = fecha*100/dato;
		printf ("%f\n",porcentaje);	
		
	case(2017):
		for (i=vector2[num_cuenca-1]+(num_embalse-1)*12;i<vector2[num_cuenca-1]+(num_embalse)*12;i++){
			fecha =  vector[mes-1].dosmildiecisiete;
			dato = vector1[num_embalse-1].etotal;
				
			//comprobación
			//printf("dato:%f\n", cuenca[i].dosmildiecisiete);
			//printf("linea:%i\n",i);
		}
		porcentaje = fecha*100/dato;
		printf ("%f\n",porcentaje);	
		
	case(2018):
		for (i=vector2[num_cuenca-1]+(num_embalse-1)*12;i<vector2[num_cuenca-1]+(num_embalse)*12;i++){
			fecha =  vector[mes-1].dosmildieciocho;
			dato = vector1[num_embalse-1].etotal;
				
			//comprobación
			//printf("dato:%f\n", cuenca[i].dosmildieciocho);
			//printf("linea:%i\n",i);
		}
		porcentaje = fecha*100/dato;
		printf ("%f\n",porcentaje);	
		
	case(2019):
		for (i=vector2[num_cuenca-1]+(num_embalse-1)*12;i<vector2[num_cuenca-1]+(num_embalse)*12;i++){
			fecha =  vector[mes-1].dosmildiecinueve;
			dato = vector1[num_embalse-1].etotal;
				
			//comprobación
			//printf("dato:%f\n", cuenca[i].dosmildiecinueve);
			//printf("linea:%i\n",i);
		}
		porcentaje = fecha*100/dato;
		printf ("%f\n",porcentaje);	
		
	case(2020):
		for (i=vector2[num_cuenca-1]+(num_embalse-1)*12;i<vector2[num_cuenca-1]+(num_embalse)*12;i++){
			fecha =  vector[mes-1].dosmilveinte;
			dato = vector1[num_embalse-1].etotal;
				
			//comprobación
			//printf("dato:%f\n", cuenca[i].dosmilveinte);
			//printf("linea:%i\n",i);
		}
		porcentaje = fecha*100/dato;
		printf ("%f\n",porcentaje);	
		
	case(2021):
		for (i=vector2[num_cuenca-1]+(num_embalse-1)*12;i<vector2[num_cuenca-1]+(num_embalse)*12;i++){
			fecha =  vector[mes-1].dosmilveintiuno;
			dato = vector1[num_embalse-1].etotal;
				
			//comprobación
			//printf("dato:%f\n", cuenca[i].dosmilveintiuno);
			//printf("linea:%i\n",i);
		}
		porcentaje = fecha*100/dato;
		printf ("%f\n",porcentaje);	

}
}

