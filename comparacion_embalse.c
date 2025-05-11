#include <stdio.h>
#include <string.h>
#include <float.h>
#include <stdlib.h>
#include "comparacion_embalse.h"

//LISTA CUENCAS:

void nombres_cuencas(int vb, linea cuenca[]){
	
	int numc=0,i;//variables cuenca
for(i=1;i<vb;i++){
	if(strcmp(cuenca[i].cuenca_hidrografica,cuenca[i+1].cuenca_hidrografica)!=0){
		
			numc++;
			printf("%i-",numc);
			printf("%s\n",cuenca[i].cuenca_hidrografica);
			
	}
	
}
}

//SELECCION CUENCA:

int seleccion_cuenca_1(int num_cuenca, char C_cuenca[]){
		
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


//LISTADO Y SELECCION DE EMBALSES:

void nombreseleccion_embalse_1(int num_cuenca,linea cuenca[], int* num_embalse, int* l_r_embalse){
		int nume=0,i;
	switch(num_cuenca)
	{case(1):
		for(i=0;i<8*12;i++){
		if(strcmp(cuenca[i].embalse_nombre,cuenca[i-1].embalse_nombre)!=0){
			nume++;
			printf("%i-",nume);
			printf("%s\n",cuenca[i].embalse_nombre);
		}
		}
		printf("Elige un numero de embalse del Cantabrico Occidental: ");
		scanf("%i",num_embalse);
		*l_r_embalse=*num_embalse * 12;
		break;
	case(2):
	 	for(i=8*12;i<12*12;i++){
		if(strcmp(cuenca[i].embalse_nombre,cuenca[i-1].embalse_nombre)!=0){
			nume++;
			printf("%i-",nume);
			printf("%s\n",cuenca[i].embalse_nombre);
	    }}
	    printf("Elige un numero de embalse del Cantabrico Oriental: ");
	    scanf("%i",num_embalse);
	    *l_r_embalse=8*12 + *num_embalse * 12;
	    break;
	case(3):
		for(i=12*12;i<24*12;i++){
		if(strcmp(cuenca[i].embalse_nombre,cuenca[i-1].embalse_nombre)!=0){
			nume++;
			printf("%i-",nume);
			printf("%s\n",cuenca[i].embalse_nombre);
		}
		}
		printf("Elige un numero de embalse de la Cuenca Mediterranea Andaluza: ");
		scanf("%i",num_embalse);
		*l_r_embalse=12*12 + *num_embalse * 12;
		break;
	case(4):
		for(i=24*12;i<31*12;i++){
		if(strcmp(cuenca[i].embalse_nombre,cuenca[i-1].embalse_nombre)!=0){
			nume++;
			printf("%i-",nume);
			printf("%s\n",cuenca[i].embalse_nombre);
		}
		}
		printf("Elige un numero de embalse de la Cuencas Internas de Cataluna: ");
		scanf("%i",num_embalse);
		*l_r_embalse=24*12 + *num_embalse * 12;
		break;
	case(5):
		for(i=31*12;i<33*12;i++){
		if(strcmp(cuenca[i].embalse_nombre,cuenca[i-1].embalse_nombre)!=0){
			nume++;
			printf("%i-",nume);
			printf("%s\n",cuenca[i].embalse_nombre);
		}
		}
		printf("Elige un numero de embalse de la Cuencas Internas del Pais Vasco: ");
		scanf("%i",num_embalse);
		*l_r_embalse=31*12 + *num_embalse * 12;
		break;
	case(6):
		for(i=33*12;i<67*12;i++){
		if(strcmp(cuenca[i].embalse_nombre,cuenca[i-1].embalse_nombre)!=0){
			nume++;
			printf("%i-",nume);
			printf("%s\n",cuenca[i].embalse_nombre);
		}
		}
		printf("Elige un numero de embalse de la Cuenca del Duero: ");
		scanf("%i",num_embalse);
		*l_r_embalse=33*12 + *num_embalse * 12;
		break;
	case(7):
		for(i=67*12;i<129*12;i++){
		if(strcmp(cuenca[i].embalse_nombre,cuenca[i-1].embalse_nombre)!=0){
			nume++;
			printf("%i-",nume);
			printf("%s\n",cuenca[i].embalse_nombre);
		}
		}
		printf("Elige un numero de embalse de la Cuenca del Ebro: ");
		scanf("%i",num_embalse);
		*l_r_embalse=67*12 + *num_embalse * 12;
		break;
	case(8):
		for(i=129*12;i<140*12;i++){
		if(strcmp(cuenca[i].embalse_nombre,cuenca[i-1].embalse_nombre)!=0){
			nume++;
			printf("%i-",nume);
			printf("%s\n",cuenca[i].embalse_nombre);
		}
		}
		printf("Elige un numero de embalse de la Cuenca de Costa de Galicia: ");
		scanf("%i",num_embalse);
		*l_r_embalse=129*12 + *num_embalse * 12;
		break;
	case(9):
		for(i=140*12;i<148*12;i++){
		if(strcmp(cuenca[i].embalse_nombre,cuenca[i-1].embalse_nombre)!=0){
			nume++;
			printf("%i-",nume);
			printf("%s\n",cuenca[i].embalse_nombre);
		}
		}
		printf("Elige un numero de embalse de la Cuenca de Guadalete-Barbete: ");
		scanf("%i",num_embalse);
		*l_r_embalse=140*12+ *num_embalse * 12;
		break;
	case(10):
		for(i=148*12;i<194*12;i++){
		if(strcmp(cuenca[i].embalse_nombre,cuenca[i-1].embalse_nombre)!=0){
			nume++;
			printf("%i-",nume);
			printf("%s\n",cuenca[i].embalse_nombre);
		}
		}
		printf("Elige un numero de embalse de la Cuenca del Guadalquivir: ");
		scanf("%i",num_embalse);
		*l_r_embalse=148*12+ *num_embalse * 12;
		break;
	case(11):
		for(i=194*12;i<228*12;i++){
		if(strcmp(cuenca[i].embalse_nombre,cuenca[i-1].embalse_nombre)!=0){
			nume++;
			printf("%i-",nume);
			printf("%s\n",cuenca[i].embalse_nombre);
		}
		}
		printf("Elige un numero de embalse de la Cuenca del Guadiana: ");
		scanf("%i",num_embalse);
		*l_r_embalse=194*12 + *num_embalse * 12;
		break;
	case(12):
		for(i=228*12;i<251*12;i++){
		if(strcmp(cuenca[i].embalse_nombre,cuenca[i-1].embalse_nombre)!=0){
			nume++;
			printf("%i-",nume);
			printf("%s\n",cuenca[i].embalse_nombre);
		}
		}
		printf("Elige un numero de embalse de la Cuenca de Jucar: ");
		scanf("%i",num_embalse);
		*l_r_embalse=228*12+ *num_embalse * 12;
		break;
	case(13):
		for(i=251*12;i<280*12;i++){
		if(strcmp(cuenca[i].embalse_nombre,cuenca[i-1].embalse_nombre)!=0){
			nume++;
			printf("%i-",nume);
			printf("%s\n",cuenca[i].embalse_nombre);
		}
		}
		printf("Elige un numero de embalse de la Cuenca de Mino-Sil: ");
		scanf("%i",num_embalse);
		*l_r_embalse=251*12+ *num_embalse * 12;
		break;
	case(14):
		for(i=280*12;i<295*12;i++){
		if(strcmp(cuenca[i].embalse_nombre,cuenca[i-1].embalse_nombre)!=0){
			nume++;
			printf("%i-",nume);
			printf("%s\n",cuenca[i].embalse_nombre);
		}
		}
		printf("Elige un numero de embalse de la Cuenca de Segura: ");
		scanf("%i",num_embalse);
		*l_r_embalse=280*12+ *num_embalse * 12;
		break;
	case(15):
		for(i=295*12;i<346*12;i++){
		if(strcmp(cuenca[i].embalse_nombre,cuenca[i-1].embalse_nombre)!=0){
			nume++;
			printf("%i-",nume);
			printf("%s\n",cuenca[i].embalse_nombre);
		}
		}
		printf("Elige un numero de embalse de la Cuenca del Tajo: ");
		scanf("%i",num_embalse);
		*l_r_embalse=295*12+ *num_embalse * 12;
		break;
	case(16):
		for(i=346*12;i<353*12;i++){
		if(strcmp(cuenca[i].embalse_nombre,cuenca[i-1].embalse_nombre)!=0){
			nume++;
			printf("%i-",nume);
			printf("%s\n",cuenca[i].embalse_nombre);
		}
		}
		printf("Elige un numero de embalse de la Cuenca de Tinto,Odiel y Piedras: ");
		scanf("%i",num_embalse);
		*l_r_embalse=346*12+ *num_embalse * 12;
		break;
	}
	printf("\nAhora elegiremos el embalse a comparar. \n");
}


//SELECCION CUENCA 2
int seleccion_cuenca_2(int num_cuenca2, char C_cuenca2[]){
	
	do{
	
	printf("\nIntroduce el numero de la cuenca: ");
	scanf("%s", C_cuenca2);
	
	if(('9'<C_cuenca2[0] && C_cuenca2[0]<'0') && ('9'<C_cuenca2[1] && C_cuenca2[1]<'0')){
		printf ("\nCaracter no valido, repite:\n");	
	}
	else{	
		if (C_cuenca2[0] == '0'){
			printf ("\nbNumero no valido, repite:\n");
		}
		
		else{		
			sscanf(C_cuenca2, "%i", &num_cuenca2);
			if((0 >= num_cuenca2) || ( num_cuenca2 > 16 )){
				printf ("\ncNumero no valido, repite:\n");
			}
		}
        }
}

while ((0 >= num_cuenca2) || ( num_cuenca2 > 16 ) || (('9'<C_cuenca2[0] && C_cuenca2[0]<'0') && ('9'<C_cuenca2[1] && C_cuenca2[1]<'0')) || (C_cuenca2[0] == '0'));

return num_cuenca2;

}


//SELECCION EMBALSE 2:
void nombreseleccion_embalse_2(int num_cuenca2,linea cuenca[], int* num_embalse2, int* l_r_embalse2){
	int nume2=0,i;
	switch(num_cuenca2)
	{case(1):
		for(i=0;i<8*12;i++){
		if(strcmp(cuenca[i].embalse_nombre,cuenca[i-1].embalse_nombre)!=0){
			nume2++;
			printf("%i-",nume2);
			printf("%s\n",cuenca[i].embalse_nombre);
		}
		}
		printf("Elige un numero de embalse del Cantabrico Occidental: ");
		scanf("%i",num_embalse2);
		*l_r_embalse2=*num_embalse2 * 12;
		break;
	case(2):
	 	for(i=8*12;i<12*12;i++){
		if(strcmp(cuenca[i].embalse_nombre,cuenca[i-1].embalse_nombre)!=0){
			nume2++;
			printf("%i-",nume2);
			printf("%s\n",cuenca[i].embalse_nombre);
	    }}
	    printf("Elige un numero de embalse del Cantabrico Oriental: ");
	    scanf("%i",num_embalse2);
	    *l_r_embalse2=8*12+ *num_embalse2 * 12;
	    break;
	case(3):
		for(i=12*12;i<24*12;i++){
		if(strcmp(cuenca[i].embalse_nombre,cuenca[i-1].embalse_nombre)!=0){
			nume2++;
			printf("%i-",nume2);
			printf("%s\n",cuenca[i].embalse_nombre);
		}
		}
		printf("Elige un numero de embalse de la Cuenca Mediterranea Andaluza: ");
		scanf("%i",num_embalse2);
		*l_r_embalse2=12*12+ *num_embalse2 * 12;
		break;
	case(4):
		for(i=24*12;i<31*12;i++){
		if(strcmp(cuenca[i].embalse_nombre,cuenca[i-1].embalse_nombre)!=0){
			nume2++;
			printf("%i-",nume2);
			printf("%s\n",cuenca[i].embalse_nombre);
		}
		}
		printf("Elige un numero de embalse de la Cuencas Internas de Cataluna: ");
		scanf("%i",num_embalse2);
		*l_r_embalse2=24*12+ *num_embalse2 * 12;
		break;
	case(5):
		for(i=31*12;i<33*12;i++){
		if(strcmp(cuenca[i].embalse_nombre,cuenca[i-1].embalse_nombre)!=0){
			nume2++;
			printf("%i-",nume2);
			printf("%s\n",cuenca[i].embalse_nombre);
		}
		}
		printf("Elige un numero de embalse de la Cuencas Internas del Pais Vasco: ");
		scanf("%i",num_embalse2);
		*l_r_embalse2=31*12+ *num_embalse2 * 12;
		break;
	case(6):
		for(i=33*12;i<67*12;i++){
		if(strcmp(cuenca[i].embalse_nombre,cuenca[i-1].embalse_nombre)!=0){
			nume2++;
			printf("%i-",nume2);
			printf("%s\n",cuenca[i].embalse_nombre);
		}
		}
		printf("Elige un numero de embalse de la Cuenca del Duero: ");
		scanf("%i",num_embalse2);
		*l_r_embalse2=33*12+ *num_embalse2 * 12;
		break;
	case(7):
		for(i=67*12;i<129*12;i++){
		if(strcmp(cuenca[i].embalse_nombre,cuenca[i-1].embalse_nombre)!=0){
			nume2++;
			printf("%i-",nume2);
			printf("%s\n",cuenca[i].embalse_nombre);
		}
		}
		printf("Elige un numero de embalse de la Cuenca del Ebro: ");
		scanf("%i",num_embalse2);
		*l_r_embalse2=67*12+ *num_embalse2 * 12;
		break;
	case(8):
		for(i=129*12;i<140*12;i++){
		if(strcmp(cuenca[i].embalse_nombre,cuenca[i-1].embalse_nombre)!=0){
			nume2++;
			printf("%i-",nume2);
			printf("%s\n",cuenca[i].embalse_nombre);
		}
		}
		printf("Elige un numero de embalse de la Cuenca de Costa de Galicia: ");
		scanf("%i",num_embalse2);
		*l_r_embalse2=129*12+ *num_embalse2 * 12;
		break;
	case(9):
		for(i=140*12;i<148*12;i++){
		if(strcmp(cuenca[i].embalse_nombre,cuenca[i-1].embalse_nombre)!=0){
			nume2++;
			printf("%i-",nume2);
			printf("%s\n",cuenca[i].embalse_nombre);
		}
		}
		printf("Elige un numero de embalse de la Cuenca de Guadalete-Barbete: ");
		scanf("%i",num_embalse2);
		*l_r_embalse2=140*12+ *num_embalse2 * 12;
		break;
	case(10):
		for(i=148*12;i<194*12;i++){
		if(strcmp(cuenca[i].embalse_nombre,cuenca[i-1].embalse_nombre)!=0){
			nume2++;
			printf("%i-",nume2);
			printf("%s\n",cuenca[i].embalse_nombre);
		}
		}
		printf("Elige un numero de embalse de la Cuenca del Guadalquivir: ");
		scanf("%i",num_embalse2);
		*l_r_embalse2=148*12+ *num_embalse2 * 12;
		break;
	case(11):
		for(i=194*12;i<228*12;i++){
		if(strcmp(cuenca[i].embalse_nombre,cuenca[i-1].embalse_nombre)!=0){
			nume2++;
			printf("%i-",nume2);
			printf("%s\n",cuenca[i].embalse_nombre);
		}
		}
		printf("Elige un numero de embalse de la Cuenca del Guadiana: ");
		scanf("%i",num_embalse2);
		*l_r_embalse2=194*12+ *num_embalse2 * 12;
		break;
	case(12):
		for(i=228*12;i<251*12;i++){
		if(strcmp(cuenca[i].embalse_nombre,cuenca[i-1].embalse_nombre)!=0){
			nume2++;
			printf("%i-",nume2);
			printf("%s\n",cuenca[i].embalse_nombre);
		}
		}
		printf("Elige un numero de embalse de la Cuenca de Jucar: ");
		scanf("%i",num_embalse2);
		*l_r_embalse2=228*12+ *num_embalse2 * 12;
		break;
	case(13):
		for(i=251*12;i<280*12;i++){
		if(strcmp(cuenca[i].embalse_nombre,cuenca[i-1].embalse_nombre)!=0){
			nume2++;
			printf("%i-",nume2);
			printf("%s\n",cuenca[i].embalse_nombre);
		}
		}
		printf("Elige un numero de embalse de la Cuenca de Mino-Sil: ");
		scanf("%i",num_embalse2);
		*l_r_embalse2=251*12+ *num_embalse2 * 12;
		break;
	case(14):
		for(i=280*12;i<295*12;i++){
		if(strcmp(cuenca[i].embalse_nombre,cuenca[i-1].embalse_nombre)!=0){
			nume2++;
			printf("%i-",nume2);
			printf("%s\n",cuenca[i].embalse_nombre);
		}
		}
		printf("Elige un numero de embalse de la Cuenca de Segura: ");
		scanf("%i",num_embalse2);
		*l_r_embalse2=280*12+ *num_embalse2 * 12;
		break;
	case(15):
		for(i=295*12;i<346*12;i++){
		if(strcmp(cuenca[i].embalse_nombre,cuenca[i-1].embalse_nombre)!=0){
			nume2++;
			printf("%i-",nume2);
			printf("%s\n",cuenca[i].embalse_nombre);
		}
		}
		printf("Elige un numero de embalse de la Cuenca del Tajo: ");
		scanf("%i",num_embalse2);
		*l_r_embalse2=295*12+ *num_embalse2 * 12;
		break;
	case(16):
		for(i=346*12;i<353*12;i++){
		if(strcmp(cuenca[i].embalse_nombre,cuenca[i-1].embalse_nombre)!=0){
			nume2++;
			printf("%i-",nume2);
			printf("%s\n",cuenca[i].embalse_nombre);
		}
		}
		printf("Elige un numero de embalse de la Cuenca de Tinto,Odiel y Piedras: ");
		scanf("%i",num_embalse2);
		*l_r_embalse2=346*12+ *num_embalse2 * 12;
		break;
	}
}


//TIPO COMPARACION
int tipo_comparacion(int mes_anyo){
	do {
printf("\n¿Que informacion precisas?\n");
printf("1.-Comparacion de embalses segun el anyo\n2.-Comparacion de embalses segun el mes.\n");	
scanf("%i",&mes_anyo);
if(mes_anyo<=0||mes_anyo>2){
	printf("Numero invalido, vuelva a intentarlo.\n");
}
}
while(mes_anyo<=0||mes_anyo>2);
}


//SELECCION AÑO:
int seleccion_anyos(int anyo){
	do {
		printf("\nIntroduce el anyo deseado 2012-2021.\n");
		scanf("%i",&anyo);
		if(anyo<2012||anyo>2021){
			("Anyo invalido, intentalo otra vez.\n");
		}
	}while(anyo<2012||anyo>2021);
}


//SELECCION MES:
int seleccion_mese(int mes){
	do {
		printf("\nIntroduce el mes deseado 1-12.\n");
		scanf("%i",&mes);
		if(mes<1||mes>12){
			("Anyo invalido, intentalo otra vez.\n");
		}
	}while(mes<1||mes>12);
}



//COMPARACION SEGUN AÑO:
void comparacion_anyo(int mes_anyo, int anyo, int l_r_embalse, int l_r_embalse2, linea cuenca[]){
		float min= FLT_MAX;
	float max=FLT_MIN;
	float min2= FLT_MAX;
	float max2=FLT_MIN;
	float res;
	

	
	switch(anyo){
		case(2012):
		    for(int  j=l_r_embalse-12; j<l_r_embalse-1; j++){
				if(cuenca[j].dosmildoce<min){min=cuenca[j].dosmildoce;}
				if(cuenca[j].dosmildoce>max){max=cuenca[j].dosmildoce;}
	         }
	        for(int  k=l_r_embalse2-12; k<l_r_embalse2-1; k++){
				if(cuenca[k].dosmildoce<min2){min2=cuenca[k].dosmildoce;}
				if(cuenca[k].dosmildoce>max2){max2=cuenca[k].dosmildoce;}
	         }
	         printf("\nLa capacidad del primer embalse %s en %i va de %.2f-%.2f\n", cuenca[l_r_embalse-1].embalse_nombre,anyo,min,max);
	         printf("La capacidad del segundo embalse %s en %i va de %.2f-%.2f\n", cuenca[l_r_embalse2-1].embalse_nombre,anyo,min2,max2);
	         if(max2>max){printf("%s sobrepaso en %.2f hm^3 a %s en su capacidad mas alta.\n", cuenca[l_r_embalse2-1].embalse_nombre,res=max2-max,cuenca[l_r_embalse-1].embalse_nombre);}
	         if(max>max2){printf("%s sobrepaso en %.2f hm^3 a %s en su capacidad mas alta.\n", cuenca[l_r_embalse-1].embalse_nombre,res=max-max2,cuenca[l_r_embalse2-1].embalse_nombre);}
	         if(max==max2){printf("%s y %s coincidieron en su capacidad mas alta.\n", cuenca[l_r_embalse-1].embalse_nombre,cuenca[l_r_embalse2-1].embalse_nombre);}
	         break;
	    case(2013):
		    for(int  j=l_r_embalse-12; j<l_r_embalse-1; j++){
				if(cuenca[j].dosmiltrece<min){min=cuenca[j].dosmiltrece;}
				if(cuenca[j].dosmiltrece>max){max=cuenca[j].dosmiltrece;}
	         }
	        for(int  k=l_r_embalse2-12; k<l_r_embalse2-1; k++){
				if(cuenca[k].dosmiltrece<min2){min2=cuenca[k].dosmiltrece;}
				if(cuenca[k].dosmiltrece>max2){max2=cuenca[k].dosmiltrece;}
	         }
	         printf("\nLa capacidad del primer embalse %s en %i va de %.2f-%.2f\n", cuenca[l_r_embalse-1].embalse_nombre,anyo,min,max);
	         printf("La capacidad del segundo embalse %s en %i va de %.2f-%.2f\n", cuenca[l_r_embalse2-1].embalse_nombre,anyo,min2,max2);
	         if(max2>max){printf("%s sobrepaso en %.2f hm^3 a %s en su capacidad mas alta.\n", cuenca[l_r_embalse2-1].embalse_nombre,res=max2-max,cuenca[l_r_embalse-1].embalse_nombre);}
	         if(max>max2){printf("%s sobrepaso en %.2f hm^3 a %s en su capacidad mas alta.\n", cuenca[l_r_embalse-1].embalse_nombre,res=max-max2,cuenca[l_r_embalse2-1].embalse_nombre);}
	         if(max==max2){printf("%s y %s coincidieron en su capacidad mas alta.\n", cuenca[l_r_embalse-1].embalse_nombre,cuenca[l_r_embalse2-1].embalse_nombre);}
	         break;
	    case(2014):
		    for(int  j=l_r_embalse-12; j<l_r_embalse-1; j++){
				if(cuenca[j].dosmilcatorce<min){min=cuenca[j].dosmilcatorce;}
				if(cuenca[j].dosmilcatorce>max){max=cuenca[j].dosmilcatorce;}
	         }
	        for(int  k=l_r_embalse2-12; k<l_r_embalse2-1; k++){
				if(cuenca[k].dosmilcatorce<min2){min2=cuenca[k].dosmilcatorce;}
				if(cuenca[k].dosmilcatorce>max2){max2=cuenca[k].dosmilcatorce;}
	         }
	         printf("\nLa capacidad del primer embalse %s en %i va de %.2f-%.2f\n", cuenca[l_r_embalse-1].embalse_nombre,anyo,min,max);
	         printf("La capacidad del segundo embalse %s en %i va de %.2f-%.2f\n", cuenca[l_r_embalse2-1].embalse_nombre,anyo,min2,max2);
	         if(max2>max){printf("%s sobrepaso en %.2f hm^3 a %s en su capacidad mas alta.\n", cuenca[l_r_embalse2-1].embalse_nombre,res=max2-max,cuenca[l_r_embalse-1].embalse_nombre);}
	         if(max>max2){printf("%s sobrepaso en %.2f hm^3 a %s en su capacidad mas alta.\n", cuenca[l_r_embalse-1].embalse_nombre,res=max-max2,cuenca[l_r_embalse2-1].embalse_nombre);}
	         if(max==max2){printf("%s y %s coincidieron en su capacidad mas alta.\n", cuenca[l_r_embalse-1].embalse_nombre,cuenca[l_r_embalse2-1].embalse_nombre);}
	         break;
	    case(2015):
		    for(int  j=l_r_embalse-12; j<l_r_embalse-1; j++){
				if(cuenca[j].dosmilquince<min){min=cuenca[j].dosmilquince;}
				if(cuenca[j].dosmilquince>max){max=cuenca[j].dosmilquince;}
	         }
	        for(int  k=l_r_embalse2-12; k<l_r_embalse2-1; k++){
				if(cuenca[k].dosmilquince<min2){min2=cuenca[k].dosmilquince;}
				if(cuenca[k].dosmilquince>max2){max2=cuenca[k].dosmilquince;}
	         }
	         printf("\nLa capacidad del primer embalse %s en %i va de %.2f-%.2f\n", cuenca[l_r_embalse-1].embalse_nombre,anyo,min,max);
	         printf("La capacidad del segundo embalse %s en %i va de %.2f-%.2f\n", cuenca[l_r_embalse2-1].embalse_nombre,anyo,min2,max2);
	         if(max2>max){printf("%s sobrepaso en %.2f hm^3 a %s en su capacidad mas alta.\n", cuenca[l_r_embalse2-1].embalse_nombre,res=max2-max,cuenca[l_r_embalse-1].embalse_nombre);}
	         if(max>max2){printf("%s sobrepaso en %.2f hm^3 a %s en su capacidad mas alta.\n", cuenca[l_r_embalse-1].embalse_nombre,res=max-max2,cuenca[l_r_embalse2-1].embalse_nombre);}
	         if(max==max2){printf("%s y %s coincidieron en su capacidad mas alta.\n", cuenca[l_r_embalse-1].embalse_nombre,cuenca[l_r_embalse2-1].embalse_nombre);}
	         break;
	    case(2016):
		    for(int  j=l_r_embalse-12; j<l_r_embalse-1; j++){
				if(cuenca[j].dosmildieciseis<min){min=cuenca[j].dosmildieciseis;}
				if(cuenca[j].dosmildieciseis>max){max=cuenca[j].dosmildieciseis;}
	         }
	        for(int  k=l_r_embalse2-12; k<l_r_embalse2-1; k++){
				if(cuenca[k].dosmildieciseis<min2){min2=cuenca[k].dosmildieciseis;}
				if(cuenca[k].dosmildieciseis>max2){max2=cuenca[k].dosmildieciseis;}
	         }
	         printf("\nLa capacidad del primer embalse %s en %i va de %.2f-%.2f\n", cuenca[l_r_embalse-1].embalse_nombre,anyo,min,max);
	         printf("La capacidad del segundo embalse %s en %i va de %.2f-%.2f\n", cuenca[l_r_embalse2-1].embalse_nombre,anyo,min2,max2);
	         if(max2>max){printf("%s sobrepaso en %.2f hm^3 a %s en su capacidad mas alta.\n", cuenca[l_r_embalse2-1].embalse_nombre,res=max2-max,cuenca[l_r_embalse-1].embalse_nombre);}
	         if(max>max2){printf("%s sobrepaso en %.2f hm^3 a %s en su capacidad mas alta.\n", cuenca[l_r_embalse-1].embalse_nombre,res=max-max2,cuenca[l_r_embalse2-1].embalse_nombre);}
	         if(max==max2){printf("%s y %s coincidieron en su capacidad mas alta.\n", cuenca[l_r_embalse-1].embalse_nombre,cuenca[l_r_embalse2-1].embalse_nombre);}
	         break;
	    case(2017):
		    for(int  j=l_r_embalse-12; j<l_r_embalse-1; j++){
				if(cuenca[j].dosmildiecisiete<min){min=cuenca[j].dosmildiecisiete;}
				if(cuenca[j].dosmildiecisiete>max){max=cuenca[j].dosmildiecisiete;}
	         }
	        for(int  k=l_r_embalse2-12; k<l_r_embalse2-1; k++){
				if(cuenca[k].dosmildiecisiete<min2){min2=cuenca[k].dosmildiecisiete;}
				if(cuenca[k].dosmildiecisiete>max2){max2=cuenca[k].dosmildiecisiete;}
	         }
	         printf("\nLa capacidad del primer embalse %s en %i va de %.2f-%.2f\n", cuenca[l_r_embalse-1].embalse_nombre,anyo,min,max);
	         printf("La capacidad del segundo embalse %s en %i va de %.2f-%.2f\n", cuenca[l_r_embalse2-1].embalse_nombre,anyo,min2,max2);
	         if(max2>max){printf("%s sobrepaso en %.2f hm^3 a %s en su capacidad mas alta.\n", cuenca[l_r_embalse2-1].embalse_nombre,res=max2-max,cuenca[l_r_embalse-1].embalse_nombre);}
	         if(max>max2){printf("%s sobrepaso en %.2f hm^3 a %s en su capacidad mas alta.\n", cuenca[l_r_embalse-1].embalse_nombre,res=max-max2,cuenca[l_r_embalse2-1].embalse_nombre);}
	         if(max==max2){printf("%s y %s coincidieron en su capacidad mas alta.\n", cuenca[l_r_embalse-1].embalse_nombre,cuenca[l_r_embalse2-1].embalse_nombre);}
	         break;
	    case(2018):
		    for(int  j=l_r_embalse-12; j<l_r_embalse-1; j++){
				if(cuenca[j].dosmildieciocho<min){min=cuenca[j].dosmildieciocho;}
				if(cuenca[j].dosmildieciocho>max){max=cuenca[j].dosmildieciocho;}
	         }
	        for(int  k=l_r_embalse2-12; k<l_r_embalse2-1; k++){
				if(cuenca[k].dosmildieciocho<min2){min2=cuenca[k].dosmildieciocho;}
				if(cuenca[k].dosmildieciocho>max2){max2=cuenca[k].dosmildieciocho;}
	         }
	         printf("\nLa capacidad del primer embalse %s en %i va de %.2f-%.2f\n", cuenca[l_r_embalse-1].embalse_nombre,anyo,min,max);
	         printf("La capacidad del segundo embalse %s en %i va de %.2f-%.2f\n", cuenca[l_r_embalse2-1].embalse_nombre,anyo,min2,max2);
	         if(max2>max){printf("%s sobrepaso en %.2f hm^3 a %s en su capacidad mas alta.\n", cuenca[l_r_embalse2-1].embalse_nombre,res=max2-max,cuenca[l_r_embalse-1].embalse_nombre);}
	         if(max>max2){printf("%s sobrepaso en %.2f hm^3 a %s en su capacidad mas alta.\n", cuenca[l_r_embalse-1].embalse_nombre,res=max-max2,cuenca[l_r_embalse2-1].embalse_nombre);}
	         if(max==max2){printf("%s y %s coincidieron en su capacidad mas alta.\n", cuenca[l_r_embalse-1].embalse_nombre,cuenca[l_r_embalse2-1].embalse_nombre);}
	         break;
	    case(2019):
		    for(int  j=l_r_embalse-12; j<l_r_embalse-1; j++){
				if(cuenca[j].dosmildiecinueve<min){min=cuenca[j].dosmildiecinueve;}
				if(cuenca[j].dosmildiecinueve>max){max=cuenca[j].dosmildiecinueve;}
	         }
	        for(int  k=l_r_embalse2-12; k<l_r_embalse2-1; k++){
				if(cuenca[k].dosmildiecinueve<min2){min2=cuenca[k].dosmildiecinueve;}
				if(cuenca[k].dosmildiecinueve>max2){max2=cuenca[k].dosmildiecinueve;}
	         }
	         printf("\nLa capacidad del primer embalse %s en %i va de %.2f-%.2f\n", cuenca[l_r_embalse-1].embalse_nombre,anyo,min,max);
	         printf("La capacidad del segundo embalse %s en %i va de %.2f-%.2f\n", cuenca[l_r_embalse2-1].embalse_nombre,anyo,min2,max2);
	         if(max2>max){printf("%s sobrepaso en %.2f hm^3 a %s en su capacidad mas alta.\n", cuenca[l_r_embalse2-1].embalse_nombre,res=max2-max,cuenca[l_r_embalse-1].embalse_nombre);}
	         if(max>max2){printf("%s sobrepaso en %.2f hm^3 a %s en su capacidad mas alta.\n", cuenca[l_r_embalse-1].embalse_nombre,res=max-max2,cuenca[l_r_embalse2-1].embalse_nombre);}
	         if(max==max2){printf("%s y %s coincidieron en su capacidad mas alta.\n", cuenca[l_r_embalse-1].embalse_nombre,cuenca[l_r_embalse2-1].embalse_nombre);}
	         break;
	    case(2020):
		    for(int  j=l_r_embalse-12; j<l_r_embalse-1; j++){
				if(cuenca[j].dosmilveinte<min){min=cuenca[j].dosmilveinte;}
				if(cuenca[j].dosmilveinte>max){max=cuenca[j].dosmilveinte;}
	         }
	        for(int  k=l_r_embalse2-12; k<l_r_embalse2-1; k++){
				if(cuenca[k].dosmilveinte<min2){min2=cuenca[k].dosmilveinte;}
				if(cuenca[k].dosmilveinte>max2){max2=cuenca[k].dosmilveinte;}
	         }
	         printf("\nLa capacidad del primer embalse %s en %i va de %.2f-%.2f\n", cuenca[l_r_embalse-1].embalse_nombre,anyo,min,max);
	         printf("La capacidad del segundo embalse %s en %i va de %.2f-%.2f\n", cuenca[l_r_embalse2-1].embalse_nombre,anyo,min2,max2);
	         if(max2>max){printf("%s sobrepaso en %.2f hm^3 a %s en su capacidad mas alta.\n", cuenca[l_r_embalse2-1].embalse_nombre,res=max2-max,cuenca[l_r_embalse-1].embalse_nombre);}
	         if(max>max2){printf("%s sobrepaso en %.2f hm^3 a %s en su capacidad mas alta.\n", cuenca[l_r_embalse-1].embalse_nombre,res=max-max2,cuenca[l_r_embalse2-1].embalse_nombre);}
	         if(max==max2){printf("%s y %s coincidieron en su capacidad mas alta.\n", cuenca[l_r_embalse-1].embalse_nombre,cuenca[l_r_embalse2-1].embalse_nombre);}
	         break;
	    case(2021):
		    for(int  j=l_r_embalse-12; j<l_r_embalse-1; j++){
				if(cuenca[j].dosmilveintiuno<min){min=cuenca[j].dosmilveintiuno;}
				if(cuenca[j].dosmilveintiuno>max){max=cuenca[j].dosmilveintiuno;}
	         }
	        for(int  k=l_r_embalse2-12; k<l_r_embalse2-1; k++){
				if(cuenca[k].dosmilveintiuno<min2){min2=cuenca[k].dosmilveintiuno;}
				if(cuenca[k].dosmilveintiuno>max2){max2=cuenca[k].dosmilveintiuno;}
	         }
	         printf("\nLa capacidad del primer embalse %s en %i va de %.2f-%.2f\n", cuenca[l_r_embalse-1].embalse_nombre,anyo,min,max);
	         printf("La capacidad del segundo embalse %s en %i va de %.2f-%.2f\n", cuenca[l_r_embalse2-1].embalse_nombre,anyo,min2,max2);
	         if(max2>max){printf("%s sobrepaso en %.2f hm^3 a %s en su capacidad mas alta.\n", cuenca[l_r_embalse2-1].embalse_nombre,res=max2-max,cuenca[l_r_embalse-1].embalse_nombre);}
	         if(max>max2){printf("%s sobrepaso en %.2f hm^3 a %s en su capacidad mas alta.\n", cuenca[l_r_embalse-1].embalse_nombre,res=max-max2,cuenca[l_r_embalse2-1].embalse_nombre);}
	         if(max==max2){printf("%s y %s coincidieron en su capacidad mas alta.\n", cuenca[l_r_embalse-1].embalse_nombre,cuenca[l_r_embalse2-1].embalse_nombre);}
	         break;
}
}


//COMPARACION SEGUN MES
void comparacion_mes( int mes_anyo, int anyo, int mes, int l_r_embalse, int l_r_embalse2, linea cuenca[]){
		float res_mes,max_mes,min_mes;
	
	    
	switch(anyo){
		case(2012):
			printf("La capacidad del primer embalse %s en el %i mes del %i es %.2f.\n",cuenca[l_r_embalse-1].embalse_nombre,mes,anyo,cuenca[l_r_embalse-13+mes].dosmildoce);
			printf("La capacidad del segundo embalse %s en el %i mes del %i es %.2f.\n",cuenca[l_r_embalse2-1].embalse_nombre,mes,anyo,cuenca[l_r_embalse2-13+mes].dosmildoce);
			if(cuenca[l_r_embalse2-13+mes].dosmildoce>cuenca[l_r_embalse-13+mes].dosmildoce){
			   max_mes=	cuenca[l_r_embalse2-13+mes].dosmildoce;
			   min_mes=cuenca[l_r_embalse-13+mes].dosmildoce;
			   printf("%s sobrepaso en %.2f hm^3 a %s en el %i mes.\n", cuenca[l_r_embalse2-1].embalse_nombre,res_mes=max_mes-min_mes,cuenca[l_r_embalse-1].embalse_nombre,mes);}
	        if(cuenca[l_r_embalse-13+mes].dosmildoce>cuenca[l_r_embalse2-13+mes].dosmildoce){
			   max_mes=	cuenca[l_r_embalse-13+mes].dosmildoce;
			   min_mes=cuenca[l_r_embalse2-13+mes].dosmildoce;
			   printf("%s sobrepaso en %.2f hm^3 a %s en el %i mes.\n", cuenca[l_r_embalse-1].embalse_nombre,res_mes=max_mes-min_mes,cuenca[l_r_embalse2-1].embalse_nombre,mes);}
	        if(cuenca[l_r_embalse2-13+mes].dosmildoce==cuenca[l_r_embalse-13+mes].dosmildoce){
			   printf("%s y %s tinen la misma capacidad en el %i mes.\n", cuenca[l_r_embalse2-1].embalse_nombre,cuenca[l_r_embalse-1].embalse_nombre,mes);}
			break;
		case(2013):
			printf("La capacidad del primer embalse %s en el %i mes del %i es %.2f.\n",cuenca[l_r_embalse-1].embalse_nombre,mes,anyo,cuenca[l_r_embalse-13+mes].dosmiltrece);
			printf("La capacidad del segundo embalse %s en el %i mes del %i es %.2f.\n",cuenca[l_r_embalse2-1].embalse_nombre,mes,anyo,cuenca[l_r_embalse2-13+mes].dosmiltrece);
			if(cuenca[l_r_embalse2-13+mes].dosmiltrece>cuenca[l_r_embalse-13+mes].dosmiltrece){
			   max_mes=	cuenca[l_r_embalse2-13+mes].dosmiltrece;
			   min_mes=cuenca[l_r_embalse-13+mes].dosmiltrece;
			   printf("%s sobrepaso en %.2f hm^3 a %s en el %i mes.\n", cuenca[l_r_embalse2-1].embalse_nombre,res_mes=max_mes-min_mes,cuenca[l_r_embalse-1].embalse_nombre,mes);}
	        if(cuenca[l_r_embalse-13+mes].dosmiltrece>cuenca[l_r_embalse2-13+mes].dosmiltrece){
			   max_mes=	cuenca[l_r_embalse-13+mes].dosmiltrece;
			   min_mes=cuenca[l_r_embalse2-13+mes].dosmiltrece;
			   printf("%s sobrepaso en %.2f hm^3 a %s en el %i mes.\n", cuenca[l_r_embalse-1].embalse_nombre,res_mes=max_mes-min_mes,cuenca[l_r_embalse2-1].embalse_nombre,mes);}
	        if(cuenca[l_r_embalse2-13+mes].dosmiltrece==cuenca[l_r_embalse-13+mes].dosmiltrece){
			   printf("%s y %s tinen la misma capacidad en el %i mes.\n", cuenca[l_r_embalse2-1].embalse_nombre,cuenca[l_r_embalse-1].embalse_nombre,mes);}
			break;
		case(2014):
			printf("La capacidad del primer embalse %s en el %i mes del %i es %.2f.\n",cuenca[l_r_embalse-1].embalse_nombre,mes,anyo,cuenca[l_r_embalse-13+mes].dosmilcatorce);
			printf("La capacidad del segundo embalse %s en el %i mes del %i es %.2f.\n",cuenca[l_r_embalse2-1].embalse_nombre,mes,anyo,cuenca[l_r_embalse2-13+mes].dosmilcatorce);
			if(cuenca[l_r_embalse2-13+mes].dosmilcatorce>cuenca[l_r_embalse-13+mes].dosmilcatorce){
			   max_mes=	cuenca[l_r_embalse2-13+mes].dosmilcatorce;
			   min_mes=cuenca[l_r_embalse-13+mes].dosmilcatorce;
			   printf("%s sobrepaso en %.2f hm^3 a %s en el %i mes.\n", cuenca[l_r_embalse2-1].embalse_nombre,res_mes=max_mes-min_mes,cuenca[l_r_embalse-1].embalse_nombre,mes);}
	        if(cuenca[l_r_embalse-13+mes].dosmilcatorce>cuenca[l_r_embalse2-13+mes].dosmilcatorce){
			   max_mes=	cuenca[l_r_embalse-13+mes].dosmilcatorce;
			   min_mes=cuenca[l_r_embalse2-13+mes].dosmilcatorce;
			   printf("%s sobrepaso en %.2f hm^3 a %s en el %i mes.\n", cuenca[l_r_embalse-1].embalse_nombre,res_mes=max_mes-min_mes,cuenca[l_r_embalse2-1].embalse_nombre,mes);}
	        if(cuenca[l_r_embalse2-13+mes].dosmilcatorce==cuenca[l_r_embalse-13+mes].dosmilcatorce){
			   printf("%s y %s tinen la misma capacidad en el %i mes.\n", cuenca[l_r_embalse2-1].embalse_nombre,cuenca[l_r_embalse-1].embalse_nombre,mes);}
			break;
		case(2015):
			printf("La capacidad del primer embalse %s en el %i mes del %i es %.2f.\n",cuenca[l_r_embalse-1].embalse_nombre,mes,anyo,cuenca[l_r_embalse-13+mes].dosmilquince);
			printf("La capacidad del segundo embalse %s en el %i mes del %i es %.2f.\n",cuenca[l_r_embalse2-1].embalse_nombre,mes,anyo,cuenca[l_r_embalse2-13+mes].dosmilquince);
			if(cuenca[l_r_embalse2-13+mes].dosmilquince>cuenca[l_r_embalse-13+mes].dosmilquince){
			   max_mes=	cuenca[l_r_embalse2-13+mes].dosmilquince;
			   min_mes=cuenca[l_r_embalse-13+mes].dosmilquince;
			   printf("%s sobrepaso en %.2f hm^3 a %s en el %i mes.\n", cuenca[l_r_embalse2-1].embalse_nombre,res_mes=max_mes-min_mes,cuenca[l_r_embalse-1].embalse_nombre,mes);}
	        if(cuenca[l_r_embalse-13+mes].dosmilquince>cuenca[l_r_embalse2-13+mes].dosmilquince){
			   max_mes=	cuenca[l_r_embalse-13+mes].dosmilquince;
			   min_mes=cuenca[l_r_embalse2-13+mes].dosmilquince;
			   printf("%s sobrepaso en %.2f hm^3 a %s en el %i mes.\n", cuenca[l_r_embalse-1].embalse_nombre,res_mes=max_mes-min_mes,cuenca[l_r_embalse2-1].embalse_nombre,mes);}
	        if(cuenca[l_r_embalse2-13+mes].dosmilquince==cuenca[l_r_embalse-13+mes].dosmilquince){
			   printf("%s y %s tinen la misma capacidad en el %i mes.\n", cuenca[l_r_embalse2-1].embalse_nombre,cuenca[l_r_embalse-1].embalse_nombre,mes);}
			break;
		case(2016):
			printf("La capacidad del primer embalse %s en el %i mes del %i es %.2f.\n",cuenca[l_r_embalse-1].embalse_nombre,mes,anyo,cuenca[l_r_embalse-13+mes].dosmildieciseis);
			printf("La capacidad del segundo embalse %s en el %i mes del %i es %.2f.\n",cuenca[l_r_embalse2-1].embalse_nombre,mes,anyo,cuenca[l_r_embalse2-13+mes].dosmildieciseis);
			if(cuenca[l_r_embalse2-13+mes].dosmildieciseis>cuenca[l_r_embalse-13+mes].dosmildieciseis){
			   max_mes=	cuenca[l_r_embalse2-13+mes].dosmildieciseis;
			   min_mes=cuenca[l_r_embalse-13+mes].dosmildieciseis;
			   printf("%s sobrepaso en %.2f hm^3 a %s en el %i mes.\n", cuenca[l_r_embalse2-1].embalse_nombre,res_mes=max_mes-min_mes,cuenca[l_r_embalse-1].embalse_nombre,mes);}
	        if(cuenca[l_r_embalse-13+mes].dosmildieciseis>cuenca[l_r_embalse2-13+mes].dosmildieciseis){
			   max_mes=	cuenca[l_r_embalse-13+mes].dosmildieciseis;
			   min_mes=cuenca[l_r_embalse2-13+mes].dosmildieciseis;
			   printf("%s sobrepaso en %.2f hm^3 a %s en el %i mes..\n", cuenca[l_r_embalse-1].embalse_nombre,res_mes=max_mes-min_mes,cuenca[l_r_embalse2-1].embalse_nombre,mes);}
	        if(cuenca[l_r_embalse2-13+mes].dosmildieciseis==cuenca[l_r_embalse-13+mes].dosmildieciseis){
			   printf("%s y %s tinen la misma capacidad en el %i mes.\n", cuenca[l_r_embalse2-1].embalse_nombre,cuenca[l_r_embalse-1].embalse_nombre,mes);}
			break;
		case(2017):
			printf("La capacidad del primer embalse %s en el %i mes del %i es %.2f.\n",cuenca[l_r_embalse-1].embalse_nombre,mes,anyo,cuenca[l_r_embalse-13+mes].dosmildiecisiete);
			printf("La capacidad del segundo embalse %s en el %i mes del %i es %.2f.\n",cuenca[l_r_embalse2-1].embalse_nombre,mes,anyo,cuenca[l_r_embalse2-13+mes].dosmildiecisiete);
			if(cuenca[l_r_embalse2-13+mes].dosmildiecisiete>cuenca[l_r_embalse-13+mes].dosmildiecisiete){
			   max_mes=	cuenca[l_r_embalse2-13+mes].dosmildiecisiete;
			   min_mes=cuenca[l_r_embalse-13+mes].dosmildiecisiete;
			   printf("%s sobrepaso en %.2f hm^3 a %s en el %i mes.\n", cuenca[l_r_embalse2-1].embalse_nombre,res_mes=max_mes-min_mes,cuenca[l_r_embalse-1].embalse_nombre,mes);}
	        if(cuenca[l_r_embalse-13+mes].dosmildiecisiete>cuenca[l_r_embalse2-13+mes].dosmildiecisiete){
			   max_mes=	cuenca[l_r_embalse-13+mes].dosmildiecisiete;
			   min_mes=cuenca[l_r_embalse2-13+mes].dosmildiecisiete;
			   printf("%s sobrepaso en %.2f hm^3 a %s en el %i mes.\n", cuenca[l_r_embalse-1].embalse_nombre,res_mes=max_mes-min_mes,cuenca[l_r_embalse2-1].embalse_nombre,mes);}
	        if(cuenca[l_r_embalse2-13+mes].dosmildiecisiete==cuenca[l_r_embalse-13+mes].dosmildiecisiete){
			   printf("%s y %s tinen la misma capacidad en el %i mes.\n", cuenca[l_r_embalse2-1].embalse_nombre,cuenca[l_r_embalse-1].embalse_nombre,mes);}
			break;
		case(2018):
			printf("La capacidad del primer embalse %s en el %i mes del %i es %.2f.\n",cuenca[l_r_embalse-1].embalse_nombre,mes,anyo,cuenca[l_r_embalse-13+mes].dosmildieciocho);
			printf("La capacidad del segundo embalse %s en el %i mes del %i es %.2f.\n",cuenca[l_r_embalse2-1].embalse_nombre,mes,anyo,cuenca[l_r_embalse2-13+mes].dosmildieciocho);
			if(cuenca[l_r_embalse2-13+mes].dosmildieciocho>cuenca[l_r_embalse-13+mes].dosmildieciocho){
			   max_mes=	cuenca[l_r_embalse2-13+mes].dosmildieciocho;
			   min_mes=cuenca[l_r_embalse-13+mes].dosmildieciocho;
			   printf("%s sobrepaso en %.2f hm^3 a %s en el %i mes.\n", cuenca[l_r_embalse2-1].embalse_nombre,res_mes=max_mes-min_mes,cuenca[l_r_embalse-1].embalse_nombre,mes);}
	        if(cuenca[l_r_embalse-13+mes].dosmildieciocho>cuenca[l_r_embalse2-13+mes].dosmildieciocho){
			   max_mes=	cuenca[l_r_embalse-13+mes].dosmildieciocho;
			   min_mes=cuenca[l_r_embalse2-13+mes].dosmildieciocho;
			   printf("%s sobrepaso en %.2f hm^3 a %s en el %i mes.\n", cuenca[l_r_embalse-1].embalse_nombre,res_mes=max_mes-min_mes,cuenca[l_r_embalse2-1].embalse_nombre,mes);}
	        if(cuenca[l_r_embalse2-13+mes].dosmildieciocho==cuenca[l_r_embalse-13+mes].dosmildieciocho){
			   printf("%s y %s tinen la misma capacidad en el %i mes.\n", cuenca[l_r_embalse2-1].embalse_nombre,cuenca[l_r_embalse-1].embalse_nombre,mes);}
			break;
		case(2019):
			printf("La capacidad del primer embalse %s en el %i mes del %i es %.2f.\n",cuenca[l_r_embalse-1].embalse_nombre,mes,anyo,cuenca[l_r_embalse-13+mes].dosmildiecinueve);
			printf("La capacidad del segundo embalse %s en el %i mes del %i es %.2f.\n",cuenca[l_r_embalse2-1].embalse_nombre,mes,anyo,cuenca[l_r_embalse2-13+mes].dosmildiecinueve);
			if(cuenca[l_r_embalse2-13+mes].dosmildiecinueve>cuenca[l_r_embalse-13+mes].dosmildiecinueve){
			   max_mes=	cuenca[l_r_embalse2-13+mes].dosmildiecinueve;
			   min_mes=cuenca[l_r_embalse-13+mes].dosmildiecinueve;
			   printf("%s sobrepaso en %.2f hm^3 a %s en el %i mes.\n", cuenca[l_r_embalse2-1].embalse_nombre,res_mes=max_mes-min_mes,cuenca[l_r_embalse-1].embalse_nombre,mes);}
	        if(cuenca[l_r_embalse-13+mes].dosmildiecinueve>cuenca[l_r_embalse2-13+mes].dosmildiecinueve){
			   max_mes=	cuenca[l_r_embalse-13+mes].dosmildiecinueve;
			   min_mes=cuenca[l_r_embalse2-13+mes].dosmildiecinueve;
			   printf("%s sobrepaso en %.2f hm^3 a %s en el %i mes.\n", cuenca[l_r_embalse-1].embalse_nombre,res_mes=max_mes-min_mes,cuenca[l_r_embalse2-1].embalse_nombre,mes);}
	        if(cuenca[l_r_embalse2-13+mes].dosmildiecinueve==cuenca[l_r_embalse-13+mes].dosmildiecinueve){
			   printf("%s y %s tinen la misma capacidad en el %i mes.\n", cuenca[l_r_embalse2-1].embalse_nombre,cuenca[l_r_embalse-1].embalse_nombre,mes);}
			break;
		case(2020):
			printf("La capacidad del primer embalse %s en el %i mes del %i es %.2f.\n",cuenca[l_r_embalse-1].embalse_nombre,mes,anyo,cuenca[l_r_embalse-13+mes].dosmilveinte);
			printf("La capacidad del segundo embalse %s en el %i mes del %i es %.2f.\n",cuenca[l_r_embalse2-1].embalse_nombre,mes,anyo,cuenca[l_r_embalse2-13+mes].dosmilveinte);
			if(cuenca[l_r_embalse2-13+mes].dosmilveinte>cuenca[l_r_embalse-13+mes].dosmilveinte){
			   max_mes=	cuenca[l_r_embalse2-13+mes].dosmilveinte;
			   min_mes=cuenca[l_r_embalse-13+mes].dosmilveinte;
			   printf("%s sobrepaso en %.2f hm^3 a %s en el %i mes.\n", cuenca[l_r_embalse2-1].embalse_nombre,res_mes=max_mes-min_mes,cuenca[l_r_embalse-1].embalse_nombre,mes);}
	        if(cuenca[l_r_embalse-13+mes].dosmilveinte>cuenca[l_r_embalse2-13+mes].dosmilveinte){
			   max_mes=	cuenca[l_r_embalse-13+mes].dosmilveinte;
			   min_mes=cuenca[l_r_embalse2-13+mes].dosmilveinte;
			   printf("%s sobrepaso en %.2f hm^3 a %s en el %i mes.\n", cuenca[l_r_embalse-1].embalse_nombre,res_mes=max_mes-min_mes,cuenca[l_r_embalse2-1].embalse_nombre,mes);}
	        if(cuenca[l_r_embalse2-13+mes].dosmilveinte==cuenca[l_r_embalse-13+mes].dosmilveinte){
			   printf("%s y %s tinen la misma capacidad en el %i mes.\n", cuenca[l_r_embalse2-1].embalse_nombre,cuenca[l_r_embalse-1].embalse_nombre,mes);}
			break;
		case(2021):
			printf("La capacidad del primer embalse %s en el %i mes del %i es %.2f.\n",cuenca[l_r_embalse-1].embalse_nombre,mes,anyo,cuenca[l_r_embalse-13+mes].dosmilveintiuno);
			printf("La capacidad del segundo embalse %s en el %i mes del %i es %.2f.\n",cuenca[l_r_embalse2-1].embalse_nombre,mes,anyo,cuenca[l_r_embalse2-13+mes].dosmilveintiuno);
			if(cuenca[l_r_embalse2-13+mes].dosmildoce>cuenca[l_r_embalse-13+mes].dosmilveintiuno){
			   max_mes=	cuenca[l_r_embalse2-13+mes].dosmilveintiuno;
			   min_mes=cuenca[l_r_embalse-13+mes].dosmilveintiuno;
			   printf("%s sobrepaso en %.2f hm^3 a %s en el %i mes.\n", cuenca[l_r_embalse2-1].embalse_nombre,res_mes=max_mes-min_mes,cuenca[l_r_embalse-1].embalse_nombre,mes);}
	        if(cuenca[l_r_embalse-13+mes].dosmilveintiuno>cuenca[l_r_embalse2-13+mes].dosmilveintiuno){
			   max_mes=	cuenca[l_r_embalse-13+mes].dosmilveintiuno;
			   min_mes=cuenca[l_r_embalse2-13+mes].dosmilveintiuno;
			   printf("%s sobrepaso en %.2f hm^3 a %s en el %i mes.\n", cuenca[l_r_embalse-1].embalse_nombre,res_mes=max_mes-min_mes,cuenca[l_r_embalse2-1].embalse_nombre,mes);}
	        if(cuenca[l_r_embalse2-13+mes].dosmilveintiuno==cuenca[l_r_embalse-13+mes].dosmilveintiuno){
			   printf("%s y %s tienen la misma capacidad en el %i mes.\n", cuenca[l_r_embalse2-1].embalse_nombre,cuenca[l_r_embalse-1].embalse_nombre,mes);}
			break;
		
	}
}


//CAPACIDAD MAX
void capacidad_max( int l_r_embalse, int l_r_embalse2, linea cuenca[],Embalse embalse[]){
	float max_capM,min_capM,dif_capM;
printf("La capacidad maxima que puede contener los embalses elegidos, %s y %s, es %.2f y %.2f respectivamente.\n", cuenca[l_r_embalse-1].embalse_nombre, cuenca[l_r_embalse2-1].embalse_nombre, embalse[l_r_embalse/12-1].etotal,embalse[l_r_embalse2/12-1].etotal);
if(embalse[l_r_embalse2/12-1].etotal>embalse[l_r_embalse/12-1].etotal){
	max_capM=embalse[l_r_embalse2/12-1].etotal;
	min_capM=embalse[l_r_embalse/12-1].etotal;
	printf("La diferencia de capacidad maxima entre %s y %s es de %.2f hm^3.\n",cuenca[l_r_embalse2-1].embalse_nombre,cuenca[l_r_embalse-1].embalse_nombre,dif_capM=max_capM-min_capM);
   }
if(embalse[l_r_embalse/12-1].etotal>embalse[l_r_embalse2/12-1].etotal){
	max_capM=embalse[l_r_embalse/12-1].etotal;
	min_capM=embalse[l_r_embalse2/12-1].etotal;
	printf("La diferencia de capacidad maxima entre %s y %s es de %.2f hm^3.\n",cuenca[l_r_embalse-1].embalse_nombre,cuenca[l_r_embalse2-1].embalse_nombre,dif_capM=max_capM-min_capM);
   }
if(embalse[l_r_embalse2/12-1].etotal==embalse[l_r_embalse/12-1].etotal){
	
	printf("Los embalses %s y %s tienen la misma capacidad maxima.\n",cuenca[l_r_embalse-1].embalse_nombre,cuenca[l_r_embalse2-1].embalse_nombre);
   }
}


//SUPERFICIE
void superficie( int l_r_embalse, int l_r_embalse2, linea cuenca[], DatosComparacion comp[]){
	float max_sup,min_sup,dif_sup;
   
printf("La superficie del primer embalse, %s, es %.2f.\n", cuenca[l_r_embalse-1].embalse_nombre,comp[l_r_embalse/12-1].superficie);
if(comp[l_r_embalse/12-1].superficie==0){
	printf("La superficie de %s no esta disponible.\n", cuenca[l_r_embalse-1].embalse_nombre );
}
printf("La superficie del segundo embalse, %s, es %.2f.\n",cuenca[l_r_embalse2-1].embalse_nombre,comp[l_r_embalse2/12-1].superficie);
if(comp[l_r_embalse2/12-1].superficie==0){
	printf("La superficie de %s no esta disponible.\n", cuenca[l_r_embalse2-1].embalse_nombre );
}
if(comp[l_r_embalse2/12-1].superficie>comp[l_r_embalse/12-1].superficie){
	max_sup=comp[l_r_embalse2/12-1].superficie;
	min_sup=comp[l_r_embalse/12-1].superficie;
	printf("La diferencia de superficies entre %s y %s es de %.2f hm.\n",cuenca[l_r_embalse2-1].embalse_nombre,cuenca[l_r_embalse-1].embalse_nombre,dif_sup=max_sup-min_sup);
   }
if(comp[l_r_embalse/12-1].superficie>comp[l_r_embalse2/12-1].superficie){
	max_sup=comp[l_r_embalse/12-1].superficie;
	min_sup=comp[l_r_embalse2/12-1].superficie;
	printf("La diferencia de superficies entre %s y %s es de %.2f hm.\n",cuenca[l_r_embalse-1].embalse_nombre,cuenca[l_r_embalse2-1].embalse_nombre,dif_sup=max_sup-min_sup);
   }
if(comp[l_r_embalse/12-1].superficie==comp[l_r_embalse2/12-1].superficie){
	
	printf("Los embalses %s y %s tienen la misma superficie.\n",cuenca[l_r_embalse-1].embalse_nombre,cuenca[l_r_embalse2-1].embalse_nombre);
   }
}


//TIPO DE EMBALSE:
void tipo_embalse(DatosComparacion comp[],int l_r_embalse, int l_r_embalse2, linea cuenca[]){
	if(strcmp(comp[l_r_embalse/12-1].tipo_presa,comp[l_r_embalse2/12-1].tipo_presa)!=0){
	printf("El primer embalse, %s, tiene un embalse de tipo %s, mientras que el segundo embalse, %s, tiene un embalse de tipo %s.\n",cuenca[l_r_embalse-1].embalse_nombre,comp[l_r_embalse/12-1].tipo_presa, cuenca[l_r_embalse2-1].embalse_nombre,comp[l_r_embalse2/12-1].tipo_presa);
}else{
	printf("Ambos embalses son del mismo tipo, %s.\n",comp[l_r_embalse/12-1].tipo_presa);
}
}


//USO DE EMBALSE:
void uso_embalse(DatosComparacion comp[],int l_r_embalse, int l_r_embalse2, linea cuenca[]){
	if(strcmp(comp[l_r_embalse/12-1].uso_abastecimiento,comp[l_r_embalse2/12-1].uso_abastecimiento)!=0){
	if(strcmp(comp[l_r_embalse/12-1].uso_abastecimiento,"Si")==0){
		printf("Solo el embalse, %s, se usa para abastecimiento.\n",cuenca[l_r_embalse-1].embalse_nombre );
	}else{
		printf("Solo el embalse, %s, se usa para abastecimiento.\n",cuenca[l_r_embalse2-1].embalse_nombre);
	}
}else{
	if(strcmp(comp[l_r_embalse/12-1].uso_abastecimiento,"Si")==0){
		printf("Ambos embalses se usan para abastecimiento.\n" );
	}}

if(strcmp(comp[l_r_embalse/12-1].uso_riego,comp[l_r_embalse2/12-1].uso_riego)!=0){
	if(strcmp(comp[l_r_embalse/12-1].uso_riego,"Si")==0){
		printf("Solo el embalse, %s, se usa para riego.\n",cuenca[l_r_embalse-1].embalse_nombre );
	}else{
		printf("Solo el embalse, %s, se usa para riego.\n",cuenca[l_r_embalse2-1].embalse_nombre);
	}
}else{
	if(strcmp(comp[l_r_embalse/12-1].uso_riego,"Si")==0){
		printf("Ambos embalses se usan para riego.\n" );
	}}
if(strcmp(comp[l_r_embalse/12-1].uso_electricidad,comp[l_r_embalse2/12-1].uso_electricidad)!=0){
	if(strcmp(comp[l_r_embalse/12-1].uso_electricidad,"Si")==0){
		printf("Solo el embalse, %s, se usa para electricidad.\n",cuenca[l_r_embalse-1].embalse_nombre );
	}else{
		printf("Solo el embalse, %s, se usa para electricidad.\n",cuenca[l_r_embalse2-1].embalse_nombre);
	}
}else{
	if(strcmp(comp[l_r_embalse/12-1].uso_electricidad,"Si")==0){
		printf("Ambos embalses se usan para electricidad.\n" );
	}}
if(strcmp(comp[l_r_embalse/12-1].uso_industrial,comp[l_r_embalse2/12-1].uso_industrial)!=0){
	if(strcmp(comp[l_r_embalse/12-1].uso_industrial,"Si")==0){
		printf("Solo el embalse, %s, se usa para industrial.\n",cuenca[l_r_embalse-1].embalse_nombre );
	}else{
		printf("Solo el embalse, %s, se usa para industrial.\n",cuenca[l_r_embalse2-1].embalse_nombre);
	}
}else{
	if(strcmp(comp[l_r_embalse/12-1].uso_industrial,"Si")==0){
		printf("Ambos embalses se usan para industrial.\n" );
	}}
if(strcmp(comp[l_r_embalse/12-1].uso_pesca,comp[l_r_embalse2/12-1].uso_pesca)!=0){
	if(strcmp(comp[l_r_embalse/12-1].uso_pesca,"Si")==0){
		printf("Solo el embalse, %s, se usa para pesca.\n",cuenca[l_r_embalse-1].embalse_nombre );
	}else{
		printf("Solo el embalse, %s, se usa para pesca.\n",cuenca[l_r_embalse2-1].embalse_nombre);
	}
}else{
	if(strcmp(comp[l_r_embalse/12-1].uso_pesca,"Si")==0){
		printf("Ambos embalses se usan para pesca.\n" );
	}}
if(strcmp(comp[l_r_embalse/12-1].uso_navegacion,comp[l_r_embalse2/12-1].uso_navegacion)!=0){
	if(strcmp(comp[l_r_embalse/12-1].uso_navegacion,"Si")==0){
		printf("Solo el embalse, %s, se usa para navegacion.\n",cuenca[l_r_embalse-1].embalse_nombre );
	}else{
		printf("Solo el embalse, %s, se usa para navegacion.\n",cuenca[l_r_embalse2-1].embalse_nombre);
	}
}else{
	if(strcmp(comp[l_r_embalse/12-1].uso_navegacion,"Si")==0){
		printf("Ambos embalses se usan para navegacion.\n" );
	}}
if(strcmp(comp[l_r_embalse/12-1].uso_banyo,comp[l_r_embalse2/12-1].uso_banyo)!=0){
	if(strcmp(comp[l_r_embalse/12-1].uso_banyo,"Si")==0){
		printf("Solo el embalse, %s, se usa para banyos.\n",cuenca[l_r_embalse-1].embalse_nombre );
	}else{
		printf("Solo el embalse, %s, se usa para banyos.\n",cuenca[l_r_embalse2-1].embalse_nombre);
	}
}else{
	if(strcmp(comp[l_r_embalse/12-1].uso_banyo,"Si")==0){
		printf("Ambos embalses se usan para banyos.\n" );
	}}
if(strcmp(comp[l_r_embalse/12-1].uso_picnic,comp[l_r_embalse2/12-1].uso_picnic)!=0){
	if(strcmp(comp[l_r_embalse/12-1].uso_picnic,"Si")==0){
		printf("Solo el embalse, %s, se usa para picnic.\n",cuenca[l_r_embalse-1].embalse_nombre );
	}else{
		printf("Solo el embalse, %s, se usa para picnic.\n",cuenca[l_r_embalse2-1].embalse_nombre);
	}
}else{
	if(strcmp(comp[l_r_embalse/12-1].uso_picnic,"Si")==0){
		printf("Ambos embalses se usan para picnic.\n" );
	}}
if(strcmp(comp[l_r_embalse/12-1].uso_restaurante,comp[l_r_embalse2/12-1].uso_restaurante)!=0){
	if(strcmp(comp[l_r_embalse/12-1].uso_restaurante,"Si")==0){
		printf("Solo el embalse, %s, se usa para restaurantes.\n",cuenca[l_r_embalse-1].embalse_nombre );
	}else{
		printf("Solo el embalse, %s, se usa para restaurantes.\n",cuenca[l_r_embalse2-1].embalse_nombre);
	}
}else{
	if(strcmp(comp[l_r_embalse/12-1].uso_restaurante,"Si")==0){
		printf("Ambos embalses se usan para restaurantes.\n" );
	}}
}


//CAMBIO DE GUION A ESPACIO
char cambios_espacios_embalses (linea cuenca [], int l_r_embalse, int l_r_embalse2){
	int c=0;
	int b=0;
	char cambio[100];
	char cambio2[100];
	strcpy(cambio, cuenca[l_r_embalse-1].embalse_nombre);
	strcpy(cambio2, cuenca[l_r_embalse2-1].embalse_nombre);
	
	while(cambio[c] != '\0'){
		if (cambio[c]=='_'){
			cambio[c]=' ';
		}
		c++;
	}
	while(cambio2[b] != '\0'){
		if(cambio2[b]=='_'){
			cambio2[b]=' ';
		}
		b++;
	}
	
	strcpy(cuenca[l_r_embalse-1].embalse_nombre,cambio);
	strcpy(cuenca[l_r_embalse2-1].embalse_nombre,cambio2);
}

char cambios_espacios_tipo_presa (DatosComparacion comp[], int l_r_embalse, int l_r_embalse2){
	int c=0;
	int b=0;
	char cambio[100];
	char cambio2[100];
	strcpy(cambio, comp[l_r_embalse/12-1].tipo_presa);
	strcpy(cambio2, comp[l_r_embalse2/12-1].tipo_presa);
	
	while(cambio[c] != '\0'){
		if (cambio[c]=='_'){
			cambio[c]=' ';
		}
		c++;
	}
	while(cambio2[b] != '\0'){
		if(cambio2[b]=='_'){
			cambio2[b]=' ';
		}
		b++;
	}
	
	strcpy(comp[l_r_embalse/12-1].tipo_presa,cambio);
	strcpy(comp[l_r_embalse2/12-1].tipo_presa,cambio2);
}

