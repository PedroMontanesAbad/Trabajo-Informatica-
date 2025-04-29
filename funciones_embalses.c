#include <stdio.h>
#include <string.h>
#include "funciones_embalses.h" 


//vector2[] es posiciones_cuencas[15]
//vector es linea cuenca[4236]
//vector1 es linea embalse[353]

//NOMBRES DE CUENCAS:

void nombres_cuencas(int j,linea vector[]){
	
	int f=0, i;
	int posiciones_cuencas[15];
	for (i=0;i<j;i++){
	
	
	if (strcmp(vector[i].cuenca_hidrografica,vector[i-1].cuenca_hidrografica)!=0){
		f++;
	
		printf("%i- ", f);
		printf("%s\n",vector[i].cuenca_hidrografica);
	}

}

}

// SELECCIÓN DE CUENCA:

int seleccion_cuenca(int num_cuenca, char C_cuenca[]){
	
	do{
	
	printf("\nIntroduce el numero de la cuenca: ");
	scanf("%s", C_cuenca);
	
	if(('9'<C_cuenca[0] && C_cuenca[0]<'0') && ('9'<C_cuenca[1] && C_cuenca[1]<'0')){
		printf ("\nCaracter no valido, repite:\n");	
	}
	else{	
		if (C_cuenca[0] == '0'){
			printf ("\nbNumero no valido, repite:\n");
		}
		
		else{		
			sscanf(C_cuenca, "%i", &num_cuenca);
			if((0 >= num_cuenca) || ( num_cuenca > 16 )){
				printf ("\ncNumero no valido, repite:\n");
			}
		}
	}
}

while ((0 >= num_cuenca) || ( num_cuenca > 16 ) || (('9'<C_cuenca[0] && C_cuenca[0]<'0') && ('9'<C_cuenca[1] && C_cuenca[1]<'0')) || (C_cuenca[0] == '0'));

return num_cuenca;

}

//NOMBRES DE EMBALSES:

void nombres_cuencas_embalse(int j, int num_cuenca, linea vector[], int vector2[]){
	int i,f=0, m;
		
	for (i=vector2[num_cuenca-1];i<vector2[num_cuenca];i++){
		if (i%12==0){
			printf("%i. %s\n", f+1, vector[i].embalse_nombre);
			f++;
			m++;
		
 		
		}
	
	}

}

// SELECCIÓN DE EMBALSES:

int seleccion_embalse(int num_embalse, int vector2[], int num_cuenca, char C_embalse[]){

	do{
	printf("\nIntroduce el numero del embalse: " );	
	scanf("%s", C_embalse);
	
	if(('9'<C_embalse[0] && C_embalse[0]<'0') && ('9'<C_embalse[1] && C_embalse[1]<'0')){
		printf ("\nCaracter no valido, repite:\n");	
	}
	else{	
		if (C_embalse[0] == '0'){
			printf ("\nNumero no valido, repite:\n");
		}
		
		else{		
			sscanf(C_embalse, "%i", &num_embalse);
			if((0 >= num_embalse) || ( num_embalse > ((vector2[num_cuenca]-vector2[num_cuenca-1])/12))){
				printf ("\nNumero no valido, repite:\n");
			}
		}
	}

}
while ((0 >= num_embalse) || ( num_embalse > ((vector2[num_cuenca]-vector2[num_cuenca-1])/12)) || ('9'<C_embalse[0] && C_embalse[0]<'0') && ('9'<C_embalse[1] && C_embalse[1]<'0') || (C_embalse[0] == '0'));

	return num_embalse;

}

//SELECCIÓN DE AÑOS:

int seleccion_anyo(int anyo, char C_anyo[]);{
		
	do{
	printf("\nIntroduce el anyo deseado 2012-2021: ");
	scanf("%s", C_anyo);
			
	if(('9'<C_anyo[0] && C_anyo[0]<'0') || ('9'<C_anyo[1] && C_anyo[1]<'0') || ('9'<C_anyo[2] && C_anyo[2]<'0') || ('9'<C_anyo[3] && C_anyo[3]<'0')){
		printf ("\nCaracter no valido, repite:\n");	
	}
	else{	
		sscanf(C_anyo, "%i", &anyo);
		if((2012 > anyo) || (anyo > 2021)){
			printf ("\nNumero no valido, repite:\n");
		}
	}
	}

while ((2012 > anyo) || ( anyo > 2021 ) || ('9'<C_anyo[0] && C_anyo[0]<'0') || ('9'<C_anyo[1] && C_anyo[1]<'0') || ('9'<C_anyo[2] && C_anyo[2]<'0') || ('9'<C_anyo[3] && C_anyo[3]<'0'));
	
	return anyo;
}
//SELECCIÓN MES:

int seleccion_mes(int N_mes, char C_mes[]){

	do{
		
	printf("\nIntroduce el mes deseado: ");
	scanf("%s",C_mes);
		
	if ((C_mes[0] < '0' && C_mes[0] > '9') || (C_mes[1] < '0' && C_mes[1] > '9')){
		printf("\nNumero no valido, repite:\n");
	}
	else{
		if (C_mes[0]== '0'){
			printf("\nNumero no valido, repite:\n");
		}
		else{
			sscanf(C_mes, "%i", &N_mes);
			
			if((N_mes < 1) || (N_mes > 12)){
				printf("\nNumero no valido, repite:\n");
			}
		
		}
 }
	}
	while (((C_mes[0] < '0' && C_mes[0] > '9') || (C_mes[1] < '0' && C_mes[1] > '9')) || (C_mes[0]== '0') || ((N_mes < 1) || (N_mes > 12)));
	
	return N_mes;
}

