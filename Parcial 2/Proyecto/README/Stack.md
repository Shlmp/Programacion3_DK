```c++
#include <iostream>  
#include <cstdlib>  
#include <stack>  
#ifndef STACK_H  
#define STACK_H  
  
template <typename T>  
class Stack : private DLList<T> { //Creates class Stack that inherits from DLList with type T  
public:  
    Stack() {  
        DLList<T>::init(); //Initializes Stack in init defined in DLList  
    }  
  
    ~Stack(){  
        clear(); //Calls clear function  
        delete DLList<T>::head; //deletes head  
        delete DLList<T>::tail; //deletes tail  
    }  
  
    void push(T &data){  
        DLList<T>::push_front(data); //Inserts data at the beginning of stack by copy  
    }  
    void push(T &&data){  
        DLList<T>::push_front(data); //Inserts data at beginning of stack by reference  
    }  
  
    void pop(){  
        DLList<T>::pop_front(); //Deletes data at beginning of stack  
    }  
  
    void clear(){  
        DLList<T>::clear(); //Clears stack  
    }  
  
    void print(){  
        DLList<T>::print(); //Prints stack  
    }  
  
    T top(){  
        return DLList<T>::head->next->data; //Prints only the first value  
    }  
};  
  
#endif //STACK_H
```