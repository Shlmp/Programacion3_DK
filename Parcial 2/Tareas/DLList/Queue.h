#ifndef PROYECTO_SEGUNDO_PARCIAL_QUEUE_H
#define PROYECTO_SEGUNDO_PARCIAL_QUEUE_H
#include "DLList.h"

template<typename ZL>
class Queue : private DLList<ZL>{
public:
    Queue(){
    }

    ~Queue(){
        clear();
        delete DLList<ZL>::head;
        delete DLList<ZL>::tail;
    }

    void enqueue(ZL &data){
        DLList<ZL>::push_back(data);
    }

    void enqueue(ZL &&data){
        DLList<ZL>::push_back(data);
    }

    void dequeue(){
        DLList<ZL>::pop_front();
    }

    void print(){
        DLList<ZL>::print();
    }

    void clear(){
        DLList<ZL>::clear();
    }

    ZL front(){
        return DLList<ZL>::head->next->data;
    }
};

#endif //PROYECTO_SEGUNDO_PARCIAL_QUEUE_H