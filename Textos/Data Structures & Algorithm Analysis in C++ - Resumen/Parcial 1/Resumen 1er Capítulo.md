
## 1.1 - De qué Trata el Libro
Hay múltiples soluciones para el mismo problema, algunos de estos son más eficientes o "mejores" que otros, sin embargo, no hay un algoritmo perfecto. Cada uno tiene sus ventajas y desventajas. 

### Ejemplo
Para identificar **N** número más grande en un conjunto de **X** números, se podría obtener al usar un método de ordenamiento como el Bubble-Sort, Merge-Sort, Quick-Sort, para ordenarlos de menor a mayor y luego regresar el número en el espacio deseado.

El problema con este es que puede llegar a ser tardado y no es muy eficiente, por lo que otra manera mejor sería juntar una cantidad **K** de números en un arreglo y ordenarlos de mayor a menor y de ahí leer uno por uno los números que faltan. Conforme van leyendo los números faltantes, en caso de ser menor es ignorado y en caso contrario este es puesto en su posición correcta. una vez terminado, se regresa el número en el espacio deseado.

No obstante, este algoritmo también llega a ser ineficiente al ponerlo a prueba con millones de operaciones. Sin embargo, ambos son simples de programar y sirven para ordenar números.


## 1.2 - Revisión Matemática
### 1.2.1 - Exponentes
![[Pasted image 20230920125313.png]]
**Fórmulas importantes que tener en cuenta**
### 1.2.2 - Logaritmos
Todos los logaritmos tienen una base de 2 a menos de que sea específicado que sea otro.
#### Teorema 1
![[Pasted image 20230920130059.png]]
*No logro comprender cómo leer la fórmula*
#### Teorema 
![[Pasted image 20230920130225.png]]

Si consideramos que
- Log A = X
- Log B = Y
- Log AB = Z
Y que la base default de los logarítmos es 2
$$
A = 2^X --
B = 2^Y --
AB = 2^Z
$$
La fórmula quedaría como:
$$2^X * 2^Y = 2^Z$$
$$X + Y = Z$$
Otras fórmulas importantes son:
![[Pasted image 20230920131826.png]]
  
### 1.2.3 - Series
Las siguientes fórmulas son las más fáciles de recordar
![[Pasted image 20230920144029.png]]
![[Pasted image 20230920144040.png]]
y si 0 < A < 1
![[Pasted image 20230920144327.png]]
y mientras que **N** tiende a ∞, la suma se acerca a 1/(1 - A).
Esta fórmula se puede derivar haciendo que S sea la suma:
$$S = 1 + A + A^2 + A^3 + A^4 +...$$
$$AS = A + A^2 + A^3 + A^4 +...$$
Se pueden restar ambas ecuaciones ya que son una serie convergente, cancelando prácticamente todos los términos en la derecha.
$$S - AS = 1$$
$$S = \frac 1{1 - A}$$
![[Pasted image 20230920152002.png]]
*No entendí esta parte*

Cualquier serie común de análisis puede ser evaluada con la fómula básica:
$$\sum_{i=1} ^N i = \frac {N(N+1)}{2} ≈ \frac {N^2}{2}$$
Otras fórmulas no tan comunes pero que existen y pueden llegas a salir son:
![[Pasted image 20230921134143.png]]

Cuando k = -1, la última fórmula no es válida, por ende, se usa otra fórmula. Hn se conoce como "Números Harmónicos" y la suma es conocida como la "Suma Harmónica" El error en su aproximación tiende a *y ≈0. 57721566*, también conocido como la **constante Euler**.
![[Pasted image 20230921134609.png]]

Estas son manipulaciones algebráicas generales:
![[Pasted image 20230921134642.png]]



### 1.2.4 - Aritmética Modular
A es congruente de B % N, escrito como $$A ≡ B (mod N)$$ si N divide A - B. De la misma manera, lo mismo es si cualquiera A o B es dividido por N. Si A ≡ B (mod N), entonces $$A + C ≡ B + C (mod N)$$ y
$$AD ≡ BD (mod N)$$

La mayoría de las veces, N es un número primo, por lo que hay 3 teoremas importantes:
1. Si N es primo, entonces ab ≡ 0 (mod N) es cierto **solo si** a ≡ 0 (mod N) o b ≡ 0 (mod N).
*Si un número primo N divide un producto de 2 números, este divide almenos a uno de los 2 números*.
2. Si N es primo, entonces la ecuación ax ≡ 1 (mod N) tiene una única solución (mod N) para toda 0 < a < N. Esta solución, 0 < x < N, es la inversa multiplicativa.
3. Si N es primo, entonces la ecuación $$x^2 ≡ a (mod N)$$ tiene ya sea 2 soluciones (mod N) por todo 0 < a < N, o no tiene solución.




