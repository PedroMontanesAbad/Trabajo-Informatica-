# Título
## Subtítulo
### Subsubtítulo
*Cursiva*
**Negrita**
- Lis
- tas
Son las cosas más básicas

Para que se vea el código que has hecho: 
printf(

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
 )
- Creas un printf y pegas el código coo un \t de separación con el printf cada línea y la primera con dos \n de separación
· (Para ver las cosas meteos como si fuerais a editar este documento)
