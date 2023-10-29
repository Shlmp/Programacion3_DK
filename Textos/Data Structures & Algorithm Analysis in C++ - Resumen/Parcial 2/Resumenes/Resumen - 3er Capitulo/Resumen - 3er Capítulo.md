# 3.1 - Tipos de Datos Abstractos (ADT)
Un tipo de dato abstracto (ADT) es un conjunto de objetos con una lista de operaciones, en otras palabras, son abstracciones matemáticas en donde en ningún momento en su definición se menciona cómo las operaciones están implementadas.

Algunas operaciones de los ADT son *add*, *remove*, *size* y *contains*. O, para definir un ADT distinto en el conjunto, se usan *union* y *find*.

Una clase en C++ permite la implementación de ADT, escondiendo los detalles de implementación necesarios, obligando a cualquier parte del programa que desee hacer una operación en el ADT a usar el método apropiado.
En caso de necesitar cambiar los detalles de implementación, se puede simplemente cambiar las rutinas que genera las operaciones del ADT.

No hay reglas en caunto a qué operaciones debe de hacer cada ADT, al igual que el arreglo de errores y tie breaking, esto suele ser designado por el diseñador del programa.

# 3.2 - Lista ADT
Algunas operaciones comunes en las listas ADT son *printList*, *makeEmpty*, *find*, *insert*, *remove* y *findKth*. También se pueden agregar operaciones como *next* y *previous*.

## 3.2.2 - Listas Enlazadas Simples
Por medio de los punteros, los cuales mantienen la dirección de memoria de los datos, se puede generar un orden en una lista.

La lista enlazada consiste en una serie de nodos, los cuales no están necesariamente juntos en la memoria. Cada nodo contiene el elemento y un vínculo, o enlace, a otro nodo con su sucesor, siendo este el *next*. El último next apunta a lo que conoce como *nullptr*.

La manera en la que funciona simplemente empieza en el primer nodo de la lista y continúa a través de la lista, siguiendo los siguientes enlaces (next).

Si se sabe dónde debe de hacerse un cambio, insertar o remover elementos de la lista enlazada no genera tanto movimiento, sino solo se necesita un número de cambios a los enlaces de nodos.

**Ejemplo de punteros**
![[Pasted image 20231003164801.png]]

**Ejemplo de listas enlazadas (A = Anya)**
![[Pasted image 20231003164712.png]]
![[Pasted image 20231003164736.png]]
# 3.3 - *vector* y *list* en el STL
El lenguaje de C++ tiene incluido en su librería una implementación de estructuras de datos comunes, mejor conocido como Standard Template Library (STL). La lista ADT es una de esas estructuras de datos implementadas por el STL. También se les conoce como colecciones o contenedores.
Hay dos implementaciones de la lista ADT, *vector* y *lista*. El vector provee una implementación de arreglos expandible a la lista ADT, sin embargo, agregar o eliminar nuevos elementos consume demasiados recursos, a menos de que estos cambios ocurran al final del vector. La lista provee una implementación de listas doble enlazadas a la lista ADT, haciendo que añadir o eliminar elementos no consuma muchos recursos, siempre y cuando se conozca la posición. Sin embargo, las listas no son indexables.

**Definición de indexable**
![[Pasted image 20231003171350.png]]
*Definición más concreta que encontré*


Tanto el vector como la lista son plantillas de clase instanciadas con el tipo de elementos que almacenan. Los siguientes métodos funcionan en todos los contenedores STL:
![[Pasted image 20231003171605.png]]
![[Pasted image 20231003171945.png]]

*Los siguientes métodos solo funcionan en listas ya que un vector no permite cambios eficientes en el inicio*
![[Pasted image 20231003172147.png]]

*El vector tiene sus propios métodos que no son parte de listas. De estos, 2 sirven para indexar eficientemente, mientras que los otros 2 permiten al programador revisar y cambiar la capacidad interna*
![[Pasted image 20231003173036.png]]
**Cómo funciona Object**
los templates son una manera en la que podemos estructurar una función o un conjunto de códigos sin importar si estos son int, float, etc. Para eso, usamos plantillas de función, no son una función como tal, pero sirven como plantilla de una.
No se consideran una función porque no se le está dando el tipo de función (int, float, etc) con la que va a trabajar.

## 3.3.1 - Iteradores
En algunas operaciones, específicamente en aquellas que necesitan añadir o remover elementos en la mitad de la lista, requieren la posición. En el STL, una posición está representada por un iterador.
### **Obtener un Iterador**
Las listas STL definen un par de métodos.
![[Pasted image 20231003174714.png]]

