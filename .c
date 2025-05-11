#include "funciones_comunes.h"


//COMPARACION
#include <stdio.h>
#include <string.h>
#include <float.h>
#include <stdlib.h>



//SELECCION CUENCA:

int seleccion_cuenca_1(int num_cuenca, char C_cuenca[]) {

	do {

		printf("\nIntroduce el numero de la cuenca: ");
		scanf("%s", C_cuenca);


		if (('9' < C_cuenca[0] && C_cuenca[0] < '0') && ('9' < C_cuenca[1] && C_cuenca[1] < '0')) {
			printf("\nCaracter no valido, repite:\n");
		}
		else {
			if (C_cuenca[0] == '0') {
				printf("\nbNumero no valido, repite:\n");
			}

			else {
				sscanf(C_cuenca, "%i", &num_cuenca);

				if ((0 >= num_cuenca) || (num_cuenca > 16)) {
					printf("\ncNumero no valido, repite:\n");
				}
			}
		}
	}

	while ((0 >= num_cuenca) || (num_cuenca > 16) || (('9' < C_cuenca[0] && C_cuenca[0] < '0') && ('9' < C_cuenca[1] && C_cuenca[1] < '0')) || (C_cuenca[0] == '0'));

	return num_cuenca;

}


//LISTADO Y SELECCION DE EMBALSES:

void nombreseleccion_embalse_1(int num_cuenca, linea cuenca[], int* num_embalse, int* l_r_embalse) {
	int nume = 0, i;
	switch (num_cuenca)
	{
	case(1):
		for (i = 0;i < 8 * 12;i++) {
			if (strcmp(cuenca[i].embalse_nombre, cuenca[i - 1].embalse_nombre) != 0) {
				nume++;
				printf("%i-", nume);
				printf("%s\n", cuenca[i].embalse_nombre);
			}
		}
		printf("Elige un numero de embalse del Cantabrico Occidental: ");
		scanf("%i", num_embalse);
		*l_r_embalse = *num_embalse * 12;
		break;
	case(2):
		for (i = 8 * 12;i < 12 * 12;i++) {
			if (strcmp(cuenca[i].embalse_nombre, cuenca[i - 1].embalse_nombre) != 0) {
				nume++;
				printf("%i-", nume);
				printf("%s\n", cuenca[i].embalse_nombre);
			}
		}
		printf("Elige un numero de embalse del Cantabrico Oriental: ");
		scanf("%i", num_embalse);
		*l_r_embalse = 8 * 12 + *num_embalse * 12;
		break;
	case(3):
		for (i = 12 * 12;i < 24 * 12;i++) {
			if (strcmp(cuenca[i].embalse_nombre, cuenca[i - 1].embalse_nombre) != 0) {
				nume++;
				printf("%i-", nume);
				printf("%s\n", cuenca[i].embalse_nombre);
			}
		}
		printf("Elige un numero de embalse de la Cuenca Mediterranea Andaluza: ");
		scanf("%i", num_embalse);
		*l_r_embalse = 12 * 12 + *num_embalse * 12;
		break;
	case(4):
		for (i = 24 * 12;i < 31 * 12;i++) {
			if (strcmp(cuenca[i].embalse_nombre, cuenca[i - 1].embalse_nombre) != 0) {
				nume++;
				printf("%i-", nume);
				printf("%s\n", cuenca[i].embalse_nombre);
			}
		}
		printf("Elige un numero de embalse de la Cuencas Internas de Cataluna: ");
		scanf("%i", num_embalse);
		*l_r_embalse = 24 * 12 + *num_embalse * 12;
		break;
	case(5):
		for (i = 31 * 12;i < 33 * 12;i++) {
			if (strcmp(cuenca[i].embalse_nombre, cuenca[i - 1].embalse_nombre) != 0) {
				nume++;
				printf("%i-", nume);
				printf("%s\n", cuenca[i].embalse_nombre);
			}
		}
		printf("Elige un numero de embalse de la Cuencas Internas del Pais Vasco: ");
		scanf("%i", num_embalse);
		*l_r_embalse = 31 * 12 + *num_embalse * 12;
		break;
	case(6):
		for (i = 33 * 12;i < 67 * 12;i++) {
			if (strcmp(cuenca[i].embalse_nombre, cuenca[i - 1].embalse_nombre) != 0) {
				nume++;
				printf("%i-", nume);
				printf("%s\n", cuenca[i].embalse_nombre);
			}
		}
		printf("Elige un numero de embalse de la Cuenca del Duero: ");
		scanf("%i", num_embalse);
		*l_r_embalse = 33 * 12 + *num_embalse * 12;
		break;
	case(7):
		for (i = 67 * 12;i < 129 * 12;i++) {
			if (strcmp(cuenca[i].embalse_nombre, cuenca[i - 1].embalse_nombre) != 0) {
				nume++;
				printf("%i-", nume);
				printf("%s\n", cuenca[i].embalse_nombre);
			}
		}
		printf("Elige un numero de embalse de la Cuenca del Ebro: ");
		scanf("%i", num_embalse);
		*l_r_embalse = 67 * 12 + *num_embalse * 12;
		break;
	case(8):
		for (i = 129 * 12;i < 140 * 12;i++) {
			if (strcmp(cuenca[i].embalse_nombre, cuenca[i - 1].embalse_nombre) != 0) {
				nume++;
				printf("%i-", nume);
				printf("%s\n", cuenca[i].embalse_nombre);
			}
		}
		printf("Elige un numero de embalse de la Cuenca de Costa de Galicia: ");
		scanf("%i", num_embalse);
		*l_r_embalse = 129 * 12 + *num_embalse * 12;
		break;
	case(9):
		for (i = 140 * 12;i < 148 * 12;i++) {
			if (strcmp(cuenca[i].embalse_nombre, cuenca[i - 1].embalse_nombre) != 0) {
				nume++;
				printf("%i-", nume);
				printf("%s\n", cuenca[i].embalse_nombre);
			}
		}
		printf("Elige un numero de embalse de la Cuenca de Guadalete-Barbete: ");
		scanf("%i", num_embalse);
		*l_r_embalse = 140 * 12 + *num_embalse * 12;
		break;
	case(10):
		for (i = 148 * 12;i < 194 * 12;i++) {
			if (strcmp(cuenca[i].embalse_nombre, cuenca[i - 1].embalse_nombre) != 0) {
				nume++;
				printf("%i-", nume);
				printf("%s\n", cuenca[i].embalse_nombre);
			}
		}
		printf("Elige un numero de embalse de la Cuenca del Guadalquivir: ");
		scanf("%i", num_embalse);
		*l_r_embalse = 148 * 12 + *num_embalse * 12;
		break;
	case(11):
		for (i = 194 * 12;i < 228 * 12;i++) {
			if (strcmp(cuenca[i].embalse_nombre, cuenca[i - 1].embalse_nombre) != 0) {
				nume++;
				printf("%i-", nume);
				printf("%s\n", cuenca[i].embalse_nombre);
			}
		}
		printf("Elige un numero de embalse de la Cuenca del Guadiana: ");
		scanf("%i", num_embalse);
		*l_r_embalse = 194 * 12 + *num_embalse * 12;
		break;
	case(12):
		for (i = 228 * 12;i < 251 * 12;i++) {
			if (strcmp(cuenca[i].embalse_nombre, cuenca[i - 1].embalse_nombre) != 0) {
				nume++;
				printf("%i-", nume);
				printf("%s\n", cuenca[i].embalse_nombre);
			}
		}
		printf("Elige un numero de embalse de la Cuenca de Jucar: ");
		scanf("%i", num_embalse);
		*l_r_embalse = 228 * 12 + *num_embalse * 12;
		break;
	case(13):
		for (i = 251 * 12;i < 280 * 12;i++) {
			if (strcmp(cuenca[i].embalse_nombre, cuenca[i - 1].embalse_nombre) != 0) {
				nume++;
				printf("%i-", nume);
				printf("%s\n", cuenca[i].embalse_nombre);
			}
		}
		printf("Elige un numero de embalse de la Cuenca de Mino-Sil: ");
		scanf("%i", num_embalse);
		*l_r_embalse = 251 * 12 + *num_embalse * 12;
		break;
	case(14):
		for (i = 280 * 12;i < 295 * 12;i++) {
			if (strcmp(cuenca[i].embalse_nombre, cuenca[i - 1].embalse_nombre) != 0) {
				nume++;
				printf("%i-", nume);
				printf("%s\n", cuenca[i].embalse_nombre);
			}
		}
		printf("Elige un numero de embalse de la Cuenca de Segura: ");
		scanf("%i", num_embalse);
		*l_r_embalse = 280 * 12 + *num_embalse * 12;
		break;
	case(15):
		for (i = 295 * 12;i < 346 * 12;i++) {
			if (strcmp(cuenca[i].embalse_nombre, cuenca[i - 1].embalse_nombre) != 0) {
				nume++;
				printf("%i-", nume);
				printf("%s\n", cuenca[i].embalse_nombre);
			}
		}
		printf("Elige un numero de embalse de la Cuenca del Tajo: ");
		scanf("%i", num_embalse);
		*l_r_embalse = 295 * 12 + *num_embalse * 12;
		break;
	case(16):
		for (i = 346 * 12;i < 353 * 12;i++) {
			if (strcmp(cuenca[i].embalse_nombre, cuenca[i - 1].embalse_nombre) != 0) {
				nume++;
				printf("%i-", nume);
				printf("%s\n", cuenca[i].embalse_nombre);
			}
		}
		printf("Elige un numero de embalse de la Cuenca de Tinto,Odiel y Piedras: ");
		scanf("%i", num_embalse);
		*l_r_embalse = 346 * 12 + *num_embalse * 12;
		break;
	}
	printf("\nAhora elegiremos el embalse a comparar. \n");
}


//SELECCION CUENCA 2
int seleccion_cuenca_2(int num_cuenca2, char C_cuenca2[]) {

	do {

		printf("\nIntroduce el numero de la cuenca: ");
		scanf("%s", C_cuenca2);

		if (('9' < C_cuenca2[0] && C_cuenca2[0] < '0') && ('9' < C_cuenca2[1] && C_cuenca2[1] < '0')) {
			printf("\nCaracter no valido, repite:\n");
		}
		else {
			if (C_cuenca2[0] == '0') {
				printf("\nbNumero no valido, repite:\n");
			}

			else {
				sscanf(C_cuenca2, "%i", &num_cuenca2);
				if ((0 >= num_cuenca2) || (num_cuenca2 > 16)) {
					printf("\ncNumero no valido, repite:\n");
				}
			}
		}
	}

	while ((0 >= num_cuenca2) || (num_cuenca2 > 16) || (('9' < C_cuenca2[0] && C_cuenca2[0] < '0') && ('9' < C_cuenca2[1] && C_cuenca2[1] < '0')) || (C_cuenca2[0] == '0'));

	return num_cuenca2;

}


