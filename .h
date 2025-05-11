#ifndef _LIB_H_
#define _LIB_H_

#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
//#include <iostream>
#include <math.h>
#include <time.h>
#include <stdint.h>
#include <string.h>
#include <ctype.h>

#include <locale.h>


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

} linea;


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




typedef struct {
	char embalse_nom[50];
	float etotal;

} Embalse;
//palabra del dia
// 
typedef struct {
	char posicion[365];
}linea_palabradia;

//FECHA ACTUAL 

struct tm* fecha_actual();

//DÍA DEL AÑO

int dia_anyo(struct tm* fecha);

//PALABRA DEL DÍA

void palabra_d(int dia, linea_palabradia digitos[]);

void palabra_dia_main();
//final palabra del dia

void gotoxy(int x, int y);
void DibujarMenu();
void cuadradosDosPorDos();
void Texto0();
void Texto1();
void Texto2();
void Texto3();
void Texto4();
void Texto5();
int donut();
void Fecha();
void SeisCuadrados();

void porcentajes_main();
void nombres_cuencas(int j, linea cuenca[]);
int seleccion_cuenca(int num_cuenca, char C_cuenca[]);
void nombres_cuencas_embalse(int j, int num_cuenca, linea vector[], int vector2[]);
int seleccion_embalse(int num_embalse, int vector2[], int num_cuenca, char C_embalse[]);
int seleccion_anyo(int anyo, char C_anyo[]);
int seleccion_mes(int N_mes, char C_mes[]);
float porcentaje_embalse(int anyo, int N_mes, int num_cuenca, int vector2[], int embalse_coincide, int num_embalse, linea vector[], Embalse vector1[]);
char* cambio_espacios_cuencas(linea vector[], int num_cuenca, int vector2[], int num_embalse);
char* cambio_espacios_embalses(linea vector[], int num_cuenca, int vector2[], int num_embalse);
void sequia(int porcentaje);



int cuestionario();
int pregunta_inicial();
int valor_letra_introducida();
int preguntas_cuestionario(int i);
void mostrar_resultado(int correcta, int i);
void informacion_respuestas(int i);
void tabla_errores(int correcta, int i);
void premios_concurso(int numero_aciertos);

//COMPARACION
void nombres_cuencas(int vb, linea cuenca[]);

int seleccion_cuenca_1(int num_cuenca, char C_cuenca[]);

void nombreseleccion_embalse_1(int num_cuenca, linea cuenca[], int* num_embalse, int* l_r_embalse);

int seleccion_cuenca_2(int num_cuenca2, char C_cuenca2[]);

void nombreseleccion_embalse_2(int num_cuenca2, linea cuenca[], int* num_embalse2, int* l_r_embalse2);

int tipo_comparacion(int mes_anyo);

void comparacion_anyo(int mes_anyo, int anyo, int l_r_embalse, int l_r_embalse2, linea cuenca[]);

int seleccion_anyos(int anyo);

void comparacion_mes(int mes_anyo, int anyo, int mes, int l_r_embalse, int l_r_embalse2, linea cuenca[]);

int seleccion_mese(int mes);


void capacidad_max(int l_r_embalse, int l_r_embalse2, linea cuenca[], Embalse embalse[]);

void superficie(int l_r_embalse, int l_r_embalse2, linea cuenca[], DatosComparacion comp[]);

void tipo_embalse(DatosComparacion comp[], int l_r_embalse, int l_r_embalse2, linea cuenca[]);

void uso_embalse(DatosComparacion comp[], int l_r_embalse, int l_r_embalse2, linea cuenca[]);

char* cambios_espacios_embalses(linea cuenca[], int l_r_embalse, int l_r_embalse2);

char* cambios_espacios_tipo_presa(DatosComparacion comp[], int l_r_embalse, int l_r_embalse2);


//
void comparacion_principal();
//FIN COMPARACION
#endif