*Referencia del begin y end*
![[Pasted image 20231003175520.png]]

### Métodos de Iteradores
![[Pasted image 20231003175147.png]]![[Pasted image 20231003175200.png]]

De la misma manera, para
```c++
for(vector::iterator itr = v.begin(); itr != v.end(); itr++)
	cout << *itr << endl;
```
también se puede escribir como
```c++
vector<int>::iterator itr = v.begin();
while (itr != v.end())
	cout << *itr++ << endl; //Se puede usar una sobrecarga de operadores para acceder al elemento actual y luego avanzar al siguiente utilizando *itr++ 
```
### Operaciones de Contenedores que Requieren Iteradores
![[Pasted image 20231003180349.png]]

## 3.3.2 - Uso de *erase* en una Lista
![[Pasted image 20231003182906.png]]
*Usar iteradores para remover cada otro elemento en una lista es eficiente para una lista, pero no para un vector*
*Esto se debe a que en una lista la rutina de tiempo será linear porque cada llamada al **erase** toma un tiempo constante, mientras que en el vector la rutina entera tomará un tiempo cuadrático por sus llamadas al **erase** ineficientes*

La línea *auto* es una aplicación de C++11 que permite evitar escribir Container::iterator.

## 3.3.3 - const-iterators
$*itr$ no solo es el valor del elemento que el iterador está viendo, sino que también es ese mismo elemento.
![[Pasted image 20231003184445.png]]
Toda colección del STL contiene tanto iteradores como iteradores constantes. Su mayor diferencia es que el $operator*$ para un *const_iterator* regresa una referencia constante, y por ende, $*itr$ para un *const_iterator* no puede aparecer en la parte izquierda de una asignación.
Al mismo tiempo, el compilador obliga a usar un *const_iterator* para checar un conjunto constante al generar 2 versiones del *begin* y 2 versiones del *end*.
```c++
iterator begin()
const_iterator begin() const

iterator end()
const_iterator end() const
```
Si se usa *auto* para declarar los iteradores, el compilador será quien decida si este será un *iterator* o *const_iterator*. En gran parte, esto ayuda al programador de estar al pendiente del tipo de iterador correcto.

También es posible escribir código funcional sin la necesidad de tener *begin* y *end* en el *Container*, estas se llaman *Non-member Free Functions* o funciones libres sin miembros. En una función libre sin miembros, tanto el *begin* como el *end* son definidos de tal manera que permiten el uso de *begin(c)* en cualquier lugar donde se permita *c.begin()*. Esto ayuda al escribir código genérico ya que, si se escribe *begin(c)* en vez de *c.begin()*, esto permite que el código funcione tanto en contenedores que tengan miembros *begin* y *end* como en contenedores que no tienen *begin* y *end*, pero que pueden ser ampliadas por Non-member free functions adecuadas.
![[Pasted image 20231003205758.png]]
Es posible tener *begin* y *end* como funciones libres en C++11 gracias a la adición de características del lenguaje como *auto* y *decltype*.
![[Pasted image 20231003210759.png]]

# 3.4 - Implementación de *vector*
En el siguiente código se muestra una implementación de una plantilla de una clase de vector usable, en donde el vector es de tipo de primera clase. Esto significa que el vector puede ser copiado y la memoria que usa puede ser automáticamente reclamada a través del destructor.

#### **Datos a de tener en cuenta de los arreglos primitivos**
- El arreglo simplemente es un puntero a un bloque de memoria, el tamaño del arreglo debe mantenerse separado por el programador.
- El bloque de memoria puede ser asignado por medio de *new[]* pero luego debe de ser liberado por medio de *delete[]*.
- El tamaño del bloque de memoria no puede ser reajustado, pero se puede obtener e inicializar un bloque nuevo más grande con el antiguo para después liberar el antiguo.

#### Detalles importantes del vector
- El vector mantendrá el arreglo primitivo (por medio de un puntero al bloque de memoria asignado), la capacidad del arreglo y el número actual de elementos almacenados en el vector.
- El vector implementará *Los Cinco Grandes (The Big-Five)* para proporcionar semánticas de copia profunda para el constructor de copia y el *operator=*, al igual que proporcionar un destructor para reclamar el arreglo primitivo.
- El vector proporcionará una rutina de cambio de tamaño, la cual cambiará el tamaño del vector, y una rutina de reserva la cual cambiará la capacidad del vector. La capacidad es cambiada al obtener un nuevo bloque de memoria para el arreglo primitivo, copiar el bloque antiguo al nuevo bloque y reclamar el bloque antiguo.
- El vector proporcionará una implementación de *operator[]*, *operator[]* es normalmente implementado con un accesor y un mutador.
- El vector proporcionará rutinas basicas como size, empty, clear, back, pop_back y push_back. La rutina push_back llama al *reserve* en caso de que el tamaño y la capacidad son iguales.
- El vector proporcionará apoyo a los *iterators* y *const_iterators*, al igual que a los métodos *begin* y *end* asociados.

