# Parte1.1
- ¿Qué es un Rvalor y un Lvalor?
	- Un Rvalor (Rvalue) es aquel valor que no tiene espacio de memoria y, por lo tanto, solo puede estar en la parte derecha.
	- Un Lvalor (Lvalue) es aquel valor que sí tiene un espacio de memoria y, por ende, puede estar tanto en la parte izquierda como en la parte derecha.

- ¿Porqué es necesario que una clase tenga constructores y operadores por
copia y por referencia?
	- Porque se podría llegar a necesitar una actualización a lo dicho por el usuario o también se podría necesitar el valor original, ya que se trabaja con Rvalores y Lvalores.

- ¿Qué función desarrollan los :: en la implementación de la clase?
	- :: indica que el Lvalor está dentro de la clase.

- ¿Cómo se le denomina a cuando una clase posee un operador puede
tener múltiples implementaciones dependiendo de los argumentos que
este reciba?
	- Overload o sobrecarga.

- ¿Cúal es la funcion del archivo .h ?
	- Header - Su función es asignar variables y declarar los parámetros de una clase.




# Parte 2
```c++
#include <iostream>

int algoritmo1(int n) {
	int resultado = 0;
	
	for (int i = 0; i < n; i++) {
		resultado += i; // Operación simple O(1)
	}
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			resultado += i * j; // Operación simple O(1)
		}
	}

return resultado;
}

int main() {
	int n;
	std::cout << "Ingrese el valor de n: ";
	std::cin >> n;
	int resultado = algoritmo1(n);
	std::cout << "Resultado: " << resultado << std::endl;
	
	return 0;
}
```

La complejidad del código es cuadrática $0(n^2)$ ya que hay un for adentro de otro for. En total hay 3 for mas uno no interactúa con los otros.