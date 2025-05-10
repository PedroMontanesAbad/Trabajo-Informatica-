#include "lib.h"

//vector2[] es posiciones_cuencas[15]
//vector es linea cuenca[4236]
//vector1 es Embalse embalse[353]

//NOMBRES DE CUENCAS:

void nombres_cuencas(int j, linea vector[]) {

	int f = 0, i;
	int posiciones_cuencas[15];
	for (i = 0;i < j;i++) {


		if (strcmp(vector[i].cuenca_hidrografica, vector[i - 1].cuenca_hidrografica) != 0) {
			f++;

			printf("%i- ", f);
			printf("%s\n", vector[i].cuenca_hidrografica);
		}

	}

}

// SELECCIÓN DE CUENCA:

int seleccion_cuenca(int num_cuenca, char C_cuenca[]) {

	do {

		printf("\nIntroduce el numero de la cuenca: ");

		scanf("%s", C_cuenca);

		if (('9' < C_cuenca[0] && C_cuenca[0] < '0') && ('9' < C_cuenca[1] && C_cuenca[1] < '0')) {
			printf("\nCaracter no valido, repite:\n");
		}
		else {
			if (C_cuenca[0] == '0') {
				printf("\nNumero no valido, repite:\n");
			}

			else {
				sscanf(C_cuenca, "%i", &num_cuenca);
				if ((0 >= num_cuenca) || (num_cuenca > 16)) {
					printf("\nNumero no valido, repite:\n");
				}
			}
		}
	}

	while ((0 >= num_cuenca) || (num_cuenca > 16) || (('9' < C_cuenca[0] && C_cuenca[0] < '0') && ('9' < C_cuenca[1] && C_cuenca[1] < '0')) || (C_cuenca[0] == '0'));

	return num_cuenca;

}

//NOMBRES DE EMBALSES:

void nombres_cuencas_embalse(int j, int num_cuenca, linea vector[], int vector2[]) {
	int i, f = 0, m=0;

	for (i = vector2[num_cuenca - 1];i < vector2[num_cuenca];i++) {
		if (i % 12 == 0) {
			printf("%i. %s\n", f + 1, vector[i].embalse_nombre);
			f++;
			m++;


		}

	}

}

// SELECCIÓN DE EMBALSES:

int seleccion_embalse(int num_embalse, int vector2[], int num_cuenca, char C_embalse[]) {

	do {
		printf("\nIntroduce el numero del embalse: ");
		scanf("%s", C_embalse);

		if (('9' < C_embalse[0] && C_embalse[0] < '0') && ('9' < C_embalse[1] && C_embalse[1] < '0')) {
			printf("\nCaracter no valido, repite:\n");
		}
		else {
			if (C_embalse[0] == '0') {
				printf("\nNumero no valido, repite:\n");
			}

			else {
				sscanf(C_embalse, "%i", &num_embalse);
				if ((0 >= num_embalse) || (num_embalse > ((vector2[num_cuenca] - vector2[num_cuenca - 1]) / 12))) {
					printf("\nNumero no valido, repite:\n");
				}
			}
		}

	} while ((0 >= num_embalse) || (num_embalse > ((vector2[num_cuenca] - vector2[num_cuenca - 1]) / 12)) || ('9' < C_embalse[0] && C_embalse[0] < '0') && ('9' < C_embalse[1] && C_embalse[1] < '0') || (C_embalse[0] == '0'));

	return num_embalse;

}

//SELECCIÓN DE AÑOS:

int seleccion_anyo(int anyo, char C_anyo[]) {

	do {
		printf("\nIntroduce el anyo deseado 2012-2021: ");

		scanf("%s", C_anyo);

		if (('9' < C_anyo[0] && C_anyo[0] < '0') || ('9' < C_anyo[1] && C_anyo[1] < '0') || ('9' < C_anyo[2] && C_anyo[2] < '0') || ('9' < C_anyo[3] && C_anyo[3] < '0')) {
			printf("\nCaracter no valido, repite:\n");
		}
		else {
			if (C_anyo[0] == '0') {
				printf("\nbNumero no valido, repite:\n");
			}

			else {
				sscanf(C_anyo, "%i", &anyo);
				if ((2012 > anyo) || (anyo > 2021)) {
					printf("\nNumero no valido, repite:\n");
				}
			}
		}
	}

	while ((2012 > anyo) || (anyo > 2021) || ('9' < C_anyo[0] && C_anyo[0] < '0') || ('9' < C_anyo[1] && C_anyo[1] < '0') || ('9' < C_anyo[2] && C_anyo[2] < '0') || ('9' < C_anyo[3] && C_anyo[3] < '0') || (C_anyo[0] == '0'));

	return anyo;
}
//SELECCIÓN MES:

int seleccion_mes(int N_mes, char C_mes[]) {

	do {

		printf("\nIntroduce el numero del mes deseado: ");

		scanf("%s", C_mes);

		if ((C_mes[0] < '0' && C_mes[0] > '9') || (C_mes[1] < '0' && C_mes[1] > '9')) {
			printf("\nNumero no valido, repite:\n");
		}
		else {
			if (C_mes[0] == '0') {
				printf("\nNumero no valido, repite:\n");
			}
			else {
				sscanf(C_mes, "%i", &N_mes);

				if ((N_mes < 1) || (N_mes > 12)) {
					printf("\nNumero no valido, repite:\n");
				}

			}
		}
	} while (((C_mes[0] < '0' && C_mes[0] > '9') || (C_mes[1] < '0' && C_mes[1] > '9')) || (C_mes[0] == '0') || ((N_mes < 1) || (N_mes > 12)));

	return N_mes;
}



//PORCENTAJE

