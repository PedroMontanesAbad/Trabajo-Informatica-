# MAIN:
## Lectura del segundo fichero:
**Abrimos el fichero**
	
 	FILE *lista;
	lista = fopen("Embalses_capacidad.txt","r");
	
	if (lista == NULL) // Si el resultado es NULL mensaje de error
	{
	printf("Error al abrir el fichero 2.\n");
	return -1;
	}
 
**Lectura:**
A la hora de leer este segundo fichero sólo nos interesa el nombre del embalse ya elegido por el fichero del usuario. Por esto mientras que leemos el archivo vamos a **comparar cada nombre de embalse con el nombre del embalse elegido**. Cada vez que avanza la lectura se suma 1 a un contador. En cuanto los embalses coincidan se iguala el número del contador a una variable "*embalse_coincide*"

 	while ( fscanf(lista, "%s\t%f\n", embalse[k].embalse_nom , &embalse[k].etotal) !=EOF )
	{

	//printf("%s\t%.2f\n", embalse[k].embalse_nom, embalse[k].etotal );
	
	if  (strcmp(cuenca[posiciones_cuencas[num_cuenca-1]+(num_embalse-1)*12].embalse_nombre , embalse[k].embalse_nom) == 0){
		embalse_coincide = k+1;
	}
	k++;	

	}


# FUNCIONALIDADES:
## Selección de cuenca:
int *seleccion_cuencas* permite al usuario **seleccionar una de las cuencas** en el intervalo del 1 al 16, si la selección está fuera de ese rango se imprime por pantalla un mensaje de error y se invita al usuario a elegir otro número mediante un bucle While. 

Dentro de este bucle se pide al usuario un dato de tipo char (formado por una cadena que permite como mucho 2 caracteres + final de cadena), y hay varias **condiciones**:

- **La primera condición** es que de entre los elementos de la tabla ASCII cada valor introducido pertenezca al intervalo ‘0’ – ‘9’, si no se cumple esta condición se imprime el mensaje de error, con esto nos aseguramos de que el valor introducido sea un número. 

- **La segunda condición** es que el primer elemento de la cadena sea distinto de 0, para que el programa no tenga errores al introducir por ejemplo “08” en vez de “8”.

Después, si se han cumplido las condiciones anteriores, con “*sscanf*” **transformamos la cadena en** un dato del tipo **int**.

- **La tercera condición**, y última, es que, ya teniendo un número, este pertenezca al intervalo en el que se encuentran en este caso las cuencas (1-16).

Tras haber pasado esta criba, si el elemento cumple la 3ª condición **se almacena en “*num_cuenca*”**.
	
	int seleccion_cuenca(int num_cuenca, char C_cuenca[]){
	
	do{
	
	printf("\nIntroduce el numero de la cuenca: ");
	scanf("%s", C_cuenca);
	
	if(('9'<C_cuenca[0] && C_cuenca[0]<'0') && ('9'<C_cuenca[1] && C_cuenca[1]<'0')){
		printf ("\nCaracter no valido, repite:\n");	
	}
	else{	
		if (C_cuenca[0] == '0'){
			printf ("\nbNumero no valido, repite:\n");
		}
		
		else{		
			sscanf(C_cuenca, "%i", &num_cuenca);
			if((0 >= num_cuenca) || ( num_cuenca > 16 )){
				printf ("\ncNumero no valido, repite:\n");
			}
		}
	  }
    }

    while ((0 >= num_cuenca) || ( num_cuenca > 16 ) || (('9'<C_cuenca[0] && C_cuenca[0]<'0') && ('9'<C_cuenca[1] && C_cuenca[1]<'0')) || (C_cuenca[0] == '0'));

    return num_cuenca;

    }


## Selección de embalse:
int *seleccion_embalses* permite al usuario **seleccionar una de los embalses** en el intervalo del 1 hasta el último elemento de la cuenca elegida en la función anterior, si la selección está fuera de ese rango se imprime por pantalla un mensaje de error y se invita al usuario a elegir otro número mediante un bucle While. 

