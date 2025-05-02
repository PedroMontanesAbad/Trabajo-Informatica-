#include <stdio.h>
#include "palabra_dia.h"

int main(){
	
	int dia, t=0;
	
	linea_p digitos[400];
	
	//OBTENEMOS EL DÍA DEL AÑO ACTUAL: 
	
	struct tm* fecha = fecha_actual();
	
	dia = dia_anyo (fecha);

	//ABRIMOS EL FICHERO
	
	FILE *palabra_dia;
    palabra_dia = fopen("palabra_dia.txt","r");
    if (palabra_dia == NULL){
    	printf("error");
	}
	
	//LEEMOS EL FICHERO
	
	while(t<400 && fscanf(palabra_dia,"%[^\n]",digitos[t].posicion) ==1){
	 	fgetc(palabra_dia);
		t++;
	}
	
	//TU(S) PALABRA(S):
	
	palabra_d (dia, digitos);
	
	//CERRAMOS FICHERO
	
    fclose(palabra_dia);
	
	return 0;
}