float porcentaje_embalse(int anyo, int N_mes, int num_cuenca, int vector2[], int embalse_coincide, int num_embalse, linea vector[], Embalse vector1[]) {
	int i;
	float capacidad_actual = 0, capacidad_max = 0, porcentaje;


	switch (anyo) {
	case(2012):
		i = vector2[num_cuenca - 1] + (num_embalse - 1) * 12 + (N_mes - 1);
		capacidad_actual = vector[i].dosmildoce;
		capacidad_max = vector1[embalse_coincide - 1].etotal;

		porcentaje = capacidad_actual * 100 / capacidad_max;
		break;

	case(2013):
		i = vector2[num_cuenca - 1] + (num_embalse - 1) * 12 + (N_mes - 1);
		capacidad_actual = vector[i].dosmiltrece;
		capacidad_max = vector1[embalse_coincide - 1].etotal;

		porcentaje = capacidad_actual * 100 / capacidad_max;
		break;

	case(2014):
		i = vector2[num_cuenca - 1] + (num_embalse - 1) * 12 + (N_mes - 1);
		capacidad_actual = vector[i].dosmilcatorce;
		capacidad_max = vector1[embalse_coincide - 1].etotal;

		porcentaje = capacidad_actual * 100 / capacidad_max;
		break;

	case(2015):
		i = vector2[num_cuenca - 1] + (num_embalse - 1) * 12 + (N_mes - 1);
		capacidad_actual = vector[i].dosmilquince;
		capacidad_max = vector1[embalse_coincide - 1].etotal;

		porcentaje = capacidad_actual * 100 / capacidad_max;
		break;

	case(2016):
		i = vector2[num_cuenca - 1] + (num_embalse - 1) * 12 + (N_mes - 1);
		capacidad_actual = vector[i].dosmildieciseis;
		capacidad_max = vector1[embalse_coincide - 1].etotal;

		porcentaje = capacidad_actual * 100 / capacidad_max;
		break;

	case(2017):
		i = vector2[num_cuenca - 1] + (num_embalse - 1) * 12 + (N_mes - 1);
		capacidad_actual = vector[i].dosmildiecisiete;
		capacidad_max = vector1[embalse_coincide - 1].etotal;

		porcentaje = capacidad_actual * 100 / capacidad_max;
		break;

	case(2018):
		i = vector2[num_cuenca - 1] + (num_embalse - 1) * 12 + (N_mes - 1);
		capacidad_actual = vector[i].dosmildieciocho;
		capacidad_max = vector1[embalse_coincide - 1].etotal;

		porcentaje = capacidad_actual * 100 / capacidad_max;
		break;

	case(2019):
		i = vector2[num_cuenca - 1] + (num_embalse - 1) * 12 + (N_mes - 1);
		capacidad_actual = vector[i].dosmildiecinueve;
		capacidad_max = vector1[embalse_coincide - 1].etotal;

		porcentaje = capacidad_actual * 100 / capacidad_max;
		break;

	case(2020):
		i = vector2[num_cuenca - 1] + (num_embalse - 1) * 12 + (N_mes - 1);
		capacidad_actual = vector[i].dosmilveinte;
		capacidad_max = vector1[embalse_coincide - 1].etotal;

		porcentaje = capacidad_actual * 100 / capacidad_max;
		break;

	case(2021):
		i = vector2[num_cuenca - 1] + (num_embalse - 1) * 12 + (N_mes - 1);
		capacidad_actual = vector[i].dosmilveintiuno;
		capacidad_max = vector1[embalse_coincide - 1].etotal;

		porcentaje = capacidad_actual * 100 / capacidad_max;
		break;

	}
	return porcentaje;
}


//PONER ESPACIOS EN _, CUENCAS:

char* cambio_espacios_cuencas(linea vector[], int num_cuenca, int vector2[], int num_embalse) {
	int c = 0;
	char cambio[100];
	strcpy(cambio, vector[vector2[num_cuenca - 1] + (num_embalse - 1) * 12].cuenca_hidrografica);

	while (cambio[c] != '\0') {
		if (cambio[c] == '_') {
			cambio[c] = ' ';
		}
		c++;
	}
	strcpy(vector[vector2[num_cuenca - 1] + (num_embalse - 1) * 12].cuenca_hidrografica, cambio);
	return vector[vector2[num_cuenca - 1] + (num_embalse - 1) * 12].cuenca_hidrografica;
}

//PONER ESPACIOS EN _, EMBALSE:

char* cambio_espacios_embalses(linea vector[], int num_cuenca, int vector2[], int num_embalse) {

	int c = 0;
	char cambio[100];
	strcpy(cambio, vector[vector2[num_cuenca - 1] + (num_embalse - 1) * 12].embalse_nombre);

	while (cambio[c] != '\0') {
		if (cambio[c] == '_') {
			cambio[c] = ' ';
		}
		c++;
	}
	strcpy(vector[vector2[num_cuenca - 1] + (num_embalse - 1) * 12].embalse_nombre, cambio);
	return vector[vector2[num_cuenca - 1] + (num_embalse - 1) * 12].embalse_nombre;
}

//% DE SEQUÍA

void sequia(int porcentaje) {


	if ((50 < porcentaje) && (porcentaje < 70)) {
		printf("\n\nPeriodo de sequia leve.");
	}
	else if ((30 < porcentaje) && (porcentaje < 50)) {
		printf("\n\nPeriodo de sequia moderada.");
	}
	else if (porcentaje < 30) {
		printf("\n\nPeriodo de sequia grave.");
	}
	else if (porcentaje > 100) {
		printf("\n\nEmbalse en maximos, posiblemente debordado.");
	}


}

// MAIN PORCENTAJES 

