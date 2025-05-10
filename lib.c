#include "lib.h"
 
int calcular_media() {

	int i, j = 0, anyo, num_cuenca, num_embalse, f = 0;

	int maxmin[4];

	int posiciones_cuencas[15];

	float media;

	linea cuenca[4236];

	FILE* tabla;
	tabla = fopen("texto_proyecto.txt", "r");
	if (tabla == NULL) // Si el resultado es NULL mensaje de error
	{
		printf("Error al abrir el fichero.\n");
		return -1;
	}


	while (fscanf(tabla, "%s\t%s\t%i\t%f\t%f\t%f\t%f\t%f\t%f\t%f\t%f\t%f\t%f\n", cuenca[j].cuenca_hidrografica, cuenca[j].embalse_nombre, &cuenca[j].mes, &cuenca[j].dosmildoce, &cuenca[j].dosmiltrece, &cuenca[j].dosmilcatorce, &cuenca[j].dosmilquince, &cuenca[j].dosmildieciseis, &cuenca[j].dosmildiecisiete, &cuenca[j].dosmildieciocho, &cuenca[j].dosmildiecinueve, &cuenca[j].dosmilveinte, &cuenca[j].dosmilveintiuno) != EOF)
	{
		j++;
	}

	//Almacenar posiciones cuencas
	//Aparecen irregularmente debemos compararlas para no repetir
	for (i = 0;i < j;i++) {

		if (strcmp(cuenca[i].cuenca_hidrografica, cuenca[i - 1].cuenca_hidrografica) != 0) {
			posiciones_cuencas[f] = i;
			f++;
		}
	}



	//Nombres cuencas numeradas:
	//nombres_cuencas(j,cuenca);

	//Nombres embalses numerados:
	//nombres_embalses(j,cuenca);

	//Nombres de los embalses de una cuenca en concreto:
	//scanf("%i", &num_cuenca);
	//nombres_cuencas_embalse( j, num_cuenca, cuenca, posiciones_cuencas);

	//Media de un año en concreto:
	//scanf("%i", &anyo);
	//media = media_anyo(j, anyo, cuenca);
	//printf("La media en %i fue de %f", anyo, media)

	//Media de un embalse un año en concreto:
	//scanf("%i", &anyo);
	//scanf("%i", &num_cuenca);
	//scanf("%i", &num_embalse);
	//media = media_anyo_embalse(j, anyo, num_cuenca, num_embalse, cuenca, posiciones_cuencas);
	//printf("La media de %i de la cuenca %s, embalse %s es %f", anyo, cuenca[posiciones_cuencas[num_cuenca-1]+(num_embalse-1)*12].cuenca_hidrografica,cuenca[posiciones_cuencas[num_cuenca-1]+(num_embalse-1)*12].embalse_nombre);


	//Máximo y minimo de un embalse un año en concreto:
	//scanf("%i", &anyo);
	//scanf("%i", &num_cuenca);
	//scanf("%i", &num_embalse);
	//max_y_min_embalse(j, anyo, num_cuenca, num_embalse, cuenca, posiciones_cuencas, maxmin);
	//printf("El maximo es %f en el mes %i, el minimo es %f en el mes %i", maxmin[0],maxmin[1],maxmin[2],maxmin[3]);


	//Ejemplo programa
	printf("Para calcular la media seleccione un año(2012)\n");
	anyo = 2012;
	printf("Para calcular la media seleccione una cuenca\n");
	nombres_cuencas(j, cuenca);
	scanf("%i", &num_cuenca);
	printf("Selecciona el embalse de la cuenca elegida\n");
	nombres_cuencas_embalse(j, num_cuenca, cuenca, posiciones_cuencas);
	scanf("%i", &num_embalse);
	media = media_anyo_embalse(j, anyo, num_cuenca, num_embalse, cuenca, posiciones_cuencas);
	//printf("La media es %f", media);
	printf("La media de %i de la cuenca %s, embalse %s es %f", anyo, cuenca[posiciones_cuencas[num_cuenca - 1] + (num_embalse - 1) * 12].cuenca_hidrografica, cuenca[posiciones_cuencas[num_cuenca - 1] + (num_embalse - 1) * 12].embalse_nombre, media);





}

void nombres_embalses(int j, linea vector[]) {		// Vector es cuencas
	int i, f = 0;
	for (i = 0;i < j;i++) {
		if (i % 12 == 0) {
			printf("%i. %s\n", f + 1, vector[i].embalse_nombre);
			f++;

		}
	}
}

void nombres_cuencas(int j, linea vector[]) {			// Vector 1 es cuencas y vector 2 posiciones cuencas
	int i, f = 0;
	for (i = 0;i < j;i++) {
		if (strcmp(vector[i].cuenca_hidrografica, vector[i - 1].cuenca_hidrografica) != 0) {
			printf("%i. %s\n", f + 1, vector[i].cuenca_hidrografica);
			f++;
		}
	}
}


void nombres_cuencas_embalse(int j, int num_cuenca, linea vector[], int vector2[]) {
	int i, f = 0;
	for (i = vector2[num_cuenca - 1];i < vector2[num_cuenca];i++) {
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
		printf("%f\n", media);
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

		return 0;
	}
	vector3[0] = maximo;
	vector3[1] = mesM;
	vector3[2] = minimo;
	vector3[3] = mesm;
	//printf("El maximo es %f en el mes %i, el minimo es %f en el mes %i", vector3[0],vector3[1],vector3[2],vector3[3]);

}

