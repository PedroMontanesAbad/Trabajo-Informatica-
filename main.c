#include <stdio.h>
#include <string.h>
#include "funciones_embalses.h" 


int main(){
	
	int f=0,j=0, k=0, i;

	int num_embalse, anyo, mes,num_cuenca, posiciones_cuencas[15] ;

	float porcentaje, fecha, dato;

	linea cuenca[4236], embalse [353];
	
	//leemos los ficheros	
	
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

while ( fscanf(lista, "%s\n%f\n", embalse[k].embalse_nom , &embalse[k].etotal) !=EOF )
	{
	//printf("%s\t%.2f\n", embalse[k].embalse_nom, embalse[k].etotal );
	k++;	
	}

//Porcentaje en un mes concreto
printf("Calculo del porcentaje:\n\n ");

//cuenca
do{
	printf("\nIntroduce el numero de la cuenca: ");
	scanf("%i", &num_cuenca);

	if((0 >= num_cuenca) || ( num_cuenca > 16 )){
		printf ("\nNumero no valido, repite:\n");
	}

}

while ((0 >= num_cuenca) || ( num_cuenca > 16 ));

//embalse
do{
	printf("\nIntroduce el numero del embalse: " );	
	
	
	scanf("%i", &num_embalse);

	if((0 > num_embalse) || ( num_embalse > 353 )){
		printf ("\nNumero no valido, repite:\n");
	}

}
while ((0 > num_embalse) || ( num_embalse > 353 ));

for(i=posiciones_cuencas[num_cuenca-1]+(num_embalse-1)*12;i<posiciones_cuencas[num_cuenca-1]+(num_embalse)*12;i++)
	{}printf("Tu embalse es: %s\n",cuenca[i-1].embalse_nombre) ;

printf("\n\nAhora vamos a seleccionar la fecha: ");
//anyo
do{
	printf("\nIntroduce el anyo deseado 2012-2021: ");
		scanf("%i", &anyo);
	if((2012 > anyo) || ( anyo > 2021 )){
		printf ("\nNumero no valido, repite:\n");
	}
}

while ((2012 > anyo) || ( anyo > 2021 ));
//mes
do{
	printf("\nIntroduce el mes deseado: ");
		scanf("%i", &mes);
	if((1 > mes) || ( mes > 12 )){
		printf ("\nNumero no valido, repite:\n");
	}
}
while ((1 > mes) || ( mes > 12 ));

porcentaje = porcentaje_embalse (anyo, mes, num_cuenca, posiciones_cuencas, num_embalse, i, embalse, cuenca);
printf("El porcentaje de agua del embalse %s de la cuenca %s es %f, en el mes %i del anyo %i", cuenca[posiciones_cuencas[num_cuenca-1]+(num_embalse-1)*12].embalse_nombre, cuenca[posiciones_cuencas[num_cuenca-1]+(num_embalse-1)*12].cuenca_hidrografica, porcentaje, mes, anyo);

//printf("\n%.2f, %.2f",fecha,dato);
	
		if (porcentaje<10){
			printf("Periodo de sequia.");
		}
	


fclose(tabla);
fclose(lista);
}

	