//SELECCION EMBALSE 2:
void nombreseleccion_embalse_2(int num_cuenca2, linea cuenca[], int* num_embalse2, int* l_r_embalse2) {
	int nume2 = 0, i;
	switch (num_cuenca2)
	{
	case(1):
		for (i = 0;i < 8 * 12;i++) {
			if (strcmp(cuenca[i].embalse_nombre, cuenca[i - 1].embalse_nombre) != 0) {
				nume2++;
				printf("%i-", nume2);
				printf("%s\n", cuenca[i].embalse_nombre);
			}
		}
		printf("Elige un numero de embalse del Cantabrico Occidental: ");
		scanf("%i", num_embalse2);
		*l_r_embalse2 = *num_embalse2 * 12;
		break;
	case(2):
		for (i = 8 * 12;i < 12 * 12;i++) {
			if (strcmp(cuenca[i].embalse_nombre, cuenca[i - 1].embalse_nombre) != 0) {
				nume2++;
				printf("%i-", nume2);
				printf("%s\n", cuenca[i].embalse_nombre);
			}
		}
		printf("Elige un numero de embalse del Cantabrico Oriental: ");
		scanf("%i", num_embalse2);
		*l_r_embalse2 = 8 * 12 + *num_embalse2 * 12;
		break;
	case(3):
		for (i = 12 * 12;i < 24 * 12;i++) {
			if (strcmp(cuenca[i].embalse_nombre, cuenca[i - 1].embalse_nombre) != 0) {
				nume2++;
				printf("%i-", nume2);
				printf("%s\n", cuenca[i].embalse_nombre);
			}
		}
		printf("Elige un numero de embalse de la Cuenca Mediterranea Andaluza: ");
		scanf("%i", num_embalse2);
		*l_r_embalse2 = 12 * 12 + *num_embalse2 * 12;
		break;
	case(4):
		for (i = 24 * 12;i < 31 * 12;i++) {
			if (strcmp(cuenca[i].embalse_nombre, cuenca[i - 1].embalse_nombre) != 0) {
				nume2++;
				printf("%i-", nume2);
				printf("%s\n", cuenca[i].embalse_nombre);
			}
		}
		printf("Elige un numero de embalse de la Cuencas Internas de Cataluna: ");
		scanf("%i", num_embalse2);
		*l_r_embalse2 = 24 * 12 + *num_embalse2 * 12;
		break;
	case(5):
		for (i = 31 * 12;i < 33 * 12;i++) {
			if (strcmp(cuenca[i].embalse_nombre, cuenca[i - 1].embalse_nombre) != 0) {
				nume2++;
				printf("%i-", nume2);
				printf("%s\n", cuenca[i].embalse_nombre);
			}
		}
		printf("Elige un numero de embalse de la Cuencas Internas del Pais Vasco: ");
		scanf("%i", num_embalse2);
		*l_r_embalse2 = 31 * 12 + *num_embalse2 * 12;
		break;
	case(6):
		for (i = 33 * 12;i < 67 * 12;i++) {
			if (strcmp(cuenca[i].embalse_nombre, cuenca[i - 1].embalse_nombre) != 0) {
				nume2++;
				printf("%i-", nume2);
				printf("%s\n", cuenca[i].embalse_nombre);
			}
		}
		printf("Elige un numero de embalse de la Cuenca del Duero: ");
		scanf("%i", num_embalse2);
		*l_r_embalse2 = 33 * 12 + *num_embalse2 * 12;
		break;
	case(7):
		for (i = 67 * 12;i < 129 * 12;i++) {
			if (strcmp(cuenca[i].embalse_nombre, cuenca[i - 1].embalse_nombre) != 0) {
				nume2++;
				printf("%i-", nume2);
				printf("%s\n", cuenca[i].embalse_nombre);
			}
		}
		printf("Elige un numero de embalse de la Cuenca del Ebro: ");
		scanf("%i", num_embalse2);
		*l_r_embalse2 = 67 * 12 + *num_embalse2 * 12;
		break;
	case(8):
		for (i = 129 * 12;i < 140 * 12;i++) {
			if (strcmp(cuenca[i].embalse_nombre, cuenca[i - 1].embalse_nombre) != 0) {
				nume2++;
				printf("%i-", nume2);
				printf("%s\n", cuenca[i].embalse_nombre);
			}
		}
		printf("Elige un numero de embalse de la Cuenca de Costa de Galicia: ");
		scanf("%i", num_embalse2);
		*l_r_embalse2 = 129 * 12 + *num_embalse2 * 12;
		break;
	case(9):
		for (i = 140 * 12;i < 148 * 12;i++) {
			if (strcmp(cuenca[i].embalse_nombre, cuenca[i - 1].embalse_nombre) != 0) {
				nume2++;
				printf("%i-", nume2);
				printf("%s\n", cuenca[i].embalse_nombre);
			}
		}
		printf("Elige un numero de embalse de la Cuenca de Guadalete-Barbete: ");
		scanf("%i", num_embalse2);
		*l_r_embalse2 = 140 * 12 + *num_embalse2 * 12;
		break;
	case(10):
		for (i = 148 * 12;i < 194 * 12;i++) {
			if (strcmp(cuenca[i].embalse_nombre, cuenca[i - 1].embalse_nombre) != 0) {
				nume2++;
				printf("%i-", nume2);
				printf("%s\n", cuenca[i].embalse_nombre);
			}
		}
		printf("Elige un numero de embalse de la Cuenca del Guadalquivir: ");
		scanf("%i", num_embalse2);
		*l_r_embalse2 = 148 * 12 + *num_embalse2 * 12;
		break;
	case(11):
		for (i = 194 * 12;i < 228 * 12;i++) {
			if (strcmp(cuenca[i].embalse_nombre, cuenca[i - 1].embalse_nombre) != 0) {
				nume2++;
				printf("%i-", nume2);
				printf("%s\n", cuenca[i].embalse_nombre);
			}
		}
		printf("Elige un numero de embalse de la Cuenca del Guadiana: ");
		scanf("%i", num_embalse2);
		*l_r_embalse2 = 194 * 12 + *num_embalse2 * 12;
		break;
	case(12):
		for (i = 228 * 12;i < 251 * 12;i++) {
			if (strcmp(cuenca[i].embalse_nombre, cuenca[i - 1].embalse_nombre) != 0) {
				nume2++;
				printf("%i-", nume2);
				printf("%s\n", cuenca[i].embalse_nombre);
			}
		}
		printf("Elige un numero de embalse de la Cuenca de Jucar: ");
		scanf("%i", num_embalse2);
		*l_r_embalse2 = 228 * 12 + *num_embalse2 * 12;
		break;
	case(13):
		for (i = 251 * 12;i < 280 * 12;i++) {
			if (strcmp(cuenca[i].embalse_nombre, cuenca[i - 1].embalse_nombre) != 0) {
				nume2++;
				printf("%i-", nume2);
				printf("%s\n", cuenca[i].embalse_nombre);
			}
		}
		printf("Elige un numero de embalse de la Cuenca de Mino-Sil: ");
		scanf("%i", num_embalse2);
		*l_r_embalse2 = 251 * 12 + *num_embalse2 * 12;
		break;
	case(14):
		for (i = 280 * 12;i < 295 * 12;i++) {
			if (strcmp(cuenca[i].embalse_nombre, cuenca[i - 1].embalse_nombre) != 0) {
				nume2++;
				printf("%i-", nume2);
				printf("%s\n", cuenca[i].embalse_nombre);
			}
		}
		printf("Elige un numero de embalse de la Cuenca de Segura: ");
		scanf("%i", num_embalse2);
		*l_r_embalse2 = 280 * 12 + *num_embalse2 * 12;
		break;
	case(15):
		for (i = 295 * 12;i < 346 * 12;i++) {
			if (strcmp(cuenca[i].embalse_nombre, cuenca[i - 1].embalse_nombre) != 0) {
				nume2++;
				printf("%i-", nume2);
				printf("%s\n", cuenca[i].embalse_nombre);
			}
		}
		printf("Elige un numero de embalse de la Cuenca del Tajo: ");
		scanf("%i", num_embalse2);
		*l_r_embalse2 = 295 * 12 + *num_embalse2 * 12;
		break;
	case(16):
		for (i = 346 * 12;i < 353 * 12;i++) {
			if (strcmp(cuenca[i].embalse_nombre, cuenca[i - 1].embalse_nombre) != 0) {
				nume2++;
				printf("%i-", nume2);
				printf("%s\n", cuenca[i].embalse_nombre);
			}
		}
		printf("Elige un numero de embalse de la Cuenca de Tinto,Odiel y Piedras: ");
		scanf("%i", num_embalse2);
		*l_r_embalse2 = 346 * 12 + *num_embalse2 * 12;
		break;
	}
}


//TIPO COMPARACION
int tipo_comparacion(int mes_anyo) {
	do {
		printf("\n¿Que informacion precisas?\n");
		printf("1.-Comparacion de embalses segun el anyo\n2.-Comparacion de embalses segun el mes.\n");
		scanf("%i", &mes_anyo);
		if (mes_anyo <= 0 || mes_anyo > 2) {
			printf("Numero invalido, vuelva a intentarlo.\n");
		}
	} while (mes_anyo <= 0 || mes_anyo > 2);
	return 0;
}


//SELECCION AÑO:
int seleccion_anyos(int anyo) {
	do {
		printf("\nIntroduce el anyo deseado 2012-2021.\n");
		scanf("%i", &anyo);
		if (anyo < 2012 || anyo>2021) {
			("Anyo invalido, intentalo otra vez.\n");
		}
	} while (anyo < 2012 || anyo>2021);
	return 0;
}


//SELECCION MES:
int seleccion_mese(int mes) {
	do {
		printf("\nIntroduce el mes deseado 1-12.\n");
		scanf("%i", &mes);
		if (mes < 1 || mes>12) {
			("Anyo invalido, intentalo otra vez.\n");
		}
	} while (mes < 1 || mes>12);
	return 0;
}


