# FUNCIONALIDADES
## Selección de cuencas:
int *seleccion_cuencas* permite al usuario **seleccionar una de las cuencas** en el intervalo del 1 al 16, si la selección está fuera de ese rango se imprime por pantalla un mensaje de error y se invita al usuario a elegir otro número mediante un bucle While. 

Dentro de este bucle se pide al usuario un dato de tipo char (formado por una cadena que permite como mucho 2 caracteres + final de cadena), y hay varias **condiciones**:

- **La primera condición** es que de entre los elementos de la tabla ASCII el valor introducido pertenezca al intervalo ‘0’ – ‘9’, si no se cumple esta condición se imprime el mensaje de error, con esto nos aseguramos de que el valor introducido sea un número. 

- **La segunda condición** es que el primer elemento de la cadena sea distinto de 0, para que el programa no tenga errores al introducir por ejemplo “08” en vez de “8”.

Después, si se han cumplido las condiciones anteriores, con “sscanf” **transformamos la cadena en** un dato del tipo **int**.

- **La tercera condición**, y última, es que, ya teniendo un número, este pertenezca al intervalo en el que se encuentran en este caso las cuencas (1-16).

Tras haber pasado esta criba, si el elemento cumple la 3ª condición **se almacena en “num_cuenca”**.
	
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


## Selección de embalses:
int *seleccion_embalses* permite al usuario **seleccionar una de los embalses** en el intervalo del 1 hasta el último elemento de la cuenca elegida en la función anterior, si la selección está fuera de ese rango se imprime por pantalla un mensaje de error y se invita al usuario a elegir otro número mediante un bucle While. 

Dentro de este bucle se pide al usuario un dato de tipo char (formado por una cadena que permite como mucho 2 caracteres + final de cadena), y hay varias **condiciones**:

- **La primera condición** es que de entre los elementos de la tabla ASCII el valor introducido pertenezca al intervalo ‘0’ – ‘9’, si no se cumple esta condición se imprime el mensaje de error, con esto nos aseguramos de que el valor introducido sea un número.

- **La segunda condición** es que el primer elemento de la cadena sea distinto de 0, para que el programa no tenga errores al introducir por ejemplo “08” en vez de “8”.

Después, si se han cumplido las condiciones anteriores, con “sscanf” **transformamos la cadena en** un dato del tipo **int**. 

- **La tercera condición**, y última, es que, ya teniendo un número, este pertenezca al intervalo en el que se encuentran en este caso los embalses (1-Último embalse de la cuenca seleccionada previamente).

Tras haber pasado esta criba, si el elemento cumple la 3ª condición **se almacena en “num_embalse”**.

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

## Selección de años:

int *seleccion_anyos* permite al usuario **seleccionar uno de los años** en el intervalo del 2012 al 2021, si la selección está fuera de ese rango se imprime por pantalla un mensaje de error y se invita al usuario a elegir otro número mediante un bucle While. 

Dentro de este bucle se pide al usuario un dato de tipo char (formado por una cadena que permite como mucho 4 caracteres + final de cadena), y hay varias **condiciones**:

(En este caso no hace falta una condición para que la primera cifra no sea 0, pues como siempre tiene 4 cifras si introduce un 0 delante la cadena tendría 5 cifras y daría error, y si pone un 0 delante y sólo tiene 4 cifras no estaría en el intervalo)

- **La primera condición** es que de entre los elementos de la tabla ASCII el valor introducido pertenezca al intervalo ‘0’ – ‘9’, si no se cumple esta condición se imprime el mensaje de error, con esto nos aseguramos de que el valor introducido sea un número.
 
Después, si se han cumplido las condición anterior, con “sscanf” **transformamos la cadena en** un dato del tipo **int**.

- **La segunda condición**, y última, es que, ya teniendo un número, este pertenezca al intervalo en el que se encuentran en este caso los años (1-12).

Tras haber pasado esta criba, si el elemento cumple la 2ª condición **se almacena en “anyo”**.

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

 