//MESES CAMBIO DE NÚMEROS A PALABRAS

	char *mes_nom[] = {"enero", "febrero", "marzo", "abril", "mayo", "junio", "julio", 
						"agosto", "septiembre", "octubre", "noviembre", "diciembre"};


char *meses_nombres(int N_mes){


	return mes_nom[N_mes-1];
	
}

//PORCENTAJE

float porcentaje_embalse (int anyo, int N_mes, int num_cuenca, int vector2[], int b, int num_embalse, linea vector[], linea vector1[]){
int i;
float capacidad_actual=0, capacidad_max=0, porcentaje;


switch(anyo){
	case(2012):
			i=vector2[num_cuenca-1]+(num_embalse-1)*12+(N_mes-1);
			capacidad_actual = vector[i].dosmildoce;
			capacidad_max = vector1[b-1].etotal;
		
		porcentaje = capacidad_actual*100/capacidad_max;
		break;

	case(2013):
			i=vector2[num_cuenca-1]+(num_embalse-1)*12+(N_mes-1);
			capacidad_actual =  vector[i].dosmiltrece;
			capacidad_max = vector1[b-1].etotal;
		
		porcentaje = capacidad_actual*100/capacidad_max;
		break;
	
	case(2014):
			i=vector2[num_cuenca-1]+(num_embalse-1)*12+(N_mes-1);
			capacidad_actual =  vector[i].dosmilcatorce;
			capacidad_max = vector1[b-1].etotal;
		
		porcentaje = capacidad_actual*100/capacidad_max;
		break;
		
	case(2015):
		i=vector2[num_cuenca-1]+(num_embalse-1)*12+(N_mes-1);
			capacidad_actual =  vector[i].dosmilquince;
			capacidad_max = vector1[b-1].etotal;
		//printf ("\n%i, CA %f, CM %f\n",b,capacidad_actual, capacidad_max);
		porcentaje = capacidad_actual*100/capacidad_max;
		break;	
		
	case(2016):
		i=vector2[num_cuenca-1]+(num_embalse-1)*12+(N_mes-1);
			capacidad_actual =  vector[i].dosmildieciseis;
			capacidad_max = vector1[b-1].etotal;
		
		porcentaje = capacidad_actual*100/capacidad_max;
		break;	
		
	case(2017):
		i=vector2[num_cuenca-1]+(num_embalse-1)*12+(N_mes-1);
			capacidad_actual =  vector[i].dosmildiecisiete;
			capacidad_max = vector1[b-1].etotal;
		
		porcentaje = capacidad_actual*100/capacidad_max;
		break;
		
	case(2018):
		i=vector2[num_cuenca-1]+(num_embalse-1)*12+(N_mes-1);
			capacidad_actual =  vector[i].dosmildieciocho;
			capacidad_max = vector1[b-1].etotal;
		
		porcentaje = capacidad_actual*100/capacidad_max;
		break;
		
	case(2019):
		i=vector2[num_cuenca-1]+(num_embalse-1)*12+(N_mes-1);
			capacidad_actual =  vector[i].dosmildiecinueve;
			capacidad_max = vector1[b-1].etotal;		
		
		porcentaje = capacidad_actual*100/capacidad_max;
		break;
		
	case(2020):
		i=vector2[num_cuenca-1]+(num_embalse-1)*12+(N_mes-1);
			capacidad_actual =  vector[i].dosmilveinte;
			capacidad_max = vector1[b-1].etotal;		
		
		porcentaje = capacidad_actual*100/capacidad_max;
		break;
		
	case(2021):
		i=vector2[num_cuenca-1]+(num_embalse-1)*12+(N_mes-1);
			capacidad_actual =  vector[i].dosmilveintiuno;
			capacidad_max = vector1[b-1].etotal;	
		
		porcentaje = capacidad_actual*100/capacidad_max;
		break;

}
return porcentaje;
}


//PONER ESPACIOS EN _, CUENCAS:

char cambio_espacios_cuencas (linea vector[], int num_cuenca, int vector2[], int num_embalse){
	int c=0;
	char cambio[100];
	strcpy(cambio, vector[vector2[num_cuenca-1]+(num_embalse-1)*12].cuenca_hidrografica );

	while (cambio[c] != '\0'){
		if (cambio[c] == '_'){
			cambio[c] = ' ';
		}
		c++;
	}
	strcpy(vector[vector2[num_cuenca-1]+(num_embalse-1)*12].cuenca_hidrografica, cambio );

	}

//PONER ESPACIOS EN _, CUENCAS:

char cambio_espacios_embalses (linea vector[], int num_cuenca, int vector2[], int num_embalse){
	
	int c=0;
	char cambio[100];
	strcpy(cambio, vector[vector2[num_cuenca-1]+(num_embalse-1)*12].embalse_nombre );

	while (cambio[c] != '\0'){
		if (cambio[c] == '_'){
			cambio[c] = ' ';
		}
		c++;
	}
	strcpy(vector[vector2[num_cuenca-1]+(num_embalse-1)*12].embalse_nombre, cambio );
	
	}
	
//% DE SEQUÍA

void sequia (int porcentaje){
	

		if ((50<porcentaje) && (porcentaje<70)){
			printf("\n\nPeriodo de sequia leve.");
		}		
		else if ((30<porcentaje) && (porcentaje<50)){
			printf("\n\nPeriodo de sequia moderada.");
		}
		else if (porcentaje<30){
			printf("\n\nPeriodo de sequia grave.");
		}
		else if (porcentaje>100){
			printf("\n\nEmbalse en maximos, posiblemente debordado.");
		}
		
		
}