Dentro de este bucle se pide al usuario un dato de tipo char (formado por una cadena que permite como mucho 2 caracteres + final de cadena), y hay varias **condiciones**:

- **La primera condición** es que de entre los elementos de la tabla ASCII cada valor introducido pertenezca al intervalo ‘0’ – ‘9’, si no se cumple esta condición se imprime el mensaje de error, con esto nos aseguramos de que el valor introducido sea un número.

- **La segunda condición** es que el primer elemento de la cadena sea distinto de 0, para que el programa no tenga errores al introducir por ejemplo “08” en vez de “8”.

Después, si se han cumplido las condiciones anteriores, con “*sscanf*” **transformamos la cadena en** un dato del tipo **int**. 

- **La tercera condición**, y última, es que, ya teniendo un número, este pertenezca al intervalo en el que se encuentran en este caso los embalses (1-Último embalse de la cuenca seleccionada previamente).

Tras haber pasado esta criba, si el elemento cumple la 3ª condición **se almacena en “*num_embalse*”**.

 	int seleccion_embalse(int num_embalse, int vector2[], int num_cuenca, char C_embalse[]){

	do{
	printf("\nIntroduce el numero del embalse: " );	
	scanf("%s", C_embalse);
	
	if(('9'<C_embalse[0] && C_embalse[0]<'0') && ('9'<C_embalse[1] && C_embalse[1]<'0')){
		printf ("\nCaracter no valido, repite:\n");	
	}
	else{	
		if (C_embalse[0] == '0'){
			printf ("\nNumero no valido, repite:\n");
		}
		
		else{		
			sscanf(C_embalse, "%i", &num_embalse);
			if((0 >= num_embalse) || ( num_embalse > ((vector2[num_cuenca]-vector2[num_cuenca-1])/12))){
				printf ("\nNumero no valido, repite:\n");
			}
		}
		}

	}
	while ((0 >= num_embalse) || ( num_embalse > ((vector2[num_cuenca]-vector2[num_cuenca-1])/12)) || ('9'<C_embalse[0] && C_embalse[0]<'0') && ('9'<C_embalse[1] && C_embalse[1]<'0') || (C_embalse[0] == '0'));

	return num_embalse;

	}

## Selección de año:

int *seleccion_anyos* permite al usuario **seleccionar uno de los años** en el intervalo del 2012 al 2021, si la selección está fuera de ese rango se imprime por pantalla un mensaje de error y se invita al usuario a elegir otro número mediante un bucle While. 

Dentro de este bucle se pide al usuario un dato de tipo char (formado por una cadena que permite como mucho 4 caracteres + final de cadena), y hay varias **condiciones**:

(En este caso no hace falta una condición para que la primera cifra no sea 0, pues como siempre tiene 4 cifras si introduce un 0 delante la cadena tendría 5 cifras y daría error, y si pone un 0 delante y sólo tiene 4 cifras no estaría en el intervalo)

- **La primera condición** es que de entre los elementos de la tabla ASCII cada valor introducido pertenezca al intervalo ‘0’ – ‘9’, si no se cumple esta condición se imprime el mensaje de error, con esto nos aseguramos de que el valor introducido sea un número.
 
Después, si se ha cumplido las condición anterior, con “*sscanf*” **transformamos la cadena en** un dato del tipo **int**.

- **La segunda condición**, y última, es que, ya teniendo un número, este pertenezca al intervalo en el que se encuentran en este caso los años (2012-2021).

Tras haber pasado esta criba, si el elemento cumple la 2ª condición **se almacena en “*anyo*”**.

	int seleccion_anyo(int anyo, char C_anyo[]);{
		
	do{
	printf("\nIntroduce el anyo deseado 2012-2021: ");
	scanf("%s", C_anyo);
			
	if(('9'<C_anyo[0] && C_anyo[0]<'0') || ('9'<C_anyo[1] && C_anyo[1]<'0') || ('9'<C_anyo[2] && C_anyo[2]<'0') || ('9'<C_anyo[3] && C_anyo[3]<'0')){
		printf ("\nCaracter no valido, repite:\n");	
	}
	else{	
		sscanf(C_anyo, "%i", &anyo);
		if((2012 > anyo) || (anyo > 2021)){
			printf ("\nNumero no valido, repite:\n");
		}
	}
	}

	while ((2012 > anyo) || ( anyo > 2021 ) || ('9'<C_anyo[0] && C_anyo[0]<'0') || ('9'<C_anyo[1] && C_anyo[1]<'0') || ('9'<C_anyo[2] && C_anyo[2]<'0') || ('9'<C_anyo[3] && C_anyo[3]<'0'));
	
	return anyo;
	}

 ## Selección de mes:
 
