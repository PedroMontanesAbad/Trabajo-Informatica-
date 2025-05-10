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
			printf("EMBALSES");
			gotoxy(x, 14);
			printf("Press ( 1 )");

		}
		////// Segundo cuadrado/////
		{
			x = 61;
			y = 9;
			gotoxy(x, y);
			printf("CUENCAS");
			gotoxy(x, 14);
			printf("Press ( 2 )");

		}
		//// Tercer cuadrado////
		{
			x = 20;
			y = 16;
			gotoxy(x, y);
			printf("ANALISIS DE DATOS");
			gotoxy(x, 21);
			printf("Press ( 3 )");

		}
		//// Cuarto cuadrado////
		{
			x = 61;
			y = 16;
			gotoxy(x, y);
			printf("ESTADISTICA");
			gotoxy(x, 21);
			printf("Press ( 4 )");

		}
		//// 5 cuadrado////
		{
			x = 20;
			y = 23;
			gotoxy(x, y);
			printf("AJUSTES");
			gotoxy(x, 28);
			printf("Press ( 5 )");

		}
		//// 6 cuadrado////
		{
			x = 61;
			y = 23;
			gotoxy(x, y);
			printf("Cerrar programa");
			gotoxy(x, 28);
			printf("Press ( 6 )");

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
			printf("Enter ( 1 )");

			//Segundo Cuadrado
			gotoxy(61, 10);
			printf("-----------------");
			gotoxy(61, 18);
			printf("Enter ( 2 )");

			//Tercer Cuadrado
			gotoxy(20, 20);
			printf("Volver al menu");
			gotoxy(20, 28);
			printf("Enter ( 3 )");

			//Cuarto Cuadrado
			gotoxy(61, 20);
			printf("Salir");
			gotoxy(61, 28);
			printf("Enter ( 4 )");

			//TITULO
			gotoxy(53, 4);
			printf("-------------");
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
		printf("CUENCAS");
	}


	//Textos
	{
		////Texto Primer Cuadrado////
		{
			x = 20;
			y = 9;
			gotoxy(x, y);
			printf("Buscar datos");
			gotoxy(x, 14);
			printf("Press ( 1 )");
		}
		////// Segundo cuadrado/////
		{
			x = 61;
			y = 9;
			gotoxy(x, y);
			printf("-----------------");
			gotoxy(x, 14);
			printf("Press ( 2 )");
		}
		//// Tercer cuadrado////
		{
			x = 20;
			y = 16;
			gotoxy(x, y);
			printf("-----------------");
			gotoxy(x, 21);
			printf("Press ( 3 )");

		}
		//// Cuarto cuadrado////
		{
			x = 61;
			y = 16;
			gotoxy(x, y);
			printf("-----------------");
			gotoxy(x, 21);
			printf("Press ( 4 )");

		}
		//// 5 cuadrado////
		{
			x = 20;
			y = 23;
			gotoxy(x, y);
			printf("Volver al menu");
			gotoxy(x, 28);
			printf("Press ( 5 )");

		}
		//// 6 cuadrado////
		{
			x = 61;
			y = 23;
			gotoxy(x, y);
			printf("Cerrar programa");
			gotoxy(x, 28);
			printf("Press ( 6 )");

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
		printf("ANALISIS DE DATOS");
	}


	//Textos
	{
		////Texto Primer Cuadrado////
		{
			x = 20;
			y = 9;
			gotoxy(x, y);
			printf("Calcular medias");
			gotoxy(x, 14);
			printf("Press ( 1 )");

		}
		////// Segundo cuadrado/////
		{
			x = 61;
			y = 9;
			gotoxy(x, y);
			printf("-----------------");
			gotoxy(x, 14);
			printf("Press ( 2 )");
		}
		//// Tercer cuadrado////
		{
			x = 20;
			y = 16;
			gotoxy(x, y);
			printf("-----------------");
			gotoxy(x, 21);
			printf("Press ( 3 )");

		}
		//// Cuarto cuadrado////
		{
			x = 61;
			y = 16;
			gotoxy(x, y);
			printf("-----------------");
			gotoxy(x, 21);
			printf("Press ( 4 )");

		}
		//// 5 cuadrado////
		{
			x = 20;
			y = 23;
			gotoxy(x, y);
			printf("Volver al menu");
			gotoxy(x, 28);
			printf("Press ( 5 )");

		}
		//// 6 cuadrado////
		{
			x = 61;
			y = 23;
			gotoxy(x, y);
			printf("Cerrar programa");
			gotoxy(x, 28);
			printf("Press ( 6 )");

		}
	}

	gotoxy(55, 7);
	printf("Ir a: ");
	gotoxy(65, 7);
}

