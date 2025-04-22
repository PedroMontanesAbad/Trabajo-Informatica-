#include <stdio.h>
#include <string.h>
#include "funciones_embalses.h" 


int main(){
	
	int f=0,j=0, k=0, b=0, c,i;

	int num_embalse, anyo, mes,num_cuenca, posiciones_cuencas[15] ;

	float porcentaje, capacidad_max, capacidad_actual;

	linea cuenca[4236], embalse [353];
	
	//abrimos ficheros
	
	FILE *tabla;
	tabla = fopen("texto_proyecto.txt","r");
	if (tabla == NULL) // Si el resultado es NULL mensaje de error
	{
	printf("Error al abrir el fichero.\n");
	return -1;
	}

	FILE *lista;
	lista = fopen("Embalses_capacidad.txt","r");
	if (lista == NULL) // Si el resultado es NULL mensaje de error
	{
	printf("Error al abrir el fichero 2.\n");
	return -1;
	}

	//leo el primer fichero	
	
	while (fscanf(tabla, "%s\t%s\t%i\t%f\t%f\t%f\t%f\t%f\t%f\t%f\t%f\t%f\t%f\n", cuenca[j].cuenca_hidrografica , cuenca[j].embalse_nombre , &cuenca[j].mes , &cuenca[j].dosmildoce, &cuenca[j].dosmiltrece, &cuenca[j].dosmilcatorce, &cuenca[j].dosmilquince, &cuenca[j].dosmildieciseis, &cuenca[j].dosmildiecisiete, &cuenca[j].dosmildieciocho,  &cuenca[j].dosmildiecinueve,  &cuenca[j].dosmilveinte,  &cuenca[j].dosmilveintiuno ) != EOF)
	{
	
	//printf("Linea %i:\n", j);
	//printf("%s\t%s\t%i\t%f\t%f\t%f\t%f\t%f\t%f\t%f\n", cuenca[j].cuenca_hidrografica , cuenca[j].embalse_nombre , cuenca[j].mes , cuenca[j].dosmildoce, cuenca[j].dosmiltrece, cuenca[j].dosmilcatorce, cuenca[j].dosmilquince, cuenca[j].dosmildieciseis, cuenca[j].dosmildiecisiete, cuenca[j].dosmildieciocho,  cuenca[j].dosmildiecinueve,  cuenca[j].dosmilveinte,  cuenca[j].dosmilveintiuno );
	
	j++;
	}
	
	// las comparamos para no repetir
	for (i=0;i<j;i++){
	
	if (strcmp(cuenca[i].cuenca_hidrografica, cuenca[i-1].cuenca_hidrografica) != 0){
		posiciones_cuencas[f]=i;
		f++;
	}
}




//Nombres cuencas numeradas:
nombres_cuencas(j,cuenca);
//num cuenca
do{
	printf("\nIntroduce el numero de la cuenca: ");
	scanf("%i", &num_cuenca);

	if((0 >= num_cuenca) || ( num_cuenca > 16 )){
		printf ("\nNumero no valido, repite:\n");
	}

}

while ((0 >= num_cuenca) || ( num_cuenca > 16 ));


//Nombres de los embalses de una cuenca en concreto:

nombres_cuencas_embalse( j, num_cuenca, cuenca, posiciones_cuencas, &c);

//num embalse

do{
	printf("\nIntroduce el numero del embalse: " );	
	
	
	scanf("%i", &num_embalse);

	if((0 > num_embalse) || ( num_embalse > c )){
		printf ("\nNumero no valido, repite:\n");
	}

}
while ((0 > num_embalse) || ( num_embalse > c));

system("cls");

for(i=posiciones_cuencas[num_cuenca-1]+(num_embalse-1)*12;i<posiciones_cuencas[num_cuenca-1]+(num_embalse)*12;i++)
	{}printf("Tu embalse es: %s\n",cuenca[i-1].embalse_nombre) ;
	
	
	while ( fscanf(lista, "%s\t%f\n", embalse[k].embalse_nom , &embalse[k].etotal) !=EOF )
	{

	//printf("%s\t%.2f\n", embalse[k].embalse_nom, embalse[k].etotal );
	
	if  (strcmp(cuenca[i-1].embalse_nombre , embalse[k].embalse_nom) == 0){
		b = k+1;
	}
	k++;	
	}

	
	
printf("\n\nAhora vamos a seleccionar la fecha: ");

do{
	printf("\nIntroduce el anyo deseado 2012-2021: ");
		scanf("%i", &anyo);
	if((2012 > anyo) || ( anyo > 2021 )){
		printf ("\nNumero no valido, repite:\n");
	}
}

while ((2012 > anyo) || ( anyo > 2021 ));

do{
	printf("\nIntroduce el mes deseado: ");
		scanf("%i", &mes);
	if((1 > mes) || ( mes > 12 )){
		printf ("\nNumero no valido, repite:\n");
	}
}
while ((1 > mes) || ( mes > 12 ));

porcentaje = porcentaje_embalse (anyo, mes, num_cuenca, posiciones_cuencas, b, num_embalse, cuenca, embalse);
printf("El embalse %s de la cuenca %s tiene una capadidad del %.2f%%, en el mes %i del anyo %i", cuenca[posiciones_cuencas[num_cuenca-1]+(num_embalse-1)*12].embalse_nombre, cuenca[posiciones_cuencas[num_cuenca-1]+(num_embalse-1)*12].cuenca_hidrografica, porcentaje, mes, anyo);

//printf("\n%.2f, %.2f",capacidad_max,capacidad_actual);

		if ((50<porcentaje) && (porcentaje<70)){
			printf("\nPeriodo de sequia leve.");
		}		
		else if ((30<porcentaje) && (porcentaje<50)){
			printf("\nPeriodo de sequia moderada.");
		}
		else if (porcentaje<30){
			printf("\nPeriodo de sequia grave.");
		}
		
		

fclose(tabla);
fclose(lista);
}