//COMPARACION SEGUN AÑO:
void comparacion_anyo(int mes_anyo, int anyo, int l_r_embalse, int l_r_embalse2, linea cuenca[]) {
	float min = FLT_MAX;
	float max = FLT_MIN;
	float min2 = FLT_MAX;
	float max2 = FLT_MIN;
	float res;



	switch (anyo) {
	case(2012):
		for (int j = l_r_embalse - 12; j < l_r_embalse - 1; j++) {
			if (cuenca[j].dosmildoce < min) { min = cuenca[j].dosmildoce; }
			if (cuenca[j].dosmildoce > max) { max = cuenca[j].dosmildoce; }
		}
		for (int k = l_r_embalse2 - 12; k < l_r_embalse2 - 1; k++) {
			if (cuenca[k].dosmildoce < min2) { min2 = cuenca[k].dosmildoce; }
			if (cuenca[k].dosmildoce > max2) { max2 = cuenca[k].dosmildoce; }
		}
		printf("\nLa capacidad del primer embalse %s en %i va de %.2f-%.2f\n", cuenca[l_r_embalse - 1].embalse_nombre, anyo, min, max);
		printf("La capacidad del segundo embalse %s en %i va de %.2f-%.2f\n", cuenca[l_r_embalse2 - 1].embalse_nombre, anyo, min2, max2);
		if (max2 > max) { printf("%s sobrepaso en %.2f hm^3 a %s en su capacidad mas alta.\n", cuenca[l_r_embalse2 - 1].embalse_nombre, res = max2 - max, cuenca[l_r_embalse - 1].embalse_nombre); }
		if (max > max2) { printf("%s sobrepaso en %.2f hm^3 a %s en su capacidad mas alta.\n", cuenca[l_r_embalse - 1].embalse_nombre, res = max - max2, cuenca[l_r_embalse2 - 1].embalse_nombre); }
		if (max == max2) { printf("%s y %s coincidieron en su capacidad mas alta.\n", cuenca[l_r_embalse - 1].embalse_nombre, cuenca[l_r_embalse2 - 1].embalse_nombre); }
		break;
	case(2013):
		for (int j = l_r_embalse - 12; j < l_r_embalse - 1; j++) {
			if (cuenca[j].dosmiltrece < min) { min = cuenca[j].dosmiltrece; }
			if (cuenca[j].dosmiltrece > max) { max = cuenca[j].dosmiltrece; }
		}
		for (int k = l_r_embalse2 - 12; k < l_r_embalse2 - 1; k++) {
			if (cuenca[k].dosmiltrece < min2) { min2 = cuenca[k].dosmiltrece; }
			if (cuenca[k].dosmiltrece > max2) { max2 = cuenca[k].dosmiltrece; }
		}
		printf("\nLa capacidad del primer embalse %s en %i va de %.2f-%.2f\n", cuenca[l_r_embalse - 1].embalse_nombre, anyo, min, max);
		printf("La capacidad del segundo embalse %s en %i va de %.2f-%.2f\n", cuenca[l_r_embalse2 - 1].embalse_nombre, anyo, min2, max2);
		if (max2 > max) { printf("%s sobrepaso en %.2f hm^3 a %s en su capacidad mas alta.\n", cuenca[l_r_embalse2 - 1].embalse_nombre, res = max2 - max, cuenca[l_r_embalse - 1].embalse_nombre); }
		if (max > max2) { printf("%s sobrepaso en %.2f hm^3 a %s en su capacidad mas alta.\n", cuenca[l_r_embalse - 1].embalse_nombre, res = max - max2, cuenca[l_r_embalse2 - 1].embalse_nombre); }
		if (max == max2) { printf("%s y %s coincidieron en su capacidad mas alta.\n", cuenca[l_r_embalse - 1].embalse_nombre, cuenca[l_r_embalse2 - 1].embalse_nombre); }
		break;
	case(2014):
		for (int j = l_r_embalse - 12; j < l_r_embalse - 1; j++) {
			if (cuenca[j].dosmilcatorce < min) { min = cuenca[j].dosmilcatorce; }
			if (cuenca[j].dosmilcatorce > max) { max = cuenca[j].dosmilcatorce; }
		}
		for (int k = l_r_embalse2 - 12; k < l_r_embalse2 - 1; k++) {
			if (cuenca[k].dosmilcatorce < min2) { min2 = cuenca[k].dosmilcatorce; }
			if (cuenca[k].dosmilcatorce > max2) { max2 = cuenca[k].dosmilcatorce; }
		}
		printf("\nLa capacidad del primer embalse %s en %i va de %.2f-%.2f\n", cuenca[l_r_embalse - 1].embalse_nombre, anyo, min, max);
		printf("La capacidad del segundo embalse %s en %i va de %.2f-%.2f\n", cuenca[l_r_embalse2 - 1].embalse_nombre, anyo, min2, max2);
		if (max2 > max) { printf("%s sobrepaso en %.2f hm^3 a %s en su capacidad mas alta.\n", cuenca[l_r_embalse2 - 1].embalse_nombre, res = max2 - max, cuenca[l_r_embalse - 1].embalse_nombre); }
		if (max > max2) { printf("%s sobrepaso en %.2f hm^3 a %s en su capacidad mas alta.\n", cuenca[l_r_embalse - 1].embalse_nombre, res = max - max2, cuenca[l_r_embalse2 - 1].embalse_nombre); }
		if (max == max2) { printf("%s y %s coincidieron en su capacidad mas alta.\n", cuenca[l_r_embalse - 1].embalse_nombre, cuenca[l_r_embalse2 - 1].embalse_nombre); }
		break;
	case(2015):
		for (int j = l_r_embalse - 12; j < l_r_embalse - 1; j++) {
			if (cuenca[j].dosmilquince < min) { min = cuenca[j].dosmilquince; }
			if (cuenca[j].dosmilquince > max) { max = cuenca[j].dosmilquince; }
		}
		for (int k = l_r_embalse2 - 12; k < l_r_embalse2 - 1; k++) {
			if (cuenca[k].dosmilquince < min2) { min2 = cuenca[k].dosmilquince; }
			if (cuenca[k].dosmilquince > max2) { max2 = cuenca[k].dosmilquince; }
		}
		printf("\nLa capacidad del primer embalse %s en %i va de %.2f-%.2f\n", cuenca[l_r_embalse - 1].embalse_nombre, anyo, min, max);
		printf("La capacidad del segundo embalse %s en %i va de %.2f-%.2f\n", cuenca[l_r_embalse2 - 1].embalse_nombre, anyo, min2, max2);
		if (max2 > max) { printf("%s sobrepaso en %.2f hm^3 a %s en su capacidad mas alta.\n", cuenca[l_r_embalse2 - 1].embalse_nombre, res = max2 - max, cuenca[l_r_embalse - 1].embalse_nombre); }
		if (max > max2) { printf("%s sobrepaso en %.2f hm^3 a %s en su capacidad mas alta.\n", cuenca[l_r_embalse - 1].embalse_nombre, res = max - max2, cuenca[l_r_embalse2 - 1].embalse_nombre); }
		if (max == max2) { printf("%s y %s coincidieron en su capacidad mas alta.\n", cuenca[l_r_embalse - 1].embalse_nombre, cuenca[l_r_embalse2 - 1].embalse_nombre); }
		break;
	case(2016):
		for (int j = l_r_embalse - 12; j < l_r_embalse - 1; j++) {
			if (cuenca[j].dosmildieciseis < min) { min = cuenca[j].dosmildieciseis; }
			if (cuenca[j].dosmildieciseis > max) { max = cuenca[j].dosmildieciseis; }
		}
		for (int k = l_r_embalse2 - 12; k < l_r_embalse2 - 1; k++) {
			if (cuenca[k].dosmildieciseis < min2) { min2 = cuenca[k].dosmildieciseis; }
			if (cuenca[k].dosmildieciseis > max2) { max2 = cuenca[k].dosmildieciseis; }
		}
		printf("\nLa capacidad del primer embalse %s en %i va de %.2f-%.2f\n", cuenca[l_r_embalse - 1].embalse_nombre, anyo, min, max);
		printf("La capacidad del segundo embalse %s en %i va de %.2f-%.2f\n", cuenca[l_r_embalse2 - 1].embalse_nombre, anyo, min2, max2);
		if (max2 > max) { printf("%s sobrepaso en %.2f hm^3 a %s en su capacidad mas alta.\n", cuenca[l_r_embalse2 - 1].embalse_nombre, res = max2 - max, cuenca[l_r_embalse - 1].embalse_nombre); }
		if (max > max2) { printf("%s sobrepaso en %.2f hm^3 a %s en su capacidad mas alta.\n", cuenca[l_r_embalse - 1].embalse_nombre, res = max - max2, cuenca[l_r_embalse2 - 1].embalse_nombre); }
		if (max == max2) { printf("%s y %s coincidieron en su capacidad mas alta.\n", cuenca[l_r_embalse - 1].embalse_nombre, cuenca[l_r_embalse2 - 1].embalse_nombre); }
		break;
	case(2017):
		for (int j = l_r_embalse - 12; j < l_r_embalse - 1; j++) {
			if (cuenca[j].dosmildiecisiete < min) { min = cuenca[j].dosmildiecisiete; }
			if (cuenca[j].dosmildiecisiete > max) { max = cuenca[j].dosmildiecisiete; }
		}
		for (int k = l_r_embalse2 - 12; k < l_r_embalse2 - 1; k++) {
			if (cuenca[k].dosmildiecisiete < min2) { min2 = cuenca[k].dosmildiecisiete; }
			if (cuenca[k].dosmildiecisiete > max2) { max2 = cuenca[k].dosmildiecisiete; }
		}
		printf("\nLa capacidad del primer embalse %s en %i va de %.2f-%.2f\n", cuenca[l_r_embalse - 1].embalse_nombre, anyo, min, max);
		printf("La capacidad del segundo embalse %s en %i va de %.2f-%.2f\n", cuenca[l_r_embalse2 - 1].embalse_nombre, anyo, min2, max2);
		if (max2 > max) { printf("%s sobrepaso en %.2f hm^3 a %s en su capacidad mas alta.\n", cuenca[l_r_embalse2 - 1].embalse_nombre, res = max2 - max, cuenca[l_r_embalse - 1].embalse_nombre); }
		if (max > max2) { printf("%s sobrepaso en %.2f hm^3 a %s en su capacidad mas alta.\n", cuenca[l_r_embalse - 1].embalse_nombre, res = max - max2, cuenca[l_r_embalse2 - 1].embalse_nombre); }
		if (max == max2) { printf("%s y %s coincidieron en su capacidad mas alta.\n", cuenca[l_r_embalse - 1].embalse_nombre, cuenca[l_r_embalse2 - 1].embalse_nombre); }
		break;
	case(2018):
		for (int j = l_r_embalse - 12; j < l_r_embalse - 1; j++) {
			if (cuenca[j].dosmildieciocho < min) { min = cuenca[j].dosmildieciocho; }
			if (cuenca[j].dosmildieciocho > max) { max = cuenca[j].dosmildieciocho; }
		}
		for (int k = l_r_embalse2 - 12; k < l_r_embalse2 - 1; k++) {
			if (cuenca[k].dosmildieciocho < min2) { min2 = cuenca[k].dosmildieciocho; }
			if (cuenca[k].dosmildieciocho > max2) { max2 = cuenca[k].dosmildieciocho; }
		}
		printf("\nLa capacidad del primer embalse %s en %i va de %.2f-%.2f\n", cuenca[l_r_embalse - 1].embalse_nombre, anyo, min, max);
		printf("La capacidad del segundo embalse %s en %i va de %.2f-%.2f\n", cuenca[l_r_embalse2 - 1].embalse_nombre, anyo, min2, max2);
		if (max2 > max) { printf("%s sobrepaso en %.2f hm^3 a %s en su capacidad mas alta.\n", cuenca[l_r_embalse2 - 1].embalse_nombre, res = max2 - max, cuenca[l_r_embalse - 1].embalse_nombre); }
		if (max > max2) { printf("%s sobrepaso en %.2f hm^3 a %s en su capacidad mas alta.\n", cuenca[l_r_embalse - 1].embalse_nombre, res = max - max2, cuenca[l_r_embalse2 - 1].embalse_nombre); }
		if (max == max2) { printf("%s y %s coincidieron en su capacidad mas alta.\n", cuenca[l_r_embalse - 1].embalse_nombre, cuenca[l_r_embalse2 - 1].embalse_nombre); }
		break;
	case(2019):
		for (int j = l_r_embalse - 12; j < l_r_embalse - 1; j++) {
			if (cuenca[j].dosmildiecinueve < min) { min = cuenca[j].dosmildiecinueve; }
			if (cuenca[j].dosmildiecinueve > max) { max = cuenca[j].dosmildiecinueve; }
		}
		for (int k = l_r_embalse2 - 12; k < l_r_embalse2 - 1; k++) {
			if (cuenca[k].dosmildiecinueve < min2) { min2 = cuenca[k].dosmildiecinueve; }
			if (cuenca[k].dosmildiecinueve > max2) { max2 = cuenca[k].dosmildiecinueve; }
		}
		printf("\nLa capacidad del primer embalse %s en %i va de %.2f-%.2f\n", cuenca[l_r_embalse - 1].embalse_nombre, anyo, min, max);
		printf("La capacidad del segundo embalse %s en %i va de %.2f-%.2f\n", cuenca[l_r_embalse2 - 1].embalse_nombre, anyo, min2, max2);
		if (max2 > max) { printf("%s sobrepaso en %.2f hm^3 a %s en su capacidad mas alta.\n", cuenca[l_r_embalse2 - 1].embalse_nombre, res = max2 - max, cuenca[l_r_embalse - 1].embalse_nombre); }
		if (max > max2) { printf("%s sobrepaso en %.2f hm^3 a %s en su capacidad mas alta.\n", cuenca[l_r_embalse - 1].embalse_nombre, res = max - max2, cuenca[l_r_embalse2 - 1].embalse_nombre); }
		if (max == max2) { printf("%s y %s coincidieron en su capacidad mas alta.\n", cuenca[l_r_embalse - 1].embalse_nombre, cuenca[l_r_embalse2 - 1].embalse_nombre); }
		break;
	case(2020):
		for (int j = l_r_embalse - 12; j < l_r_embalse - 1; j++) {
			if (cuenca[j].dosmilveinte < min) { min = cuenca[j].dosmilveinte; }
			if (cuenca[j].dosmilveinte > max) { max = cuenca[j].dosmilveinte; }
		}
		for (int k = l_r_embalse2 - 12; k < l_r_embalse2 - 1; k++) {
			if (cuenca[k].dosmilveinte < min2) { min2 = cuenca[k].dosmilveinte; }
			if (cuenca[k].dosmilveinte > max2) { max2 = cuenca[k].dosmilveinte; }
		}
		printf("\nLa capacidad del primer embalse %s en %i va de %.2f-%.2f\n", cuenca[l_r_embalse - 1].embalse_nombre, anyo, min, max);
		printf("La capacidad del segundo embalse %s en %i va de %.2f-%.2f\n", cuenca[l_r_embalse2 - 1].embalse_nombre, anyo, min2, max2);
		if (max2 > max) { printf("%s sobrepaso en %.2f hm^3 a %s en su capacidad mas alta.\n", cuenca[l_r_embalse2 - 1].embalse_nombre, res = max2 - max, cuenca[l_r_embalse - 1].embalse_nombre); }
		if (max > max2) { printf("%s sobrepaso en %.2f hm^3 a %s en su capacidad mas alta.\n", cuenca[l_r_embalse - 1].embalse_nombre, res = max - max2, cuenca[l_r_embalse2 - 1].embalse_nombre); }
		if (max == max2) { printf("%s y %s coincidieron en su capacidad mas alta.\n", cuenca[l_r_embalse - 1].embalse_nombre, cuenca[l_r_embalse2 - 1].embalse_nombre); }
		break;
	case(2021):
		for (int j = l_r_embalse - 12; j < l_r_embalse - 1; j++) {
			if (cuenca[j].dosmilveintiuno < min) { min = cuenca[j].dosmilveintiuno; }
			if (cuenca[j].dosmilveintiuno > max) { max = cuenca[j].dosmilveintiuno; }
		}
		for (int k = l_r_embalse2 - 12; k < l_r_embalse2 - 1; k++) {
			if (cuenca[k].dosmilveintiuno < min2) { min2 = cuenca[k].dosmilveintiuno; }
			if (cuenca[k].dosmilveintiuno > max2) { max2 = cuenca[k].dosmilveintiuno; }
		}
		printf("\nLa capacidad del primer embalse %s en %i va de %.2f-%.2f\n", cuenca[l_r_embalse - 1].embalse_nombre, anyo, min, max);
		printf("La capacidad del segundo embalse %s en %i va de %.2f-%.2f\n", cuenca[l_r_embalse2 - 1].embalse_nombre, anyo, min2, max2);
		if (max2 > max) { printf("%s sobrepaso en %.2f hm^3 a %s en su capacidad mas alta.\n", cuenca[l_r_embalse2 - 1].embalse_nombre, res = max2 - max, cuenca[l_r_embalse - 1].embalse_nombre); }
		if (max > max2) { printf("%s sobrepaso en %.2f hm^3 a %s en su capacidad mas alta.\n", cuenca[l_r_embalse - 1].embalse_nombre, res = max - max2, cuenca[l_r_embalse2 - 1].embalse_nombre); }
		if (max == max2) { printf("%s y %s coincidieron en su capacidad mas alta.\n", cuenca[l_r_embalse - 1].embalse_nombre, cuenca[l_r_embalse2 - 1].embalse_nombre); }
		break;
	}
}


