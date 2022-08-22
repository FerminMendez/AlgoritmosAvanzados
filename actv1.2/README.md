![Tec de Monterrey](images/logotecmty.png)
# Actividad 1.2 Implementación de la técnica de programación "Programación dinámica" y "algoritmos avaros"

## <span style="color: rgb(26, 99, 169);">¿Qué tengo que hacer?</span>
En este repositorio encontrarás el archivo "main.cpp". En este archivo deberás desarrollar la implementación del problema presentado en esta actividad.  En la parte superior del archivo coloca, en comentarios, tus datos. Por ejemplo:
```
// =========================================================
// File: main.cpp
// Authors:
//  Edward Elric - A00123456
//  Alphonse Elric - A00124598
// Date: 01/01/2021
// =========================================================
```
Implementa, <span style="text-decoration-line: underline;">en equipos de 2 personas (máximo)</span>, una solución para el problema que se describe a continuación.

## <span style="color: rgb(26, 99, 169);">**Descripción**</span>
Utilizando las técnicas de **Programación Dinámica** y **Algoritmos Ávidos**, desarrollar un programa en C++ que resuelva el problema del cambio de monedas.

## <span style="color: rgb(26, 99, 169);">**Entrada**</span>
El programa recibe número entero, *N*, seguido de *N* valores enteros que representan las diferentes denominaciones disponibles de las monedas. A continuación, se recibe *Q*, seguido de *Q* valores enteros que representan los cambios que se tienen calcular.

## <span style="color: rgb(26, 99, 169);">**Salida**</span>
El programa deberá desplegar para cada una de las *Q* consultas, la cantidad de monedas que se requieren con la solución **Ávida**, así cómo el número de monedas de la denominación requeridas, **ordenadas de menor a mayor**. En seguida, se deplegará la información que genera la solución de **Programación Dinámica**. Cada consulta estará separada con una línea de 10 guiones medios. Revisa el formato de salida que se presenta a continuación.

## <span style="color: rgb(26, 99, 169);">**Ejemplo de entrada**</span>
```
3
1 3 4
3
3 11 10
```

## <span style="color: rgb(26, 99, 169);">**Ejemplo de salida**</span>
```
QUERY #1, CHANGE = 3
GREEDY SOLUTION, TOTAL COINS = 1
CURRENCY = 3 AMOUNT = 1

DP SOLUTION, TOTAL COINS = 1
CURRENCY = 3 AMOUNT = 1
---------
QUERY #2, CHANGE = 11
GREEDY SOLUTION, TOTAL COINS = 3
CURRENCY = 3 AMOUNT = 1
CURRENCY = 4 AMOUNT = 2

DP SOLUTION, TOTAL COINS = 3
CURRENCY = 3 AMOUNT = 1
CURRENCY = 4 AMOUNT = 2
---------
QUERY #3, CHANGE = 10
GREEDY SOLUTION, TOTAL COINS = 4
CURRENCY = 1 AMOUNT = 2
CURRENCY = 4 AMOUNT = 2

DP SOLUTION, TOTAL COINS = 3
CURRENCY = 3 AMOUNT = 2
CURRENCY = 4 AMOUNT = 1
---------

```

Para probar tu implementación, compila tu programa con el comando:
```
g++ -std=c++11 main.cpp -o app
```
Posteriormente, ejecuta tu programa. Para realizar las pruebas, puedes usar las siguientes líneas de código.
```
./app < inputX.txt > mysolutionX.txt
diff mysolutionX.txt outputX.txt
```
Si el segundo comando no tiene ninguna salida, los resultados que obtuviste son los esperados.

## <span style="color: rgb(26, 99, 169);">**¿Bajo qué criterios se evalúa mi evidencia?**</span>

- **80%** - Para cada una de las funcionalidades se evaluará:

    - **Excelente (80%)** - pasa correctamente todos los casos de prueba.
    - **Muy Bien (60%)** - pasa correctamente el 75% de los casos de prueba.
    - **Bien (40%)** - pasa correctamente el 50% de los casos de prueba.
    - **Insuficiente (20%)** - pasa correctamente menos del 50% de los casos de prueba.

- **10%** - El código deberá seguir los lineamientos estipulados en el estándar de codificación: <span class="instructure_file_holder link_holder">[liga_estándar_codificación](estandar.pdf)</span>
- **10%** - Se especifica (en comentarios) la complejidad computacional de cada uno de las funciones desarrolladas.

## <span style="color: rgb(26, 99, 169);">**¿Dónde la entrego?**</span>
Cuando hayas pasado todas las pruebas, recuerda publicar el código en tu repositorio (*git push*).

## <span style="color: rgb(26, 99, 169);">**Importante**</span>
Recuerda colocar el nombre y las matrículas de ambos integrantes en en los comentarios iniciales. En caso de que se incumpla este punto, se penalizará con 20 puntos sobre la calificación obtenida.
