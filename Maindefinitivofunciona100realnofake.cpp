
#include "lib.h"

int main(void)//system cls importantes antes de cada funcion
{

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
					//maxymin_main(j,cuencas[], posiciones_cuencas[], maxmin[], C_cuenca[]);

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
				if (n == 7)
					system("color 56");
				if (n == 8)
					system("color 97");
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