### 1.2.5 - P-Word
Las dos maneras más comúnes de demostrar afirmaciones en el análisis de la estructura de datos son prueba por inducción y prueba por contradicción (y ocasionalmente la prueba por intimidación, usado solamente por profesores). La mejor manera de demostrar que un teorema es falso es al enseñar un contraejemplo.
- **Prueba por Inducción**
		- Tiene dos partes estándares. El primer paso es demostrar un caso base, establecer que el teorema es verdadero para valores pequeños. Después, se asume una hipótesis inductiva, generalmente se asume que el teorema es verdadero para todos los casos hasta un límite k. Usando esta suposición, el teorema es demostrado como verdadero para el siguiente valor, normalmente siendo k + 1, demostrando el teorema.
- **Prueba por Contraejemplo**
		- La afirmación $$F_k ≤ k^2$$ es falsa. La manera más fácil de comprobarlo es al calcular $$F_{11} = 144 > 11^2$$
- **Prueba por Contradicción**
		- Asume que el teorema es falso y demuestra queesta suposición implica que alguna propiedad conocida es falsa y por ende, la suposición original es incorrecta. 




## 1.3 - Introducción Breve a Recursión
Una función que se llama a sí misma se considera Recursiva. Mientras que C++ permita a las funciones ser recursivas, es importante saber que C++ solo provee un intento de esa recursividad. No toda función recursiva matemática es eficiente, o correctamente implementada en la simulación de recursividad de C++. 
![[Pasted image 20230921181610.png]]
En este código, las líneas 3 y 4 son lo que se considera como el **caso base**, o el valor donde la función es directamente identificada sin necesidad de hacerla recursiva. Mientras que la línea 6 hace la llamada recursiva. La función de C++ no tiene mucho sentido sin el caso base.

### ¿No es esto solo lógica circular?
Aún cuando se está llamando la función a sí misma, no se está llamando un instante específico de la función a sí misma.
#### Ejemplo
Si evaluamos f(5) al calcular f(5), sería circular. Mientras que, si evaluamos f(5) al calcular f(4) no sería circular, a menos que f(4) luego sea evaluado al calcular f(5).



Una llamada recursiva seguirá siendo llamada hasta que se llegue a un caso base.
La recursión tiene 2 reglas fundamentales:
1. Casos Base - Siempre debe de haber casos base, los cuales pueden ser resueltos sin recursión.
2. Hacer Progreso - Para los casos que deben ser resueltos recursivamente, la llamada recursiva siempre debe de ser a un caso que haga progreso hacia un caso base.
3. Regla de Diseño - Asume que toda llamada recursiva funciona.


El mayor problema con una función recursiva es el coste escondido de recursos. Hay veces donde tal costo es justificable, ya que simplifican el diseño del algoritmo y suelen dar un código más leíble. Sin embargo, no debería ser usado como un sustituto para un bucle "for" simple.

Al escribir rutinas recursivas, es importante tener en cuenta las 4 reglas básicas de la recursividad:
1. Casos Base - Siempre debe de  haber casos base que pueden ser resueltos sin recursión.
2. Hacer Progreso - Para los casos que deben ser resueltos recursivamente, la llamada recursiva siempre debe llamar a un caso que haga progreso hacía un caso base.
3. Regla de Diseño - Asumir que toda llamada recursiva funciona.
4. Regla de Interés Compuesta - Nunca duplicar trabajo al resolver el mismo instante de un problema en una llamada recursiva distinta.


## 1.4 - Clases en C++
### 1.4.1 - Sintaxis Básica de una Clase
Una clase en C++ consiste de sus miembros, los cuales pueden ser tanto funciones como data (información). Las funciones se llaman Funciones Miembro. Cada instante de una clase es un Objeto. Cada objeto contiene los componentes data especificados en la clase (a menos de que los componentes sean estáticos). Una función miembro se usa para actuar en un objeto. Las funciones miembro también son conocidas como métodos.

Si un miembro es de acceso público (public) este puede ser accedido por cualquier método en cualquier clase.
Si un miembro es de acceso privado (private) solo puede ser accedido por métodos en su clase.

Normalmente, los miembros data (información) son declarados como privados, restringiendo el acceso a datos internos de la clase. Mientras que los métodos dedicados al uso general son hechos públicos.

Al usar miembros data privados, se puede cambiar la representación interna de un objeto sin alterar otras partes del programa que usen el objeto. Esto es porque el objeto es accedido a través de funciones miembro públicas, las cuales se mantienen igual.

