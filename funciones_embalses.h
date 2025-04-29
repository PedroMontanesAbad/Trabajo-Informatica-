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

int seleccion_cuenca(int num_cuenca,char C_cuenca[]);

void nombres_cuencas_embalse(int j, int num_cuenca, linea vector[], int vector2[]);

int seleccion_embalse(int num_embalse, int vector2[], int num_cuenca, char C_embalse[]);

int seleccion_anyo(int anyo);

int seleccion_mes(int N_mes, char C_mes[]);

char *meses_nombres(int N_mes);

float porcentaje_embalse (int anyo, int N_mes, int num_cuenca, int vector2[], int b, int num_embalse, linea vector[], linea vector1[]);

char cambio_espacios_cuencas (linea vector[], int num_cuenca, int vector2[], int num_embalse);

char cambio_espacios_embalses (linea vector[], int num_cuenca, int vector2[], int num_embalse);

void sequia (int porcentaje);
