#include <stdio.h>
#include <string.h>
#include <float.h>
#include "comparacion_embalse.h"


int main(){
	
//variables
int vb=0, vc=0, vco=0,i;//for y ficheros

int num_cuenca,num_embalse,l_r_embalse;//embalse1
int num_cuenca2,num_embalse2,l_r_embalse2;//embalse2
int mes_anyo, anyo,mes;//fechas y meses
	
frase cuenca[4236], embalse[353]; 
DatosComparacion comp[353];

	
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
	{
	
    	vb++;
	}
while(fscanf(capacidad,"%s\t%f\n",embalse[vc].embalse_nom,&embalse[vc].etotal)!=EOF){
	
		vc++;
	}
while(fscanf(F_comparacion,"%99[^,],%f,%99[^,],%4[^,],%4[^,],%4[^,],%4[^,],%4[^,],%4[^,],%4[^,],%4[^,],%4[^\n]\n",comp[vco].nombre_embalse,&comp[vco].superficie,comp[vco].tipo_presa,comp[vco].uso_abastecimiento,comp[vco].uso_riego,comp[vco].uso_electricidad,comp[vco].uso_industrial,comp[vco].uso_pesca,comp[vco].uso_navegacion,comp[vco].uso_banyo,comp[vco].uso_picnic,comp[vco].uso_restaurante)!=EOF){
	    vco++;
	}
	
//LISTA CUENCAS
nombres_cuencas(vb,cuenca);

//SELECCION CUENCA
num_cuenca=seleccion_cuenca_1(num_cuenca);

//SELECCION EMBALSE
nombreseleccion_embalse_1(num_cuenca,cuenca, &num_embalse, &l_r_embalse);

//2 LISTA CUENCAS:
nombres_cuencas(vb,cuenca);

//SELECCION 2 CUENCA:
num_cuenca2=seleccion_cuenca_2(num_cuenca2);

//SELECCION 2 EMBALSE
nombreseleccion_embalse_2(num_cuenca2,cuenca, &num_embalse2, &l_r_embalse2);

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
}