void porcentajes_main() {

	int f = 0, j = 0, k = 0, embalse_coincide = 0, c, i;

	char C_cuenca[2], C_embalse[2], C_mes[2], C_anyo[5], cambio[100];

	int num_embalse=0, anyo=0, N_mes=0, num_cuenca=0, posiciones_cuencas[15];

	float porcentaje, capacidad_max, capacidad_actual;

	linea cuenca[4236];
	Embalse embalse[353];

	//ABRIMOS FICHEROS:

	FILE* tabla;
	tabla = fopen("texto_proyecto.csv", "r");

	if (tabla == NULL) // Si el resultado es NULL mensaje de error
	{
		printf("Error al abrir el fichero.\n");

	}

	FILE* lista;
	lista = fopen("Embalses_capacidad.txt", "r");

	if (lista == NULL) // Si el resultado es NULL mensaje de error
	{
		printf("Error al abrir el fichero 2.\n");

	}

	//SE LEE EL PRIMER FICHERO:

		//Poner que el puntero avance una linea
	fseek(tabla, 90, SEEK_SET);
	while (fscanf(tabla, "%[^,],%[^,],%i,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f\n", cuenca[j].cuenca_hidrografica, cuenca[j].embalse_nombre, &cuenca[j].mes, &cuenca[j].dosmildoce, &cuenca[j].dosmiltrece, &cuenca[j].dosmilcatorce, &cuenca[j].dosmilquince, &cuenca[j].dosmildieciseis, &cuenca[j].dosmildiecisiete, &cuenca[j].dosmildieciocho, &cuenca[j].dosmildiecinueve, &cuenca[j].dosmilveinte, &cuenca[j].dosmilveintiuno) != EOF)
	{

		//printf("Linea %i:\n", j);
		//printf("%[^,],%[^,],%i,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f\n", cuenca[j].cuenca_hidrografica , cuenca[j].embalse_nombre , cuenca[j].mes , cuenca[j].dosmildoce, cuenca[j].dosmiltrece, cuenca[j].dosmilcatorce, cuenca[j].dosmilquince, cuenca[j].dosmildieciseis, cuenca[j].dosmildiecisiete, cuenca[j].dosmildieciocho,  cuenca[j].dosmildiecinueve,  cuenca[j].dosmilveinte,  cuenca[j].dosmilveintiuno );

		j++;
	}

	// las comparamos para no repetir

	for (i = 0;i < j;i++) {

		if (strcmp(cuenca[i].cuenca_hidrografica, cuenca[i - 1].cuenca_hidrografica) != 0) {

			posiciones_cuencas[f] = i;
			//printf("\ni es %i",posiciones_cuencas[f]);
			f++;
		}
	}

	//añadimos la número 16

	posiciones_cuencas[f] = j;

	//NOMBRES DE CUENCAS ENNUMERADAS



	nombres_cuencas(j, cuenca);

	//NÚMERO DE CUENCA

	num_cuenca = seleccion_cuenca(num_cuenca, C_cuenca);

	//IMPRIME EMBALSES DE UNA CUENCA EN CONCRETO

	nombres_cuencas_embalse(j, num_cuenca, cuenca, posiciones_cuencas);

	//SELECCIONA EL NÚMERO DE EMBALSE

	num_embalse = seleccion_embalse(num_embalse, posiciones_cuencas, num_cuenca, C_embalse);


	//IMPRIME CUENCA Y EMBALSE, PARA VER COMO VAS.

	//printf("Tu embalse es %s, de la cuenca %s \n",cuenca[posiciones_cuencas[num_cuenca-1]+(num_embalse-1)*12].embalse_nombre,cuenca[posiciones_cuencas[num_cuenca-1]+(num_embalse-1)*12].cuenca_hidrografica) ;


	//ESCANEA EL SEGUNDO FICHERO; 
	//Y COMPARA SUS LINEAS (LAS DEL SEGUNDO FICHERO) CON EL NOMBRE DEL EMBALSE ESCOGIDO EN EL PRIMER FICHERO.
	//CUANDO COINCIDEN SE CUMPLE EL IF, Y DAMOS EL VALOR NÚMERICO A b, k+1 POR SER VECTOR. ESE VALOR NOS PERMITE CONOCER LA LÍNEA DEL
	//SECUNDO FICHERO DONDE ESTÁ EL EMBALSE QUE COINCIDE CON EL PRIMER FICHERO, Y POR TANTO SU CAPACIDAD TOTAL.

	while (fscanf(lista, "%s\t%f\n", embalse[k].embalse_nom, &embalse[k].etotal) != EOF)
	{

		//printf("%s\t%.2f\n", embalse[k].embalse_nom, embalse[k].etotal );

		if (strcmp(cuenca[posiciones_cuencas[num_cuenca - 1] + (num_embalse - 1) * 12].embalse_nombre, embalse[k].embalse_nom) == 0) {
			embalse_coincide = k + 1;
		}
		k++;

	}

	//PEDIMOS FECHA 

	printf("\n\nAhora vamos a seleccionar la fecha: \n");

	anyo = seleccion_anyo(anyo, C_anyo);

	N_mes = seleccion_mes(N_mes, C_mes);

	//MOSTRAMOS TEXTO FINAL CON TODOS LOS DATOS

	porcentaje = porcentaje_embalse(anyo, N_mes, num_cuenca, posiciones_cuencas, embalse_coincide, num_embalse, cuenca, embalse);

	cambio_espacios_cuencas(cuenca, num_cuenca, posiciones_cuencas, num_embalse);

	cambio_espacios_embalses(cuenca, num_cuenca, posiciones_cuencas, num_embalse);
	
	printf("El embalse %s de la cuenca %s estaba al %.2f%% de su capadidad, en el mes %i del anyo %i.", cuenca[posiciones_cuencas[num_cuenca - 1] + (num_embalse - 1) * 12].embalse_nombre, cuenca[posiciones_cuencas[num_cuenca - 1] + (num_embalse - 1) * 12].cuenca_hidrografica, porcentaje,N_mes, anyo);

	//SÓLO SI HAY SEQÍA

	sequia(porcentaje);

	fclose(tabla);
	fclose(lista);
}


void nombres_embalses(int j, linea vector[]) {		// Vector es cuencas
	int i, f = 0;
	for (i = 0;i < j;i++) {
		if (i % 12 == 0) {
			printf("%i- %s\n", f + 1, vector[i].embalse_nombre);
			f++;

		}
	}
}


//LISTA CUENCAS:

void lista_cuencas(){
		int j = 0;


	linea cuenca[4236];

	//ABRIMOS FICHEROS:

	FILE* tabla;
	tabla = fopen("texto_proyecto.csv", "r");

	if (tabla == NULL) // Si el resultado es NULL mensaje de error
	{
		printf("Error al abrir el fichero.\n");

	}
	fseek(tabla, 90, SEEK_SET);
	while (fscanf(tabla, "%[^,],%[^,],%i,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f\n", cuenca[j].cuenca_hidrografica, cuenca[j].embalse_nombre, &cuenca[j].mes, &cuenca[j].dosmildoce, &cuenca[j].dosmiltrece, &cuenca[j].dosmilcatorce, &cuenca[j].dosmilquince, &cuenca[j].dosmildieciseis, &cuenca[j].dosmildiecisiete, &cuenca[j].dosmildieciocho, &cuenca[j].dosmildiecinueve, &cuenca[j].dosmilveinte, &cuenca[j].dosmilveintiuno) != EOF)
	{

		//printf("Linea %i:\n", j);
		//printf("%[^,],%[^,],%i,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f\n", cuenca[j].cuenca_hidrografica , cuenca[j].embalse_nombre , cuenca[j].mes , cuenca[j].dosmildoce, cuenca[j].dosmiltrece, cuenca[j].dosmilcatorce, cuenca[j].dosmilquince, cuenca[j].dosmildieciseis, cuenca[j].dosmildiecisiete, cuenca[j].dosmildieciocho,  cuenca[j].dosmildiecinueve,  cuenca[j].dosmilveinte,  cuenca[j].dosmilveintiuno );

		j++;
	}
	printf("Tus cuencas son:\n\n");
	nombres_cuencas(j, cuenca) ;
	
}

//LISTA EMBALSES:

void lista_embalses(){
		int j = 0;


	linea cuenca[4236];

	//ABRIMOS FICHEROS:

	FILE* tabla;
	tabla = fopen("texto_proyecto.csv", "r");

	if (tabla == NULL) // Si el resultado es NULL mensaje de error
	{
		printf("Error al abrir el fichero.\n");

	}
	fseek(tabla, 90, SEEK_SET);
	while (fscanf(tabla, "%[^,],%[^,],%i,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f\n", cuenca[j].cuenca_hidrografica, cuenca[j].embalse_nombre, &cuenca[j].mes, &cuenca[j].dosmildoce, &cuenca[j].dosmiltrece, &cuenca[j].dosmilcatorce, &cuenca[j].dosmilquince, &cuenca[j].dosmildieciseis, &cuenca[j].dosmildiecisiete, &cuenca[j].dosmildieciocho, &cuenca[j].dosmildiecinueve, &cuenca[j].dosmilveinte, &cuenca[j].dosmilveintiuno) != EOF)
	{

		//printf("Linea %i:\n", j);
		//printf("%[^,],%[^,],%i,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f\n", cuenca[j].cuenca_hidrografica , cuenca[j].embalse_nombre , cuenca[j].mes , cuenca[j].dosmildoce, cuenca[j].dosmiltrece, cuenca[j].dosmilcatorce, cuenca[j].dosmilquince, cuenca[j].dosmildieciseis, cuenca[j].dosmildiecisiete, cuenca[j].dosmildieciocho,  cuenca[j].dosmildiecinueve,  cuenca[j].dosmilveinte,  cuenca[j].dosmilveintiuno );

		j++;
	}
	printf("Tus embalses son:\n\n");
	nombres_embalses(j, cuenca) ;
	
}

