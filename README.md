# IntroPP2190093
Contiene las diferentes carpetas en las que se encuentran los proyectos trabajados durante el semestre.

En este `README.md`, encontrarás instrucciones para compilar y ejecutar ambos programas, así como sugerencias sobre cómo medir y comparar los tiempos de ejecución para diferentes tamaños de matrices. Asegúrate de modificar la variable `N` en los archivos de código fuente para cambiar el tamaño de las matrices y realizar las comparaciones necesarias.

# Multiplicación de Matrices - Comparación de Rendimiento

Este repositorio contiene dos implementaciones de la multiplicación de matrices en C++: una versión secuencial y otra paralela utilizando OpenMP.

## Instrucciones de Compilación y Ejecución

### Secuencial
1. Abre una terminal.
2. Navega al directorio que contiene `matrix_multiplication_seq.cpp`.
3. Compila el código fuente secuencial utilizando un compilador de C++:

Ejemplo:
  ```bash
   g++ -o matrix_multiplication_seq matrix_multiplication_seq.cpp

Ejecuta el programa
 ./matrix_multiplication_seq


### Paralelo (OpenMP)
1.Abre una terminal.
2.Asegúrate de que tengas OpenMP habilitado en tu compilador de C++. Si estás utilizando g++, OpenMP suele estar habilitado por defecto. De lo contrario, consulta la documentación de tu compilador para habilitarlo.
3.Navega al directorio que contiene matrix_multiplication_omp.cpp.
4.Compila el código fuente paralelo utilizando un compilador de C++:

Ejemplo:

g++ -o matrix_multiplication_omp -fopenmp matrix_multiplication_omp.cpp

Ejecuta el programa
./matrix_multiplication_omp

Comparación de Tiempos de Ejecución

Se puede medir el tiempo de ejecución de cada implementación para diferentes tamaños de matrices. Utilizando el comando time en la terminal para obtener el tiempo de ejecución. Por ejemplo:

time ./matrix_multiplication_seq