int *seleccion_mes* permite al usuario **seleccionar uno de los meses** en el intervalo del 1 al 12, si la selección está fuera de ese rango se imprime por pantalla un mensaje de error y se invita al usuario a elegir otro número mediante un bucle While. 

Dentro de este bucle se pide al usuario un dato de tipo char (formado por una cadena que permite como mucho 2 caracteres + final de cadena), y hay varias **condiciones**:

- **La primera condición** es que de entre los elementos de la tabla ASCII cada valor introducido pertenezca al intervalo ‘0’ – ‘9’, si no se cumple esta condición se imprime el mensaje de error, con esto nos aseguramos de que el valor introducido sea un número.
- 
- **La segunda condición** es que el primer elemento de la cadena sea distinto de 0, para que el programa no tenga errores al introducir por ejemplo “08” en vez de “8”.
- 
Después, si se han cumplido las condiciones anteriores, con “*sscanf*” **transformamos la cadena en** un dato del tipo **int**.

- **La tercera condición**, y última, es que, ya teniendo un número, este pertenezca al intervalo en el que se encuentran en este caso los meses (1-12).

Tras haber pasado esta criba, si el elemento cumple la 3ª condición **se almacena en “*N_mes*”**.

	int seleccion_mes(int N_mes, char C_mes[]){

	do{
		
	printf("\nIntroduce el mes deseado: ");
	scanf("%s",C_mes);
		
	if ((C_mes[0] < '0' && C_mes[0] > '9') || (C_mes[1] < '0' && C_mes[1] > '9')){
		printf("\nNumero no valido, repite:\n");
	}
	else{
		if (C_mes[0]== '0'){
			printf("\nNumero no valido, repite:\n");
		}
		else{
			sscanf(C_mes, "%i", &N_mes);
			
			if((N_mes < 1) || (N_mes > 12)){
				printf("\nNumero no valido, repite:\n");
			}
		
		}
	}
	}
	while (((C_mes[0] < '0' && C_mes[0] > '9') || (C_mes[1] < '0' && C_mes[1] > '9')) || (C_mes[0]== '0') || ((N_mes < 1) || (N_mes > 12)));
	
	return N_mes;
	}

## Cambio  del mes numerado al mes escrito

char **meses_nombres* no es funcional, sino que es estético, su único fin es **cambiar el mes numerado** (por ejemplo 6) **por el** mes **escrito** (junio), esto le hace al usuario más fácil la lectura. 

Para ello se define un puntero char global para poder acceder a el desde la función y que no ocupe espacio en el main.

	char *mes_nom[] = {"enero", "febrero", "marzo", "abril", "mayo", "junio", "julio", 
			"agosto", "septiembre", "octubre", "noviembre", "diciembre"};

La función char **meses_nombres* a partir devuelve el nombre del mes a partir del número de mes "*N_mes*" obtenido en la función aterior (se le resta 1 porque el almacenamiento en la cadena empieza en el 0).

	char *meses_nombres(int N_mes){
	return mes_nom[N_mes-1];
	}

## Capacidad del embalse

float *porcentaje_embalse* es función que permite al usuario conocer la **capacidad del embalse** en un mes y año concreto. 

Para esto se usa un switch que ofrece todas las opciones según el año elegido previamente por el usuario en la función seleccion_anyo.

- Se obtiene la **capacidad actual**, esta pertenece al vector cuencas de la estructura principal tomando i como la posición del embalse en el año seleccionado, esto permite mostrar la capacidad en dicahs coordenadas.

