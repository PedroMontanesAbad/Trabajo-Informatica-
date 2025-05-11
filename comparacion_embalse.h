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
	}linea;
typedef struct {
	char embalse_nom[50];
	float etotal;
	//
}Embalse;
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

void nombres_cuencas(int vb, linea cuenca[]);

int seleccion_cuenca_1(int num_cuenca, char C_cuenca[]);

void nombreseleccion_embalse_1(int num_cuenca,linea cuenca[], int* num_embalse, int* l_r_embalse);

int seleccion_cuenca_2(int num_cuenca2, char C_cuenca2[]);

void nombreseleccion_embalse_2(int num_cuenca2,linea cuenca[], int* num_embalse2, int* l_r_embalse2);

int tipo_comparacion(int mes_anyo);

void comparacion_anyo(int mes_anyo, int anyo, int l_r_embalse, int l_r_embalse2, linea cuenca[]);

int seleccion_anyos(int anyo);

void comparacion_mes(int mes_anyo, int anyo, int mes, int l_r_embalse, int l_r_embalse2, linea cuenca[]);

int seleccion_mese(int mes);

void capacidad_max(int l_r_embalse, int l_r_embalse2,linea cuenca[],Embalse embalse[]);

void superficie(int l_r_embalse, int l_r_embalse2, linea cuenca[], DatosComparacion comp[]);

void tipo_embalse(DatosComparacion comp[],int l_r_embalse, int l_r_embalse2, linea cuenca[]);

void uso_embalse(DatosComparacion comp[],int l_r_embalse, int l_r_embalse2, linea cuenca[]);

char cambios_espacios_embalses (linea cuenca [], int l_r_embalse, int l_r_embalse2);

char cambios_espacios_tipo_presa (DatosComparacion comp[], int l_r_embalse, int l_r_embalse2);





#endif 
