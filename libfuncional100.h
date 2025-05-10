#ifndef _LIB_H_
#define _LIB_H_

#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <iostream>
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

int cuestionario();
int pregunta_inicial();
int valor_letra_introducida();
int preguntas_cuestionario(int i);
void mostrar_resultado(int correcta, int i);
void informacion_respuestas(int i);
void tabla_errores(int correcta, int i);
void premios_concurso(int numero_aciertos);

#endif