float media_anyo(int j, int anyo, linea vector[]) {		// Vector es cuencas
	int i;
	float suma = 0, media;
	switch (anyo) {
	case(2012):
		for (i = 0;i < j;i++) {
			suma = suma + vector[i].dosmildoce;

		}
		media = suma / j;
		printf("%f\n", media);
		break;

	case(2013):
		for (i = 0;i < j;i++) {
			suma = suma + vector[i].dosmiltrece;

		}
		media = suma / j;
		printf("%f\n", media);
		break;

	case(2014):
		for (i = 0;i < j;i++) {
			suma = suma + vector[i].dosmilcatorce;

		}
		media = suma / j;
		printf("%f\n", media);
		break;

	case(2015):
		for (i = 0;i < j;i++) {
			suma = suma + vector[i].dosmilquince;

		}
		media = suma / j;
		printf("%f\n", media);
		break;

	case(2016):
		for (i = 0;i < j;i++) {
			suma = suma + vector[i].dosmildieciseis;

		}
		media = suma / j;
		printf("%f\n", media);
		break;

	case(2017):
		for (i = 0;i < j;i++) {
			suma = suma + vector[i].dosmildiecisiete;

		}
		media = suma / j;
		printf("%f\n", media);
		break;

	case(2018):
		for (i = 0;i < j;i++) {
			suma = suma + vector[i].dosmildieciocho;

		}
		media = suma / j;
		printf("%f\n", media);
		break;

	case(2019):
		for (i = 0;i < j;i++) {
			suma = suma + vector[i].dosmildiecinueve;

		}
		media = suma / j;
		printf("%f\n", media);
		break;

	case(2020):
		for (i = 0;i < j;i++) {
			suma = suma + vector[i].dosmilveinte;

		}
		media = suma / j;
		printf("%f\n", media);
		break;

	case(2021):
		for (i = 0;i < j;i++) {
			suma = suma + vector[i].dosmilveintiuno;

		}
		media = suma / j;
		printf("%f\n", media);
		break;

	default:
		printf("Año no registrado\n");
		media = -1;
		break;

	}
	return media;
}

float media_anyo_embalse(int j, int anyo, int num_cuenca, int num_embalse, linea vector[], int vector2[]) {		//  Vector 1 es cuencas y vector 2 es posiciones cuencas
	int i;
	float suma=0, media;
	switch (anyo) {
	case(2012):
		for (i = vector2[num_cuenca - 1] + (num_embalse - 1) * 12;i < vector2[num_cuenca - 1] + (num_embalse) * 12;i++) {
			suma = suma + vector[i].dosmildoce;
			printf("dato:%f\n", vector[i].dosmildoce);
			printf("linea:%i\n", i);
		}
		media = suma / 12;
		//printf("%f\n", media);
		break;

	case(2013):
		for (i = vector2[num_cuenca - 1] + (num_embalse - 1) * 12;i < vector2[num_cuenca - 1] + (num_embalse) * 12;i++) {
			suma = suma + vector[i].dosmiltrece;
			printf("dato:%f\n", vector[i].dosmiltrece);
			printf("linea:%i\n", i);
		}
		media = suma / 12;
		//printf("%f\n", media);
		break;

	case(2014):
		for (i = vector2[num_cuenca - 1] + (num_embalse - 1) * 12;i < vector2[num_cuenca - 1] + (num_embalse) * 12;i++) {
			suma = suma + vector[i].dosmilcatorce;
			printf("dato:%f\n", vector[i].dosmilcatorce);
			printf("linea:%i\n", i);
		}
		media = suma / 12;
		//printf("%f\n", media);
		break;

	case(2015):
		for (i = vector2[num_cuenca - 1] + (num_embalse - 1) * 12;i < vector2[num_cuenca - 1] + (num_embalse) * 12;i++) {
			suma = suma + vector[i].dosmilquince;
			printf("dato:%f\n", vector[i].dosmilquince);
			printf("linea:%i\n", i);
		}
		media = suma / 12;
		//printf("%f\n", media);
		break;


	case(2016):
		for (i = vector2[num_cuenca - 1] + (num_embalse - 1) * 12;i < vector2[num_cuenca - 1] + (num_embalse) * 12;i++) {
			suma = suma + vector[i].dosmildieciseis;
			printf("dato:%f\n", vector[i].dosmildieciseis);
			printf("linea:%i\n", i);
		}
		media = suma / 12;
		//printf("%f\n", media);
		break;


	case(2017):
		for (i = vector2[num_cuenca - 1] + (num_embalse - 1) * 12;i < vector2[num_cuenca - 1] + (num_embalse) * 12;i++) {
			suma = suma + vector[i].dosmildiecisiete;
			printf("dato:%f\n", vector[i].dosmildiecisiete);
			printf("linea:%i\n", i);
		}
		media = suma / 12;
		//printf("%f\n", media);
		break;


	case(2018):
		for (i = vector2[num_cuenca - 1] + (num_embalse - 1) * 12;i < vector2[num_cuenca - 1] + (num_embalse) * 12;i++) {
			suma = suma + vector[i].dosmildieciocho;
			printf("dato:%f\n", vector[i].dosmildieciocho);
			printf("linea:%i\n", i);
		}
		media = suma / 12;
		//printf("%f\n", media);
		break;


	case(2019):
		for (i = vector2[num_cuenca - 1] + (num_embalse - 1) * 12;i < vector2[num_cuenca - 1] + (num_embalse) * 12;i++) {
			suma = suma + vector[i].dosmildiecinueve;
			printf("dato:%f\n", vector[i].dosmildiecinueve);
			printf("linea:%i\n", i);
		}
		media = suma / 12;
		//printf("%f\n", media);
		break;


	case(2020):
		for (i = vector2[num_cuenca - 1] + (num_embalse - 1) * 12;i < vector2[num_cuenca - 1] + (num_embalse) * 12;i++) {
			suma = suma + vector[i].dosmilveinte;
			printf("dato:%f\n", vector[i].dosmilveinte);
			printf("linea:%i\n", i);
		}
		media = suma / 12;
		//printf("%f\n", media);
		break;


	case(2021):
		for (i = vector2[num_cuenca - 1] + (num_embalse - 1) * 12;i < vector2[num_cuenca - 1] + (num_embalse) * 12;i++) {
			suma = suma + vector[i].dosmilveintiuno;
			printf("dato:%f\n", vector[i].dosmilveintiuno);
			printf("linea:%i\n", i);
		}
		media = suma / 12;
		printf("%f\n", media);
		break;

	default:
		printf("Anyo no registrado\n");
		media = -1;
		break;

	}
	return media;
}

float max_y_min_embalse(int j, int anyo, int num_cuenca, int num_embalse, linea vector[], int vector2[], int vector3[]) { // Vector 3 es vector auxiliar para guardar los datos obtenidos
	int i, mesM, mesm;
	float maximo = 0, minimo = 1000;
	switch (anyo) {
	case(2012):
		for (i = vector2[num_cuenca - 1] + (num_embalse - 1) * 12;i < vector2[num_cuenca - 1] + (num_embalse) * 12;i++) {
			if (vector[i].dosmildoce > maximo)
			{
				maximo = vector[i].dosmildoce;
				mesM = (i + 1) % 12;
			}
			if (vector[i].dosmildoce < minimo)
			{
				minimo = vector[i].dosmildoce;
				mesm = (i + 1) % 12;
			}

		}
		break;


	}
	vector3[0] = maximo;
	vector3[1] = mesM;
	vector3[2] = minimo;
	vector3[3] = mesm;
	//printf("El maximo es %f en el mes %i, el minimo es %f en el mes %i", vector3[0],vector3[1],vector3[2],vector3[3]);
	return 0;
}


