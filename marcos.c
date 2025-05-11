
void maxymin_main() { 

char C_cuenca[2], C_embalse[2], C_mes[2], C_anyo[5], cambio[100];

int i,j=0,anyo,num_cuenca,num_embalse,f=0;

int maxmin[4];

int posiciones_cuencas[16];

float media;

linea cuenca[4236];

FILE *tabla;
tabla = fopen("texto_proyecto_actualizado.csv","r");
if (tabla == NULL) // Si el resultado es NULL mensaje de error
{
printf("Error al abrir el fichero.\n");
return -1;
}
//Poner que el puntero avance una linea

while (fscanf(tabla, "%[^,],%[^,],%i,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f\n", cuenca[j].cuenca_hidrografica , cuenca[j].embalse_nombre , &cuenca[j].mes , &cuenca[j].dosmildoce, &cuenca[j].dosmiltrece, &cuenca[j].dosmilcatorce, &cuenca[j].dosmilquince, &cuenca[j].dosmildieciseis, &cuenca[j].dosmildiecisiete, &cuenca[j].dosmildieciocho,  &cuenca[j].dosmildiecinueve,  &cuenca[j].dosmilveinte,  &cuenca[j].dosmilveintiuno ) != EOF)
{
	j++;
}

//Almacenar posiciones cuencas
//Aparecen irregularmente debemos compararlas para no repetir
for (i=0;i<j;i++){
	
	if (strcmp(cuenca[i].cuenca_hidrografica, cuenca[i-1].cuenca_hidrografica) != 0){
		posiciones_cuencas[f]=i;
		f++;
	}
}
posiciones_cuencas[f]=j; //Añadimos un ultimo valor señalando el fin de los datos
  
	printf("Selecciona una cuenca, un embalse y un año para calcular su maximo y minimo:\n);
	nombres_cuencas(j,cuenca[]);
	num_cuenca = seleccion_cuenca(num_cuenca, C_cuenca);
	nombres_cuencas_embalse(j, num_cuenca, cuenca[], posiciones_cuencas);
	num_embalse = seleccion_embalse(num_embalse, posicinoes_cuencas, num_cuenca, C_embalse)
	anyo = seleccion_anyo(anyo, C_anyo);
	max_y_min_embalse(j, anyo, num_cuenca, num_embalse, cuenca[], posiciones_cuencas[], maxmin[]) { 
}

void medias_main(){
}