##### **Ejemplo de Código**
```c++
1 #include <algorithm>
2
3 template <typename Object>
4 class Vector
5 {
6 public:
7 explicit Vector( int initSize = 0 ) : theSize{ initSize },
8 theCapacity{ initSize + SPARE_CAPACITY }
9 { objects = new Object[ theCapacity ]; }
10
11 Vector( const Vector & rhs ) : theSize{ rhs.theSize },
12 theCapacity{ rhs.theCapacity }, objects{ nullptr }
13 {
14 objects = new Object[ theCapacity ];
15 for( int k = 0; k < theSize; ++k )
16 objects[ k ] = rhs.objects[ k ];
17 }
18
19 Vector & operator= ( const Vector & rhs )
20 {
21 Vector copy = rhs;
22 std::swap( *this, copy );
23 return *this;
24 }
25
26 ~Vector( )
27 { delete [ ] objects; }
28
29 Vector( Vector && rhs ) : theSize{ rhs.theSize },
30 theCapacity{ rhs.theCapacity }, objects{ rhs.objects }
31 {
32 rhs.objects = nullptr;
33 rhs.theSize = 0;
34 rhs.theCapacity = 0;
35 }
36
37 Vector & operator= ( Vector && rhs )
38 {
39 std::swap( theSize, rhs.theSize );
40 std::swap( theCapacity, rhs.theCapacity );
41 std::swap( objects, rhs.objects );
42
43 return *this;
44 }
45
46 void resize( int newSize )
47 {
48 if( newSize > theCapacity )
49 reserve( newSize * 2 );
50 theSize = newSize;
51 }
52
53 void reserve( int newCapacity )
54 {
55 if( newCapacity < theSize )
56 return;
57
58 Object *newArray = new Object[ newCapacity ];
59 for( int k = 0; k < theSize; ++k )
60 newArray[ k ] = std::move( objects[ k ] );
61
62 theCapacity = newCapacity;
63 std::swap( objects, newArray );
64 delete [ ] newArray;
65 }
66
67 Object & operator[]( int index )
68 { return objects[ index ]; }
69 const Object & operator[]( int index ) const
70 { return objects[ index ]; }
71
72 bool empty( ) const
73 { return size( ) == 0; }
74 int size( ) const
75 { return theSize; }
76 int capacity( ) const
77 { return theCapacity; }
78
79 void push_back( const Object & x )
80 {
81 if( theSize == theCapacity )
82 reserve( 2 * theCapacity + 1 );
83 objects[ theSize++ ] = x;
84 }
85
86 void push_back( Object && x )
87 {
88 if( theSize == theCapacity )
89 reserve( 2 * theCapacity + 1 );
90 objects[ theSize++ ] = std::move( x );
91 }
92
93 void pop_back( )
94 {
95 --theSize;
96 }
97
98 const Object & back ( ) const
99 {
100 return objects[ theSize - 1 ];
101 }
102
103 typedef Object * iterator;
104 typedef const Object * const_iterator;
105
106 iterator begin( )
107 { return &objects[ 0 ]; }
108 const_iterator begin( ) const
109 { return &objects[ 0 ]; }
110 iterator end( )
111 { return &objects[ size( ) ]; }
112 const_iterator end( ) const
113 { return &objects[ size( ) ]; }
114
115 static const int SPARE_CAPACITY = 16;
116
117 private:
118 int theSize;
119 int theCapacity;
120 Object * objects;
121 };
```

##### **Explicación del Código**
![[Pasted image 20231003230113.png]]
![[Pasted image 20231003230307.png]]
![[Pasted image 20231003230337.png]]
# 3.5 - Implementación de *lista*
Como en el caso del vector, el siguiente código muesta una implementación de una plantilla de clase de tipo lista, la cual es implementada como una lista de doble enlace y por lo tanto se necesita apuntar a ambos lados de la lista. Esto ayuda a mantener un costo de tiempo constante por operación, siempre y cuando se conozca la posición. La posición puede ser cualquier fin de la lista (inicio o fin) o una posición especificada por un iterador.