En una clase, todos los miembros son privados por default.


Un constructor es un método que describe cómo un instante de una clase debe ser construido. Si no hay un constructor explícitamente definido, uno que inicialice los miembros data usando lenguajes default será automáticamente generado.

#### Ejemplo
``` c++
/**
2 * A class for simulating an integer memory cell.
3 */
4 class IntCell
5 {
6 public:
7 /**
8 * Construct the IntCell.
9 * Initial value is 0.
10 */
11 IntCell( )
12 { storedValue = 0; }
13
14 /**
15 * Construct the IntCell.
16 * Initial value is initialValue.
17 */
18 IntCell( int initialValue )
19 { storedValue = initialValue; }
20
21 /**
22 * Return the stored value.
23 */
24 int read( )
25 { return storedValue; }
26
27 /**
28 * Change the stored value to x.
29 */
30 void write( int x )
31 { storedValue = x; }
32
33 private:
34 int storedValue;
35 };
```



### 1.4.2 - Sintaxis de un Constructor Extra y Accesores
Aunque las clases funcionen como son escritas, hay sintaxis extra que ayuda a generar un mejor código.
#### Parámetros Default
Un valor default de 0 significa que 0 es usado si no hay parámetros dados. Parámetros default pueden ser usados in cualquier función, sin embargo, son normalmente usados en constructores.

#### Lista de Inicialización
La lista de inicialización es usada para inicializar los miembros data directamente. Usar una lista de inicilaización en vez de una sentencia de asignación puede ahorrar tiempo en casos donde los miembros data son de tipo clase con inicializaciones complejas. Puede llegar a ser necesario. Ejemplo, si un miembro data en constante (const, no es cambiable después de que el objeto fue creado), entonces el valor del miembro data solo puede ser inicializado en la lista de inicialización. También, si un miembro data es un tipo clase que no tiene un constructor con parámetro cero, entonces debe ser inicializado en la lista de inicialización.
```c++
1 /**
2 * A class for simulating an integer memory cell.
3 */
4 class IntCell
5 {
6 public:
7 explicit IntCell( int initialValue = 0 )
8 : storedValue{ initialValue } { }
9 int read( ) const
10 { return storedValue; }
11 void write( int x )
12 { storedValue = x; }
13
14 private:
15 int storedValue;
16 };
```

#### Constructor Explícito
Todo constructor con un parámetro debería de ser explícito para prevenir conversiones de tipo "detrás de escenas". De otra forma, hay reglas indulgentes que permiten conversiones de tipo sin usar operaciones explícitamente. Usualmente, esto es mala práctica ya que puede destruir una escritura fuerte y esto puede llevar a bugs difíciles de encontrar.

![[Pasted image 20230921195356.png]]
obj y 37 no son del mismo tipo, por ende se debería de cambiar.
![[Pasted image 20230921195512.png]]

#### Función de Miembro Constante
Una función miembro que examina pero no cambia el estado de su objeto es un accesor. Una función miembro que cambia el estado es un mutador, ya que este muta el estado del objeto.
En una clase de colección típica, isEmpty es un accesor, mientras que makeEmpty es un mutador.

En C++ se puede marcar cada función miembro como un accesor o como un mutador. Esto es un paso muy importante del proceso de diseño y no se debería de ver como un simple comentario. Hay consecuencias semánticas importantes que tener en cuenta.
Por ejemplo, los mutadores no pueden ser aplicados a objetos constantes. Por default, las funciones miembro son mutadores. Para hacer una función miembro un accesor, se debe añadir la palabra **const** después de cerrar el paréntesis que termina la lista de tipos de parámetro. const puede ser utilizado con múltiples significados. La declaración de función puede tener const en tres diferentes contextos, pero, solo el const después del cierre de paréntesis significa un accesor.

### 1.4.3 - Separación de Interface e Implementación
En C++, es común separar la interfaz de clase de sus implementaciones. La interface enlista la clase y sus miembros (data y funciones).

#### Comandos del Preprocesador
La interfaz es normalmente puesta en un archivo que termina  con .h. El código de origen que requiere conocimiento de la interfaz debe incluir #include en la interfaz del archivo.

Ocasionalmente, en proyectos complicados hay archivos que incluyen otros archivos, y hay un peligro de que un interfaz sea leído dos veces en el transcurso de la compilación de un archivo. Para prevenir esto, cada archivo de cabecera usa el preprocesadorpara definir un símbolo cuando la interfaz de clase es leída.
![[Pasted image 20230921202645.png]]
![[Pasted image 20230921202707.png]]
![[Pasted image 20230921202747.png]]