#include "lib.h"
 
int calcular_media() {

	int i, j = 0, anyo, num_cuenca, num_embalse, f = 0;

	int maxmin[4];

	int posiciones_cuencas[15];

	float media;

	linea cuenca[4236];

	FILE* tabla;
	tabla = fopen("texto_proyecto.txt", "r");
	if (tabla == NULL) // Si el resultado es NULL mensaje de error
	{
		printf("Error al abrir el fichero.\n");
		return -1;
	}


	while (fscanf(tabla, "%s\t%s\t%i\t%f\t%f\t%f\t%f\t%f\t%f\t%f\t%f\t%f\t%f\n", cuenca[j].cuenca_hidrografica, cuenca[j].embalse_nombre, &cuenca[j].mes, &cuenca[j].dosmildoce, &cuenca[j].dosmiltrece, &cuenca[j].dosmilcatorce, &cuenca[j].dosmilquince, &cuenca[j].dosmildieciseis, &cuenca[j].dosmildiecisiete, &cuenca[j].dosmildieciocho, &cuenca[j].dosmildiecinueve, &cuenca[j].dosmilveinte, &cuenca[j].dosmilveintiuno) != EOF)
	{
		j++;
	}

	//Almacenar posiciones cuencas
	//Aparecen irregularmente debemos compararlas para no repetir
	for (i = 0;i < j;i++) {

		if (strcmp(cuenca[i].cuenca_hidrografica, cuenca[i - 1].cuenca_hidrografica) != 0) {
			posiciones_cuencas[f] = i;
			f++;
		}
	}



	//Nombres cuencas numeradas:
	//nombres_cuencas(j,cuenca);

	//Nombres embalses numerados:
	//nombres_embalses(j,cuenca);

	//Nombres de los embalses de una cuenca en concreto:
	//scanf("%i", &num_cuenca);
	//nombres_cuencas_embalse( j, num_cuenca, cuenca, posiciones_cuencas);

	//Media de un año en concreto:
	//scanf("%i", &anyo);
	//media = media_anyo(j, anyo, cuenca);
	//printf("La media en %i fue de %f", anyo, media)

	//Media de un embalse un año en concreto:
	//scanf("%i", &anyo);
	//scanf("%i", &num_cuenca);
	//scanf("%i", &num_embalse);
	//media = media_anyo_embalse(j, anyo, num_cuenca, num_embalse, cuenca, posiciones_cuencas);
	//printf("La media de %i de la cuenca %s, embalse %s es %f", anyo, cuenca[posiciones_cuencas[num_cuenca-1]+(num_embalse-1)*12].cuenca_hidrografica,cuenca[posiciones_cuencas[num_cuenca-1]+(num_embalse-1)*12].embalse_nombre);


	//Máximo y minimo de un embalse un año en concreto:
	//scanf("%i", &anyo);
	//scanf("%i", &num_cuenca);
	//scanf("%i", &num_embalse);
	//max_y_min_embalse(j, anyo, num_cuenca, num_embalse, cuenca, posiciones_cuencas, maxmin);
	//printf("El maximo es %f en el mes %i, el minimo es %f en el mes %i", maxmin[0],maxmin[1],maxmin[2],maxmin[3]);


	//Ejemplo programa
	printf("Para calcular la media seleccione un año(2012)\n");
	anyo = 2012;
	printf("Para calcular la media seleccione una cuenca\n");
	nombres_cuencas(j, cuenca);
	scanf("%i", &num_cuenca);
	printf("Selecciona el embalse de la cuenca elegida\n");
	nombres_cuencas_embalse(j, num_cuenca, cuenca, posiciones_cuencas);
	scanf("%i", &num_embalse);
	media = media_anyo_embalse(j, anyo, num_cuenca, num_embalse, cuenca, posiciones_cuencas);
	//printf("La media es %f", media);
	printf("La media de %i de la cuenca %s, embalse %s es %f", anyo, cuenca[posiciones_cuencas[num_cuenca - 1] + (num_embalse - 1) * 12].cuenca_hidrografica, cuenca[posiciones_cuencas[num_cuenca - 1] + (num_embalse - 1) * 12].embalse_nombre, media);





}

void nombres_embalses(int j, linea vector[]) {		// Vector es cuencas
	int i, f = 0;
	for (i = 0;i < j;i++) {
		if (i % 12 == 0) {
			printf("%i. %s\n", f + 1, vector[i].embalse_nombre);
			f++;

		}
	}
}

void nombres_cuencas(int j, linea vector[]) {			// Vector 1 es cuencas y vector 2 posiciones cuencas
	int i, f = 0;
	for (i = 0;i < j;i++) {
		if (strcmp(vector[i].cuenca_hidrografica, vector[i - 1].cuenca_hidrografica) != 0) {
			printf("%i. %s\n", f + 1, vector[i].cuenca_hidrografica);
			f++;
		}
	}
}


