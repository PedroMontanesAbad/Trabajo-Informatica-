# FUNCIONALIDADES
## Selección de cuencas:
int *seleccion_cuencas* permite al usuario **seleccionar una de las cuencas** en el intervalo del 1 al 16, si la selección está fuera de ese rango se imprime por pantalla un mensaje de error y se invita al usuario a elegir otro número mediante un bucle While. 

Dentro de este bucle se pide al usuario un dato de tipo char (formado por una cadena que permite como mucho 2 caracteres), y hay varias **condiciones**:

- **La primera condición** es que de entre los elementos de la tabla ASCII el valor introducido pertenezca al intervalo ‘0’ – ‘9’, si no se cumple esta condición se imprime el mensaje de error, con esto nos aseguramos de que el valor introducido sea un número. 

- **La segunda condición** es que el primer elemento de la cadena sea distinto de 0, para que el programa no tenga errores al introducir por ejemplo “08” en vez de “8”.

Después, si se han cumplido las condiciones anteriores, con “sscanf” **transformamos la cadena en** un dato del tipo **int**.

- **La tercera condición**, y última, es que, ya teniendo un número, este pertenezca al intervalo en el que se encuentran en este caso las cuencas (1-16).

Tras haber pasado esta criba, si el elemento cumple la 3º condición **se almacena en “num_cuenca”**.
	
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

Dentro de este bucle se pide al usuario un dato de tipo char (formado por una cadena que permite como mucho 2 caracteres), y hay varias **condiciones**:

- **La primera condición** es que de entre los elementos de la tabla ASCII el valor introducido pertenezca al intervalo ‘0’ – ‘9’, si no se cumple esta condición se imprime el mensaje de error, con esto nos aseguramos de que el valor introducido sea un número.

- **La segunda condición** es que el primer elemento de la cadena sea distinto de 0, para que el programa no tenga errores al introducir por ejemplo “08” en vez de “8”.

Después, si se han cumplido las condiciones anteriores, con “sscanf” **transformamos la cadena en** un dato del tipo **int**. 

- **La tercera condición**, y última, es que, ya teniendo un número, este pertenezca al intervalo en el que se encuentran en este caso los embalses (1-Último embalse de la cuenca seleccionada previamente).

Tras haber pasado esta criba, si el elemento cumple la 3º condición **se almacena en “num_embalse”**.

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





