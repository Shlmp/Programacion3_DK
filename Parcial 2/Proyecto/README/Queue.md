```c++
#ifndef QUEUE_H  
#define QUEUE_H  
  
template<typename Data>  
class Queue : private DLList<Data>{ //Creates class Queue that inherits DLList with Data type  
public:  
    Queue(){  
        DLList<Data>::init(); //Initializes Queue in init declared in DLList  
    }  
  
    ~Queue(){  
        clear(); //Calls clear function  
        delete DLList<Data>::head; //Deletes head  
        delete DLList<Data>::tail; //Deletes tail  
    }  
  
    void enqueue(Data &data){  
        DLList<Data>::push_back(data); //Inserts data at the end of Queue by copy  
    }  
  
    void enqueue(Data &&data){  
        DLList<Data>::push_back(data); //Inserts data at the end of Queue by reference  
    }  
  
    void dequeue(){  
        DLList<Data>::pop_front(); //Deletes data at beginning of queue  
    }  
  
    void print(){  
        DLList<Data>::print(); //Prints Queue  
    }  
  
    void clear(){  
        DLList<Data>::clear(); //Deletes Queue  
    }  
  
    Data front(){  
        return DLList<Data>::head->next->data; //Prints only the first value of Queue  
    }  
};  
  
#endif //QUEUE_H
```