#ifndef COMPARACION_EMBALSE_H
#define COMPARACION_EMBALSE_H

//
typedef struct {
	char cuenca_hidrografica[50];
	char embalse_nombre[50];
	int mes;
	float dosmildoce;
	float dosmiltrece;
	float dosmilcatorce;
	float dosmilquince;
	float dosmildieciseis;
	float dosmildiecisiete;
	float dosmildieciocho;
	float dosmildiecinueve;
	float dosmilveinte;
	float dosmilveintiuno;
	//
	char embalse_nom[50];
	float etotal;
	//
}frase;
//
typedef struct {
    char nombre_embalse[100];
    float superficie;
    char tipo_presa[100];
    char uso_abastecimiento[5];
    char uso_riego[5];
    char uso_electricidad[5];
    char uso_industrial[5];
    char uso_pesca[5];
    char uso_navegacion[5];
    char uso_banyo[5];
    char uso_picnic[5];
    char uso_restaurante[5];
} DatosComparacion;
//

void nombres_cuencas(int vb, frase cuenca[]);

int seleccion_cuenca_1(int num_cuenca);

void nombreseleccion_embalse_1(int num_cuenca,frase cuenca[], int* num_embalse, int* l_r_embalse);

int seleccion_cuenca_2(int num_cuenca2);

void nombreseleccion_embalse_2(int num_cuenca2,frase cuenca[], int* num_embalse2, int* l_r_embalse2);

int tipo_comparacion(int mes_anyo);

void comparacion_anyo(int mes_anyo, int anyo, int l_r_embalse, int l_r_embalse2, frase cuenca[]);

int seleccion_anyo(int anyo);

void comparacion_mes(int mes_anyo, int anyo, int mes, int l_r_embalse, int l_r_embalse2, frase cuenca[]);

int seleccion_mes(int mes);

char *meses_nombre(int mes);

void capacidad_max(int l_r_embalse, int l_r_embalse2, frase cuenca[],frase embalse[]);

void superficie(int l_r_embalse, int l_r_embalse2, frase cuenca[], DatosComparacion comp[]);

void tipo_embalse(DatosComparacion comp[],int l_r_embalse, int l_r_embalse2, frase cuenca[]);

void uso_embalse(DatosComparacion comp[],int l_r_embalse, int l_r_embalse2, frase cuenca[]);




#endif 