- Se obtiene la **capacidad total** como el vector embalse de la estructura principal tomando b como la posición del embalse en el segundo fichero, esto permite mostrar el total de la capacidad.

Este proceso se repite para cada caso.

Tras el último caso se hace el cálculo del porcentaje, sabemos que es la capacidad actual por cien, entre la total. La función devuelve el valor de dicho porcentaje.

	float porcentaje_embalse (int anyo, int N_mes, int num_cuenca, int vector2[], int embalse_coincide, int num_embalse, linea vector[], linea vector1[]){
	int i;
	float capacidad_actual=0, capacidad_max=0, porcentaje;


	switch(anyo){
	case(2012):
			i=vector2[num_cuenca-1]+(num_embalse-1)*12+(N_mes-1);
			capacidad_actual = vector[i].dosmildoce;
			capacidad_max = vector1[embalse_coincide-1].etotal;
		
		porcentaje = capacidad_actual*100/capacidad_max;
		break;

	case(2013):
			i=vector2[num_cuenca-1]+(num_embalse-1)*12+(N_mes-1);
			capacidad_actual =  vector[i].dosmiltrece;
			capacidad_max = vector1[embalse_coincide-1].etotal;
		
		porcentaje = capacidad_actual*100/capacidad_max;
		break;
	
	case(2014):
			i=vector2[num_cuenca-1]+(num_embalse-1)*12+(N_mes-1);
			capacidad_actual =  vector[i].dosmilcatorce;
			capacidad_max = vector1[embalse_coincide-1].etotal;
		
		porcentaje = capacidad_actual*100/capacidad_max;
		break;
		
	case(2015):
		i=vector2[num_cuenca-1]+(num_embalse-1)*12+(N_mes-1);
			capacidad_actual =  vector[i].dosmilquince;
			capacidad_max = vector1[embalse_coincide-1].etotal;
		
		porcentaje = capacidad_actual*100/capacidad_max;
		break;	
		
	case(2016):
		i=vector2[num_cuenca-1]+(num_embalse-1)*12+(N_mes-1);
			capacidad_actual =  vector[i].dosmildieciseis;
			capacidad_max = vector1[embalse_coincide-1].etotal;
		
		porcentaje = capacidad_actual*100/capacidad_max;
		break;	
		
	case(2017):
		i=vector2[num_cuenca-1]+(num_embalse-1)*12+(N_mes-1);
			capacidad_actual =  vector[i].dosmildiecisiete;
			capacidad_max = vector1[embalse_coincide-1].etotal;
		
		porcentaje = capacidad_actual*100/capacidad_max;
		break;
		
	case(2018):
		i=vector2[num_cuenca-1]+(num_embalse-1)*12+(N_mes-1);
			capacidad_actual =  vector[i].dosmildieciocho;
			capacidad_max = vector1[embalse_coincide-1].etotal;
		
		porcentaje = capacidad_actual*100/capacidad_max;
		break;
		
	case(2019):
		i=vector2[num_cuenca-1]+(num_embalse-1)*12+(N_mes-1);
			capacidad_actual =  vector[i].dosmildiecinueve;
			capacidad_max = vector1[embalse_coincide-1].etotal;		
		
		porcentaje = capacidad_actual*100/capacidad_max;
		break;
		
	case(2020):
		i=vector2[num_cuenca-1]+(num_embalse-1)*12+(N_mes-1);
			capacidad_actual =  vector[i].dosmilveinte;
			capacidad_max = vector1[embalse_coincide-1].etotal;		
		
		porcentaje = capacidad_actual*100/capacidad_max;
		break;
		
	case(2021):
		i=vector2[num_cuenca-1]+(num_embalse-1)*12+(N_mes-1);
			capacidad_actual =  vector[i].dosmilveintiuno;
			capacidad_max = vector1[embalse_coincide-1].etotal;	
		
		porcentaje = capacidad_actual*100/capacidad_max;
		break;

	}
	return porcentaje;
	}

## Cambio de barras bajas '_' por espacios ' ' para **cuencas**