void gotoxy(int x, int y)
{
	HANDLE Identiventana;

	Identiventana = GetStdHandle(STD_OUTPUT_HANDLE);

	COORD Coordenadas;
	Coordenadas.X = x;
	Coordenadas.Y = y;

	SetConsoleCursorPosition(Identiventana, Coordenadas);
}

void DibujarMenu()
{
	int x = 19, y = 8, i, fila = 81, columna = 21;//De espacio hay -1

	////Dibujar Cuadrados////
	{
		//Cuadrado Grande
		{
			for (i = 0; i < fila; i++)//Fila Arriba
			{
				x++;
				gotoxy(x, y);
				printf("%c", 205);
			}
			gotoxy(x, y);
			printf("%c", 187);
			for (i = 0; i < columna; i++)//Columna derecha
			{
				y++;
				gotoxy(x, y);
				printf("%c", 186);

			}
			gotoxy(x, y);
			printf("%c", 188);
			for (i = 0; i < fila; i++)//Fila abajo
			{
				x--;
				gotoxy(x, y);
				printf("%c", 205);
			}
			gotoxy(x, y);
			printf("%c", 200);
			for (i = 0; i < columna; i++)//Columna izquierda
			{
				y--;
				gotoxy(x, y);
				printf("%c", 186);
			}
			gotoxy(x, y);
			printf("%c", 201);
		}

		//Cuadrados
		{
			//Columna centro
			{
				x = 60, y = 8;
				gotoxy(x, y);
				printf("%c", 203);
				for (i = 0; i < columna; i++)
				{
					y++;
					gotoxy(x, y);
					printf("%c", 186);
				}
				gotoxy(x, y);
				printf("%c", 202);
			}

			//Fila 1
			{
				x = 19, y = 15;
				gotoxy(x, y);
				printf("%c", 204);
				for (i = 0; i < fila; i++)//Fila Arriba
				{
					x++;
					gotoxy(x, y);
					printf("%c", 205);
				}
				gotoxy(x, y);
				printf("%c", 185);

			}

			//Fila 2
			{
				x = 19, y = 22;
				gotoxy(x, y);
				printf("%c", 204);
				for (i = 0; i < fila; i++)//Fila Arriba
				{
					x++;
					gotoxy(x, y);
					printf("%c", 205);
				}
				gotoxy(x, y);
				printf("%c", 185);
			}

			gotoxy(60, 15), printf("%c", 206);
			gotoxy(60, 22), printf("%c", 206);

		}
	}
}


int x, y;
//Texto0
void Texto0()
{
	//Titulo// 
	{
		gotoxy(55, 4);
		printf("MENU PRINCIPAL");
	}


	//Textos
	{
		////Texto Primer Cuadrado////
		{
			x = 20;
			y = 9;
			gotoxy(x, y);
			printf("LISTADOS");
			gotoxy(x, 14);
			printf("Presionar ( 1 )");

		}
		////// Segundo cuadrado/////
		{
			x = 61;
			y = 9;
			gotoxy(x, y);
			printf("INFORMACION GENERAL");
			gotoxy(x, 14);
			printf("Presionar ( 2 )");

		}
		//// Tercer cuadrado////
		{
			x = 20;
			y = 16;
			gotoxy(x, y);
			printf("CUESTIONARIO");
			gotoxy(x, 21);
			printf("Presionar ( 3 )");

		}
		//// Cuarto cuadrado////
		{
			x = 61;
			y = 16;
			gotoxy(x, y);
			printf("PALABRA DEL DIA");
			gotoxy(x, 21);
			printf("Presionar ( 4 )");

		}
		//// 5 cuadrado////
		{
			x = 20;
			y = 23;
			gotoxy(x, y);
			printf("AJUSTES");
			gotoxy(x, 28);
			printf("Presionar ( 5 )");

		}
		//// 6 cuadrado////
		{
			x = 61;
			y = 23;
			gotoxy(x, y);
			printf("SALIR DEL PROGRAMA");
			gotoxy(x, 28);
			printf("Presionar ( 6 )");

		}
	}

	gotoxy(55, 7);
	printf("Ir a: ");
	gotoxy(65, 7);
}

//Texto1
void Texto1()
{
	int x = 19, y = 9, i, fila = 81, columna = 20;

	////Dibujar Cuadrados 2X2////
	{
		//Cuadrado Grande
		{
			for (i = 0; i < fila; i++)//Fila Arriba
			{
				x++;
				gotoxy(x, y);
				printf("%c", 205);
			}
			gotoxy(x, y);
			printf("%c", 187);
			for (i = 0; i < columna; i++)//Columna derecha
			{
				y++;
				gotoxy(x, y);
				printf("%c", 186);

			}
			gotoxy(x, y);
			printf("%c", 188);
			for (i = 0; i < fila; i++)//Fila abajo
			{
				x--;
				gotoxy(x, y);
				printf("%c", 205);
			}
			gotoxy(x, y);
			printf("%c", 200);
			for (i = 0; i < columna; i++)//Columna izquierda
			{
				y--;
				gotoxy(x, y);
				printf("%c", 186);
			}
			gotoxy(x, y);
			printf("%c", 201);
		}
		//Separador
		{
			//Columna centro
			{
				x = 60, y = 9;
				gotoxy(x, y);
				printf("%c", 203);
				for (i = 0; i < columna; i++)
				{
					y++;
					gotoxy(x, y);
					printf("%c", 186);
				}
				gotoxy(x, y);
				printf("%c", 202);
			}

			//Fila 
			{
				x = 19, y = 19;
				gotoxy(x, y);
				printf("%c", 204);
				for (i = 0; i < fila; i++)//Fila Arriba
				{
					x++;
					gotoxy(x, y);
					printf("%c", 205);
				}
				gotoxy(x, y);
				printf("%c", 185);

			}

			gotoxy(60, 19), printf("%c", 206);
		}


		//Texto 
		{
			//TITULO
			gotoxy(53, 4);
			printf("LISTADOS");

			//Primer Cuadrado
			gotoxy(20, 10);
			printf("LISTADO DE CUENCAS");
			gotoxy(20, 18);
			printf("Presionar ( 1 )");

			//Segundo Cuadrado
			gotoxy(61, 10);
			printf("LISTADO DE EMBALSES");
			gotoxy(61, 18);
			printf("Presionar ( 2 )");

			//Tercer Cuadrado
			gotoxy(20, 20);
			printf("VOLVER AL MENU");
			gotoxy(20, 28);
			printf("Presionar ( 3 )");

			//Cuarto Cuadrado
			gotoxy(61, 20);
			printf("SALIR DEL PROGRAMA");
			gotoxy(61, 28);
			printf("Presionar ( 4 )");


		}

		gotoxy(55, 7);
		printf("Ir a: ");
		gotoxy(65, 7);
	}
}

