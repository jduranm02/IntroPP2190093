David Vasquez - Juan Duran.

# Evaluación 2 -  Procesamiento Memoria Distribuída

En este proyecto se busca como objetivo hacer un seguimiento sobre el uso de memoria distribuida a través de paso de mensajes, usando MPI. Se trabajará con el problema de la ecuacion del calor en un dominio 2D.

## Código

Se cuenta con los siguientes archivos:

* main.c: El archivo principal del programa. Contiene la lógica principal para llevar a cabo la simulación del problema de calor en 2D. Esto incluye la parte de hacer que diferentes procesos MPI trabajen juntos, administrar la información de temperatura en el sistema y crear salidas visuales.
* core.c: Este archivo se encarga de que los diferentes procesos MPI se comuniquen entre sí y luego utiliza un método llamado "diferencias finitas" para calcular cómo cambia la temperatura en un sistema bidimensional con el tiempo.
* heat.h: En este archivo, se definen las estructuras de datos y las funciones necesarias para hacer posible la solución de un problema de calor en dos dimensiones utilizando MPI. Sirve para organizar y estructurar todo lo que el programa necesita.
* io.c: Estos archivos se encargan de tareas como preparar los datos iniciales, mostrar información en pantalla y guardar datos. También permiten la posibilidad de reanudar una simulación desde un punto específico si fuera necesario.
* pngwriter.c y pngwriter.h: Este código está diseñado para tomar datos bidimensionales que representan temperaturas y convertirlos en imágenes en formato PNG. Es útil para visualizar los resultados de la simulación.
* utilities.c: Estos archivos son esenciales para administrar la memoria utilizada por el programa y para realizar operaciones en los datos de temperatura que se están calculando en la simulación del problema de calor. Ayudan a que el programa funcione de manera eficiente.
* setup.c: Este archivo se encarga de configurar y preparar la simulación del problema de calor. Esto implica generar datos iniciales, gestionar la comunicación entre procesadores y definir las dimensiones del sistema en el que se está simulando la temperatura.

## Funcionamiento

El archivo "main.c" desempeña un papel central en la simulación del proceso de resolución de la ecuación de calor en un entorno bidimensional. Inicia definiendo variables clave, como la constante de difusión y los campos que representan la temperatura actual y la temperatura previa, además de configurar los pasos de tiempo y la información necesaria para la paralelización MPI.

A continuación, establece el entorno MPI y establece los valores iniciales de los campos de temperatura. Durante la simulación, realiza cálculos en intervalos regulares para actualizar cómo cambia la temperatura en el dominio a lo largo del tiempo. También se encarga de generar imágenes que representan visualmente la evolución de la temperatura y de guardar puntos de control que permiten reanudar la simulación desde un punto específico si es necesario.

Al concluir la simulación, "main.c" calcula el tiempo que llevó ejecutar todo el proceso y presenta los resultados obtenidos. Además, se asegura de liberar la memoria utilizada durante la simulación antes de cerrar el entorno MPI. En resumen, este archivo concentra la lógica fundamental para la simulación de la ecuación de calor en 2D, abordando aspectos como la paralelización, el seguimiento de la temperatura y la creación de representaciones visuales de los resultados.


## Pasos para la compilación

1. Entrar a un entorno Mpi: Para comenzar, es necesario ingresar a un ambiente que sea compatible con MPI. Para iniciar múltiples procesos MPI. En el siguiente ejemplo, se inicia un entorno que consta de 24 procesos paralelos
   
      Codigo: srun -n 24 --pty /bin/bash
  
3. Cargar Módulos necesarios para la ejecucion mpi, con el siguiente comando:

      Codigo: module load devtools/mpi/openmpi/3.1.4
  
4. Se limpian archivos anterior para la proxima ejecución:
 
      Codigo: make clean

5. Se Copilan los programas:

      Codigo: make

## Ejecuión

Habiendo preparado el entorno es posible ejecutar el programa principal: Esto se hara de dos maneras, de manera interactiva y de manera pasiva.

### Ejecución interactiva

Los comandos de ejecución utilizados son los siguientes:

* mpirun -np X ./heat_mpi  - Ejecución con valores predetermiandos.
  
* mpirun -np X ./heat_mpi botella.dat - Ejecucion haciendo uso de datos inciiales.
  
* mpirun -np X ./heat_mpi botella.dat 1000 - Ademas del campo inicial se agregan pasos de tiempo, en este caso 1000
  
* mpirun -np X ./heat_mpi 800 800 1000 --> Sumado a lo anterior, se agregan dimensiones de ancho y alto, en este caso 800 x 800


Siendo x el numero de procesos paralelos se realizaran pruebas con x = 8.

### Ejecución Interactiva

Pruebas con los codigos mencionados anteriormente:

* mpirun -np 8 ./heat_mpi  - Ejecución con valores predetermiandos.

  ![image](https://github.com/jduranm02/IntroPP2190093/assets/70860023/851206ce-bc95-4daf-a52d-03c88fa64028)

* mpirun -np 8 ./heat_mpi botella.dat - Ejecucion haciendo uso de datos inciiales.

  ![image](https://github.com/jduranm02/IntroPP2190093/assets/70860023/5adde40c-dab1-43f8-8364-5df642abe170)
  
* mpirun -np 8 ./heat_mpi botella.dat 1000 - Ademas del campo inicial se agregan pasos de tiempo, en este caso 1000

![image](https://github.com/jduranm02/IntroPP2190093/assets/70860023/1be0d85a-a4c2-46e9-b9e6-8a4b5ab27466)
  
* mpirun -np 8 ./heat_mpi 800 800 1000 --> Sumado a lo anterior, se agregan dimensiones de ancho y alto, en este caso 800 x 800

![image](https://github.com/jduranm02/IntroPP2190093/assets/70860023/05e98d68-6078-41b5-9247-fa7f490aebbc)



### Ejecución pasiva

* Se debe crear un script ejecutable ejecutable.sh que se encargue de la compilación:
    
```
#!/bin/bash
#SBATCH --job-name=heat_mpi_job
#SBATCH --ntasks=4
#SBATCH --nodes=2
#SBATCH --cpus-per-task=1
#SBATCH --output=heat_mpi_output.txt

module load devtools/mpi/openmpi/3.1.4

EXECUTABLE=./heat_mpi
INPUT_FILE=botella.dat
NUM_STEPS=1000

mpirun -np 8 $EXECUTABLE $INPUT_FILE $NUM_STEPS
```

se ejecuta en el servidor con el comando:

```
ejecutable.sh
```
