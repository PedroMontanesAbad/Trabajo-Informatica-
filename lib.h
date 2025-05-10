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

void gotoxy(int x, int y);
void DibujarMenu();
void Texto0();
void Texto1();
void Texto2();
void Texto3();
void Texto4();
void Texto5();
int donut();
void Fecha();
void CuatroCuadrados();

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

	char embalse_nom[50];
	float etotal;

} linea;

int calcular_media();

void nombres_embalses(int j,linea vector[]);
void nombres_cuencas(int j,linea vector[]);
void nombres_cuencas_embalse(int j, int num_cuenca, linea vector[], int vector2[]);
float media_anyo(int j,int anyo, linea vector[]);
float media_anyo_embalse(int j,int anyo, int num_cuenca, int num_embalse, linea vector[], int vector2[]);
float max_y_min_embalse(int j,int anyo, int num_cuenca, int num_embalse, linea vector[], int vector2[], int vector3[]);

//Funciones_comparacion
void nombres_cuencas_E(int vb, frase cuenca[]);
int seleccion_cuenca_1(int num_cuenca, char C_cuenca[]);
void nombreseleccion_embalse_1(int num_cuenca,frase cuenca[], int* num_embalse, int* l_r_embalse);
int seleccion_cuenca_2(int num_cuenca2, char C_cuenca2[]);
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
char cambios_espacios_embalses_E(frase cuenca [], int l_r_embalse, int l_r_embalse2);
char cambios_espacios_tipo_presa(DatosComparacion comp[], int l_r_embalse, int l_r_embalse2);
//Funciones_comparacion

#endif

