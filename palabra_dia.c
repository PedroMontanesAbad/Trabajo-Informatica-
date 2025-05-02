#include <stdio.h>
#include <time.h>
#include "palabra_dia.h"

//FECHA ACTUAL DESDE 1970

struct tm* fecha_actual(){
	
	time_t tiempo = time(NULL); // ALMACENAMOS SEGUNDOS TRANSCURRIDOS DESDE 1970 EN tiempo

	return localtime(&tiempo); //LOCATIME TOMA LA DIRECCIÓN DE TIEMPO Y DEVUELVE UN PUNTERO DE LA ESTRUCTURA struct tm (ya creada)
}

//OBTENEMOS EL DÍA DEL AÑO

int dia_anyo (struct tm* fecha){
	
	char buffer [10];
	int dia;
	
	strftime(buffer, sizeof(buffer), "%j", fecha);//%j DEVUELVE EL Nº DE DÍAS TRANSCURRIDOS DESDE EL 1 DE ENERO., FUNCIÓN ESPECÍFICA DEL TIME.H
	
	sscanf(buffer, "%i", &dia); //CONVERTIMOS LA CADENA EN UN INT
	
	return dia;
	
}

//OBTENEMOS LA PALABRA DEL DÍA

void palabra_d (int dia, linea_p digitos[]){
	printf ("TU(S) PALABRA(S) DE HOY:\n\n%s", digitos[dia-1].posicion);
}