//COMPARACION SEGUN MES
void comparacion_mes(int mes_anyo, int anyo, int mes, int l_r_embalse, int l_r_embalse2, linea cuenca[]) {
	float res_mes, max_mes, min_mes;


	switch (anyo) {
	case(2012):
		printf("La capacidad del primer embalse %s en el %i mes del %i es %.2f.\n", cuenca[l_r_embalse - 1].embalse_nombre, mes, anyo, cuenca[l_r_embalse - 13 + mes].dosmildoce);
		printf("La capacidad del segundo embalse %s en el %i mes del %i es %.2f.\n", cuenca[l_r_embalse2 - 1].embalse_nombre, mes, anyo, cuenca[l_r_embalse2 - 13 + mes].dosmildoce);
		if (cuenca[l_r_embalse2 - 13 + mes].dosmildoce > cuenca[l_r_embalse - 13 + mes].dosmildoce) {
			max_mes = cuenca[l_r_embalse2 - 13 + mes].dosmildoce;
			min_mes = cuenca[l_r_embalse - 13 + mes].dosmildoce;
			printf("%s sobrepaso en %.2f hm^3 a %s en el %i mes.\n", cuenca[l_r_embalse2 - 1].embalse_nombre, res_mes = max_mes - min_mes, cuenca[l_r_embalse - 1].embalse_nombre, mes);
		}
		if (cuenca[l_r_embalse - 13 + mes].dosmildoce > cuenca[l_r_embalse2 - 13 + mes].dosmildoce) {
			max_mes = cuenca[l_r_embalse - 13 + mes].dosmildoce;
			min_mes = cuenca[l_r_embalse2 - 13 + mes].dosmildoce;
			printf("%s sobrepaso en %.2f hm^3 a %s en el %i mes.\n", cuenca[l_r_embalse - 1].embalse_nombre, res_mes = max_mes - min_mes, cuenca[l_r_embalse2 - 1].embalse_nombre, mes);
		}
		if (cuenca[l_r_embalse2 - 13 + mes].dosmildoce == cuenca[l_r_embalse - 13 + mes].dosmildoce) {
			printf("%s y %s tinen la misma capacidad en el %i mes.\n", cuenca[l_r_embalse2 - 1].embalse_nombre, cuenca[l_r_embalse - 1].embalse_nombre, mes);
		}
		break;
	case(2013):
		printf("La capacidad del primer embalse %s en el %i mes del %i es %.2f.\n", cuenca[l_r_embalse - 1].embalse_nombre, mes, anyo, cuenca[l_r_embalse - 13 + mes].dosmiltrece);
		printf("La capacidad del segundo embalse %s en el %i mes del %i es %.2f.\n", cuenca[l_r_embalse2 - 1].embalse_nombre, mes, anyo, cuenca[l_r_embalse2 - 13 + mes].dosmiltrece);
		if (cuenca[l_r_embalse2 - 13 + mes].dosmiltrece > cuenca[l_r_embalse - 13 + mes].dosmiltrece) {
			max_mes = cuenca[l_r_embalse2 - 13 + mes].dosmiltrece;
			min_mes = cuenca[l_r_embalse - 13 + mes].dosmiltrece;
			printf("%s sobrepaso en %.2f hm^3 a %s en el %i mes.\n", cuenca[l_r_embalse2 - 1].embalse_nombre, res_mes = max_mes - min_mes, cuenca[l_r_embalse - 1].embalse_nombre, mes);
		}
		if (cuenca[l_r_embalse - 13 + mes].dosmiltrece > cuenca[l_r_embalse2 - 13 + mes].dosmiltrece) {
			max_mes = cuenca[l_r_embalse - 13 + mes].dosmiltrece;
			min_mes = cuenca[l_r_embalse2 - 13 + mes].dosmiltrece;
			printf("%s sobrepaso en %.2f hm^3 a %s en el %i mes.\n", cuenca[l_r_embalse - 1].embalse_nombre, res_mes = max_mes - min_mes, cuenca[l_r_embalse2 - 1].embalse_nombre, mes);
		}
		if (cuenca[l_r_embalse2 - 13 + mes].dosmiltrece == cuenca[l_r_embalse - 13 + mes].dosmiltrece) {
			printf("%s y %s tinen la misma capacidad en el %i mes.\n", cuenca[l_r_embalse2 - 1].embalse_nombre, cuenca[l_r_embalse - 1].embalse_nombre, mes);
		}
		break;
	case(2014):
		printf("La capacidad del primer embalse %s en el %i mes del %i es %.2f.\n", cuenca[l_r_embalse - 1].embalse_nombre, mes, anyo, cuenca[l_r_embalse - 13 + mes].dosmilcatorce);
		printf("La capacidad del segundo embalse %s en el %i mes del %i es %.2f.\n", cuenca[l_r_embalse2 - 1].embalse_nombre, mes, anyo, cuenca[l_r_embalse2 - 13 + mes].dosmilcatorce);
		if (cuenca[l_r_embalse2 - 13 + mes].dosmilcatorce > cuenca[l_r_embalse - 13 + mes].dosmilcatorce) {
			max_mes = cuenca[l_r_embalse2 - 13 + mes].dosmilcatorce;
			min_mes = cuenca[l_r_embalse - 13 + mes].dosmilcatorce;
			printf("%s sobrepaso en %.2f hm^3 a %s en el %i mes.\n", cuenca[l_r_embalse2 - 1].embalse_nombre, res_mes = max_mes - min_mes, cuenca[l_r_embalse - 1].embalse_nombre, mes);
		}
		if (cuenca[l_r_embalse - 13 + mes].dosmilcatorce > cuenca[l_r_embalse2 - 13 + mes].dosmilcatorce) {
			max_mes = cuenca[l_r_embalse - 13 + mes].dosmilcatorce;
			min_mes = cuenca[l_r_embalse2 - 13 + mes].dosmilcatorce;
			printf("%s sobrepaso en %.2f hm^3 a %s en el %i mes.\n", cuenca[l_r_embalse - 1].embalse_nombre, res_mes = max_mes - min_mes, cuenca[l_r_embalse2 - 1].embalse_nombre, mes);
		}
		if (cuenca[l_r_embalse2 - 13 + mes].dosmilcatorce == cuenca[l_r_embalse - 13 + mes].dosmilcatorce) {
			printf("%s y %s tinen la misma capacidad en el %i mes.\n", cuenca[l_r_embalse2 - 1].embalse_nombre, cuenca[l_r_embalse - 1].embalse_nombre, mes);
		}
		break;
	case(2015):
		printf("La capacidad del primer embalse %s en el %i mes del %i es %.2f.\n", cuenca[l_r_embalse - 1].embalse_nombre, mes, anyo, cuenca[l_r_embalse - 13 + mes].dosmilquince);
		printf("La capacidad del segundo embalse %s en el %i mes del %i es %.2f.\n", cuenca[l_r_embalse2 - 1].embalse_nombre, mes, anyo, cuenca[l_r_embalse2 - 13 + mes].dosmilquince);
		if (cuenca[l_r_embalse2 - 13 + mes].dosmilquince > cuenca[l_r_embalse - 13 + mes].dosmilquince) {
			max_mes = cuenca[l_r_embalse2 - 13 + mes].dosmilquince;
			min_mes = cuenca[l_r_embalse - 13 + mes].dosmilquince;
			printf("%s sobrepaso en %.2f hm^3 a %s en el %i mes.\n", cuenca[l_r_embalse2 - 1].embalse_nombre, res_mes = max_mes - min_mes, cuenca[l_r_embalse - 1].embalse_nombre, mes);
		}
		if (cuenca[l_r_embalse - 13 + mes].dosmilquince > cuenca[l_r_embalse2 - 13 + mes].dosmilquince) {
			max_mes = cuenca[l_r_embalse - 13 + mes].dosmilquince;
			min_mes = cuenca[l_r_embalse2 - 13 + mes].dosmilquince;
			printf("%s sobrepaso en %.2f hm^3 a %s en el %i mes.\n", cuenca[l_r_embalse - 1].embalse_nombre, res_mes = max_mes - min_mes, cuenca[l_r_embalse2 - 1].embalse_nombre, mes);
		}
		if (cuenca[l_r_embalse2 - 13 + mes].dosmilquince == cuenca[l_r_embalse - 13 + mes].dosmilquince) {
			printf("%s y %s tinen la misma capacidad en el %i mes.\n", cuenca[l_r_embalse2 - 1].embalse_nombre, cuenca[l_r_embalse - 1].embalse_nombre, mes);
		}
		break;
	case(2016):
		printf("La capacidad del primer embalse %s en el %i mes del %i es %.2f.\n", cuenca[l_r_embalse - 1].embalse_nombre, mes, anyo, cuenca[l_r_embalse - 13 + mes].dosmildieciseis);
		printf("La capacidad del segundo embalse %s en el %i mes del %i es %.2f.\n", cuenca[l_r_embalse2 - 1].embalse_nombre, mes, anyo, cuenca[l_r_embalse2 - 13 + mes].dosmildieciseis);
		if (cuenca[l_r_embalse2 - 13 + mes].dosmildieciseis > cuenca[l_r_embalse - 13 + mes].dosmildieciseis) {
			max_mes = cuenca[l_r_embalse2 - 13 + mes].dosmildieciseis;
			min_mes = cuenca[l_r_embalse - 13 + mes].dosmildieciseis;
			printf("%s sobrepaso en %.2f hm^3 a %s en el %i mes.\n", cuenca[l_r_embalse2 - 1].embalse_nombre, res_mes = max_mes - min_mes, cuenca[l_r_embalse - 1].embalse_nombre, mes);
		}
		if (cuenca[l_r_embalse - 13 + mes].dosmildieciseis > cuenca[l_r_embalse2 - 13 + mes].dosmildieciseis) {
			max_mes = cuenca[l_r_embalse - 13 + mes].dosmildieciseis;
			min_mes = cuenca[l_r_embalse2 - 13 + mes].dosmildieciseis;
			printf("%s sobrepaso en %.2f hm^3 a %s en el %i mes..\n", cuenca[l_r_embalse - 1].embalse_nombre, res_mes = max_mes - min_mes, cuenca[l_r_embalse2 - 1].embalse_nombre, mes);
		}
		if (cuenca[l_r_embalse2 - 13 + mes].dosmildieciseis == cuenca[l_r_embalse - 13 + mes].dosmildieciseis) {
			printf("%s y %s tinen la misma capacidad en el %i mes.\n", cuenca[l_r_embalse2 - 1].embalse_nombre, cuenca[l_r_embalse - 1].embalse_nombre, mes);
		}
		break;
	case(2017):
		printf("La capacidad del primer embalse %s en el %i mes del %i es %.2f.\n", cuenca[l_r_embalse - 1].embalse_nombre, mes, anyo, cuenca[l_r_embalse - 13 + mes].dosmildiecisiete);
		printf("La capacidad del segundo embalse %s en el %i mes del %i es %.2f.\n", cuenca[l_r_embalse2 - 1].embalse_nombre, mes, anyo, cuenca[l_r_embalse2 - 13 + mes].dosmildiecisiete);
		if (cuenca[l_r_embalse2 - 13 + mes].dosmildiecisiete > cuenca[l_r_embalse - 13 + mes].dosmildiecisiete) {
			max_mes = cuenca[l_r_embalse2 - 13 + mes].dosmildiecisiete;
			min_mes = cuenca[l_r_embalse - 13 + mes].dosmildiecisiete;
			printf("%s sobrepaso en %.2f hm^3 a %s en el %i mes.\n", cuenca[l_r_embalse2 - 1].embalse_nombre, res_mes = max_mes - min_mes, cuenca[l_r_embalse - 1].embalse_nombre, mes);
		}
		if (cuenca[l_r_embalse - 13 + mes].dosmildiecisiete > cuenca[l_r_embalse2 - 13 + mes].dosmildiecisiete) {
			max_mes = cuenca[l_r_embalse - 13 + mes].dosmildiecisiete;
			min_mes = cuenca[l_r_embalse2 - 13 + mes].dosmildiecisiete;
			printf("%s sobrepaso en %.2f hm^3 a %s en el %i mes.\n", cuenca[l_r_embalse - 1].embalse_nombre, res_mes = max_mes - min_mes, cuenca[l_r_embalse2 - 1].embalse_nombre, mes);
		}
		if (cuenca[l_r_embalse2 - 13 + mes].dosmildiecisiete == cuenca[l_r_embalse - 13 + mes].dosmildiecisiete) {
			printf("%s y %s tinen la misma capacidad en el %i mes.\n", cuenca[l_r_embalse2 - 1].embalse_nombre, cuenca[l_r_embalse - 1].embalse_nombre, mes);
		}
		break;
	case(2018):
		printf("La capacidad del primer embalse %s en el %i mes del %i es %.2f.\n", cuenca[l_r_embalse - 1].embalse_nombre, mes, anyo, cuenca[l_r_embalse - 13 + mes].dosmildieciocho);
		printf("La capacidad del segundo embalse %s en el %i mes del %i es %.2f.\n", cuenca[l_r_embalse2 - 1].embalse_nombre, mes, anyo, cuenca[l_r_embalse2 - 13 + mes].dosmildieciocho);
		if (cuenca[l_r_embalse2 - 13 + mes].dosmildieciocho > cuenca[l_r_embalse - 13 + mes].dosmildieciocho) {
			max_mes = cuenca[l_r_embalse2 - 13 + mes].dosmildieciocho;
			min_mes = cuenca[l_r_embalse - 13 + mes].dosmildieciocho;
			printf("%s sobrepaso en %.2f hm^3 a %s en el %i mes.\n", cuenca[l_r_embalse2 - 1].embalse_nombre, res_mes = max_mes - min_mes, cuenca[l_r_embalse - 1].embalse_nombre, mes);
		}
		if (cuenca[l_r_embalse - 13 + mes].dosmildieciocho > cuenca[l_r_embalse2 - 13 + mes].dosmildieciocho) {
			max_mes = cuenca[l_r_embalse - 13 + mes].dosmildieciocho;
			min_mes = cuenca[l_r_embalse2 - 13 + mes].dosmildieciocho;
			printf("%s sobrepaso en %.2f hm^3 a %s en el %i mes.\n", cuenca[l_r_embalse - 1].embalse_nombre, res_mes = max_mes - min_mes, cuenca[l_r_embalse2 - 1].embalse_nombre, mes);
		}
		if (cuenca[l_r_embalse2 - 13 + mes].dosmildieciocho == cuenca[l_r_embalse - 13 + mes].dosmildieciocho) {
			printf("%s y %s tinen la misma capacidad en el %i mes.\n", cuenca[l_r_embalse2 - 1].embalse_nombre, cuenca[l_r_embalse - 1].embalse_nombre, mes);
		}
		break;
	case(2019):
		printf("La capacidad del primer embalse %s en el %i mes del %i es %.2f.\n", cuenca[l_r_embalse - 1].embalse_nombre, mes, anyo, cuenca[l_r_embalse - 13 + mes].dosmildiecinueve);
		printf("La capacidad del segundo embalse %s en el %i mes del %i es %.2f.\n", cuenca[l_r_embalse2 - 1].embalse_nombre, mes, anyo, cuenca[l_r_embalse2 - 13 + mes].dosmildiecinueve);
		if (cuenca[l_r_embalse2 - 13 + mes].dosmildiecinueve > cuenca[l_r_embalse - 13 + mes].dosmildiecinueve) {
			max_mes = cuenca[l_r_embalse2 - 13 + mes].dosmildiecinueve;
			min_mes = cuenca[l_r_embalse - 13 + mes].dosmildiecinueve;
			printf("%s sobrepaso en %.2f hm^3 a %s en el %i mes.\n", cuenca[l_r_embalse2 - 1].embalse_nombre, res_mes = max_mes - min_mes, cuenca[l_r_embalse - 1].embalse_nombre, mes);
		}
		if (cuenca[l_r_embalse - 13 + mes].dosmildiecinueve > cuenca[l_r_embalse2 - 13 + mes].dosmildiecinueve) {
			max_mes = cuenca[l_r_embalse - 13 + mes].dosmildiecinueve;
			min_mes = cuenca[l_r_embalse2 - 13 + mes].dosmildiecinueve;
			printf("%s sobrepaso en %.2f hm^3 a %s en el %i mes.\n", cuenca[l_r_embalse - 1].embalse_nombre, res_mes = max_mes - min_mes, cuenca[l_r_embalse2 - 1].embalse_nombre, mes);
		}
		if (cuenca[l_r_embalse2 - 13 + mes].dosmildiecinueve == cuenca[l_r_embalse - 13 + mes].dosmildiecinueve) {
			printf("%s y %s tinen la misma capacidad en el %i mes.\n", cuenca[l_r_embalse2 - 1].embalse_nombre, cuenca[l_r_embalse - 1].embalse_nombre, mes);
		}
		break;
	case(2020):
		printf("La capacidad del primer embalse %s en el %i mes del %i es %.2f.\n", cuenca[l_r_embalse - 1].embalse_nombre, mes, anyo, cuenca[l_r_embalse - 13 + mes].dosmilveinte);
		printf("La capacidad del segundo embalse %s en el %i mes del %i es %.2f.\n", cuenca[l_r_embalse2 - 1].embalse_nombre, mes, anyo, cuenca[l_r_embalse2 - 13 + mes].dosmilveinte);
		if (cuenca[l_r_embalse2 - 13 + mes].dosmilveinte > cuenca[l_r_embalse - 13 + mes].dosmilveinte) {
			max_mes = cuenca[l_r_embalse2 - 13 + mes].dosmilveinte;
			min_mes = cuenca[l_r_embalse - 13 + mes].dosmilveinte;
			printf("%s sobrepaso en %.2f hm^3 a %s en el %i mes.\n", cuenca[l_r_embalse2 - 1].embalse_nombre, res_mes = max_mes - min_mes, cuenca[l_r_embalse - 1].embalse_nombre, mes);
		}
		if (cuenca[l_r_embalse - 13 + mes].dosmilveinte > cuenca[l_r_embalse2 - 13 + mes].dosmilveinte) {
			max_mes = cuenca[l_r_embalse - 13 + mes].dosmilveinte;
			min_mes = cuenca[l_r_embalse2 - 13 + mes].dosmilveinte;
			printf("%s sobrepaso en %.2f hm^3 a %s en el %i mes.\n", cuenca[l_r_embalse - 1].embalse_nombre, res_mes = max_mes - min_mes, cuenca[l_r_embalse2 - 1].embalse_nombre, mes);
		}
		if (cuenca[l_r_embalse2 - 13 + mes].dosmilveinte == cuenca[l_r_embalse - 13 + mes].dosmilveinte) {
			printf("%s y %s tinen la misma capacidad en el %i mes.\n", cuenca[l_r_embalse2 - 1].embalse_nombre, cuenca[l_r_embalse - 1].embalse_nombre, mes);
		}
		break;
	case(2021):
		printf("La capacidad del primer embalse %s en el %i mes del %i es %.2f.\n", cuenca[l_r_embalse - 1].embalse_nombre, mes, anyo, cuenca[l_r_embalse - 13 + mes].dosmilveintiuno);
		printf("La capacidad del segundo embalse %s en el %i mes del %i es %.2f.\n", cuenca[l_r_embalse2 - 1].embalse_nombre, mes, anyo, cuenca[l_r_embalse2 - 13 + mes].dosmilveintiuno);
		if (cuenca[l_r_embalse2 - 13 + mes].dosmildoce > cuenca[l_r_embalse - 13 + mes].dosmilveintiuno) {
			max_mes = cuenca[l_r_embalse2 - 13 + mes].dosmilveintiuno;
			min_mes = cuenca[l_r_embalse - 13 + mes].dosmilveintiuno;
			printf("%s sobrepaso en %.2f hm^3 a %s en el %i mes.\n", cuenca[l_r_embalse2 - 1].embalse_nombre, res_mes = max_mes - min_mes, cuenca[l_r_embalse - 1].embalse_nombre, mes);
		}
		if (cuenca[l_r_embalse - 13 + mes].dosmilveintiuno > cuenca[l_r_embalse2 - 13 + mes].dosmilveintiuno) {
			max_mes = cuenca[l_r_embalse - 13 + mes].dosmilveintiuno;
			min_mes = cuenca[l_r_embalse2 - 13 + mes].dosmilveintiuno;
			printf("%s sobrepaso en %.2f hm^3 a %s en el %i mes.\n", cuenca[l_r_embalse - 1].embalse_nombre, res_mes = max_mes - min_mes, cuenca[l_r_embalse2 - 1].embalse_nombre, mes);
		}
		if (cuenca[l_r_embalse2 - 13 + mes].dosmilveintiuno == cuenca[l_r_embalse - 13 + mes].dosmilveintiuno) {
			printf("%s y %s tienen la misma capacidad en el %i mes.\n", cuenca[l_r_embalse2 - 1].embalse_nombre, cuenca[l_r_embalse - 1].embalse_nombre, mes);
		}
		break;

	}
}


