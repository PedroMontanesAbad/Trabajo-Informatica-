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

float porcentaje_embalse (int anyo, int mes, int num_cuenca, int vector2[], int num_embalse, int i, linea vector[], linea vector1[]);