//Texto2
void Texto2()
{
	//Titulo// 
	{
		gotoxy(55, 4);
		printf("EMBALSES");
	}


	//Textos
	{
		////Texto Primer Cuadrado////
		{
			x = 20;
			y = 9;
			gotoxy(x, y);
			printf("MEDIAS");
			gotoxy(x, 14);
			printf("Presionar ( 1 )");
		}
		////// Segundo cuadrado/////
		{
			x = 61;
			y = 9;
			gotoxy(x, y);
			printf("PORCENTAJES");
			gotoxy(x, 14);
			printf("Presionar ( 2 )");
		}
		//// Tercer cuadrado////
		{
			x = 20;
			y = 16;
			gotoxy(x, y);
			printf("COMPARACION");
			gotoxy(x, 21);
			printf("Presionar ( 3 )");

		}
		//// Cuarto cuadrado////
		{
			x = 61;
			y = 16;
			gotoxy(x, y);
			printf("MAXIMO Y MINIMO");
			gotoxy(x, 21);
			printf("Presionar ( 4 )");

		}
		//// 5 cuadrado////
		{
			x = 20;
			y = 23;
			gotoxy(x, y);
			printf("VOLVER AL MENU");
			gotoxy(x, 28);
			printf("Presionar ( 5 )");

		}
		//// 6 cuadrado////
		{
			x = 61;
			y = 23;
			gotoxy(x, y);
			printf("SALIR DEL PROGRAMA");
			gotoxy(x, 28);
			printf("Presionar ( 6 )");

		}
	}

	gotoxy(55, 7);
	printf("Ir a: ");
	gotoxy(65, 7);
}

//Texto3
//void Texto3()

	//Titulo// 


	/*
	//Textos
	{
		////Texto Primer Cuadrado////
		{
			x = 20;
			y = 9;
			gotoxy(x, y);
			printf("-------------");
			gotoxy(x, 14);
			printf("Presionar ( 1 )");

		}
		////// Segundo cuadrado/////
		{
			x = 61;
			y = 9;
			gotoxy(x, y);
			printf("-----------------");
			gotoxy(x, 14);
			printf("Presionar ( 2 )");
		}
		//// Tercer cuadrado////
		{
			x = 20;
			y = 16;
			gotoxy(x, y);
			printf("-----------------");
			gotoxy(x, 21);
			printf("Presionar ( 3 )");

		}
		//// Cuarto cuadrado////
		{
			x = 61;
			y = 16;
			gotoxy(x, y);
			printf("-----------------");
			gotoxy(x, 21);
			printf("Presionar ( 4 )");

		}
		//// 5 cuadrado////
		{
			x = 20;
			y = 23;
			gotoxy(x, y);
			printf("VOLVER AL MENU");
			gotoxy(x, 28);
			printf("Presionar ( 5 )");

		}
		//// 6 cuadrado////
		{
			x = 61;
			y = 23;
			gotoxy(x, y);
			printf("SALIR DEL PROGRAMA");
			gotoxy(x, 28);
			printf("Presionar ( 6 )");

		}
	}

	gotoxy(55, 7);
	printf("Ir a: ");
	gotoxy(65, 7);
}*/

//Texto4

	void Texto4()
	{
		//Titulo//
		{
			gotoxy(55, 4);
			printf("PALABRA DEL DIA");
		}


		//Textos
		{
			////Texto Primer Cuadrado////
			{
				x = 20;
				y = 9;
				gotoxy(x, y);
				printf("-----------------");
				gotoxy(x, 12);
				printf("y");

				gotoxy(x, 14);
				printf("Presionar ( 1 )");

			}
			////// Segundo cuadrado/////
			{
				x = 61;
				y = 9;
				gotoxy(x, y);
				printf("-----------------");
				gotoxy(x, 12);
				printf("y");

				gotoxy(x, 14);
				printf("Presionar ( 2 )");

			}
			//// Tercer cuadrado////
			{
				x = 20;
				y = 16;
				gotoxy(x, y);
				printf("-----------------");
				gotoxy(x, 21);
				printf("Presionar ( 3 )");

			}
			//// Cuarto cuadrado////
			{
				x = 61;
				y = 16;
				gotoxy(x, y);
				printf("-----------------");
				gotoxy(x, 21);
				printf("Presionar ( 4 )");

			}
			//// 5 cuadrado////
			{
				x = 20;
				y = 23;
				gotoxy(x, y);
				printf("VOLVER AL MENU");
				gotoxy(x, 28);
				printf("Presionar ( 5 )");

			}
			//// 6 cuadrado////
			{
				x = 61;
				y = 23;
				gotoxy(x, y);
				printf("SALIR DEL PROGRAMA");
				gotoxy(x, 28);
				printf("Presionar ( 6 )");

			}
		}

		gotoxy(55, 7);
		printf("Ir a:");
		gotoxy(65, 7);
	}

	//Texto5
	void Texto5()
	{

		//TEXTO
	//Titulo// 
		{
			gotoxy(53, 4);
			printf("AJUSTES");
		}


		//Textos
		{
			////Texto Primer Cuadrado////
			{
				x = 20;
				y = 10;
				gotoxy(x, y);
				printf("MODO DIABLO:1");
				x = 20;
				y = 11;
				gotoxy(x, y);
				printf("VIOLETA:7");
				x = 20;
				y = 12;
				gotoxy(x, y);
				printf("AZUL:8");
				gotoxy(x, 18);
				printf("");

			}
			////// Segundo cuadrado/////
			{
				x = 61;
				y = 10;
				gotoxy(x, y);
				printf("SORPRESA");
				gotoxy(x, 18);
				printf("Presionar ( 2 )");

			}
			//// Tercer cuadrado////
			{
				x = 20;
				y = 20;
				gotoxy(x, y);
				printf("VOLVER AL MENU");
				gotoxy(x, 28);
				printf("Presionar ( 5 )");

			}
			//// Cuarto cuadrado////
			{
				x = 61;
				y = 20;
				gotoxy(x, y);
				printf("SALIR DEL PROGRAMA");
				gotoxy(x, 28);
				printf("Presionar ( 6 )");

			}
		}

		gotoxy(55, 7);
		printf("Ir a: ");
		gotoxy(65, 7);
	}





int donut() {
	float A = 0, B = 0;
	float i, j;
	int k;
	float z[1760];
	char b[1760];
	printf("\x1b[2J");
	for (;;) {
		memset(b, 32, 1760);
		memset(z, 0, 7040);
		for (j = 0; j < 6.28; j += 0.07) {
			for (i = 0; i < 6.28; i += 0.02) {
				float c = sin(i);
				float d = cos(j);
				float e = sin(A);
				float f = sin(j);
				float g = cos(A);
				float h = d + 2;
				float D = 1 / (c * h * e + f * g + 5);
				float l = cos(i);
				float m = cos(B);
				float n = sin(B);
				float t = c * h * g - f * e;
				int x = 40 + 30 * D * (l * h * m - t * n);
				int y = 12 + 15 * D * (l * h * n + t * m);
				int o = x + 80 * y;
				int N = 8 * ((f * e - c * d * g) * m - c * d * e - f * g - l * d * n);
				if (22 > y && y > 0 && x > 0 && 80 > x && D > z[o]) {
					z[o] = D;
					b[o] = ".,-~:;=!*#$@"[N > 0 ? N : 0];
				}
			}
		}
		printf("\x1b[H");
		for (k = 0; k < 1761; k++) {
			putchar(k % 80 ? b[k] : 10);
			A += 0.00004;
			B += 0.00002;
		}
		Sleep(30); // Usamos Sleep() en lugar de usleep(). El argumento está en milisegundos.
	}
	return 0;
}