void nombres_cuencas_embalse(int j, int num_cuenca, linea vector[], int vector2[]) {
	int i, f = 0;
	for (i = vector2[num_cuenca - 1];i < vector2[num_cuenca];i++) {
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
		printf("%f\n", media);
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

		return 0;
	}
	vector3[0] = maximo;
	vector3[1] = mesM;
	vector3[2] = minimo;
	vector3[3] = mesm;
	//printf("El maximo es %f en el mes %i, el minimo es %f en el mes %i", vector3[0],vector3[1],vector3[2],vector3[3]);

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

//Texto3
void Texto3()
{
	//Titulo// 
	{
		gotoxy(55, 4);
		printf("CUESTIONARIO");
	}

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
	/*
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
}*/

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

//Inicio funciones del cuestionario
int pregunta_inicial(){
    int valor;
    printf("\n \n¿Iniciar cuestionario?\n");
    
    printf("\t1-SI\n\t2-NO\n");
    
    do{
        
        scanf("%d", &valor);
        
    }while(valor != 1 && valor != 2);
        
    return valor;
}

int preguntas_cuestionario(int i){
    
    char letra; 
    
    int valor;
    
    switch(i){
    
      case 0:
            printf("PREGUNTA Nª1: \n");
      
            printf("¿En que continente está el embalse más grande del mundo?");
      
            printf("\n \tA)América \n \tB)Europa \n \tC)África \n \tD)Asia\n");
            
            valor = valor_letra_introducida();
            
            return valor - 'A' + 1; /*Se resta al valor de la letra el valor de A para que sea un número entre el 0 y el 3 y se le suma 1 para que esté en 1-4*/;
            
      case  1:  
      
            printf("\nPREGUNTA Nª2: \n");
      
            printf("¿Que país de Europa tiene el mayor número de embalses?");
      
            printf("\n \tA)Albania \n \tB)Rumanía \n \tC)Noruega \n \tD)España\n");
            
            valor = valor_letra_introducida();
            
            return valor - 'A' + 1;
            
      case  2:  
      
            printf("\nPREGUNTA Nª3: \n");
      
            printf("¿Paísen el que se encuentra el embalse más grande de Europa?");
      
            printf("\n \tA)Francia \n \tB)España \n \tC)Italia \n \tD)Suecia\n");
            
            valor = valor_letra_introducida();
            
            return valor - 'A' + 1;    
            
      case  3:  
      
            printf("\nPREGUNTA Nª4: \n");
      
            printf("¿Qué factor influye en mayor medida a el nivel de agua en los embalses de España?");
      
            printf("\n \tA)Altitud de las montañas \n \tB)Población de la zona \n \tC)Temperatura media del mar \n \tD)Precipitaciones y sequías\n");
            
            valor = valor_letra_introducida();
            
            return valor - 'A' + 1;
      case  4:  
      
            printf("\nPREGUNTA Nª5: \n");
      
            printf("¿Dónde se encuentra el embalse más antiguo de España?");
      
            printf("\n \tA)Alicante \n \tB)Asturias \n \tC)Castilla y León \n \tD)País Vasco\n");
            
            valor = valor_letra_introducida();
            
            return valor - 'A' + 1;
      case  5:  
      
            printf("\nPREGUNTA Nª6: \n");
      
            printf("¿Cual fue el año desde el 2004 en el que hubo más agua embalsada en todo el país?");
      
            printf("\n \tA)2008 \n \tB)2021 \n \tC)2013 \n \tD)2017\n");
            
            valor = valor_letra_introducida();
            
            return valor - 'A' + 1;
    }
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
            
            printf("\nCarácter incorrecto. Introduzca la respuesta de nuevo:");
        }
        
        i++;/*Ponemos un i de manera que el texto de carácter incorrecto solo salta a la segunda*/
        
    }while(letra!='A' && letra!='B' && letra!='C' && letra!='D' );
    
    return letra;
}

void mostrar_resultado(int correcta){
    
    if( correcta ){
        
            printf("\n\t \t \t        X\n");
            
            printf("\t \t \t       X\n");
            
            printf("\t \t \t      X \n");
            
            printf("\t \t \tX   X\n");
            
            printf("\t \t \t X X\n");
            
            printf("\t \t \t  X \n");
            
       }
        else{
            
            printf("\n\t \t \tX   X\n");
            
            printf("\t \t \t X X\n");
            
            printf("\t \t \t  X\n");
            
            printf("\t \t \t X X\n");
            
            printf("\t \t \tX   X\n");
        }
}

tabla_errores(correcta,i){
    printf("\n \t \t ***************");
    
    if(correcta){
        
    printf("\n \t \t *PREGUNTA %d*SI*", i);
    
    }
    else{
        
    printf("\n \t \t *PREGUNTA %d*NO*", i);
    
    }
}

int cuestionario(){
    
    printf("\nOímos, vemos y hablamos sobre los embalses cotidianamente, nos abastecen de agua para el consumo y la agricultura y tienen un impacto en el día a día del que el ciudadano promedio no es consciente. Dicho esto, ¿sabrás lo suficiente cómo para llevarte el premio al que más sabe de embalses?");
    
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
    
    printf("\n joe :(");
    
    return 0;
    
    }
    
    else{
        
        return 0;
        
    }

    return 0;
}
//Final funciones del cuestionario

//Funciones de comparacion
//LISTA CUENCAS:

void nombres_cuencas_E(int vb, linea cuenca[]){
	
	int numc=0,i;//variables cuenca
for(i=0;i<vb;i++){
	if(strcmp(cuenca[i].cuenca_hidrografica,cuenca[i-1].cuenca_hidrografica)!=0){
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
		scanf("%i",&num_embalse);
		*l_r_embalse=129*12+ *num_embalse * 12;
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
int seleccion_anyo(int anyo){
	do {
		printf("\nIntroduce el anyo deseado 2012-2021.\n");
		scanf("%i",&anyo);
		if(anyo<2012||anyo>2021){
			("Anyo invalido, intentalo otra vez.\n");
		}
	}while(anyo<2012||anyo>2021);
}


//SELECCION MES:
int seleccion_mes(int mes){
	do {
		printf("\nIntroduce el mes deseado 1-12.\n");
		scanf("%i",&mes);
		if(mes<1||mes>12){
			("Anyo invalido, intentalo otra vez.\n");
		}
	}while(mes<1||mes>12);
}


//MESES_NOMBRES

	char *mes_nom[] = {"enero", "febrero", "marzo", "abril", "mayo", "junio", "julio", 
						"agosto", "septiembre", "octubre", "noviembre", "diciembre"};


char *meses_nombre(int mes){
	return mes_nom[mes-1];
	
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
			printf("La capacidad del primer embalse %s en %s del %i es %.2f.\n",cuenca[l_r_embalse-1].embalse_nombre,meses_nombre(mes),anyo,cuenca[l_r_embalse-13+mes].dosmildoce);
			printf("La capacidad del segundo embalse %s en %s del %i es %.2f.\n",cuenca[l_r_embalse2-1].embalse_nombre,meses_nombre(mes),anyo,cuenca[l_r_embalse2-13+mes].dosmildoce);
			if(cuenca[l_r_embalse2-13+mes].dosmildoce>cuenca[l_r_embalse-13+mes].dosmildoce){
			   max_mes=	cuenca[l_r_embalse2-13+mes].dosmildoce;
			   min_mes=cuenca[l_r_embalse-13+mes].dosmildoce;
			   printf("%s sobrepaso en %.2f hm^3 a %s en %s.\n", cuenca[l_r_embalse2-1].embalse_nombre,res_mes=max_mes-min_mes,cuenca[l_r_embalse-1].embalse_nombre,meses_nombre(mes));}
	        if(cuenca[l_r_embalse-13+mes].dosmildoce>cuenca[l_r_embalse2-13+mes].dosmildoce){
			   max_mes=	cuenca[l_r_embalse-13+mes].dosmildoce;
			   min_mes=cuenca[l_r_embalse2-13+mes].dosmildoce;
			   printf("%s sobrepaso en %.2f hm^3 a %s en %s.\n", cuenca[l_r_embalse-1].embalse_nombre,res_mes=max_mes-min_mes,cuenca[l_r_embalse2-1].embalse_nombre,meses_nombre(mes));}
	        if(cuenca[l_r_embalse2-13+mes].dosmildoce==cuenca[l_r_embalse-13+mes].dosmildoce){
			   printf("%s y %s tinen la misma capacidad en %s.\n", cuenca[l_r_embalse2-1].embalse_nombre,cuenca[l_r_embalse-1].embalse_nombre,meses_nombre(mes));}
			break;
		case(2013):
			printf("La capacidad del primer embalse %s en %s del %i es %.2f.\n",cuenca[l_r_embalse-1].embalse_nombre,meses_nombre(mes),anyo,cuenca[l_r_embalse-13+mes].dosmiltrece);
			printf("La capacidad del segundo embalse %s en %s del %i es %.2f.\n",cuenca[l_r_embalse2-1].embalse_nombre,meses_nombre(mes),anyo,cuenca[l_r_embalse2-13+mes].dosmiltrece);
			if(cuenca[l_r_embalse2-13+mes].dosmiltrece>cuenca[l_r_embalse-13+mes].dosmiltrece){
			   max_mes=	cuenca[l_r_embalse2-13+mes].dosmiltrece;
			   min_mes=cuenca[l_r_embalse-13+mes].dosmiltrece;
			   printf("%s sobrepaso en %.2f hm^3 a %s en %s.\n", cuenca[l_r_embalse2-1].embalse_nombre,res_mes=max_mes-min_mes,cuenca[l_r_embalse-1].embalse_nombre,meses_nombre(mes));}
	        if(cuenca[l_r_embalse-13+mes].dosmiltrece>cuenca[l_r_embalse2-13+mes].dosmiltrece){
			   max_mes=	cuenca[l_r_embalse-13+mes].dosmiltrece;
			   min_mes=cuenca[l_r_embalse2-13+mes].dosmiltrece;
			   printf("%s sobrepaso en %.2f hm^3 a %s en %s.\n", cuenca[l_r_embalse-1].embalse_nombre,res_mes=max_mes-min_mes,cuenca[l_r_embalse2-1].embalse_nombre,meses_nombre(mes));}
	        if(cuenca[l_r_embalse2-13+mes].dosmiltrece==cuenca[l_r_embalse-13+mes].dosmiltrece){
			   printf("%s y %s tinen la misma capacidad en %s.\n", cuenca[l_r_embalse2-1].embalse_nombre,cuenca[l_r_embalse-1].embalse_nombre,meses_nombre(mes));}
			break;
		case(2014):
			printf("La capacidad del primer embalse %s en %s del %i es %.2f.\n",cuenca[l_r_embalse-1].embalse_nombre,meses_nombre(mes),anyo,cuenca[l_r_embalse-13+mes].dosmilcatorce);
			printf("La capacidad del segundo embalse %s en %s del %i es %.2f.\n",cuenca[l_r_embalse2-1].embalse_nombre,meses_nombre(mes),anyo,cuenca[l_r_embalse2-13+mes].dosmilcatorce);
			if(cuenca[l_r_embalse2-13+mes].dosmilcatorce>cuenca[l_r_embalse-13+mes].dosmilcatorce){
			   max_mes=	cuenca[l_r_embalse2-13+mes].dosmilcatorce;
			   min_mes=cuenca[l_r_embalse-13+mes].dosmilcatorce;
			   printf("%s sobrepaso en %.2f hm^3 a %s en %s.\n", cuenca[l_r_embalse2-1].embalse_nombre,res_mes=max_mes-min_mes,cuenca[l_r_embalse-1].embalse_nombre,meses_nombre(mes));}
	        if(cuenca[l_r_embalse-13+mes].dosmilcatorce>cuenca[l_r_embalse2-13+mes].dosmilcatorce){
			   max_mes=	cuenca[l_r_embalse-13+mes].dosmilcatorce;
			   min_mes=cuenca[l_r_embalse2-13+mes].dosmilcatorce;
			   printf("%s sobrepaso en %.2f hm^3 a %s en %s.\n", cuenca[l_r_embalse-1].embalse_nombre,res_mes=max_mes-min_mes,cuenca[l_r_embalse2-1].embalse_nombre,meses_nombre(mes));}
	        if(cuenca[l_r_embalse2-13+mes].dosmilcatorce==cuenca[l_r_embalse-13+mes].dosmilcatorce){
			   printf("%s y %s tinen la misma capacidad en %s.\n", cuenca[l_r_embalse2-1].embalse_nombre,cuenca[l_r_embalse-1].embalse_nombre,meses_nombre(mes));}
			break;
		case(2015):
			printf("La capacidad del primer embalse %s en %s del %i es %.2f.\n",cuenca[l_r_embalse-1].embalse_nombre,meses_nombre(mes),anyo,cuenca[l_r_embalse-13+mes].dosmilquince);
			printf("La capacidad del segundo embalse %s en %s del %i es %.2f.\n",cuenca[l_r_embalse2-1].embalse_nombre,meses_nombre(mes),anyo,cuenca[l_r_embalse2-13+mes].dosmilquince);
			if(cuenca[l_r_embalse2-13+mes].dosmilquince>cuenca[l_r_embalse-13+mes].dosmilquince){
			   max_mes=	cuenca[l_r_embalse2-13+mes].dosmilquince;
			   min_mes=cuenca[l_r_embalse-13+mes].dosmilquince;
			   printf("%s sobrepaso en %.2f hm^3 a %s en %s.\n", cuenca[l_r_embalse2-1].embalse_nombre,res_mes=max_mes-min_mes,cuenca[l_r_embalse-1].embalse_nombre,meses_nombre(mes));}
	        if(cuenca[l_r_embalse-13+mes].dosmilquince>cuenca[l_r_embalse2-13+mes].dosmilquince){
			   max_mes=	cuenca[l_r_embalse-13+mes].dosmilquince;
			   min_mes=cuenca[l_r_embalse2-13+mes].dosmilquince;
			   printf("%s sobrepaso en %.2f hm^3 a %s en %s.\n", cuenca[l_r_embalse-1].embalse_nombre,res_mes=max_mes-min_mes,cuenca[l_r_embalse2-1].embalse_nombre,meses_nombre(mes));}
	        if(cuenca[l_r_embalse2-13+mes].dosmilquince==cuenca[l_r_embalse-13+mes].dosmilquince){
			   printf("%s y %s tinen la misma capacidad en %s.\n", cuenca[l_r_embalse2-1].embalse_nombre,cuenca[l_r_embalse-1].embalse_nombre,meses_nombre(mes));}
			break;
		case(2016):
			printf("La capacidad del primer embalse %s en %s del %i es %.2f.\n",cuenca[l_r_embalse-1].embalse_nombre,meses_nombre(mes),anyo,cuenca[l_r_embalse-13+mes].dosmildieciseis);
			printf("La capacidad del segundo embalse %s en %s del %i es %.2f.\n",cuenca[l_r_embalse2-1].embalse_nombre,meses_nombre(mes),anyo,cuenca[l_r_embalse2-13+mes].dosmildieciseis);
			if(cuenca[l_r_embalse2-13+mes].dosmildieciseis>cuenca[l_r_embalse-13+mes].dosmildieciseis){
			   max_mes=	cuenca[l_r_embalse2-13+mes].dosmildieciseis;
			   min_mes=cuenca[l_r_embalse-13+mes].dosmildieciseis;
			   printf("%s sobrepaso en %.2f hm^3 a %s en %s.\n", cuenca[l_r_embalse2-1].embalse_nombre,res_mes=max_mes-min_mes,cuenca[l_r_embalse-1].embalse_nombre,meses_nombre(mes));}
	        if(cuenca[l_r_embalse-13+mes].dosmildieciseis>cuenca[l_r_embalse2-13+mes].dosmildieciseis){
			   max_mes=	cuenca[l_r_embalse-13+mes].dosmildieciseis;
			   min_mes=cuenca[l_r_embalse2-13+mes].dosmildieciseis;
			   printf("%s sobrepaso en %.2f hm^3 a %s en %s.\n", cuenca[l_r_embalse-1].embalse_nombre,res_mes=max_mes-min_mes,cuenca[l_r_embalse2-1].embalse_nombre,meses_nombre(mes));}
	        if(cuenca[l_r_embalse2-13+mes].dosmildieciseis==cuenca[l_r_embalse-13+mes].dosmildieciseis){
			   printf("%s y %s tinen la misma capacidad en %s.\n", cuenca[l_r_embalse2-1].embalse_nombre,cuenca[l_r_embalse-1].embalse_nombre,meses_nombre(mes));}
			break;
		case(2017):
			printf("La capacidad del primer embalse %s en %s del %i es %.2f.\n",cuenca[l_r_embalse-1].embalse_nombre,meses_nombre(mes),anyo,cuenca[l_r_embalse-13+mes].dosmildiecisiete);
			printf("La capacidad del segundo embalse %s en %s del %i es %.2f.\n",cuenca[l_r_embalse2-1].embalse_nombre,meses_nombre(mes),anyo,cuenca[l_r_embalse2-13+mes].dosmildiecisiete);
			if(cuenca[l_r_embalse2-13+mes].dosmildiecisiete>cuenca[l_r_embalse-13+mes].dosmildiecisiete){
			   max_mes=	cuenca[l_r_embalse2-13+mes].dosmildiecisiete;
			   min_mes=cuenca[l_r_embalse-13+mes].dosmildiecisiete;
			   printf("%s sobrepaso en %.2f hm^3 a %s en %s.\n", cuenca[l_r_embalse2-1].embalse_nombre,res_mes=max_mes-min_mes,cuenca[l_r_embalse-1].embalse_nombre,meses_nombre(mes));}
	        if(cuenca[l_r_embalse-13+mes].dosmildiecisiete>cuenca[l_r_embalse2-13+mes].dosmildiecisiete){
			   max_mes=	cuenca[l_r_embalse-13+mes].dosmildiecisiete;
			   min_mes=cuenca[l_r_embalse2-13+mes].dosmildiecisiete;
			   printf("%s sobrepaso en %.2f hm^3 a %s en %s.\n", cuenca[l_r_embalse-1].embalse_nombre,res_mes=max_mes-min_mes,cuenca[l_r_embalse2-1].embalse_nombre,meses_nombre(mes));}
	        if(cuenca[l_r_embalse2-13+mes].dosmildiecisiete==cuenca[l_r_embalse-13+mes].dosmildiecisiete){
			   printf("%s y %s tinen la misma capacidad en %s.\n", cuenca[l_r_embalse2-1].embalse_nombre,cuenca[l_r_embalse-1].embalse_nombre,meses_nombre(mes));}
			break;
		case(2018):
			printf("La capacidad del primer embalse %s en %s del %i es %.2f.\n",cuenca[l_r_embalse-1].embalse_nombre,meses_nombre(mes),anyo,cuenca[l_r_embalse-13+mes].dosmildieciocho);
			printf("La capacidad del segundo embalse %s en %s del %i es %.2f.\n",cuenca[l_r_embalse2-1].embalse_nombre,meses_nombre(mes),anyo,cuenca[l_r_embalse2-13+mes].dosmildieciocho);
			if(cuenca[l_r_embalse2-13+mes].dosmildieciocho>cuenca[l_r_embalse-13+mes].dosmildieciocho){
			   max_mes=	cuenca[l_r_embalse2-13+mes].dosmildieciocho;
			   min_mes=cuenca[l_r_embalse-13+mes].dosmildieciocho;
			   printf("%s sobrepaso en %.2f hm^3 a %s en %s.\n", cuenca[l_r_embalse2-1].embalse_nombre,res_mes=max_mes-min_mes,cuenca[l_r_embalse-1].embalse_nombre,meses_nombre(mes));}
	        if(cuenca[l_r_embalse-13+mes].dosmildieciocho>cuenca[l_r_embalse2-13+mes].dosmildieciocho){
			   max_mes=	cuenca[l_r_embalse-13+mes].dosmildieciocho;
			   min_mes=cuenca[l_r_embalse2-13+mes].dosmildieciocho;
			   printf("%s sobrepaso en %.2f hm^3 a %s en %s.\n", cuenca[l_r_embalse-1].embalse_nombre,res_mes=max_mes-min_mes,cuenca[l_r_embalse2-1].embalse_nombre,meses_nombre(mes));}
	        if(cuenca[l_r_embalse2-13+mes].dosmildieciocho==cuenca[l_r_embalse-13+mes].dosmildieciocho){
			   printf("%s y %s tinen la misma capacidad en %s.\n", cuenca[l_r_embalse2-1].embalse_nombre,cuenca[l_r_embalse-1].embalse_nombre,meses_nombre(mes));}
			break;
		case(2019):
			printf("La capacidad del primer embalse %s en %s del %i es %.2f.\n",cuenca[l_r_embalse-1].embalse_nombre,meses_nombre(mes),anyo,cuenca[l_r_embalse-13+mes].dosmildiecinueve);
			printf("La capacidad del segundo embalse %s en %s del %i es %.2f.\n",cuenca[l_r_embalse2-1].embalse_nombre,meses_nombre(mes),anyo,cuenca[l_r_embalse2-13+mes].dosmildiecinueve);
			if(cuenca[l_r_embalse2-13+mes].dosmildiecinueve>cuenca[l_r_embalse-13+mes].dosmildiecinueve){
			   max_mes=	cuenca[l_r_embalse2-13+mes].dosmildiecinueve;
			   min_mes=cuenca[l_r_embalse-13+mes].dosmildiecinueve;
			   printf("%s sobrepaso en %.2f hm^3 a %s en %s.\n", cuenca[l_r_embalse2-1].embalse_nombre,res_mes=max_mes-min_mes,cuenca[l_r_embalse-1].embalse_nombre,meses_nombre(mes));}
	        if(cuenca[l_r_embalse-13+mes].dosmildiecinueve>cuenca[l_r_embalse2-13+mes].dosmildiecinueve){
			   max_mes=	cuenca[l_r_embalse-13+mes].dosmildiecinueve;
			   min_mes=cuenca[l_r_embalse2-13+mes].dosmildiecinueve;
			   printf("%s sobrepaso en %.2f hm^3 a %s en %s.\n", cuenca[l_r_embalse-1].embalse_nombre,res_mes=max_mes-min_mes,cuenca[l_r_embalse2-1].embalse_nombre,meses_nombre(mes));}
	        if(cuenca[l_r_embalse2-13+mes].dosmildiecinueve==cuenca[l_r_embalse-13+mes].dosmildiecinueve){
			   printf("%s y %s tinen la misma capacidad en %s.\n", cuenca[l_r_embalse2-1].embalse_nombre,cuenca[l_r_embalse-1].embalse_nombre,meses_nombre(mes));}
			break;
		case(2020):
			printf("La capacidad del primer embalse %s en %s del %i es %.2f.\n",cuenca[l_r_embalse-1].embalse_nombre,meses_nombre(mes),anyo,cuenca[l_r_embalse-13+mes].dosmilveinte);
			printf("La capacidad del segundo embalse %s en %s del %i es %.2f.\n",cuenca[l_r_embalse2-1].embalse_nombre,meses_nombre(mes),anyo,cuenca[l_r_embalse2-13+mes].dosmilveinte);
			if(cuenca[l_r_embalse2-13+mes].dosmilveinte>cuenca[l_r_embalse-13+mes].dosmilveinte){
			   max_mes=	cuenca[l_r_embalse2-13+mes].dosmilveinte;
			   min_mes=cuenca[l_r_embalse-13+mes].dosmilveinte;
			   printf("%s sobrepaso en %.2f hm^3 a %s en %s.\n", cuenca[l_r_embalse2-1].embalse_nombre,res_mes=max_mes-min_mes,cuenca[l_r_embalse-1].embalse_nombre,meses_nombre(mes));}
	        if(cuenca[l_r_embalse-13+mes].dosmilveinte>cuenca[l_r_embalse2-13+mes].dosmilveinte){
			   max_mes=	cuenca[l_r_embalse-13+mes].dosmilveinte;
			   min_mes=cuenca[l_r_embalse2-13+mes].dosmilveinte;
			   printf("%s sobrepaso en %.2f hm^3 a %s en %s.\n", cuenca[l_r_embalse-1].embalse_nombre,res_mes=max_mes-min_mes,cuenca[l_r_embalse2-1].embalse_nombre,meses_nombre(mes));}
	        if(cuenca[l_r_embalse2-13+mes].dosmilveinte==cuenca[l_r_embalse-13+mes].dosmilveinte){
			   printf("%s y %s tinen la misma capacidad en %s.\n", cuenca[l_r_embalse2-1].embalse_nombre,cuenca[l_r_embalse-1].embalse_nombre,meses_nombre(mes));}
			break;
		case(2021):
			printf("La capacidad del primer embalse %s en %s del %i es %.2f.\n",cuenca[l_r_embalse-1].embalse_nombre,meses_nombre(mes),anyo,cuenca[l_r_embalse-13+mes].dosmilveintiuno);
			printf("La capacidad del segundo embalse %s en %s del %i es %.2f.\n",cuenca[l_r_embalse2-1].embalse_nombre,meses_nombre(mes),anyo,cuenca[l_r_embalse2-13+mes].dosmilveintiuno);
			if(cuenca[l_r_embalse2-13+mes].dosmildoce>cuenca[l_r_embalse-13+mes].dosmilveintiuno){
			   max_mes=	cuenca[l_r_embalse2-13+mes].dosmilveintiuno;
			   min_mes=cuenca[l_r_embalse-13+mes].dosmilveintiuno;
			   printf("%s sobrepaso en %.2f hm^3 a %s en %s.\n", cuenca[l_r_embalse2-1].embalse_nombre,res_mes=max_mes-min_mes,cuenca[l_r_embalse-1].embalse_nombre,meses_nombre(mes));}
	        if(cuenca[l_r_embalse-13+mes].dosmilveintiuno>cuenca[l_r_embalse2-13+mes].dosmilveintiuno){
			   max_mes=	cuenca[l_r_embalse-13+mes].dosmilveintiuno;
			   min_mes=cuenca[l_r_embalse2-13+mes].dosmilveintiuno;
			   printf("%s sobrepaso en %.2f hm^3 a %s en %s.\n", cuenca[l_r_embalse-1].embalse_nombre,res_mes=max_mes-min_mes,cuenca[l_r_embalse2-1].embalse_nombre,meses_nombre(mes));}
	        if(cuenca[l_r_embalse2-13+mes].dosmilveintiuno==cuenca[l_r_embalse-13+mes].dosmilveintiuno){
			   printf("%s y %s tinen la misma capacidad en %s.\n", cuenca[l_r_embalse2-1].embalse_nombre,cuenca[l_r_embalse-1].embalse_nombre,meses_nombre(mes));}
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
printf("La superficie del segundo embalse, %s, es %.2f.\n",cuenca[l_r_embalse2-1].embalse_nombre,comp[l_r_embalse2/12-1].superficie);
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
char cambios_espacios_embalses_E(linea cuenca [], int l_r_embalse, int l_r_embalse2){
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

char cambios_espacios_tipo_presa(DatosComparacion comp[], int l_r_embalse, int l_r_embalse2){
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

//Fin Funciones de comparación
//COMPARACION_MAIN
void comparacion(){
	//variables
int vb=0, vc=0, vco=0,i;//for y ficheros
char C_cuenca[2], C_cuenca2[2];
int num_cuenca,num_embalse,l_r_embalse;//embalse1
int num_cuenca2,num_embalse2,l_r_embalse2;//embalse2
int mes_anyo, anyo,mes;//fechas y meses
	
linea* cuenca= NULL;
Embalse* embalse= NULL; 
DatosComparacion* comp= NULL;

cuenca=(linea*)malloc(5000*sizeof(linea));
embalse=(Embalse*)malloc(500*sizeof(Embalse));
comp= (DatosComparacion*)malloc(500*sizeof(DatosComparacion));

if(!cuenca|| !embalse|| !comp){
	printf("Error al abrir la memoria.\n");
	return -1;

}
	
//Fich
FILE *base;
base=fopen("dataset.csv","r");
		if(base==NULL){
			printf("Error al abrir el fichero base.\n");
			return -1;
		}
FILE *capacidad;
capacidad=fopen("Embalses_capacidad.txt","r");
	    if(capacidad==NULL){
			printf("Error al abrir el fichero de capacidad.\n");
			return -1;
		}
FILE *F_comparacion;
F_comparacion=fopen("comparacion2.txt","r");
	    if(F_comparacion==NULL){
			printf("Error al abrir el fichero de comparación.\n");
			return -1;
		}

	
//
	
fseek(base,90,SEEK_SET);
	while (fscanf(base, "%[^,],%[^,],%i,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f\n", cuenca[vb].cuenca_hidrografica , cuenca[vb].embalse_nombre , &cuenca[vb].mes , &cuenca[vb].dosmildoce, &cuenca[vb].dosmiltrece, &cuenca[vb].dosmilcatorce, &cuenca[vb].dosmilquince, &cuenca[vb].dosmildieciseis, &cuenca[vb].dosmildiecisiete, &cuenca[vb].dosmildieciocho,  &cuenca[vb].dosmildiecinueve,  &cuenca[vb].dosmilveinte,  &cuenca[vb].dosmilveintiuno ) != EOF)
	{ vb++;
	}
	while(fscanf(capacidad,"%s\t%f\n",embalse[vc].embalse_nom,&embalse[vc].etotal)!=EOF){
	
		vc++;
	}
while(fscanf(F_comparacion,"%99[^,],%f,%99[^,],%4[^,],%4[^,],%4[^,],%4[^,],%4[^,],%4[^,],%4[^,],%4[^,],%4[^\n]\n",comp[vco].nombre_embalse,&comp[vco].superficie,comp[vco].tipo_presa,comp[vco].uso_abastecimiento,comp[vco].uso_riego,comp[vco].uso_electricidad,comp[vco].uso_industrial,comp[vco].uso_pesca,comp[vco].uso_navegacion,comp[vco].uso_banyo,comp[vco].uso_picnic,comp[vco].uso_restaurante)!=EOF){
	    vco++;
	}
	

do{	
//LISTA CUENCAS
nombres_cuencas_E(vb,cuenca);
	
//SELECCION CUENCA
num_cuenca=seleccion_cuenca_1(num_cuenca, C_cuenca);

//SELECCION EMBALSE
nombreseleccion_embalse_1(num_cuenca,cuenca, &num_embalse, &l_r_embalse);

//2 LISTA CUENCAS:
nombres_cuencas_E(vb,cuenca);

//SELECCION 2 CUENCA:
num_cuenca2=seleccion_cuenca_2(num_cuenca2, C_cuenca2);

//SELECCION 2 EMBALSE
nombreseleccion_embalse_2(num_cuenca2,cuenca, &num_embalse2, &l_r_embalse2);

if(l_r_embalse==l_r_embalse2){
	printf("\nHas elegido el mismo embalse, no se puede hacer la comparacion. Intentelo de nuevo.\n");
}

}while(l_r_embalse==l_r_embalse2);

cambios_espacios_embalses_E(cuenca,l_r_embalse,l_r_embalse2);
cambios_espacios_tipo_presa (comp,l_r_embalse,l_r_embalse2);

	printf("\nEl primer embalse elegido es %s\n", cuenca[l_r_embalse-1].embalse_nombre);
	printf("El segundo embalse elegido es %s\n", cuenca[l_r_embalse2-1].embalse_nombre);

//TIPO COMPARACION
mes_anyo=tipo_comparacion(mes_anyo);

//COMPARACION SEGUN AÑO:
if(mes_anyo==1){
	anyo=seleccion_anyo(anyo);
	comparacion_anyo(mes_anyo,anyo,l_r_embalse,l_r_embalse2,cuenca);
}

//COMPARACION SEGUN MES:
if(mes_anyo==2){
	anyo=seleccion_anyo(anyo);
	mes=seleccion_mes(mes);
    comparacion_mes(mes_anyo,anyo,mes,l_r_embalse,l_r_embalse2,cuenca);
}

//CAPACIDAD MAXIMA:
capacidad_max(l_r_embalse,l_r_embalse2,cuenca,embalse);

//SUPERFICIE
superficie(l_r_embalse, l_r_embalse2,cuenca,comp);

//TIPO DE EMBALSE
tipo_embalse(comp,l_r_embalse,l_r_embalse2,cuenca);

//USO
uso_embalse(comp,l_r_embalse,l_r_embalse2,cuenca);

fclose(base);
fclose(capacidad);
fclose(F_comparacion);
free(cuenca);
free(embalse);
free(comp);
}
//FIN_COMPARACION_MAIN
