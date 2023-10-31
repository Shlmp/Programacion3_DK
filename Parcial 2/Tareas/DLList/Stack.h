#include <iostream>
#include <cstdlib>
#include <stack>
#ifndef PROYECTO_SEGUNDO_PARCIAL_STACK_H
#define PROYECTO_SEGUNDO_PARCIAL_STACK_H

template <typename Iterator>
class Stack : private DLList<Iterator> {
public:
    Stack() {
    }

    ~Stack(){
        clear();
        delete DLList<Iterator>::head;
        delete DLList<Iterator>::tail;
    }

    void push(Iterator &data){
        DLList<Iterator>::push_front(data);
    }
    void push(Iterator &&data){
        DLList<Iterator>::push_front(data);
    }

    void pop(){
        DLList<Iterator>::pop_front();
    }

    void clear(){
        DLList<Iterator>::clear();
    }

    void print(){
        DLList<Iterator>::print();
    }

    Iterator top(){
        return DLList<Iterator>::head->next->data;
    }
};

#endif //PROYECTO_SEGUNDO_PARCIAL_STACK_H