//CAPACIDAD MAX
void capacidad_max(int l_r_embalse, int l_r_embalse2, linea cuenca[], Embalse embalse[]) {
	float max_capM, min_capM, dif_capM;
	printf("La capacidad maxima que puede contener los embalses elegidos, %s y %s, es %.2f y %.2f respectivamente.\n", cuenca[l_r_embalse - 1].embalse_nombre, cuenca[l_r_embalse2 - 1].embalse_nombre, embalse[l_r_embalse / 12 - 1].etotal, embalse[l_r_embalse2 / 12 - 1].etotal);
	if (embalse[l_r_embalse2 / 12 - 1].etotal > embalse[l_r_embalse / 12 - 1].etotal) {
		max_capM = embalse[l_r_embalse2 / 12 - 1].etotal;
		min_capM = embalse[l_r_embalse / 12 - 1].etotal;
		printf("La diferencia de capacidad maxima entre %s y %s es de %.2f hm^3.\n", cuenca[l_r_embalse2 - 1].embalse_nombre, cuenca[l_r_embalse - 1].embalse_nombre, dif_capM = max_capM - min_capM);
	}
	if (embalse[l_r_embalse / 12 - 1].etotal > embalse[l_r_embalse2 / 12 - 1].etotal) {
		max_capM = embalse[l_r_embalse / 12 - 1].etotal;
		min_capM = embalse[l_r_embalse2 / 12 - 1].etotal;
		printf("La diferencia de capacidad maxima entre %s y %s es de %.2f hm^3.\n", cuenca[l_r_embalse - 1].embalse_nombre, cuenca[l_r_embalse2 - 1].embalse_nombre, dif_capM = max_capM - min_capM);
	}
	if (embalse[l_r_embalse2 / 12 - 1].etotal == embalse[l_r_embalse / 12 - 1].etotal) {

		printf("Los embalses %s y %s tienen la misma capacidad maxima.\n", cuenca[l_r_embalse - 1].embalse_nombre, cuenca[l_r_embalse2 - 1].embalse_nombre);
	}
}


