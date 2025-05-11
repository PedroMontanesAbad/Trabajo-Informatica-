
#include "lib.h"

int main(void)//system cls importantes antes de cada funcion
{
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

		//EL PUNTERO AVANZA LA PRIMERA LINEA QUE NO CONTIENE DATOS:
		fseek(tabla, 90, SEEK_SET);
	
	while (fscanf(tabla, "%[^,],%[^,],%i,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f\n", cuenca[j].cuenca_hidrografica, cuenca[j].embalse_nombre, &cuenca[j].mes, &cuenca[j].dosmildoce, &cuenca[j].dosmiltrece, &cuenca[j].dosmilcatorce, &cuenca[j].dosmilquince, &cuenca[j].dosmildieciseis, &cuenca[j].dosmildiecisiete, &cuenca[j].dosmildieciocho, &cuenca[j].dosmildiecinueve, &cuenca[j].dosmilveinte, &cuenca[j].dosmilveintiuno) != EOF)
	{

		//printf("Linea %i:\n", j);
		//printf("%[^,],%[^,],%i,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f\n", cuenca[j].cuenca_hidrografica , cuenca[j].embalse_nombre , cuenca[j].mes , cuenca[j].dosmildoce, cuenca[j].dosmiltrece, cuenca[j].dosmilcatorce, cuenca[j].dosmilquince, cuenca[j].dosmildieciseis, cuenca[j].dosmildiecisiete, cuenca[j].dosmildieciocho,  cuenca[j].dosmildiecinueve,  cuenca[j].dosmilveinte,  cuenca[j].dosmilveintiuno );

		j++;
	}

	//CREAMOS VECTOR AUXILIAR QUE ALMACENE LA POSICION DE LAS CUENCAS:
	
	for (i = 0;i < j;i++) {

		if (strcmp(cuenca[i].cuenca_hidrografica, cuenca[i - 1].cuenca_hidrografica) != 0) {

			posiciones_cuencas[f] = i;
			//printf("\ni es %i",posiciones_cuencas[f]);
			f++;
		}
	}

	//añadimos la número 16

	posiciones_cuencas[f] = j;

	int n;
	char c, basura;
	system("color 0A");

	do
	{
		system("cls");
		printf("\a");
		gotoxy(80, 2);
		Fecha();
		DibujarMenu();
		Texto0();
		//seguro por si se escribe una letra
		scanf_s("%c", &c, 1);
		system("cls");
		n = c - '0';


		switch (n)
		{
		case 1:
			do
			{
				cuadradosDosPorDos();
				Texto1();
				scanf_s("%c", &c, 1);
				
				n = c - '0';
				
				if (n == 3)
				{
					n = 0;
					break;

				}
				else if (n == 4)
				{
					system("cls");
					exit(-1);
				}
				
			} while (n != 5);

			break;
		case 2:
			do
			{
				DibujarMenu();
				Texto2();

				scanf_s("%c", &c, 1);
				n = c - '0';

				if (n == 1)
				{
					

				}
				if (n == 2)
				{
					system("cls");
					porcentajes_main(j,cuencas[], posiciones_cuencas[]);
					system("pause");
				}
				if (n == 3)
				{
					system("cls");
					comparacion_principal(j,cuencas[], posiciones_cuencas[]);
					system("pause");
				}
				if (n == 4)
				{
					system("cls");
					maxymin_main(j,cuencas[], posiciones_cuencas[], maxmin[], C_cuenca[]);

				}

				else if (n == 5)
				{
					n = 0;
					break;

				}
				else if (n == 6)
				{
					system("cls");
					exit(-1);
				}
				system("cls");
			} while (n != 5);

			break;
		case 3://cuestionario
			cuestionario();
			system("pause");
			n=7; //Cuando hace el break sigue haciendo el bucle
			system("cls");
			
			break;
			
		case 4://palabra del dia
	
			palbra_dia_main();
			system("pause");
			n = 7;
			system("cls");
			break;
				
		case 5://AJUSTES
			do
			{
				cuadradosDosPorDos();
				Texto5();
				scanf_s("%c", &c, 1);
				n = c - '0';
				


				if (n == 1)
				system("color 46");
				if (n == 5)
				system("color 56");
				if (n == 6)
				system("color 97");
				if (n == 7)
				system("color 65");
				if (n == 8)
				system("color 80");
					
				else if (n == 2)
				{
					system("cls");
					donut();
					//system("pause");
			//pause solo necesario para los printf, para funciones no parece ser necesarios
				}
				else if (n == 3)
				{
					n = 0;
					break;

				}
				else if (n == 4)
				{
					system("cls");
					exit(-1);
				}
				system("cls");
			} while (n != 4);

			break;
		case 6:
			exit(-1);
		default:
			break;

		}
	} while (n < 1 || n>6);

	scanf_s("%c", &c, 1);	
	n = c - '0';


	return 0;
}
