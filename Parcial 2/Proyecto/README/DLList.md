```c++
#ifndef DLLIST_H  
#define DLLIST_H  
  
#include <iostream>  
#include <utility>  
  
template <typename Object>  
class DLList{  
private:  
    struct Node  {  
        Object data;  
        Node *next;  
        Node *prev;  
  
        //Constructor de copia  
        Node(const Object &d = Object{}, Node *n = nullptr, Node *p = nullptr)  
                : data{d}, next{n}, prev{p} {}  
  
        //Constructor de referncia  
        Node(Object &&d, Node *n = nullptr, Node *p = nullptr)  
                : data{std::move(d)}, next{n}, prev{p} {}  
    };  
  
public:  
    class iterator{  
    public:  
        //constructor implicito, se hace nulo el puntero  
        iterator() : current{nullptr} {}  
  
        //Operador * para que se compporte como puntero  
        Object &operator*() {  
            if(current == nullptr)  
                throw std::logic_error("Trying to dereference a null pointer.");  
            return current->data;  
        }  
  
        //Movimiento  
        //Operador hace que pueda moverse por la lista.        iterator &operator++() {  
            if(current)  
                current = current->next;  
            else  
                throw std::logic_error("Trying to increment past the end.");  
            return *this;  
        }  
  
        iterator operator++(int) {  
            iterator old = *this;  
            ++(*this);  
            return old;  
        }  
  
        iterator &operator--() {  
            if(current)  
                current = current->prev;  
            else  
                throw std::logic_error("Trying to decrease past the beginning.");  
            return *this;  
        }  
  
        iterator operator--(int) {  
            iterator old = *this;  
            --(*this);  
            return old;  
        }  
  
        iterator &operator+(int addition){  
  
            for(int i = 0; i<addition;i++){  
                ++(*this);  
            }  
            return  *this;  
        }  
  
        //Operadores para realizar comparaciones  
        bool operator==(const iterator &rhs) const {  
            return current == rhs.current;  
        }  
  
        bool operator!=(const iterator &rhs) const {  
            return !(*this == rhs);  
        }  
  
    protected:  
        //apunta al nodo al que estoy trabajando en ese momento  
        Node *current;  
        iterator(Node *p) : current{p} {}  
        //la clase amigo de acceso a los atributos privados  
        friend class DLList<Object>;  
  
        Object & retrieve() const{  
            return current->data;  
        }  
    };  
  
public:  
    //Define la dimension de la lista  
    //Cuando se llame al constructor, ya tiene que estar una cabeza y una cola    DLList() {  
        init();  
    }  
  
    //Destructor de la lista  
    //Primero borra el contenido y despues la cola y la cabeza    ~DLList() {  
        clear();  
        delete head;  
        delete tail;  
    }  
  
    //Sirve para meter el iterador al principio o al final  
    iterator begin() { return {head->next}; }  
    iterator end() { return {tail}; }  
  
    //el tamaño de la lista, para que un iterador sepa cuanto debe recorrer  
    int size() const { return theSize; }  
    bool empty() const { return size() == 0; }  
  
    //Mientras no este vacia borra el objeto de en frente  
    void clear() { while (!empty()) pop_front(); }  
  
    //Si la lista esta vacia da un error, si no retorna el inicio  
    Object &front() {  
        if(empty())  
            throw std::logic_error("List is empty.");  
        return *begin();  
    }  
  
    //funcion de push por copia  
    void push_front(const Object &x) {  
        insert(begin(), x);  
    }  
    //funcion de push por referencia  
    void push_front(Object &&x) {  
        insert(begin(), std::move(x));  
    }  
  
    void push_back(const Object &x) {  
        insert(end(), x);  
    }  
    //funcion de push por referencia  
    void push_back(Object &&x) {  
        insert(end(), std::move(x));  
    }  
  
    //elimina el valo de en frente  
    void pop_front() {  
        if(empty())  
            throw std::logic_error("List is empty.");  
        erase(begin());  
    }  
  
    //Recibe un iterador, lee esa posicion e inserta un código en la posicion que le demos  
    //este funciona por copia    iterator insert(iterator itr, const Object &x) {  
        Node *p = itr.current;  
        theSize++;  
        return {p->prev = p->prev->next = new Node{x, p, p->prev}};  
    }  
  
    //este funciona por referencia  
    iterator insert(iterator itr, Object &&x) {  
        Node *p = itr.current;  
        theSize++;  
        return {p->prev = p->prev->next = new Node{std::move(x), p, p->prev}};  
    }  
  
    void insert(int pos, const Object &x) {  
        insert(get_iterator(pos), x);  
    }  
  
    iterator get_iterator(int a)  
    {  
        iterator it = begin();  
        for(int i = 0; i != a; ++i) {  
            ++it;  
        }  
        return it;  
    }  
  
    //recibe un iterador y borra el dato en la posicion que le digamos  
    iterator erase(iterator itr) {  
  
        if (itr == end())  
            throw std::logic_error("Cannot erase at end iterator");  
        Node *p = itr.current;  
        iterator returnValue(p->next);  
        p->prev->next = p->next;  
        p->next->prev = p->prev;  
        delete p;  
        theSize--;  
  
        return returnValue;  
    }  
  
    void erase(int pos)  
    {  
        erase(get_iterator(pos));  
    }  
  
    //Getter para toda la lista  
    void print() {  
        iterator itr = begin();  
        while (itr != end()) {  
            std::cout << *itr << " ";  
            ++itr;  
        }  
        std::cout << std::endl;  
    }  
  
  
protected:  
    Node *head;  
    Node *tail;  
    int theSize;  
    //init necesita acceso a los datos privados para inicializar una lista vacia  
    void init() {  
        head = new Node;  
        tail = new Node;  
        theSize = 0;  
  
        head->next = tail;  
        head->prev = nullptr;  
  
        tail->prev = head;  
        tail->next = nullptr;  
    }  
  
  
};  
  
#endif //DLLIST_H
```
Sigo con dudas de esta parte. No como tal del código sino del cómo arreglamos una parte. El código original que teníamos tenía un error en la manera que añadía insert. Por lo que yo entendí, push_back sí lograba insertarlo al final de la lista, y el push_front lo añadía al inicio, no daba errores en estos.
El error pasaba cuando se deseaba agregar una variable en un espacio que no fuera el inicio o el final. Hacía una de dos problemas, los añadía una posición antes de la deseada o los añadía al inicio de la lista sin importar la posición que se desaba, no recuerdo exactamente el problema. De igual manera, se tenía que arreglar, por lo que esto lo intentamos arreglar de muchas formas (cambiando la definición de *init*, modificando *insert*, y modificando alguna otra variable que nos causaba duda {ej. *head* a *p*}).

