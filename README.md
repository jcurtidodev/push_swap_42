# 🔄 Push Swap - Ordenación de Stacks 📚
## 📌 Descripción

Bienvenido a push_swap, un programa diseñado para ordenar una lista de números enteros utilizando dos pilas (stacks). El objetivo es ordenar los números de la pila **a** en orden ascendente utilizando un conjunto mínimo de operaciones. El programa optimiza la cantidad de movimientos y asegura que los números estén en el orden correcto al final.


## 🎯 Funcionalidades
**Objetivo**: Ordenar la pila a de menor a mayor con la menor cantidad posible de operaciones.

**Operaciones disponibles**:
- **sa**: Intercambia los dos primeros elementos de la pila a.
- **sb**: Intercambia los dos primeros elementos de la pila b.
- **ss**: Realiza sa y sb al mismo tiempo.
- **pa**: Toma el primer elemento de b y lo coloca en a.
- **pb**: Toma el primer elemento de a y lo coloca en b.
- **ra**: Desplaza todos los elementos de a hacia arriba una posición.
- **rb**: Desplaza todos los elementos de b hacia arriba una posición.
- **rr**: Realiza ra y rb al mismo tiempo.
- **rra**: Desplaza todos los elementos de a hacia abajo una posición.
- **rrb**: Desplaza todos los elementos de b hacia abajo una posición.
- **rrr**: Realiza rra y rrb al mismo tiempo.


## 📦 Requisitos
- **libft**: Este proyecto utiliza la biblioteca libft para funciones estándar de C.

## 🖥️ Compilación e Instalación
⚠️ **IMPORTANTE** ⚠️
Una vez clones `push_swap`, debes clonar `libft` dentro del repositorio para que funcione.  


📂 push_swap/
```bash
git clone https://github.com/jcurtidodev/libft-42.git
```
Una vez hecho, continua con:
```bash
make
```
Este comando generará el ejecutable push_swap.

Para limpiar archivos objeto y binarios:
```Makefile
make clean      # Elimina archivos objeto
make fclean     # Elimina archivos objeto y ejecutables
make re         # Realiza una recompilación completa
```
## 🚀 Uso

El programa recibe como argumento una lista de enteros representando la pila a en el formato siguiente:
```
./push_swap 3 1 4 2 5
```
Este ejemplo ordenará la pila a de menor a mayor. El programa mostrará una lista de instrucciones necesarias para ordenar la pila, de la forma más eficiente posible.

## 🏗️ Estructura del Código
```
📂 push_swap/
├── 📜 Makefile            # Compilación del proyecto
├── 📜 index_utils.c       # Funciones auxiliares para la gestión de índices
├── 📜 main.c              # Función principal
├── 📜 main_utils.c        # Funciones auxiliares principales
├── 📜 moves_controller.c  # Gestión de las operaciones
├── 📜 push_swap.c         # Código principal para ordenar las pilas
├── 📜 push_swap.h         # Archivo de cabecera
├── 📜 push_swap_moves.c   # Funciones relacionadas con los movimientos
└── 📜 push_swap_utils.c   # Funciones auxiliares para ordenar
```
## 🛠️ Funciones Permitidas
- `read`, `write`, `malloc`, `free`, `exit`
- `ft_printf` y/o cualquier función de **libft**

## 🏆 Reglas y Restricciones

- El Makefile debe compilar los archivos fuente y no debe realizar relink.
- Las variables globales están prohibidas.
- El programa debe recibir una lista de números enteros como argumento (pila a).
- El programa debe mostrar la lista de instrucciones más corta posible para ordenar la pila a de menor a mayor.
- Las instrucciones deben separarse utilizando un salto de línea (\n).
- El programa debe ordenar la pila a utilizando el mínimo número de operaciones posibles.
- Durante la evaluación se comparará el número de instrucciones generadas con un límite máximo de operaciones.
- Si no se especifican parámetros o si hay errores (como argumentos no enteros, duplicados o fuera de rango), el programa deberá mostrar Error seguido de un salto de línea y terminar correctamente.

# 📚 Método de Ordenación por Radices utilizado - Radix Sort
## 📌 ¿Qué es Radix Sort?

**Radix Sort** es un algoritmo de ordenación que organiza los números (o cadenas de texto) basándose en sus dígitos o caracteres, procesando un dígito a la vez. Es un algoritmo no comparativo, lo que significa que no realiza comparaciones directas entre los elementos como otros algoritmos como el **quicksort** o **merge sort**. En cambio, se enfoca en los valores de los dígitos de los números, comenzando desde el dígito menos significativo (el de las unidades) hasta el más significativo.
## 🎯 ¿Cómo funciona Radix Sort?

Radix Sort trabaja en varias etapas:

1. **Organizar por dígitos**: Comienza con el dígito menos significativo de cada número (la unidad) y ordena todos los números según este dígito.
2. **Mover al siguiente dígito**: Una vez que los números están organizados por su primer dígito, el algoritmo pasa al siguiente dígito (las decenas) y vuelve a ordenar los números.
3. **Repetir hasta que se ordenen todos los dígitos**: Este proceso se repite para cada dígito, y se va moviendo hacia los dígitos más significativos (decenas, centenas, etc.) hasta que todos los dígitos de los números hayan sido procesados.
4. **Orden final**: Después de procesar todos los dígitos, los números estarán ordenados de menor a mayor.

## 🔄 Radix Sort en acción

**Ejemplo de ordenación con Radix Sort**:

Supongamos que tenemos los siguientes números:
`[170, 45, 75, 90, 802, 24, 2, 66]`.

Radix Sort los ordenaría en las siguientes etapas:

1. **Primera fase**: Ordenar por el primer dígito (las unidades):
    [170, 90, 802, 2, 45, 75, 24, 66]

2. **Segunda fase**: Ordenar por el segundo dígito (las decenas):
    [802, 2, 24, 45, 66, 170, 75, 90]

    Tercera fase: Ordenar por el tercer dígito (las centenas):
    [2, 24, 45, 66, 75, 90, 170, 802]

Al final, los números están ordenados:
[2, 24, 45, 66, 75, 90, 170, 802].
🎨 Características y Ventajas

    No comparativo: A diferencia de algoritmos como quicksort o mergesort, radix sort no compara los elementos entre sí, lo que le permite trabajar de manera eficiente en casos donde los números tienen muchas cifras.
    Estabilidad: Radix sort es un algoritmo estable, lo que significa que si dos elementos tienen el mismo valor en el dígito actual, su orden relativo no cambiará.
    Eficiencia en ciertos casos: Para listas de números con un rango de valores pequeño o números con pocos dígitos (como en algunos proyectos de 42), Radix Sort puede ser más eficiente que otros algoritmos como quicksort, ya que la complejidad temporal es lineal en función del número de dígitos.

🛠️ Complejidad Temporal

    Mejor caso, peor caso, caso promedio: O(k * n), donde:
        n es el número de elementos en el array.
        k es el número de dígitos en el número más grande.

El valor de k depende de la magnitud de los números que se están ordenando. A diferencia de otros algoritmos de ordenación como quicksort (O(n log n)), Radix Sort puede ser muy eficiente si k es pequeño.
🔧 Implementación de Radix Sort

Radix Sort se suele implementar utilizando una técnica de ordenación estable como counting sort para ordenar los números por sus dígitos. Esto asegura que el orden de los números con el mismo valor en un dígito no cambie durante las iteraciones.
