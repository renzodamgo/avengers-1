# ALGORITMOS Y ESTRUCTURAS DE DATOS

## TRABAJO FINAL

### INTEGRANTES
* Joaquín Aguirre 18
* Bruno Tiglla Arrascue 18
* Renzo Damián Gomez 18

### INTRODUCCIÓN

En el curso de especialidad de la carrera de Ciencias de Computación, Algoritmos y Estructura de datos se les ha encargado a los alumnos un trabajo que tiene como competencia general, desarrollar un pensamiento innovador capaz de diseñar sistemas, componentes o procesos para encontrar soluciones en la atención a las necesidades de la gente.
En este caso trabajar con proyectos de DataScience para poder manejar grandes cantidades de datos de manera eficiente, mediante la búsqueda, organizacón y filtrado de datos.

### PROBLEMA

Cuando se quiere trabajar con grandes cantidades de datos, se necesita acceder a determinada información de forma rápida eficiente, veloz y consumiendo la menor cantidad de recursos posibles. Esto representa un problema considerable en la mayoría de proyectos de software destinados a un gran público o empresas con un gran número de clientes.  
En el proceso de desarrollo de software, una de las partes más importantes es que sea escalable conservando la usabilidad y los tiempos de carga. Para que nuestro programa cumpla con los requisitos establecidos se deberá crear una estructura capaz de soportar un millón de datos y ser capaz de ubicar, indexar y mostrar los datos en tiempo logarítmico.

### OBJETIVOS

**Objetivo General:** 
- Al finalizar el curso el estudiante construye tipos de datos abstractos y algoritmos teniendo en cuenta las restricciones impuestas por los recursos computacionales.

**Objetivos Específicos:**
1. **Crear** una biblioteca basada en pandas que nos permita manejar una gran cantidad de datos.
2. **Implementar la biblioteca** que nos permita importar, indexar, seleccionar, filtrar y ordenar datos por columnas. Además de exportar datos a archivos planos con diferentes formatos.
3. **Testear** el buen y completo funcionamiento de la biblioteca.

### MARCO CONCEPTUAL

#### DATAFRAME 

Es una estructura de datos tabular bidimensional, potencialmente heterogénea, con ejes etiquetados (filas y columnas).
Es decir, los datos se alinean de forma tabular en filas y columnas. Éste consta de tres componentes principales: los datos, las filas y las columnas.

#### ORDENAMIENTO

Es la operación de arreglar los registros de una tabla en algún orden secuencial de acuerdo a un criterio de ordenamiento.
Éste se efectúa con base en el valor de algún campo en un registro. El propósito principal de un ordenamiento es el de facilitar las búsquedas de los miembros del conjunto ordenado.
El ordenar un grupo de datos significa mover los datos o sus referencias para que queden en una secuencia tal que represente un orden, el cual puede ser numérico, alfabético o incluso alfanumérico, ascendente o descendente.
En la computación el ordenamiento de datos también cumple un rol muy importante, ya sea como un fin en sí o como parte de otros procedimientos más complejos.
Se han desarrollado muchas técnicas en este ámbito, cada una con características específicas, y con ventajas y desventajas sobre las demás.Algoritmos de búsqueda

#### BÚSQUEDA

Un algoritmo de búsqueda como lo dice su nombre es una secuencia de pasos para encontrar dentro de una lista de datos un dato determinado.
Los algoritmos de búsqueda varían según los pasos o métodos que emplea para encontrar datos, pero todos cumplen con el mismo fin.
Entre los más frecuentes se encuentran la búsqueda binaria, lineal.

La búsqueda lineal es la técnica más simple y funciona bien con arreglos pequeños y no ordenados, consiste en comparar la clave de búsqueda con todos los elementos del arreglo.

La búsqueda binaria es la técnica de más alta velocidad y funciona eficientemente con arreglos grandes y ordenados previamente, consiste en eliminar, tras cada comparación, la mitad de los elementos del arreglo en los que se efectúa la búsqueda.
Primero localiza el elemento central del arreglo y luego lo compara con la clave de búsqueda, si son iguales, se ha encontrado dicha clave y se devuelve el subíndice de ese elemento.
De otro modo, el problema se reduce a buscar en una mitad del arreglo.

### DIAGRAMA DE CLASES (ALTO NIVEL)

![](diagram_class.jpg)

### CRONOGRAMA

Referencia a milestones del proyecto.