Sin embargo, esto causó que modificaramos demasiadas partes del código y llegó a confundirme en cuanto a los errores que teníamos y las soluciones/modificaciones que hicimos.

Al final el código funciona como se desea, mas no sé el por qué se arregló, cómo se arregló o qué lo arregló.

En sí, estas serían mis dudas actuales de los temas vistos, logro comprender la diferencia entre una pila y una cola (stack & queue) y las diferencias entre una lista simple y una doblemente enlazada, al menos las bases.

Adjunto el código anterior y el primer código:
### Código Anterior
```c++
#ifndef DLLIST_DLLIST_H
#define DLLIST_DLLIST_H
#include <iostream>
#include <utility>
template <typename Object>
class DLList{
private:
    struct Node  {
        Object data;
        Node *next;
        Node *prev;

        //Constructor de copia
        Node(const Object &d = Object{}, Node *n = nullptr, Node *p = nullptr)
                : data{d}, next{n}, prev{p} {}

        //Constructor de referncia
        Node(Object &&d, Node *n = nullptr, Node *p = nullptr)
                : data{std::move(d)}, next{n}, prev{p} {}
    };

public:
    class iterator{
    public:
        //constructor implicito, se hace nulo el puntero
        iterator() : current{nullptr} {}
        //Operador * para que se compporte como puntero
        Object &operator*() {
            if(current == nullptr)
                throw std::logic_error("Trying to dereference a null pointer.");
            return current->data;
        }
        //Movimiento
        //Operador hace que pueda moverse por la lista.
        iterator &operator++() {
            if(current)
                current = current->next;
            else
                throw std::logic_error("Trying to increment past the end.");
            return *this;
        }
        iterator operator++(int) {
            iterator old = *this;
            ++(*this);
            return old;
        }
        iterator &operator--() {
            if(current)
                current = current->prev;
            else
                throw std::logic_error("Trying to decrease past the beginning.");
            return *this;
        }
        iterator operator--(int) {
            iterator old = *this;
            --(*this);
            return old;
        }

        iterator &operator+(int addition){

            for(int i = 0; i<addition;i++){
                ++(*this);
            }
            return  *this;
        }

        //Operadores para realizar comparaciones
        bool operator==(const iterator &rhs) const {
            return current == rhs.current;
        }
        bool operator!=(const iterator &rhs) const {
            return !(*this == rhs);
        }

    protected:
        //apunta al nodo al que estoy trabajando en ese momento
        Node *current;
        iterator(Node *p) : current{p} {}
        //la clase amigo de acceso a los atributos privados
        friend class DLList<Object>;
    };
public:
    //Define la dimension de la lista
    //Cuando se llame al constructor, ya tiene que estar una cabeza y una cola
    DLList() : head(new Node()), tail(new Node()), theSize(0) {
        head->next = tail;
    }
    //Destructor de la lista
    //Primero borra el contenido y despues la cola y la cabeza
    ~DLList() {
        clear();
        delete head;
        delete tail;
    }
    //Sirve para meter el iterador al principio o al final
    iterator begin() { return {head->next}; }
    iterator end() { return {tail}; }
    //el tamaño de la lista, para que un iterador sepa cuanto debe recorrer
    int size() const { return theSize; }
    bool empty() const { return size() == 0; }
    //Mientras no este vacia borra el objeto de en frente
    void clear() { while (!empty()) pop_front(); }
    //Si la lista esta vacia da un error, si no retorna el inicio
    Object &front() {
        if(empty())
            throw std::logic_error("List is empty.");
        return *begin();
    }
    //funcion de push por copia
    void push_front(const Object &x) { insert(begin(), x); }
    //funcion de push por referencia
    void push_front(Object &&x) { insert(begin(), std::move(x)); }
    void push_back(const Object &x) { insert(end(), x); }
    //funcion de push por referencia
    void push_back(Object &&x) { insert(end(), std::move(x)); }
    //elimina el valo de en frente
    void pop_front() {
        if(empty())
            throw std::logic_error("List is empty.");
        erase(begin());
    }
    //Recibe un iterador, lee esa posicion e inserta un código en la posicion que le demos
    //este funciona por copia
    iterator insert(iterator itr, const Object &x) {
        Node *p = itr.current;
        p->next = new Node{x, p->next, p};
        theSize++;
        return iterator(p->next);
    }

    //este funciona por referencia
    iterator insert(iterator itr, Object &&x) {
        Node *p = itr.current;
        p->next = new Node(std::move(x),p->next, p);
        theSize++;
        return iterator(p->next);
    }

    void insert(int pos, const Object &x) {
        insert(get_iterator(pos), x);
    }
    iterator get_iterator(int a)
    {
        iterator it = begin();
        for(int i = 0; i != a; ++i) {
            ++it;
        }
        return it;
    }
    //recibe un iterador y borra el dato en la posicion que le digamos
    iterator erase(iterator itr) {
        if (itr == end())
            throw std::logic_error("Cannot erase at end iterator");
        Node *p = head;
        while (p->next != itr.current) p = p->next;
        p->next = itr.current->next;
        delete itr.current;
        theSize--;
        return iterator(p->next);
    }
    void erase(int pos)
    {
        erase(get_iterator(pos));
    }
    //Getter para toda la lista
    void print() {
        iterator itr = begin();
        while (itr != end()) {
            std::cout << *itr << " ";
            ++itr;
        }
        std::cout << std::endl;
    }


protected:
    Node *head;
    Node *tail;
    int theSize;
    //init necesita acceso a los datos privados para inicializar una lista vacia
    void init() {
        head = new Node();
        tail = new Node();
        theSize = 0;

        head->next = tail;
        head->prev = nullptr;

        tail->prev = head;
        tail->next = nullptr;
    }


};
#endif //DLLIST_DLLIST_H
```