//Fecha
void Fecha()
{
	printf("%s", __DATE__);

}

void SeisCuadrados()
{
	int x = 19, y = 9, i, fila = 81, columna = 20;

	////Dibujar Cuadrados////
	{
		//Cuadrado Grande
		{
			for (i = 0; i < fila; i++)//Fila Arriba
			{
				x++;
				gotoxy(x, y);
				printf("%c", 205);
			}
			gotoxy(x, y);
			printf("%c", 187);
			for (i = 0; i < columna; i++)//Columna derecha
			{
				y++;
				gotoxy(x, y);
				printf("%c", 186);

			}
			gotoxy(x, y);
			printf("%c", 188);
			for (i = 0; i < fila; i++)//Fila abajo
			{
				x--;
				gotoxy(x, y);
				printf("%c", 205);
			}
			gotoxy(x, y);
			printf("%c", 200);
			for (i = 0; i < columna; i++)//Columna izquierda
			{
				y--;
				gotoxy(x, y);
				printf("%c", 186);
			}
			gotoxy(x, y);
			printf("%c", 201);
		}
		//Separador
		{
			//Columna centro
			{
				x = 60, y = 9;
				gotoxy(x, y);
				printf("%c", 203);
				for (i = 0; i < columna; i++)
				{
					y++;
					gotoxy(x, y);
					printf("%c", 186);
				}
				gotoxy(x, y);
				printf("%c", 202);
			}

			//Fila 
			{
				x = 19, y = 19;
				gotoxy(x, y);
				printf("%c", 204);
				for (i = 0; i < fila; i++)//Fila Arriba
				{
					x++;
					gotoxy(x, y);
					printf("%c", 205);
				}
				gotoxy(x, y);
				printf("%c", 185);

			}

			gotoxy(60, 19), printf("%c", 206);
		}


		//Texto 
		{

			//Primer Cuadrado
			gotoxy(20, 10);
			printf("-----------------");
			gotoxy(20, 18);
			printf("Presionar ( 1 )");

			//Segundo Cuadrado
			gotoxy(61, 10);
			printf("-----------------");
			gotoxy(61, 18);
			printf("Presionar ( 2 )");

			//Tercer Cuadrado
			gotoxy(20, 20);
			printf("-----------------");
			gotoxy(20, 28);
			printf("Presionar ( 3 )");

			//Cuarto Cuadrado
			gotoxy(61, 20);
			printf("-----------------");
			gotoxy(61, 28);
			printf("Presionar ( 4 )");

			//TITULO
			gotoxy(53, 4);
			printf("-----------------");
		}

		gotoxy(55, 7);
		printf("Ir a: ");
		gotoxy(65, 7);
	}
}
void cuadradosDosPorDos()
{
	int x = 19, y = 9, i, fila = 81, columna = 20;

	////Dibujar Cuadrados 2X2////
	{
		//Cuadrado Grande
		{
			for (i = 0; i < fila; i++)//Fila Arriba
			{
				x++;
				gotoxy(x, y);
				printf("%c", 205);
			}
			gotoxy(x, y);
			printf("%c", 187);
			for (i = 0; i < columna; i++)//Columna derecha
			{
				y++;
				gotoxy(x, y);
				printf("%c", 186);

			}
			gotoxy(x, y);
			printf("%c", 188);
			for (i = 0; i < fila; i++)//Fila abajo
			{
				x--;
				gotoxy(x, y);
				printf("%c", 205);
			}
			gotoxy(x, y);
			printf("%c", 200);
			for (i = 0; i < columna; i++)//Columna izquierda
			{
				y--;
				gotoxy(x, y);
				printf("%c", 186);
			}
			gotoxy(x, y);
			printf("%c", 201);
		}
		//Separador
		{
			//Columna centro
			{
				x = 60, y = 9;
				gotoxy(x, y);
				printf("%c", 203);
				for (i = 0; i < columna; i++)
				{
					y++;
					gotoxy(x, y);
					printf("%c", 186);
				}
				gotoxy(x, y);
				printf("%c", 202);
			}

			//Fila 
			{
				x = 19, y = 19;
				gotoxy(x, y);
				printf("%c", 204);
				for (i = 0; i < fila; i++)//Fila Arriba
				{
					x++;
					gotoxy(x, y);
					printf("%c", 205);
				}
				gotoxy(x, y);
				printf("%c", 185);

			}

			gotoxy(60, 19), printf("%c", 206);
		}
	}
}
//Inicio funciones del cuestionario
int pregunta_inicial() {
	int valor;
	printf("\n \n¿Iniciar cuestionario?\n");

	printf("\t1-SI\n\t2-NO\n");

	do {

		scanf("%d", &valor);

		while ((getchar()) != '\n');

	} while (valor != 1 && valor != 2);

	return valor;
}

int valor_letra_introducida() {

	int i = 0;
	char letra;
	char cadena[10];

	printf("Introduzca la respuesta: ");

	do {

		fgets(cadena, sizeof(cadena), stdin);

		letra = toupper(cadena[0]);

		if (letra != 'A' && letra != 'B' && letra != 'C' && letra != 'D' && i > 0) {

			printf("\nCarácter incorrecto. Introduzca la respuesta de nuevo:");
		}

		i++;/*Ponemos un i de manera que el texto de carácter incorrecto solo salta a la segunda*/

	} while (letra != 'A' && letra != 'B' && letra != 'C' && letra != 'D');

	return letra;
}

int preguntas_cuestionario(int i) {

	char letra;

	int valor;

	switch (i) {

	case 0:
		printf("PREGUNTA Nª1: \n");

		printf("¿En que continente está el embalse artificial más grande del mundo?");

		printf("\n \tA)América \n \tB)Europa \n \tC)África \n \tD)Asia\n");

		valor = valor_letra_introducida();

		break;

	case  1:

		printf("\nPREGUNTA Nª2: \n");

		printf("¿Que país de Europa tiene el mayor número de embalses?");

		printf("\n \tA)Albania \n \tB)Rumanía \n \tC)Noruega \n \tD)España\n");

		valor = valor_letra_introducida();

		break;

	case  2:

		printf("\nPREGUNTA Nª3: \n");

		printf("¿País en el que se encuentra el embalse más grande de Europa?");

		printf("\n \tA)Francia \n \tB)Ucrania \n \tC)Italia \n \tD)Suecia\n");

		valor = valor_letra_introducida();

		break;

	case  3:

		printf("\nPREGUNTA Nª4: \n");

		printf("¿Qué factor influye en mayor medida a el nivel de agua en los embalses de España?");

		printf("\n \tA)Altitud de las montañas \n \tB)Población de la zona \n \tC)Temperatura media del mar \n \tD)Precipitaciones y sequías\n");

		valor = valor_letra_introducida();

		break;

	case  4:

		printf("\nPREGUNTA Nª5: \n");

		printf("¿Dónde se encuentra el embalse más antiguo de España?");

		printf("\n \tA)Extremadura \n \tB)Asturias \n \tC)Castilla y León \n \tD)País Vasco\n");

		valor = valor_letra_introducida();

		break;

	case  5:

		printf("\nPREGUNTA Nª6: \n");

		printf("¿Cual fue el año desde el 2004 en el que hubo más agua embalsada en todo el país?");

		printf("\n \tA)2008 \n \tB)2021 \n \tC)2013 \n \tD)2017\n");

		valor = valor_letra_introducida();

		break;

	}

	return valor - 'A' + 1;/*Se resta al valor de la letra el valor de A para que sea un número entre el 0 y el 3 y se le suma 1 para que esté en 1-4*/;
}

