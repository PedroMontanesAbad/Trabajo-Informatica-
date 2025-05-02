#include <time.h>

typedef struct{
	char posicion[365];
}linea_p;

//FECHA ACTUAL 

struct tm* fecha_actual();

//DÍA DEL AÑO

int dia_anyo (struct tm* fecha);

//PALABRA DEL DÍA

void palabra_d (int dia, linea_p digitos[]);
