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


void nombres_cuencas(int j,linea cuenca[]);

int seleccion_cuenca(int num_cuenca);

void nombres_cuencas_embalse(int j, int num_cuenca, linea vector[], int vector2[],int *c);

int seleccion_embalse(int num_embalse, int c);

int seleccion_anyo(int anyo);

int seleccion_mes(int mes);

char *meses_nombres(int mes);

float porcentaje_embalse (int anyo, int mes, int num_cuenca, int vector2[], int b, int num_embalse, linea vector[], linea vector1[]);

void sequia (int porcentaje);