void mostrar_resultado(int correcta, int i) {

	if (correcta) {

		printf("\n \t \t!Respuesta correcta!\n");

		printf("\n\t \t \t        X\n");

		printf("\t \t \t       X\n");

		printf("\t \t \t      X \n");

		printf("\t \t \tX   X\n");

		printf("\t \t \t X X\n");

		printf("\t \t \t  X \n");

	}
	else {

		printf("\n \t \t!Respuesta incorrecta!: La respuesta era la ");

		switch (i) {

		case 0:

			printf("C-Africa");

			break;

		case 1:

			printf("D-España");

			break;

		case 2:

			printf("B-Ucrania");

			break;

		case 3:

			printf("D-Precipitaciones y sequías");

			break;

		case 4:

			printf("A-Extremadura");

			break;

		case 5:

			printf("C-2013");

			break;

		}

		printf("\n \n\t \t \tX   X\n");

		printf("\t \t \t X X\n");

		printf("\t \t \t  X\n");

		printf("\t \t \t X X\n");

		printf("\t \t \tX   X\n");
	}
}

void informacion_respuestas(int i) {
	switch (i) {

	case 0:

		printf("\n \n-En África se encuentra el embalse y lago artifical más grande del mundo, el lago Kariba en la fronterea entre Zimbawe y Zambia: Este posee un  volumen de 130 km^3 y desemboca en el Oceano Índico.\n");

		break;

	case 1:

		printf("\n \n-España es el país de Europa con más embalses y uno de los que más tiene en todo el mundo. Son más de 1200 los embalses de más de 1hm^3 de capacidad que hay repartidos por el país. No es de extrañar el número debido a la geografía y clima del país que favorece la creacíon de estas estructuras. \n");

		break;

	case 2:

		printf("\n \n-La presa de Kuibuyshev, en Rusia, es la presa más grande de Europa, con una capacidad de 58km^3.\n");

		break;

	case 3:

		printf("\n \n-El nivel de los embalses depende principalmente del balance entre el agua que reciben (principalmente de la lluvia y el deshielo) y la que se extrae para riego, consumo y otros usos. Las precipitaciones y las sequías tienen un impacto directo, mucho más que otros factores como la altitud o la densidad poblacional.\n");

		break;

	case 4:

		printf("\n \n-El embalse más antiguo de España se encuentra en la Comunidad Autónoma de Extremadura, más concretamente en Mérida. Es el embalse de Proserpina, fue construido por los romanos entre el I y II d.C y todavía sigue en uso (con fines recreativos). \n");

		break;

	case 5:

		printf("\n \n-El año con más acumulación fue el 2013, con 63.000 hm^3 acumulados, lo que representaba sobre la media un 111/100. \n");

		break;

	}
}
void tabla_errores(int correcta, int i) {

	printf("\n \t \t ***************");

	if (correcta) {

		printf("\n \t \t *PREGUNTA %d*SI*", i + 1);

	}
	else {

		printf("\n \t \t *PREGUNTA %d*NO*", i + 1);

	}
}

void premios_concurso(int numero_aciertos) {
	printf("\n \nTu número de aciertos es %d", numero_aciertos);

	switch (numero_aciertos) {
	case 0:

		printf("\n ¡¡Felicidades!! ");
		printf("\n   _______\n  |       |\n  |  X_X  |  ¡Has conseguido no acertar nada! \n  |_______|\n");

		break;

	case 1:
	case 2:
		printf("\n Bueno, al menos lo has intentado ¿no?. ");
		printf("\n    .-\"      \"-.\\n   /   O    O   \\\\n  |      /\\      |     Poco a poco\\n  |     ====     |     Sigue aprendiendo.\\n   \\            /\\n    '-.______.'\\n");

		break;

	case 3:
	case 4:
		printf("\n ¡Buen intento! Vas mejorando. ");
		printf("\n    .-\"      \"-. \n   /   O    O   \\ \n  |      /\\      |     ¡Ya estás cerca! \n  |     ====     |     En nada lo tienes. \n   \\            / \n    '-.______.' \n");

		break;

	case 5:
		printf("\n ¡Casi perfecto! ");
		printf("\n     _______\n    /       \\\n   |  _____  |\n   | |     | |\n   | |_____| |  Te mereces una medalla\n    \\_______/\n     \\_____/\n");

		break;

	case 6:
		printf("\n ¡Eres un maestro de embalses!");
		printf("\n      ___________\n     '._==_==_=_.' \n     .-\\:      /-.\n    | (|:.     |) |   Aquí tienes tu trofeo. \n     '-|:.     |-'\n       \\::.    /\n        '::. .'\n          ) (\n        _.' '._\n       `\"\"\"\"\"\"\"`\n");

		break;
	}
}

int cuestionario() {


	printf("\nOímos, vemos y hablamos sobre los embalses cotidianamente, nos abastecen de agua para el consumo y la agricultura y tienen un impacto en el día a día del que el ciudadano promedio no es consciente. Dicho esto, ¿sabrás lo suficiente cómo para llevarte el premio al que más sabe de embalses?");

	int valor_pregunta = pregunta_inicial(), respuestas[6], respuestas_correctas[6] = { 3,4,2,4,1,3 };

	if (valor_pregunta == 1) {

		printf("\t \t \t*********************************\n");

		printf("\t \t \t*    CUESTIONARIO DE EMBALSES   *\n");

		printf("\t \t \t*********************************\n");

		for (int i = 0;i < 6;i++) {

			respuestas[i] = preguntas_cuestionario(i);

			mostrar_resultado(respuestas[i] == respuestas_correctas[i], i);

			informacion_respuestas(i);
		}

		int numero_aciertos = 0;

		for (int i = 0;i < 6;i++) {

			tabla_errores(respuestas[i] == respuestas_correctas[i], i);

			if (respuestas[i] == respuestas_correctas[i]) {

				numero_aciertos++;

			}

		}

		printf("\n \t \t ***************");/*se acaba la tabla por abajo*/

		premios_concurso(numero_aciertos);

	}

	else if (valor_pregunta == 2) {

		printf("\n joe :(");

		return 0;

	}

	else {

		return 0;

	}

	return 0;
}
//Final funciones del cuestionario