#### Operador de Resolución de Alcance
En el archivo de implementación, el cual normalmente termina con .cpp, .cc o .c, cada función miembro debe identificar la clase a la que pertenece. De otra manera, se supondrá que la función es de alcance global, causando muchos errores. La sintaxis es ClassName::member.
*El :: se llama Operador de Resolución de Alcance*

#### Las Firmas deben Ser Iguales
La firma de una función miembro implementada debe ser exactamente igual a la firma enlistada el la interfaz de la clase. Recordando si una función miembro es un accesor (via const al final) o un mutador.

#### Los Objetos son Declarados como Tipos Primitivos
Un objeto es declarado como si fuera un tipo primitivo. Por ende, los siguientes ejemplos son declaraciones legales de un objeto tipo IntCell:
![[Pasted image 20230921203955.png]]
No obstante, los siguientes ejemplos no lo son:
![[Pasted image 20230921204032.png]]
Esto es porque obj3 su constructor de un parámetro es explícito, sería legal si utilizara paréntesis para identificar su valor. obj 4 indica que es una función que no toma parámetros y regresa un IntCell.
![[Pasted image 20230921204410.png]]

### 1.4.4 - Vector y String
Los estándares de C++ define 2 clases: el Vector y el String.
Las clases vector y string en STL tratan los arreglos y strings como objetos de primera clase. Un vector sabe qué tan largo son. Dos objetos de tipo String pueden ser comparados por == , <, etc. Ambos pueden ser copiados con un =. 

## 1.5 - Detalles de C++
### 1.5.1 - Punteros
Una variable de puntero es una variable que almacena la dirección de lugar de otro objeto. Es el mecanismo fundamental usado en la estructura de datos. 

#### Declaración
![[Pasted image 20230921205859.png]]

#### Creación de Objetos Dinámico
![[Pasted image 20230921210022.png]]

#### Colección de Basura y Delete
Cuando un objeto ya no es referenciado, la operación *delete* debe ser aplicada al objeto a través de un puntero. De otra manera, la memoria que consume será perdida hasta que el programa termine, causando lo que se conoce como **memory leak**.
*No usar **new** cuando una variable automática puede ser usada*


#### Asignación y Comparación de Punteros
La asignación y comparación de punteros en C++ se basa en el valor del puntero, o de la dirección de memoria que contiene. Así, dos punteros son iguales si apuntan al mismo objeto, y si apuntan a distintos objetos, los punteros no son iguales, aún si los objetos son iguales.
#### Accediendo a Miembros de un Objeto a Través de un Puntero
Si un puntero apunta a un tipo clase, entonces un miembro visible del objeto puede ser accedido a via el operador ->.
#### Operador Adress-of (&)
Este operador regresa la ubicación de memoria en donde un objeto está.

### 1.5.2 - ValoresL, ValoresR y Referencias
Un valorL es una expresión que identifica un objeto no temporal. Un valorR es una expresión que identifica un objeto temporal o un valor no asociado a un objeto.
![[Pasted image 20230921211808.png]]
arr, str, arr[x], &x, y, z, ptr, *ptr, (*ptr)[x] -> son valoresL
2, "foo", x+y, str.substr(0,1) -> son valoresR

Una referencia de valorL es declarada al escribir & después de un tipo. Este se convierte en otro nombre del objeto al que está referenciando.
![[Pasted image 20230921212219.png]]
Una referencia de valorR se declara al escribir && después de un tipo. Este tiene las mismas características que una refeerencia de valorL con excepción de que este también puede referenciar un valorR.
![[Pasted image 20230921212442.png]]

#### Usos de las Referencias de valorL #1: Alias de Nombres Complicados
Usar una variable de referencia local con el único propósito de renombrar un objeto que es conocido por una expresión complicada. 
![[Pasted image 20230921212722.png]]
#### Usos de las Referencias de valorL #2: Rango de Bucles For
Supongamos que se desea incrementar por 1 todos los valores en un vector. Mientras que
![[Pasted image 20230921213057.png]]
funciona, también se podría escribir:
![[Pasted image 20230921213236.png]]

#### Usos de las Referencias de valorL #3: Evitar una Copia
Supongamos que se tiene una función findMax que regresa el valor más grande e un vector. Si se da un nuevo vector arr e invocamos findMax, se escribiría
![[Pasted image 20230921213522.png]]
Sin embargo, el vector guarda objetos grandes, haciendo que el valor de x sea una copia del valor más grande en arr. Si se desea obtener una copia, no habría problema, sin embargo esto es muy improbable y es mejor declarar  que x es una referencia.
![[Pasted image 20230921213832.png]]