//SUPERFICIE
void superficie(int l_r_embalse, int l_r_embalse2, linea cuenca[], DatosComparacion comp[]) {
	float max_sup, min_sup, dif_sup;

	printf("La superficie del primer embalse, %s, es %.2f.\n", cuenca[l_r_embalse - 1].embalse_nombre, comp[l_r_embalse / 12 - 1].superficie);
	if (comp[l_r_embalse / 12 - 1].superficie == 0) {
		printf("La superficie de %s no esta disponible.\n", cuenca[l_r_embalse - 1].embalse_nombre);
	}
	printf("La superficie del segundo embalse, %s, es %.2f.\n", cuenca[l_r_embalse2 - 1].embalse_nombre, comp[l_r_embalse2 / 12 - 1].superficie);
	if (comp[l_r_embalse2 / 12 - 1].superficie == 0) {
		printf("La superficie de %s no esta disponible.\n", cuenca[l_r_embalse2 - 1].embalse_nombre);
	}
	if (comp[l_r_embalse2 / 12 - 1].superficie > comp[l_r_embalse / 12 - 1].superficie) {
		max_sup = comp[l_r_embalse2 / 12 - 1].superficie;
		min_sup = comp[l_r_embalse / 12 - 1].superficie;
		printf("La diferencia de superficies entre %s y %s es de %.2f hm.\n", cuenca[l_r_embalse2 - 1].embalse_nombre, cuenca[l_r_embalse - 1].embalse_nombre, dif_sup = max_sup - min_sup);
	}
	if (comp[l_r_embalse / 12 - 1].superficie > comp[l_r_embalse2 / 12 - 1].superficie) {
		max_sup = comp[l_r_embalse / 12 - 1].superficie;
		min_sup = comp[l_r_embalse2 / 12 - 1].superficie;
		printf("La diferencia de superficies entre %s y %s es de %.2f hm.\n", cuenca[l_r_embalse - 1].embalse_nombre, cuenca[l_r_embalse2 - 1].embalse_nombre, dif_sup = max_sup - min_sup);
	}
	if (comp[l_r_embalse / 12 - 1].superficie == comp[l_r_embalse2 / 12 - 1].superficie) {

		printf("Los embalses %s y %s tienen la misma superficie.\n", cuenca[l_r_embalse - 1].embalse_nombre, cuenca[l_r_embalse2 - 1].embalse_nombre);
	}
}


//TIPO DE EMBALSE:
void tipo_embalse(DatosComparacion comp[], int l_r_embalse, int l_r_embalse2, linea cuenca[]) {
	if (strcmp(comp[l_r_embalse / 12 - 1].tipo_presa, comp[l_r_embalse2 / 12 - 1].tipo_presa) != 0) {
		printf("El primer embalse, %s, tiene un embalse de tipo %s, mientras que el segundo embalse, %s, tiene un embalse de tipo %s.\n", cuenca[l_r_embalse - 1].embalse_nombre, comp[l_r_embalse / 12 - 1].tipo_presa, cuenca[l_r_embalse2 - 1].embalse_nombre, comp[l_r_embalse2 / 12 - 1].tipo_presa);
	}
	else {
		printf("Ambos embalses son del mismo tipo, %s.\n", comp[l_r_embalse / 12 - 1].tipo_presa);
	}
}


//USO DE EMBALSE:
void uso_embalse(DatosComparacion comp[], int l_r_embalse, int l_r_embalse2, linea cuenca[]) {
	if (strcmp(comp[l_r_embalse / 12 - 1].uso_abastecimiento, comp[l_r_embalse2 / 12 - 1].uso_abastecimiento) != 0) {
		if (strcmp(comp[l_r_embalse / 12 - 1].uso_abastecimiento, "Si") == 0) {
			printf("Solo el embalse, %s, se usa para abastecimiento.\n", cuenca[l_r_embalse - 1].embalse_nombre);
		}
		else {
			printf("Solo el embalse, %s, se usa para abastecimiento.\n", cuenca[l_r_embalse2 - 1].embalse_nombre);
		}
	}
	else {
		if (strcmp(comp[l_r_embalse / 12 - 1].uso_abastecimiento, "Si") == 0) {
			printf("Ambos embalses se usan para abastecimiento.\n");
		}
	}

	if (strcmp(comp[l_r_embalse / 12 - 1].uso_riego, comp[l_r_embalse2 / 12 - 1].uso_riego) != 0) {
		if (strcmp(comp[l_r_embalse / 12 - 1].uso_riego, "Si") == 0) {
			printf("Solo el embalse, %s, se usa para riego.\n", cuenca[l_r_embalse - 1].embalse_nombre);
		}
		else {
			printf("Solo el embalse, %s, se usa para riego.\n", cuenca[l_r_embalse2 - 1].embalse_nombre);
		}
	}
	else {
		if (strcmp(comp[l_r_embalse / 12 - 1].uso_riego, "Si") == 0) {
			printf("Ambos embalses se usan para riego.\n");
		}
	}
	if (strcmp(comp[l_r_embalse / 12 - 1].uso_electricidad, comp[l_r_embalse2 / 12 - 1].uso_electricidad) != 0) {
		if (strcmp(comp[l_r_embalse / 12 - 1].uso_electricidad, "Si") == 0) {
			printf("Solo el embalse, %s, se usa para electricidad.\n", cuenca[l_r_embalse - 1].embalse_nombre);
		}
		else {
			printf("Solo el embalse, %s, se usa para electricidad.\n", cuenca[l_r_embalse2 - 1].embalse_nombre);
		}
	}
	else {
		if (strcmp(comp[l_r_embalse / 12 - 1].uso_electricidad, "Si") == 0) {
			printf("Ambos embalses se usan para electricidad.\n");
		}
	}
	if (strcmp(comp[l_r_embalse / 12 - 1].uso_industrial, comp[l_r_embalse2 / 12 - 1].uso_industrial) != 0) {
		if (strcmp(comp[l_r_embalse / 12 - 1].uso_industrial, "Si") == 0) {
			printf("Solo el embalse, %s, se usa para industrial.\n", cuenca[l_r_embalse - 1].embalse_nombre);
		}
		else {
			printf("Solo el embalse, %s, se usa para industrial.\n", cuenca[l_r_embalse2 - 1].embalse_nombre);
		}
	}
	else {
		if (strcmp(comp[l_r_embalse / 12 - 1].uso_industrial, "Si") == 0) {
			printf("Ambos embalses se usan para industrial.\n");
		}
	}
	if (strcmp(comp[l_r_embalse / 12 - 1].uso_pesca, comp[l_r_embalse2 / 12 - 1].uso_pesca) != 0) {
		if (strcmp(comp[l_r_embalse / 12 - 1].uso_pesca, "Si") == 0) {
			printf("Solo el embalse, %s, se usa para pesca.\n", cuenca[l_r_embalse - 1].embalse_nombre);
		}
		else {
			printf("Solo el embalse, %s, se usa para pesca.\n", cuenca[l_r_embalse2 - 1].embalse_nombre);
		}
	}
	else {
		if (strcmp(comp[l_r_embalse / 12 - 1].uso_pesca, "Si") == 0) {
			printf("Ambos embalses se usan para pesca.\n");
		}
	}
	if (strcmp(comp[l_r_embalse / 12 - 1].uso_navegacion, comp[l_r_embalse2 / 12 - 1].uso_navegacion) != 0) {
		if (strcmp(comp[l_r_embalse / 12 - 1].uso_navegacion, "Si") == 0) {
			printf("Solo el embalse, %s, se usa para navegacion.\n", cuenca[l_r_embalse - 1].embalse_nombre);
		}
		else {
			printf("Solo el embalse, %s, se usa para navegacion.\n", cuenca[l_r_embalse2 - 1].embalse_nombre);
		}
	}
	else {
		if (strcmp(comp[l_r_embalse / 12 - 1].uso_navegacion, "Si") == 0) {
			printf("Ambos embalses se usan para navegacion.\n");
		}
	}
	if (strcmp(comp[l_r_embalse / 12 - 1].uso_banyo, comp[l_r_embalse2 / 12 - 1].uso_banyo) != 0) {
		if (strcmp(comp[l_r_embalse / 12 - 1].uso_banyo, "Si") == 0) {
			printf("Solo el embalse, %s, se usa para banyos.\n", cuenca[l_r_embalse - 1].embalse_nombre);
		}
		else {
			printf("Solo el embalse, %s, se usa para banyos.\n", cuenca[l_r_embalse2 - 1].embalse_nombre);
		}
	}
	else {
		if (strcmp(comp[l_r_embalse / 12 - 1].uso_banyo, "Si") == 0) {
			printf("Ambos embalses se usan para banyos.\n");
		}
	}
	if (strcmp(comp[l_r_embalse / 12 - 1].uso_picnic, comp[l_r_embalse2 / 12 - 1].uso_picnic) != 0) {
		if (strcmp(comp[l_r_embalse / 12 - 1].uso_picnic, "Si") == 0) {
			printf("Solo el embalse, %s, se usa para picnic.\n", cuenca[l_r_embalse - 1].embalse_nombre);
		}
		else {
			printf("Solo el embalse, %s, se usa para picnic.\n", cuenca[l_r_embalse2 - 1].embalse_nombre);
		}
	}
	else {
		if (strcmp(comp[l_r_embalse / 12 - 1].uso_picnic, "Si") == 0) {
			printf("Ambos embalses se usan para picnic.\n");
		}
	}
	if (strcmp(comp[l_r_embalse / 12 - 1].uso_restaurante, comp[l_r_embalse2 / 12 - 1].uso_restaurante) != 0) {
		if (strcmp(comp[l_r_embalse / 12 - 1].uso_restaurante, "Si") == 0) {
			printf("Solo el embalse, %s, se usa para restaurantes.\n", cuenca[l_r_embalse - 1].embalse_nombre);
		}
		else {
			printf("Solo el embalse, %s, se usa para restaurantes.\n", cuenca[l_r_embalse2 - 1].embalse_nombre);
		}
	}
	else {
		if (strcmp(comp[l_r_embalse / 12 - 1].uso_restaurante, "Si") == 0) {
			printf("Ambos embalses se usan para restaurantes.\n");
		}
	}
}