char *cambio_espacios_cuencas* no es funcional. Es una función estética con el fin de que sea más agradable la lectura para el usuario. Su objetivo es **sustituir las barras bajas por espacios** cuando sea necesario para ello usamos un bucle while y un condicional if dentro del mismo.

- **Primero:** se copia la cadena que guarda el nombre de la cuenca en la cadena *"cambio"* (que será una cadena de paso).

- **Segundo:** se crea un bucle que lee cada caracter de la cadena (desde el inicial hasta que encuentra el caracter nulo), dentro de este bucle se encuentra la condición de que siempre que lea un caracter barra baja '_' lo sustituya por el caracter espacio ' '.

- **Por último:** cuando el bucle termina y se ha editado si fuera necesario la cadena *"cambio"*, esta se copia en la cadena que guardaba el nombre de la cuenca.

Esto sustituye la cadena original desde que se aplique esta función en adelante.

	char cambio_espacios_cuencas (linea vector[], int num_cuenca, int vector2[], int num_embalse){
	int c=0;
	char cambio[100];
	strcpy(cambio, vector[vector2[num_cuenca-1]+(num_embalse-1)*12].cuenca_hidrografica );

	while (cambio[c] != '\0'){
		if (cambio[c] == '_'){
			cambio[c] = ' ';
		}
		c++;
	}
	strcpy(vector[vector2[num_cuenca-1]+(num_embalse-1)*12].cuenca_hidrografica, cambio );

	}


## Cambio de barras bajas '_' por espacios ' ' para **embalses**

char cambio_espacios_embalses no es funcional. Es una función estética con el fin de que sea más agradable la lectura para el usuario. Su objetivo es sustituir las barras bajas por espacios cuando sea necesario para ello usamos un bucle while y un condicional if dentro del mismo.

- **Primero:** se copia la cadena que guarda el nombre de la cuenca en la cadena *"cambio"* (que será una cadena de paso).

- **Segundo:** se crea un bucle que lee cada caracter de la cadena (desde el inicial hasta que encuentra el caracter nulo), dentro de este bucle se encuentra la condición de que siempre que lea un caracter barra baja '_' lo sustituya por el caracter espacio ' '.

- **Por último:** cuando el bucle termina y se ha editado, si fuera necesario, la cadena *"cambio"*, esta se copia en la cadena que guardaba el nombre del embalse.

Esto sustituye la cadena original desde que se aplique esta función en adelante.

	char cambio_espacios_embalses (linea vector[], int num_cuenca, int vector2[], int num_embalse){
	
	int c=0;
	char cambio[100];
	strcpy(cambio, vector[vector2[num_cuenca-1]+(num_embalse-1)*12].embalse_nombre );

	while (cambio[c] != '\0'){
		if (cambio[c] == '_'){
			cambio[c] = ' ';
		}
		c++;
	}
	strcpy(vector[vector2[num_cuenca-1]+(num_embalse-1)*12].embalse_nombre, cambio );
	
	}

## Peligro de sequía o desbordamiento

void *sequia* es una función que *avisa* al usuario si el embalse seleccionado tiene algún riesgo*. En los embalses españoles por lo general se dice que:
- Hay **sequía leve** si el porcentaje está entre 50% y 70%.
- Hay **sequía moderada** si el porcentaje está entre 30% y 50%.
- Hay **sequía grave** si el porcentaje es menor que 30%.
También se ha añadido la opción de peligro de **desbordamientos** si el embalse supera el máximo de su capacidad útil, es decir, esta está por encima del 100%.

Para esto se utilizan condicionales if.
		
  	void sequia (int porcentaje){

  		if ((50<porcentaje) && (porcentaje<70)){
			printf("\n\nPeriodo de sequia leve.");
		}		
		else if ((30<porcentaje) && (porcentaje<50)){
			printf("\n\nPeriodo de sequia moderada.");
		}
		else if (porcentaje<30){
			printf("\n\nPeriodo de sequia grave.");
		}
		else if (porcentaje>100){
			printf("\n\nEmbalse en maximos, peligro de desbordamiento.");
		}
		
		
}

