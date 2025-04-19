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

} linea;

int calcular_media();

void nombres_embalses(int j,linea vector[]);
void nombres_cuencas(int j,linea vector[]);
void nombres_cuencas_embalse(int j, int num_cuenca, linea vector[], int vector2[]);
float media_anyo(int j,int anyo, linea vector[]);
float media_anyo_embalse(int j,int anyo, int num_cuenca, int num_embalse, linea vector[], int vector2[]);
float max_y_min_embalse(int j,int anyo, int num_cuenca, int num_embalse, linea vector[], int vector2[], int vector3[]);

#endif