//CAMBIO DE GUION A ESPACIO
char* cambios_espacios_embalses(linea cuenca[], int l_r_embalse, int l_r_embalse2) {
	int c = 0;
	int b = 0;
	char cambio[100];
	char cambio2[100];
	strcpy(cambio, cuenca[l_r_embalse - 1].embalse_nombre);
	strcpy(cambio2, cuenca[l_r_embalse2 - 1].embalse_nombre);

	while (cambio[c] != '\0') {
		if (cambio[c] == '_') {
			cambio[c] = ' ';
		}
		c++;
	}
	while (cambio2[b] != '\0') {
		if (cambio2[b] == '_') {
			cambio2[b] = ' ';
		}
		b++;
	}

	strcpy(cuenca[l_r_embalse - 1].embalse_nombre, cambio);
	strcpy(cuenca[l_r_embalse2 - 1].embalse_nombre, cambio2);

	return cuenca[l_r_embalse - 1].embalse_nombre;
	return cuenca[l_r_embalse2 - 1].embalse_nombre;
}

char* cambios_espacios_tipo_presa(DatosComparacion comp[], int l_r_embalse, int l_r_embalse2) {
	int c = 0;
	int b = 0;
	char cambio[100];
	char cambio2[100];
	strcpy(cambio, comp[l_r_embalse / 12 - 1].tipo_presa);
	strcpy(cambio2, comp[l_r_embalse2 / 12 - 1].tipo_presa);

	while (cambio[c] != '\0') {
		if (cambio[c] == '_') {
			cambio[c] = ' ';
		}
		c++;
	}
	while (cambio2[b] != '\0') {
		if (cambio2[b] == '_') {
			cambio2[b] = ' ';
		}
		b++;
	}

	strcpy(comp[l_r_embalse / 12 - 1].tipo_presa, cambio);
	strcpy(comp[l_r_embalse2 / 12 - 1].tipo_presa, cambio2);

	return comp[l_r_embalse / 12 - 1].tipo_presa;
	return comp[l_r_embalse2 / 12 - 1].tipo_presa;
	
}



//
void comparacion_principal() {
	//variables

	int vb = 0, vc = 0, vco = 0, i;//for y ficheros

	int num_cuenca = 0, num_embalse, l_r_embalse;//embalse1
	int num_cuenca2 = 0, num_embalse2, l_r_embalse2;//embalse2
	int mes_anyo = 0, anyo = 0, mes = 0;//fechas y meses
	char C_cuenca[2];

	linea* cuenca = NULL;
	Embalse* embalse = NULL;
	DatosComparacion* comp = NULL;

	cuenca = (linea*)malloc(4236 * sizeof(linea));
	embalse = (Embalse*)malloc(353 * sizeof(Embalse));
	comp = (DatosComparacion*)malloc(353 * sizeof(DatosComparacion));

	if (cuenca == NULL || embalse == NULL || comp == NULL) {
		printf("Error al reservar memoria.\n");
		return;
	}

	//Fich
	FILE* base;
	base = fopen("texto_proyecto.csv", "r");
	if (base == NULL) {
		printf("Error al abrir el fichero base.\n");
		return;
	}
	FILE* capacidad;
	capacidad = fopen("Embalses_capacidad.txt", "r");
	if (capacidad == NULL) {
		printf("Error al abrir el fichero de capacidad.\n");
		return;
	}
	FILE* F_comparacion;
	F_comparacion = fopen("comparacion2.txt", "r");
	if (F_comparacion == NULL) {
		printf("Error al abrir el fichero de comparación.\n");
		return;
	}


	//

	fseek(base, 90, SEEK_SET);
	while (fscanf(base, "%[^,],%[^,],%i,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f\n", cuenca[vb].cuenca_hidrografica, cuenca[vb].embalse_nombre, &cuenca[vb].mes, &cuenca[vb].dosmildoce, &cuenca[vb].dosmiltrece, &cuenca[vb].dosmilcatorce, &cuenca[vb].dosmilquince, &cuenca[vb].dosmildieciseis, &cuenca[vb].dosmildiecisiete, &cuenca[vb].dosmildieciocho, &cuenca[vb].dosmildiecinueve, &cuenca[vb].dosmilveinte, &cuenca[vb].dosmilveintiuno) != EOF)
	{



		vb++;
	}
	while (fscanf(capacidad, "%s\t%f\n", embalse[vc].embalse_nom, &embalse[vc].etotal) != EOF) {

		vc++;
	}
	while (fscanf(F_comparacion, "%99[^,],%f,%99[^,],%4[^,],%4[^,],%4[^,],%4[^,],%4[^,],%4[^,],%4[^,],%4[^,],%4[^\n]\n", comp[vco].nombre_embalse, &comp[vco].superficie, comp[vco].tipo_presa, comp[vco].uso_abastecimiento, comp[vco].uso_riego, comp[vco].uso_electricidad, comp[vco].uso_industrial, comp[vco].uso_pesca, comp[vco].uso_navegacion, comp[vco].uso_banyo, comp[vco].uso_picnic, comp[vco].uso_restaurante) != EOF) {
		vco++;

	}
			/*printf("\n*********************************\n");
    
    		printf("*      COMPARACION EMBALSES     *\n");
    
    		printf("*********************************\n\n");*/
    		/*printf("\n*********************************\n");
    
    		printf("*        CALCULO MEDIAS        *\n");
    
    		printf("*********************************\n\n");*/
    		/*printf("\n*********************************\n");
    
    		printf("*       MAXIMOS Y MINIMOS       *\n");
    
    		printf("*********************************\n\n");*/
    		/*printf("\n*********************************\n");
    
    		printf("*      LISTADO DE CUENCAS:      *\n");
    
    		printf("*********************************\n\n");*/
    		/*printf("\n*********************************\n");
    
    		printf("*      LISTADO DE EMBALSES:     *\n");
    
    		printf("*********************************\n\n");*/

	do {
	
		//LISTA CUENCAS
		nombres_cuencas(vb, cuenca);

		//SELECCION CUENCA
		num_cuenca = seleccion_cuenca_1(num_cuenca, C_cuenca);

		//SELECCION EMBALSE
		nombreseleccion_embalse_1(num_cuenca, cuenca, &num_embalse, &l_r_embalse);

		//2 LISTA CUENCAS:
		nombres_cuencas(vb, cuenca);

		//SELECCION 2 CUENCA:
		num_cuenca2 = seleccion_cuenca_2(num_cuenca2, C_cuenca);

		//SELECCION 2 EMBALSE
		nombreseleccion_embalse_2(num_cuenca2, cuenca, &num_embalse2, &l_r_embalse2);

		if (l_r_embalse == l_r_embalse2) {
			printf("\nHas elegido el mismo embalse, no se puede hacer la comparacion. Intentelo de nuevo.\n");
		}

	} while (l_r_embalse == l_r_embalse2);


	cambios_espacios_embalses(cuenca, l_r_embalse, l_r_embalse2);
	cambios_espacios_tipo_presa(comp, l_r_embalse, l_r_embalse2);

	printf("\nEl primer embalse elegido es %s\n", cuenca[l_r_embalse - 1].embalse_nombre);
	printf("El segundo embalse elegido es %s\n", cuenca[l_r_embalse2 - 1].embalse_nombre);

	//TIPO COMPARACION

	mes_anyo = tipo_comparacion(mes_anyo);

	//COMPARACION SEGUN AÑO:
	if (mes_anyo == 1) {
		anyo = seleccion_anyos(anyo);
		comparacion_anyo(mes_anyo, anyo, l_r_embalse, l_r_embalse2, cuenca);
	}

	//COMPARACION SEGUN MES:
	if (mes_anyo == 2) {
		anyo = seleccion_anyos(anyo);
		mes = seleccion_mese(mes);
		comparacion_mes(mes_anyo, anyo, mes, l_r_embalse, l_r_embalse2, cuenca);
	}

	//CAPACIDAD MAXIMA:
	capacidad_max(l_r_embalse, l_r_embalse2, cuenca, embalse);

	//SUPERFICIE
	superficie(l_r_embalse, l_r_embalse2, cuenca, comp);

	//TIPO DE EMBALSE
	tipo_embalse(comp, l_r_embalse, l_r_embalse2, cuenca);

	//USO
	uso_embalse(comp, l_r_embalse, l_r_embalse2, cuenca);

	free(cuenca);
	free(embalse),
		free(comp);
	fclose(base);
	fclose(capacidad);
	fclose(F_comparacion);


	return;
}
//FIN COMPARACION


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

//<MAIN> 

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

	printf("\n*********************************\n");
    
    printf("*     CALCULO DE PORCENTAJES    *\n");
    
    printf("*********************************\n\n");

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

	printf("El embalse %s de la cuenca %s estaba al %.2f%% de su capadidad, en %i del anyo %i.", cuenca[posiciones_cuencas[num_cuenca - 1] + (num_embalse - 1) * 12].embalse_nombre, cuenca[posiciones_cuencas[num_cuenca - 1] + (num_embalse - 1) * 12].cuenca_hidrografica, porcentaje,N_mes, anyo);

	//SÓLO SI HAY SEQÍA

	sequia(porcentaje);

	fclose(tabla);
	fclose(lista);

}

//FIN PORCENTAJE


//PALABRA DEL DIA
//FECHA ACTUAL DESDE 1970

struct tm* fecha_actual() {

	time_t tiempo = time(NULL); // ALMACENAMOS SEGUNDOS TRANSCURRIDOS DESDE 1970 EN tiempo

	return localtime(&tiempo); //CONVIERTE EL TIEMPO EN SEGUNDOS Y DEVUELVE UN PUNTERO DE LA ESTRUCTURA struct tm (ya creada)
}

//OBTENEMOS EL DÍA DEL AÑO

int dia_anyo(struct tm* fecha) {

	char C_dia[4];
	int dia;

	strftime(C_dia, sizeof(C_dia), "%j", fecha);//%j DEVUELVE EL Nº DE DÍAS TRANSCURRIDOS DESDE EL 1 DE ENERO., FUNCIÓN ESPECÍFICA DEL TIME.H

	sscanf(C_dia, "%i", &dia);

	return dia;

}

//OBTENEMOS LA PALABRA DEL DÍA

void palabra_d(int dia, linea_palabradia digitos[]) {
	printf("TU(S) PALABRA(S) DE HOY:\n\n%s", digitos[dia - 1].posicion);
}

