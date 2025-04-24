#include <stdio.h>
#include <string.h>
#include "funciones_embalses.h" 

int main(){
	
	int f=0,j=0, k=0, b=0, c,i;

	int num_embalse, anyo, mes,num_cuenca, posiciones_cuencas[15] ;

	float porcentaje, capacidad_max, capacidad_actual;

	linea cuenca[4236], embalse [353];
		
//ABRIMOS FICHEROS:
	
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

//SE LEE EL PRIMER FICHERO:
	
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
		//printf("\ni es %i",posiciones_cuencas[f]);
		f++;
	}
}

	//añadimos la número 16

	posiciones_cuencas[f]=j;

//NOMBRES DE CUENCAS ENNUMERADAS

nombres_cuencas(j,cuenca);

//NÚMERO DE CUENCA

num_cuenca = seleccion_cuenca(num_cuenca);

//IMPRIME EMBALSES DE UNA CUENCA EN CONCRETO

nombres_cuencas_embalse( j, num_cuenca, cuenca, posiciones_cuencas);

//SELECCIONA EL NÚMERO DE EMBALSE

num_embalse = seleccion_embalse(num_embalse,posiciones_cuencas,num_cuenca);


//IMPRIME CUENCA Y EMBALSE, PARA VER COMO VAS.

printf("Tu embalse es %s, de la cuenca %s \n",cuenca[posiciones_cuencas[num_cuenca-1]+(num_embalse-1)*12].embalse_nombre,cuenca[posiciones_cuencas[num_cuenca-1]+(num_embalse-1)*12].cuenca_hidrografica) ;
	
	
//ESCANEA EL SEGUNDO FICHERO; 
//Y COMPARA SUS LINEAS (LAS DEL SEGUNDO FICHERO) CON EL NOMBRE DEL EMBALSE ESCOGIDO EN EL PRIMER FICHERO.
//CUANDO COINCIDEN SE CUMPLE EL IF, Y DAMOS EL VALOR NÚMERICO A b, k+1 POR SER VECTOR. ESE VALOR NOS PERMITE CONOCER LA LÍNEA DEL
//SECUNDO FICHERO DONDE ESTÁ EL EMBALSE QUE COINCIDE CON EL PRIMER FICHERO, Y POR TANTO SU CAPACIDAD TOTAL.
	
	while ( fscanf(lista, "%s\t%f\n", embalse[k].embalse_nom , &embalse[k].etotal) !=EOF )
	{

	//printf("%s\t%.2f\n", embalse[k].embalse_nom, embalse[k].etotal );
	
	if  (strcmp(cuenca[posiciones_cuencas[num_cuenca-1]+(num_embalse-1)*12].embalse_nombre , embalse[k].embalse_nom) == 0){
		b = k+1;
	}
	k++;	

	}
	
//PEDIMOS FECHA 

printf("\n\nAhora vamos a seleccionar la fecha: \n");

anyo = seleccion_anyo(anyo);

mes = seleccion_mes(mes);

//MOSTRAMOS TEXTO FINAL CON TODOS LOS DATOS

porcentaje = porcentaje_embalse (anyo, mes, num_cuenca, posiciones_cuencas, b, num_embalse, cuenca, embalse);
printf("El embalse %s de la cuenca %s estaba al %.2f%% de su capadidad, en %s del anyo %i.", cuenca[posiciones_cuencas[num_cuenca-1]+(num_embalse-1)*12].embalse_nombre, cuenca[posiciones_cuencas[num_cuenca-1]+(num_embalse-1)*12].cuenca_hidrografica, porcentaje, meses_nombres(mes), anyo);

//SÓLO SI HAY SEQÍA

sequia (porcentaje);

fclose(tabla);
fclose(lista);
}

