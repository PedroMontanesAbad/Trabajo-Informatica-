
#include "TF.h"



int main(void)//system cls importantes antes de cada funcion
{
	char C_cuenca[2], C_embalse[2], C_mes[2], C_anyo[5], cambio[100];

	int i, j = 0, anyo = 0, num_cuenca = 0, num_embalse = 0, f = 0;

	int maxmin[4];

	int posiciones_cuencas[16];

	float media;

	linea cuenca[4236];

	
	FILE* tabla;
	tabla = fopen("texto_proyecto.csv", "r");
	if (tabla == NULL) // Si el resultado es NULL mensaje de error
	{
		printf("Error al abrir el fichero.\n");
		return -1;
	}
	//Poner que el puntero avance una linea
	fseek(tabla, 90, SEEK_SET);
	while (fscanf(tabla, "%[^,],%[^,],%i,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f\n", cuenca[j].cuenca_hidrografica, cuenca[j].embalse_nombre, &cuenca[j].mes, &cuenca[j].dosmildoce, &cuenca[j].dosmiltrece, &cuenca[j].dosmilcatorce, &cuenca[j].dosmilquince, &cuenca[j].dosmildieciseis, &cuenca[j].dosmildiecisiete, &cuenca[j].dosmildieciocho, &cuenca[j].dosmildiecinueve, &cuenca[j].dosmilveinte, &cuenca[j].dosmilveintiuno) != EOF)
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
	posiciones_cuencas[f] = j; //Añadimos un ultimo valor señalando el fin de los datos
	fclose(tabla);
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
				
				if (n == 1) {
					system("cls");
					nombres_cuencas_p(j, cuenca);
					system("pause");
					system("cls");
				}
				if (n == 2)
				{
					system("cls");
					nombres_embalses_p(j, cuenca);
					system("pause");
					system("cls");

				}

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
					system("cls");
					medias_main();
					system("pause");
				}
				if (n == 2)
				{
					system("cls");
					porcentajes_main();
					system("pause");
					
				}
				if (n == 3)
				{
					system("cls");
					comparacion_principal();
					system("pause");
				}
				if (n == 4)
				{
					system("cls");
					maxymin_main();
					system("pause");

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
			printf("\n");
			system("pause");
			n = 7;
			system("cls");
			break;
			
		case 4://palabra del dia
			palabra_dia_main();
			printf("\n");
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
				if (n == 2)
					system("color 56");
				if (n == 5)
					system("color 97");
				if (n == 6)
					system("color 65");
				if (n == 7)
					system("color 80");

				else if (n == 8)
				{
					system("cls");
					donut();

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

