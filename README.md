# Seleccion mes y año
Los int **seleccion_mese** y **seleccion_anyos** son funciones que permiten al usuario seleccionar un mes y año concreto para su uso mas adelante.
# Listado y selección de embalse:
Los void **nombreseleccion_embalse_1** y **nombreseleccion_embalse_2** son funciones que permiten al usuario seleccionar un embalse específico perteneciente a una cuenca previamente elegida.

Para ello, se utiliza la estructura switch-case que depende del valor de la variable num_cuenca. Para cada caso, se recorre el fichero cuenca[], mostrando sin repetir a los embalses pertenecientes a la cuenca elegida.
Una vez listados los embalses, scanf almacenará el número elegido por el usuario en la variable num_embalse. Finalmente, se conseguirá el espacio que ocupa realmente el embalse elegido en el fichero cuenca[] mediante la variable l_r_embalse. La cual se determina a través de el num_embalse y el índice de inicio de intervalo de la cuenca.
# Tipo de comparación:
El int **tipo_comparacion** permite al usuario seleccionar uno de los dos métodos de comparación disponibles: por año o por mes. Si la selección llegará a estar fuera de rango, se imprime por pantalla un mensaje de error y se invita al usuario a elegir otro número mediante un bucle do-while. Una vez ingresado un número válido, este se almacena en la variable mes_anyo.
# Comparación según año:
El void **comparacion_anyo** es una función que se ejecuta cuando se ha seleccionado el método de comparación según el año (mes_anyo ==1). 

Para ello, se utiliza la estructura switch-case que depende del valor de la variable anyo. Para cada caso, se recorren los datos mensuales de ambos embalses en ese año y se calcula el máximo y mínimo de capacidad que han obtenido. Al finalizar el recorrido, se imprimen los rangos de capacidad que obtuvieron los embalses en el año elegido, así como la diferencia entre sus valores máximos, indicando quién tuvo mayor capacidad en su punto más alto.
# Comparación según mes:
El void **comparacion_mes** es una función que se ejecuta cuando se ha seleccionado el método de comparación según el mes (mes_anyo ==2).

Para ello, se utiliza la estructura switch-case que depende del valor de la variable anyo. Para cada caso, se recuperan las capacidades de los embalses en el mes elegido. Luego, mediante estructuras if, se compará quien tiene mayor capacidad o si tienen la misma. Al finalizar el recorrido, se imprime la capacidad mensual que obtuvieron los embalses en el mes y año elegido y la diferencia entre estos.
# Capacidad máxima:
El void **capacidad_max** es una función que permite al usuario conocer la capacidad máxima de los embalses seleccionados .

Para ello, se accede al arreglo embalse[] y se obtienen las capacidades máximas de los embalses elegidos por el usuario. A continuación, se comparan las capacidades mediante estructuras if, para ver quién tiene la mayor capacidad o si tienen la misma. Al finalizar el recorrido, se imprime la capacidad máxima de ambos embalses y si corresponde, la diferencia entre estos.
# Superficie:
El void **superficie** es una función que permite al usuario conocer la superficie de los embalses seleccionados.

Para ello, se accede al arreglo comp[] y se obtienen las superficies de los embalses elegidos por el usuario. A continuación, se comparan las superficies mediante estructuras if, para ver quién tiene la mayor superficie o si tienen la misma. Al finalizar el recorrido, se imprimen los valores individuales y si es necesario, la diferencia entre estos.
# Tipo de presa:
El void **tipo_embalse** es una función que permite al usuario conocer el tipo de presa de los embalses seleccionados. 

Para ello, se accede al arreglo comp[] que contiene las especificaciones de construcción de los embalses elegidos por el usuario. A continuación, se comparan mediante estructuras if, para determinar si pertenecen al mismo grupo. Finalmente, imprime un mensaje indicando si son el mismo tipo de presa o si difieren, mostrando así a qué grupo pertenece cada uno.
# Tipo de uso:
El void **uso_embalse** es una función que compara los distintos usos asignados a los embalses seleccionados por el usuario. 

Para ello, se accede al arreglo comp[] que contiene los diferentes fines de cada presa. Para cada tipo de uso, se usa la estructura strcmp para verificar si ambos embalses comparten dicho uso, o si sólo uno de ellos lo tiene asignado. En caso de que alguno de ellos se use para un fin, se imprime un mensaje indicando si uno o ambos lo posee.