#### Se necesitan 4 clases:
- La clase ***lista***, que contiene enlaces en ambos puntos, el tamaño de la lista y un organizador de métodos.
- La clase ***nodo***, la cual probablemente sea una clase privada anidada. Un nodo contiene los datos y punteros a los nodos previos y siguientes, junto con los constructores apropiados.
- La clase ***const_iterator***, quien abstrae la noción de una posición y es una clase pública anidada. Este guarda un puntero al nodo actual y proporciona la implementación de las operaciones básicas de un iterador, en operadores sobrecargados como =, $==$, != y ++.
- La clase ***iterator***, que abstrae la noción de una posición y es una clase pública anidada. Tiene una función similar al ***const_iterator***, con excepción de que $operator*$ regresa una referencia al objeto actual, en vez de una referencia constante al objeto. Un problema técnico importante es que el ***iterator*** puede ser usado en cualquier rutina que requiera un ***const_iterator***, pero no vice versa.


Se puede crear un nodo extra al final de la lista para marcar el final de esta, al igual que un nodo extra al inicio de la lista para marcar su inicio. A estos nodos se les conoce como *nodo sentinela*, también conocidos como *nodo cabeza (header node)* al inicial, y *nodo cola (tail node)* al último.
Usar estos dos nodos ayua a simplificar el código ya que ayuda a remover una parte de casos especiales. Por ejemplo, si no se usa un nodo inicial, entonces la eliminación del primer nodo se convierte en un caso especial, ya que se debe reiniciar el enlace de la lista al primer nodo durante la eliminación y el algoritmo de eliminación necesita acceder al nodo anterior al nodo que se está eliminando. Sin un nodo cabeza, el primer nodo no tiene un nodo anterior.
![[Pasted image 20231004142046.png]]
![[Pasted image 20231004142102.png]]


##### Ejemplo de Código
```c++
1 template <typename Object>
2 class List
3 {
4 private:
5 struct Node
6 { /* See Figure 3.13 */ };
7
8 public:
9 class const_iterator
10 { /* See Figure 3.14 */ };
11
12 class iterator : public const_iterator
13 { /* See Figure 3.15 */ };
14
15 public:
16 List( )
17 { /* See Figure 3.16 */ }
18 List( const List & rhs )
19 { /* See Figure 3.16 */ }
20 ~List( )
21 { /* See Figure 3.16 */ }
22 List & operator= ( const List & rhs )
23 { /* See Figure 3.16 */ }
24 List( List && rhs )
25 { /* See Figure 3.16 */ }
26 List & operator= ( List && rhs )
27 { /* See Figure 3.16 */ }
28
29 iterator begin( )
30 { return { head->next }; }
31 const_iterator begin( ) const
32 { return { head->next }; }
33 iterator end( )
34 { return { tail }; }
35 const_iterator end( ) const
36 { return { tail }; }
37
38 int size( ) const
39 { return theSize; }
40 bool empty( ) const
41 { return size( ) == 0; }
42
43 void clear( )
44 {
45 while( !empty( ) )
46 pop_front( );
47 }
48 Object & front( )
49 { return *begin( ); }
50 const Object & front( ) const
51 { return *begin( ); }
52 Object & back( )
53 { return *--end( ); }
54 const Object & back( ) const
55 { return *--end( ); }
56 void push_front( const Object & x )
57 { insert( begin( ), x ); }
58 void push_front( Object && x )
59 { insert( begin( ), std::move( x ) ); }
60 void push_back( const Object & x )
61 { insert( end( ), x ); }
62 void push_back( Object && x )
63 { insert( end( ), std::move( x ) ); }
64 void pop_front( )
65 { erase( begin( ) ); }
66 void pop_back( )
67 { erase( --end( ) ); }
68
69 iterator insert( iterator itr, const Object & x )
70 { /* See Figure 3.18 */ }
71 iterator insert( iterator itr, Object && x )
72 { /* See Figure 3.18 */ }
73
74 iterator erase( iterator itr )
75 { /* See Figure 3.20 */ }
76 iterator erase( iterator from, iterator to )
77 { /* See Figure 3.20 */ }
78
79 private:
80 int theSize;
81 Node *head;
82 Node *tail;
83
84 void init( )
85 { /* See Figure 3.16 */ }
86 };
```
##### Explicación del Código
![[Pasted image 20231004142933.png]]
![[Pasted image 20231004143004.png]]

