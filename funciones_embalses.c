#include <stdio.h>
#include <string.h>
#include "funciones_embalses.h" 


//vector2[] es posiciones_cuencas[15]
//vector es linea cuenca[4236]
//vector1 es linea embalse[353]

//NOMBRES DE CUENCAS:

void nombres_cuencas(int j,linea vector[]){
	
	int p=0, i;
	int posiciones_cuencas[15];
	for (i=0;i<j;i++){
	
	
	if (strcmp(vector[i].cuenca_hidrografica,vector[i-1].cuenca_hidrografica)!=0){
		p++;
	
		printf("%i- ", p);
		printf("%s\n",vector[i].cuenca_hidrografica);
	}

}

}

// SELECCIÓN DE CUENCA:

int seleccion_cuenca(int num_cuenca){
	
	do{
	printf("\nIntroduce el numero de la cuenca: ");
	scanf("%i", &num_cuenca);

	if((0 >= num_cuenca) || ( num_cuenca > 16 )){
		printf ("\nNumero no valido, repite:\n");
	}
	
	return num_cuenca;
}

while ((0 >= num_cuenca) || ( num_cuenca > 16 ));


}

//NOMBRES DE EMBALSES:

void nombres_cuencas_embalse(int j, int num_cuenca, linea vector[], int vector2[], int *c){
	int i,f=0, m;
		
	for (i=vector2[num_cuenca-1];i<vector2[num_cuenca];i++){
		if (i%12==0){
			printf("%i. %s\n", f+1, vector[i].embalse_nombre);
			f++;
			m++;
		
 		
		}
	
	}
/*
	if  (num_cuenca == 16){
	f=0;
	for (i<vector2[num_cuenca-1]; i<=vector2[num_cuenca];i++){
		printf("a");
		if (i%12==0){
			printf("%i. %s\n", f+1, vector[i].embalse_nombre);
			f++;
			m++;
			
		}
	}
	}*/
	*c = m;
}

// SELECCIÓN DE EMBALSES:

int seleccion_embalse(int num_embalse, int c){

	do{
	printf("\nIntroduce el numero del embalse: " );	
	
	
	scanf("%i", &num_embalse);

	if((0 > num_embalse) || ( num_embalse > c)){
		printf ("\nNumero no valido, repite:\n");
	}

}
while ((0 > num_embalse) || ( num_embalse > c));

	return num_embalse;

}

//SELECCIÓN DE AÑOS:

int seleccion_anyo(int anyo){
		
	do{
	printf("\nIntroduce el anyo deseado 2012-2021: ");
		scanf("%i", &anyo);
	if((2012 > anyo) || ( anyo > 2021 )){
		printf ("\nNumero no valido, repite:\n");
	}
}

while ((2012 > anyo) || ( anyo > 2021 ));
	
	return anyo;
}
//SELECCIÓN MES:

int seleccion_mes(int mes){
	
	do{
	printf("\nIntroduce el mes deseado: ");
		scanf("%i", &mes);
	if((1 > mes) || ( mes > 12 )){
		printf ("\nNumero no valido, repite:\n");
	}
}
while ((1 > mes) || ( mes > 12 ));

	return mes;
}

//MESES CAMBIO DE NÚMEROS A PALABRAS

	char *mes_nom[] = {"enero", "febrero", "marzo", "abril", "mayo", "junio", "julio", 
						"agosto", "septiembre", "octubre", "noviembre", "diciembre"};


char *meses_nombres(int mes){


	return mes_nom[mes-1];
	
}



float porcentaje_embalse (int anyo, int mes, int num_cuenca, int vector2[], int b, int num_embalse, linea vector[], linea vector1[]){
int i;
float capacidad_actual=0, capacidad_max=0, porcentaje;


switch(anyo){
	case(2012):
			i=vector2[num_cuenca-1]+(num_embalse-1)*12+(mes-1);
			capacidad_actual = vector[i].dosmildoce;
			capacidad_max = vector1[b-1].etotal;
		
		porcentaje = capacidad_actual*100/capacidad_max;
		break;

	case(2013):
			i=vector2[num_cuenca-1]+(num_embalse-1)*12+(mes-1);
			capacidad_actual =  vector[i].dosmiltrece;
			capacidad_max = vector1[b-1].etotal;
		
		porcentaje = capacidad_actual*100/capacidad_max;
		break;
	
	case(2014):
			i=vector2[num_cuenca-1]+(num_embalse-1)*12+(mes-1);
			capacidad_actual =  vector[i].dosmilcatorce;
			capacidad_max = vector1[b-1].etotal;
		
		porcentaje = capacidad_actual*100/capacidad_max;
		break;
		
	case(2015):
		i=vector2[num_cuenca-1]+(num_embalse-1)*12+(mes-1);
			capacidad_actual =  vector[i].dosmilquince;
			capacidad_max = vector1[b-1].etotal;
		//printf ("\n%i, CA %f, CM %f\n",b,capacidad_actual, capacidad_max);
		porcentaje = capacidad_actual*100/capacidad_max;
		break;	
		
	case(2016):
		i=vector2[num_cuenca-1]+(num_embalse-1)*12+(mes-1);
			capacidad_actual =  vector[i].dosmildieciseis;
			capacidad_max = vector1[b-1].etotal;
		
		porcentaje = capacidad_actual*100/capacidad_max;
		break;	
		
	case(2017):
		i=vector2[num_cuenca-1]+(num_embalse-1)*12+(mes-1);
			capacidad_actual =  vector[i].dosmildiecisiete;
			capacidad_max = vector1[b-1].etotal;
		
		porcentaje = capacidad_actual*100/capacidad_max;
		break;
		
	case(2018):
		i=vector2[num_cuenca-1]+(num_embalse-1)*12+(mes-1);
			capacidad_actual =  vector[i].dosmildieciocho;
			capacidad_max = vector1[b-1].etotal;
		
		porcentaje = capacidad_actual*100/capacidad_max;
		break;
		
	case(2019):
		i=vector2[num_cuenca-1]+(num_embalse-1)*12+(mes-1);
			capacidad_actual =  vector[i].dosmildiecinueve;
			capacidad_max = vector1[b-1].etotal;		
		
		porcentaje = capacidad_actual*100/capacidad_max;
		break;
		
	case(2020):
		i=vector2[num_cuenca-1]+(num_embalse-1)*12+(mes-1);
			capacidad_actual =  vector[i].dosmilveinte;
			capacidad_max = vector1[b-1].etotal;		
		
		porcentaje = capacidad_actual*100/capacidad_max;
		break;
		
	case(2021):
		i=vector2[num_cuenca-1]+(num_embalse-1)*12+(mes-1);
			capacidad_actual =  vector[i].dosmilveintiuno;
			capacidad_max = vector1[b-1].etotal;		
		
		porcentaje = capacidad_actual*100/capacidad_max;
		break;

}
return porcentaje;
}


	 
	 
	