Las referencias de valor tienen 2 conceptos importantes:
1. Las variables de referencia son usadas para evitar copiar objetos a través de bordes de llamadas de funciones.
2. La sintaxis es necesaria en declaraciones de funciones y en regresos para habilitar el paso y regresar valores usando referencias.

### 1.5.3 - Paso de Parámetros
Los parámetros en C++ pueden llegar a ser demasiado grandes y complejos que puede llegar a ser ineficiente el copiarlo. Por ende, se crearon diferentes maneras de pasar parámetros.
- Call-by-Reference
- Call-by-Reference-to-a-Constant
- Call-by-Value
- Call-by-Rvalue-Reference

### 1.5.4 - Paso de Regreso
![[Pasted image 20230921230826.png]]
Estas firmas muestran la idea básica que la función regresa un objeto de un tipo el cual puede ser usado por el llamador. En todos los casos, el resultado es un valorR.
### 1.5.5 - std::swap y std::move
![[Pasted image 20230921233008.png]]

## 1.6 - Plantillas
### 1.6.1 - Plantillas de Función
Una plantilla de función no es en realidad una función, sino un patrón de lo que podría convertirse una función.
Como los argumentos de plantilla pueden asumir cualquier tipo de clase, cuando se deciden las convenciones de pasos de parámetros y de pasos de regreso, se debería asumir que los argumentos de plantilla no son de tipo primitivo y, por eso, se tiene un regreso por referencia constante.
![[Pasted image 20230921215249.png]]
![[Pasted image 20230921215320.png]]
### 1.6.2 - Plantillas de Clase
Una plantilla de clase funciona similar a una plantilla de función.![[Pasted image 20230921215515.png]]
![[Pasted image 20230921215543.png]]
### 1.6.3 - Object, Comparable y Ejemplo
![[Pasted image 20230921231647.png]]
Aquí se muestra un ejemplo de un tipo de clase que implementa la funcionalidad requeridad de Comparable e ilustra un **Operator Overloading**. Esto permite definir el significado de un built-in operator. La clase Square representa un cuadrado al guardar el tamaño de un lado y definir operator<. También, por default, provee un constructor de parámetro cero, operator= y un constructor de copia. Por lo que se puede usar como Comparable in la funcioón findMax.
### 1.6.5 - Compilación Separada de Plantillas de Clase
Como las clases normales, las plantillas de clase pueden ser implementadas ya sea completamente en su declaración o se puede separar la interfaz desde la implementación.
Para prevenir errores de compilación a través de plataformas, se implementan todas las plantillas de clase completamente es su declaración en el archivo de cabecera.
## 1.7 - Uso de Matrices
### 1.7.1 - Miembros de Data, Constructor y Accesores Básicos
Una matríz es representada por un miembro de datos de matríz el cual es declarado como un vector de vector(Object). El constructor, primero construye un arreglo como entradas de filas en cada tipo vevctor(Object) que se construye.
Después el cuerpo del constructor es puesto, y cada fila es reescalada para tener columnas. El constructor termina con lo que parece ser un arreglo de dos dimensiones.
![[Pasted image 20230921222040.png]]


### 1.7.2 - Operator[]
La idea de operator[] es que si se tiene una matriz m, entonces m[i] debería regresar un vector correspondiente a la fila i de la matrix m. Y por ende, m[i],[j] debería dar la posición en j para el vector m[i]. Así, el matrix operator[] regresa un vector(Object) y no un Object.

## Conclusiones y Opiniones Críticas
Aunque ambas formas logren el objetivo, escribir un código de manera primitiva puede lograr a ser demasiado ineficiente y a gastar demasiados recursos para un resultado simple y que no requiere de tanto gasto. Un ejemplo de esto sería el uso amplio de funciones como for, while, do while en situaciones que simplemente no los requieren y que se pueden reemplazar por otro código más complejo para entender (en especial al compararlo con un for) mas logra un uso más eficiente de los recursos.

Aún cuando este libro se enfoca en el lenguaje de C++, me genera la duda, ¿otros lenguajes como python o java tienen algún algoritmo similar para matrices, plantillas, o hasta para punteros?
Por lo que pude encontrar, en Python, no hay punteros como tal. Si no que se utiliza el paso de referencia cuando se pasan los objetos a una función.
## Referencias
Weiss and W. M. Allen, _Data Structures and algorithm analysis in C++_. Pearson Education India, 2007.
“Akshat Dhawan,” Mar. 03, 2023. https://datatrained.com/post/pointers-in-python/#:~:text=No%2C%20Python%20does%20not%20have%20any%20type%20of%20pointers%20in,variables%20are%20passed%20by%20value.