###### Figura 3.13
![[Pasted image 20231004143604.png]]
###### Figura 3.14
```c++
1 class const_iterator
2 {
3 public:
4 const_iterator( ) : current{ nullptr }
5 { }
6
7 const Object & operator* ( ) const
8 { return retrieve( ); }
9
10 const_iterator & operator++ ( )
11 {
12 current = current->next;
13 return *this;
14 }
15
16 const_iterator operator++ ( int )
17 {
18 const_iterator old = *this;
19 ++( *this );
20 return old;
21 }
22
23 bool operator== ( const const_iterator & rhs ) const
24 { return current == rhs.current; }
25 bool operator!= ( const const_iterator & rhs ) const
26 { return !( *this == rhs ); }
27
28 protected:
29 Node *current;
30
31 Object & retrieve( ) const
32 { return current->data; }
33
34 const_iterator( Node *p ) : current{ p }
35 { }
36
37 friend class List<Object>;
38 };
```
![[Pasted image 20231004143842.png]]

###### Figura 3.15 (continuación de 3.14)
```c++
39 class iterator : public const_iterator
40 {
41 public:
42 iterator( )
43 { }
44
45 Object & operator* ( )
46 { return const_iterator::retrieve( ); }
47 const Object & operator* ( ) const
48 { return const_iterator::operator*( ); }
49
50 iterator & operator++ ( )
51 {
52 this->current = this->current->next;
53 return *this;
54 }
55
56 iterator operator++ ( int )
57 {
58 iterator old = *this;
59 ++( *this );
60 return old;
61 }
62
63 protected:
64 iterator( Node *p ) : const_iterator{ p }
65 { }
66
67 friend class List<Object>;
68 };
```
![[Pasted image 20231004144046.png]]

###### Figura 3.16
```c++
1 List( )
2 { init( ); }
3
4 ~List( )
5 {
6 clear( );
7 delete head;
8 delete tail;
9 }
10
11 List( const List & rhs )
12 {
13 init( );
14 for( auto & x : rhs )
15 push_back( x );
16 }
17
18 List & operator= ( const List & rhs )
19 {
20 List copy = rhs;
21 std::swap( *this, copy );
22 return *this;
23 }
24
25
26 List( List && rhs )
27 : theSize{ rhs.theSize }, head{ rhs.head }, tail{ rhs.tail }
28 {
29 rhs.theSize = 0;
30 rhs.head = nullptr;
31 rhs.tail = nullptr;
32 }
33
34 List & operator= ( List && rhs )
35 {
36 std::swap( theSize, rhs.theSize );
37 std::swap( head, rhs.head );
38 std::swap( tail, rhs.tail );
39
40 return *this;
41 }
42
43 void init( )
44 {
45 theSize = 0;
46 head = new Node;
47 tail = new Node;
48 head->next = tail;
49 tail->prev = head;
50 }
```
![[Pasted image 20231004144139.png]]

###### Figura 3.17 (contexto)
![[Pasted image 20231004144436.png]]

###### Figura 3.18
![[Pasted image 20231004144525.png]]

###### Figura 3.19 (contexto)
![[Pasted image 20231004144622.png]]

###### Figura 3.20
```c++
1 // Erase item at itr.
2 iterator erase( iterator itr )
3 {
4 Node *p = itr.current;
5 iterator retVal{ p->next };
6 p->prev->next = p->next;
7 p->next->prev = p->prev;
8 delete p;
9 theSize--;
10
11 return retVal;
12 }
13
14 iterator erase( iterator from, iterator to )
15 {
16 for( iterator itr = from; itr != to; )
17 itr = erase( itr );
18
19 return to;
20 }
```
![[Pasted image 20231004144722.png]]
![[Pasted image 20231004144738.png]]

# Conclusiones
Tanto el vector como la lista ayudan a enlistar una serie de elementos y ayudan a agregar, eliminar, modificar, encontrar y leer estos elementos. Cada uno tiene sus ventajas y sus desventajas. Un ejemplo sería la ineficiencia del vector para añadir o eliminar elementos al inicio de la lista, ya que debería cambiar la posición de todos los elementos consecuentes al lugar en donde se agregó el nuevo elemento, problema que no ocurre con las listas. O la incapacidad de las listas para acceder a elementos individuales de manera eficiente, caso que no ocurre con los vectores.

#### Tabla para diferenciar Vector *vs* List
![[Pasted image 20231004150020.png]]


# Referencias
ChatGPT - Explicación de "Indexable"

GeeksforGeeks, “Difference between vector and list,” _GeeksforGeeks_, Jun. 2022, [Online]. Available: https://www.geeksforgeeks.org/difference-between-vector-and-list/ - Tabla

Weiss and W. M. Allen, _Data Structures and algorithm analysis in C++_. Pearson Education India, 2007. - Información general