//Texto4
void Texto4()
{
	//Titulo// 
	{
		gotoxy(55, 4);
		printf("DATOS ESTADISTICOS");
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
			printf("Press ( 1 )");

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
			printf("Press ( 2 )");

		}
		//// Tercer cuadrado////
		{
			x = 20;
			y = 16;
			gotoxy(x, y);
			printf("-----------------");
			gotoxy(x, 21);
			printf("Press ( 3 )");

		}
		//// Cuarto cuadrado////
		{
			x = 61;
			y = 16;
			gotoxy(x, y);
			printf("-----------------");
			gotoxy(x, 21);
			printf("Press ( 4 )");

		}
		//// 5 cuadrado////
		{
			x = 20;
			y = 23;
			gotoxy(x, y);
			printf("Volver al menu");
			gotoxy(x, 28);
			printf("Press ( 5 )");

		}
		//// 6 cuadrado////
		{
			x = 61;
			y = 23;
			gotoxy(x, y);
			printf("Cerrar programa");
			gotoxy(x, 28);
			printf("Press ( 6 )");

		}
	}

	gotoxy(55, 7);
	printf("Ir a:");
	gotoxy(65, 7);
}

//Texto5
void Texto5()
{
	//Titulo// 
	{
		gotoxy(55, 4);
		printf("EASTER EGGS");
	}


	//Textos
	{
		////Texto Primer Cuadrado////
		{
			x = 20;
			y = 9;
			gotoxy(x, y);
			printf("MODO DIABLO??:1");
			x = 20;
			y = 10;
			gotoxy(x, y);
			printf("Color Violeta:12");
			x = 20;
			y = 11;
			gotoxy(x, y);
			printf("Color azul:13");
			gotoxy(x, 14);
			printf("");

		}
		////// Segundo cuadrado/////
		{
			x = 61;
			y = 9;
			gotoxy(x, y);
			printf("sorpresa");
			gotoxy(x, 14);
			printf("Press ( 2 )");

		}
		//// Tercer cuadrado////
		{
			x = 20;
			y = 16;
			gotoxy(x, y);
			printf("?????????");
			gotoxy(x, 21);
			printf("Press ( 3 )");

		}
		//// Cuarto cuadrado////
		{
			x = 61;
			y = 16;
			gotoxy(x, y);
			printf("¿¿¿¿¿¿¿¿¿¿¡");
			gotoxy(x, 21);
			printf("Press ( 4 )");

		}
		//// 5 cuadrado////
		{
			x = 20;
			y = 23;
			gotoxy(x, y);
			printf("Volver al menu");
			gotoxy(x, 28);
			printf("Press ( 5 )");

		}
		//// 6 cuadrado////
		{
			x = 61;
			y = 23;
			gotoxy(x, y);
			printf("Salir del programa");
			gotoxy(x, 28);
			printf("Press ( 6 )");

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

void CuatroCuadrados()
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
			printf("Enter ( 1 )");

			//Segundo Cuadrado
			gotoxy(61, 10);
			printf("-----------------");
			gotoxy(61, 18);
			printf("Enter ( 2 )");

			//Tercer Cuadrado
			gotoxy(20, 20);
			printf("-----------------");
			gotoxy(20, 28);
			printf("Enter ( 3 )");

			//Cuarto Cuadrado
			gotoxy(61, 20);
			printf("-----------------");
			gotoxy(61, 28);
			printf("Enter ( 4 )");

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
//Final funciones del cuestionario