### Primer Código
```c++
#ifndef DLLIST_DLLIST_H
#define DLLIST_DLLIST_H

#include <iostream>
#include <utility>

template <typename Object>
class DLList{
private:
    struct Node  {
        Object data;
        Node *next;
        Node *prev;

        //Constructor de copia
        Node(const Object &d = Object{}, Node *n = nullptr)
                : data{d}, next{n}, prev{n} {}

        //Constructor de referncia
        Node(Object &&d, Node *n = nullptr)
                : data{std::move(d)}, next{n}, prev{n} {}
    };

public:
    class iterator{
    public:
        //constructor implicito, se hace nulo el puntero
        iterator() : current{nullptr} {}

        //Operador * para que se compporte como puntero
        Object &operator*() {
            if(current == nullptr)
                throw std::logic_error("Trying to dereference a null pointer.");
            return current->data;
        }

        //Movimiento
        //Operador hace que pueda moverse por la lista.
        iterator &operator++() {
            if(current)
                current = current->next;
            else
                throw std::logic_error("Trying to increment past the end.");
            return *this;
        }

        iterator operator++(int) {
            iterator old = *this;
            ++(*this);
            return old;
        }

        iterator &operator--() {
            if(current)
                current = current->prev;
            else
                throw std::logic_error("Trying to decrease past the beginning.");
            return *this;
        }

        iterator operator--(int) {
            iterator old = *this;
            --(*this);
            return old;
        }

        //Operadores para realizar comparaciones
        bool operator==(const iterator &rhs) const {
            return current == rhs.current;
        }

        bool operator!=(const iterator &rhs) const {
            return !(*this == rhs);
        }

    private:
        //apunta al nodo al que estoy trabajando en ese momento
        Node *current;
        iterator(Node *p) : current{p} {}
        //la clase amigo de acceso a los atributos privados
        friend class DLList<Object>;
    };

public:
    //Define la dimension de la lista
    //Cuando se llame al constructor, ya tiene que estar una cabeza y una cola
    DLList() : head(new Node()), tail(new Node()), theSize(0) {
        head->next = tail;
    }

    //Destructor de la lista
    //Primero borra el contenido y despues la cola y la cabeza
    ~DLList() {
        clear();
        delete head;
        delete tail;
    }

    //Sirve para meter el iterador al principio o al final
    iterator begin() { return {head->next}; }
    iterator end() { return {tail}; }

    //el tamaño de la lista, para que un iterador sepa cuanto debe recorrer
    int size() const { return theSize; }
    bool empty() const { return size() == 0; }

    //Mientras no este vacia borra el objeto de en frente
    void clear() { while (!empty()) pop_front(); }

    //Si la lista esta vacia da un error, si no retorna el inicio
    Object &front() {
        if(empty())
            throw std::logic_error("List is empty.");
        return *begin();
    }

    //funcion de push por copia
    void push_front(const Object &x) { insert(begin(), x); }
    //funcion de push por referencia
    void push_front(Object &&x) { insert(begin(), std::move(x)); }

    void push_back(const Object &x) { insert(end(), x); }
    //funcion de push por referencia
    void push_back(Object &&x) { insert(end(), std::move(x)); }




    //elimina el valo de en frente
    void pop_front() {
        if(empty())
            throw std::logic_error("List is empty.");
        erase(begin());
    }

    //Recibe un iterador, lee esa posicion e inserta un código en la posicion que le demos
    //este funciona por copia
    iterator insert(iterator itr, const Object &x) {
        Node *p = itr.current;
        head->next = new Node{x, head->next};
        theSize++;
        return iterator(head->next);
    }

    //este funciona por referencia
    iterator insert(iterator itr, Object &&x) {
        Node *p = itr.current;
        head->next = new Node{std::move(x), head->next};
        theSize++;
        return iterator(head->next);
    }

    void insert(int pos, const Object &x) {
        insert(get_iterator(pos), x);
    }

    iterator get_iterator(int a)
    {
        iterator it = begin();
        for(int i = 0; i != a; ++i) {
            ++it;
        }
        return it;
    }

    //recibe un iterador y borra el dato en la posicion que le digamos
    iterator erase(iterator itr) {

        if (itr == end())
            throw std::logic_error("Cannot erase at end iterator");
        Node *p = head;
        while (p->next != itr.current) p = p->next;
        p->next = itr.current->next;
        delete itr.current;
        theSize--;
        return iterator(p->next);
    }

    void erase(int pos)
    {
        erase(get_iterator(pos));
    }

    //Getter para toda la lista
    void print() {
        iterator itr = begin();
        while (itr != end()) {
            std::cout << *itr << " ";
            ++itr;
        }
        std::cout << std::endl;
    }



private:
    Node *head;
    Node *tail;
    int theSize;
    //init necesita acceso a los datos privados para inicializar una lista vacia
    void init() {
        theSize = 0;
        head->next = tail;
    }


};

#endif //DLLIST_DLLIST_H
```