void palabra_dia_main() {

	int dia, t = 0;

	linea_palabradia digitos[400];

	//OBTENEMOS EL DÍA DEL AÑO ACTUAL: 

	struct tm* fecha = fecha_actual();

	dia = dia_anyo(fecha);
	//se pondría en el main
		//ABRIMOS EL FICHERO

	FILE* palabra_dia;
	palabra_dia = fopen("palabra_dia.txt", "r");
	if (palabra_dia == NULL) {
		printf("error");
	}

	//LEEMOS EL FICHERO

	while (fscanf(palabra_dia, "%[^\n]", digitos[t].posicion) != EOF) {
		fgetc(palabra_dia);
		t++;
	}
	//hasta aquí
		//TU(S) PALABRA(S):

	palabra_d(dia, digitos);

	//CERRAMOS FICHERO

	fclose(palabra_dia);

}
//final palabra del dia


void nombres_embalses(int j, linea vector[]) {		// Vector es cuencas
	int i, f = 0;
	for (i = 0;i < j;i++) {
		if (i % 12 == 0) {
			printf("%i. %s\n", f + 1, vector[i].embalse_nombre);
			f++;

		}
	}
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

//INTERFAZ
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
			printf("CUENCAS");
			gotoxy(x, 14);
			printf("Presionar ( 1 )");

		}
		////// Segundo cuadrado/////
		{
			x = 61;
			y = 9;
			gotoxy(x, y);
			printf("EMBALSES");
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
			printf("CUENCAS");

			//Primer Cuadrado
			gotoxy(20, 10);
			printf("NOMBRES DE CUENCAS");
			gotoxy(20, 18);
			printf("Presionar ( 1 )");

			//Segundo Cuadrado
			gotoxy(61, 10);
			printf("NOMBRES DE CUENCAS");
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
			printf("MEDIDAS");
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
				printf("CAMBIAR COLOR:");
				x = 20;
				y = 12;
				gotoxy(x, y);
				printf("MODO DIABLO:1");
				x = 20;
				y = 13;
				gotoxy(x, y);
				printf("VIOLETA:5");
				x = 20;
				y = 14;
				gotoxy(x, y);
				printf("AZUL:6");
				x = 20;
				y = 15;
				gotoxy(x, y);
				printf("AMARILLO:7");
				x = 20;
				y = 16;
				gotoxy(x, y);
				printf("GRIS:8");

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
				printf("Presionar ( 3 )");

			}
			//// Cuarto cuadrado////
			{
				x = 61;
				y = 20;
				gotoxy(x, y);
				printf("SALIR DEL PROGRAMA");
				gotoxy(x, 28);
				printf("Presionar ( 4 )");

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
//FIN INTERFAZ


//Inicio funciones del cuestionario
int pregunta_inicial(){
    int valor;
    printf("\n \n??Iniciar cuestionario??\n");
    
    printf("\t1-SI\n\t2-NO\n");
    
    do{
        scanf("%d", &valor);
        while ((getchar()) != '\n');
    }while(valor != 1 && valor != 2);
        
    return valor;
}

int valor_letra_introducida(){
    
    int i=0;
    char letra;
    char cadena[10];
    
    printf("Introduzca la respuesta: ");
    
    do{
        fgets(cadena, sizeof(cadena), stdin);
        letra = toupper(cadena[0]);
        
        if(letra!='A' && letra!='B' && letra!='C' && letra!='D' && i>0){
            printf("\nCaracter incorrecto. Introduzca la respuesta de nuevo:");
        }
        
        i++;
        
    }while(letra!='A' && letra!='B' && letra!='C' && letra!='D' );
    
    return letra;
}

int preguntas_cuestionario(int i){
    
    char letra; 
    int valor;
    
    switch(i){
      case 0:
            printf("PREGUNTA N 1: \n");
            printf("??En que continente esta el embalse artificial mas grande del mundo??");
            printf("\n \tA)America \n \tB)Europa \n \tC)Africa \n \tD)Asia\n");
            valor = valor_letra_introducida();
            break; 
      case  1:  
            printf("\nPREGUNTA N 2: \n");
            printf("??Que pais de Europa tiene el mayor numero de embalses??");
            printf("\n \tA)Albania \n \tB)Rumania \n \tC)Noruega \n \tD)Espanya\n");
            valor = valor_letra_introducida();
            break;
      case  2:  
            printf("\nPREGUNTA N 3: \n");
            printf("??Pais en el que se encuentra el embalse mas grande de Europa??");
            printf("\n \tA)Francia \n \tB)Ucrania \n \tC)Italia \n \tD)Suecia\n");
            valor = valor_letra_introducida();
            break;    
      case  3:  
            printf("\nPREGUNTA N 4: \n");
            printf("??Que factor influye en mayor medida a el nivel de agua en los embalses de Espanya??");
            printf("\n \tA)Altitud de las montanyas \n \tB)Poblacion de la zona \n \tC)Temperatura media del mar \n \tD)Precipitaciones y sequias\n");
            valor = valor_letra_introducida();
            break;
      case  4:  
            printf("\nPREGUNTA N 5: \n");
            printf("??Donde se encuentra el embalse mas antiguo de Espanya??");
            printf("\n \tA)Extremadura \n \tB)Asturias \n \tC)Castilla y Leon \n \tD)Pais Vasco\n");
            valor = valor_letra_introducida();
            break;
      case  5:  
            printf("\nPREGUNTA N 6: \n");
            printf("??Cual fue el anyo desde el 2004 en el que hubo mas agua embalsada en todo el pais??");
            printf("\n \tA)2008 \n \tB)2021 \n \tC)2013 \n \tD)2017\n");
            valor = valor_letra_introducida();
            break;
    }
            
    return valor - 'A' + 1;   
}

void mostrar_resultado(int correcta, int i){
    
    if( correcta ){
        printf("\n \t \t!!Respuesta correcta!!\n");
        printf("\n\t \t \t        X\n");
        printf("\t \t \t       X\n");
        printf("\t \t \t      X \n");
        printf("\t \t \tX   X\n");
        printf("\t \t \t X X\n");
        printf("\t \t \t  X \n");
    }
    else{
        printf("\n \t \t!!Respuesta incorrecta!!: La respuesta era la ");
        switch(i){
            case 0: printf("C-Africa"); break;
            case 1: printf("D-Espanya"); break;
            case 2: printf("B-Ucrania"); break;
            case 3: printf("D-Precipitaciones y sequias"); break;
            case 4: printf("A-Extremadura"); break;
            case 5: printf("C-2013"); break;
        }
        printf("\n \n\t \t \tX   X\n");
        printf("\t \t \t X X\n");
        printf("\t \t \t  X\n");
        printf("\t \t \t X X\n");
        printf("\t \t \tX   X\n");
    }
}

void informacion_respuestas(int i){
    switch(i){
        case 0:
            printf("\n \n-En Africa se encuentra el embalse y lago artifical mas grande del mundo, el lago Kariba en la fronterea entre Zimbawe y Zambia: Este posee un  volumen de 130 km^3 y desemboca en el Oceano Indico.\n");
            break;
        case 1:
            printf("\n \n-Espanya es el pais de Europa con mas embalses y uno de los que mas tiene en todo el mundo. Son mas de 1200 los embalses de mas de 1hm^3 de capacidad que hay repartidos por el pais. No es de extranyar el numero debido a la geografia y clima del pais que favorece la creacion de estas estructuras. \n");
            break;
        case 2:
            printf("\n \n-La presa de Kuibuyshev, en Rusia, es la presa mas grande de Europa, con una capacidad de 58km^3.\n");
            break;
        case 3:
            printf("\n \n-El nivel de los embalses depende principalmente del balance entre el agua que reciben (principalmente de la lluvia y el deshielo) y la que se extrae para riego, consumo y otros usos. Las precipitaciones y las sequias tienen un impacto directo, mucho mas que otros factores como la altitud o la densidad poblacional.\n");
            break;
        case 4:
            printf("\n \n-El embalse mas antiguo de Espanya se encuentra en la Comunidad Autonoma de Extremadura, mas concretamente en Merida. Es el embalse de Proserpina, fue construido por los romanos entre el I y II d.C y todavia sigue en uso (con fines recreativos). \n");
            break;
        case 5:
            printf("\n \n-El anyo con mas acumulacion fue el 2013, con 63.000 hm^3 acumulados, lo que representaba sobre la media un 111/100. \n");
            break;
    }
}

void tabla_errores(int correcta,int i){
    printf("\n \t \t ***************");
    if(correcta){
        printf("\n \t \t *PREGUNTA %d*SI*", i+1);
    } else {
        printf("\n \t \t *PREGUNTA %d*NO*", i+1);
    }
}

void premios_concurso(int numero_aciertos){
    printf("\n \nTu numero de aciertos es %d", numero_aciertos);
    
    switch(numero_aciertos){
        case 0:
           
           printf("\n !!Felicidades!! ");
           printf("\n   _______\n  |       |\n  |  X_X  |  ¡Has conseguido no acertar nada! \n  |_______|\n");

        break;
        
        case 1:
        case 2:
           printf("\n Bueno, al menos lo has intentado ?no?. \n");
           printf("\n    .-\"      \"-.\n   /   O    O   \ \n  |      /\\      |     Poco a poco\n  |     ====     |     Sigue aprendiendo.\n   \\            /\n      '-.__.-'\n");

        break;
        
        case 3: 
        case 4:
           printf("\n !Buen intento! Vas mejorando. ");
            printf("\n"
       "    .-\"      \"-. \n"
       "   /   O    O   \\ \n"
       "  |      /\\      |     !Ya estas cerca! \n"
       "  |     ====     |     En nada lo tienes. \n"
       "   \\            / \n"
       "    '-.______.–' \n");

        break;
        
        case 5:
           printf("\n !Casi perfecto! ");
           printf("\n     _______\n    /       \\\n   |  _____  |\n   | |     | |\n   | |_____| |  Te mereces una medalla\n    \\_______/\n     \\_____/\n");

        break;
        
        case 6:
           printf("\n !Eres un maestro de embalses!");
           printf("\n      ___________\n     '._==_==_=_.' \n     .-\\:      /-.\n    | (|:.     |) |   Aqui tienes tu trofeo. \n     '-|:.     |-'\n       \\::.    /\n        '::. .'\n          ) (\n        _.' '._\n       \"\"\"\"\"\"\"\n");

        break;
    }
}

int cuestionario(){
    
    printf("\nOimos, vemos y hablamos sobre los embalses cotidianamente, nos abastecen de agua para el consumo y la agricultura y tienen un impacto en el dia a dia del que el ciudadano promedio no es consciente. Dicho esto, ¿sabras lo suficiente como para llevarte el premio al que mas sabe de embalses?");
    
    int valor_pregunta = pregunta_inicial(), respuestas[6], respuestas_correctas[6]={3,4,2,4,1,3};
    
    if(valor_pregunta == 1){
        
      printf("\t \t \t*********************************\n");
    
      printf("\t \t \t*    CUESTIONARIO DE EMBALSES   *\n");
    
      printf("\t \t \t*********************************\n");
    
    for(int i=0;i<6;i++){
        
        respuestas[i] = preguntas_cuestionario( i );
       
        mostrar_resultado(respuestas[i]==respuestas_correctas[i], i);
      
        informacion_respuestas(i);
    }
    
    int numero_aciertos=0;
    
    for(int i=0;i<6;i++){
        
      tabla_errores(respuestas[i]==respuestas_correctas[i], i);
    
        if(respuestas[i]==respuestas_correctas[i]){
        
            numero_aciertos++;
    
        }
    
    }
    
    printf("\n \t \t ***************");/*se acaba la tabla por abajo*/
    
    premios_concurso(numero_aciertos);
    
    }
    
    else if(valor_pregunta == 2){
    
    printf("\njoe :(");
    
    return 0;
    
    }
    
    else{
        
        return 0;
        
    }

    return 0;
}
//Final funciones del cuestionario
