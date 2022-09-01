![Tec de Monterrey](images/logotecmty.png)
# Actividad 2.1 Implementación de "Hash String"

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
En esta actividad, deberá generar el código de redundancia cíclica (CRC) para un archivo de texto.  El CRC es un código de detección de errores usado frecuentemente en redes digitales y en dispositivos de almacenamiento para detectar cambios accidentales en los datos. En este casi, emplearemos una función de hash para generar este código. ([Manejo de archivos](https://www2.eii.uva.es/fund_inf/cpp/temas/10_ficheros/ficheros_cpp.html))

## <span style="color: rgb(26, 99, 169);">**Entrada**</span>
El programa recibe el nombre de un archivo de texto, seguido de un número entero, *N*, múltiplo de 4 (4 <= *N* <= 64).

## <span style="color: rgb(26, 99, 169);">**Salida**</span>
La salida es una cadena de longitud *N*/4 que es la representación hexadecimal de aplicación de una función de dispersión al archivo de texto. La función de dispersión se explica a continuación:
- El número entero *N* determina el número de columnas que contendrá una tabla donde ser irán acomodando los caracteres del archivo de texto (incluyendo los saltos de línea) en los renglones que sean necesarios.
- Si el número de caracterez en el archivo de entrada no es múltiplo de *N*, el último renglón se deberá rellenar con el valor de *N*.
- Para cada renglón, se deberá aplicar la siguiente función de dispersión H(renglón) = la suma de los ASCII de cada caracter en el renglón) % 256.

La salida se genera concatenando la representación hexadecimal (*mayúsculas*) a dos dígitos de cada renglón.

## <span style="color: rgb(26, 99, 169);">**Ejemplo de entrada**</span>
```
quijote1.txt 4
```

## <span style="color: rgb(26, 99, 169);">**Ejemplo de salida**</span>
```
14816F15A15512F19A11517116C1A611D1B41621A81A51291091AD16C1B1FD16416016B19A15A16015C15B1601621B517214615A1AC16916415D19FB019B1611AD12F1441A81091A316115A1671491B712E1A61601601611A811114816E17F19A1C416E1561A71191B11601781AE1241A915F1B1161DD19C1AC16E1601AD1221C51A516016B1641BE109170192161F11BE15814614A1AD16216915F1A41251AA1581601B116015F15A1B512016017B1B31B6EE1601651281741601581581BE1A11591651961601281B316A15515D16211813114F17615716414F16715619710916E1AB1A8E51641B615816BF41A414415C16E1B0E517017814C1AD1291A813215915C1B41441631A9E917019F14E16319CF51AF14F14A1491681BE16019816116915F1AB1501481331571571AE1BE15A1161AA1091A41241B21671661C812515C1AC19B10215715A15215E1001B51571A316B16714F16E1A71B014E14F190C813519913215816C1581661AB1531AA14D15F1631CA16915E1B1157EB1B117016416B1711AA1C016A1B91AB16B14E1501B515B16B16419BDA19915E14716716C1BE1651611641BE1671B611D16816B15F1501A815313F11D16B1951231C715810D1B11001A

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
