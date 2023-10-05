```c++
#ifndef SLLLIST_H
#define SLLLIST_H

//Libraries
#include <iostream>
#include <utility>

template <typename Object> //Declares a Template where anything called Object will be replaced with value/class
class SLList {
private:
    //Cada Cuadrito
    struct Node  {
        Object data;
        Node *next;//Anya

//Same as FloatCell, constructors
        Node(const Object &d = Object{}, Node *n = nullptr) //Declares a copy constructor as well as a default constructor since it equals to 0
            : data{d}, next{n} {} //Points to n, with data of d

        Node(Object &&d, Node *n = nullptr) //Declares a reference constructor
            : data{std::move(d)}, next{n} {} //Points to n, with data of d
    };

public:
    class iterator { //Declares iterator class
    public:
        iterator() : current{nullptr} {} //Default constructor

        Object &operator*() { //Declares Pointer
            if(current == nullptr) //If pointer = 0, prints a message of logic_error
                throw std::logic_error("Trying to dereference a null pointer.");
            return current->data; //Returns current data
        }

        iterator &operator++() { //Declares addition to next position
            if(current) //If pointers is in current position, go to next position
                current = current->next;
            else //If pointer does not have next, print message of logic_error
                throw std::logic_error("Trying to increment past the end.");
            return *this;
        }

        iterator operator++(int) { //Uses ++ to determine the position
            iterator old = *this;
            ++(*this); //Adds 1 to position
            return old;
        }

        bool operator==(const iterator &rhs) const { //Declares ==, If both statements are the same, returns true, if not, return false
            return current == rhs.current;
        }

        bool operator!=(const iterator &rhs) const { //Declares !=, If Both statements are the same, returns false, if not, returns true
            return !(*this == rhs);
        }

    private:
        Node *current; //Pointer
        iterator(Node *p) : current{p} {} //Constructor
        friend class SLList<Object>; //Declares friend to class SLList
    };

public:
    SLList() : head(new Node()), tail(new Node()), theSize(0) { //Default Constructor for Lists
        head->next = tail;
    }

    ~SLList() { //Destructor
        clear();
        delete head;
        delete tail;
    }

    iterator begin() { return {head->next}; } //Gets beginning of List
    iterator end() { return {tail}; } //Gets ending of List

    int size() const { return theSize; } //Gets size of List
    bool empty() const { return size() == 0; } //Checks if List is empty, if List is empty, returns true and false otherwise

    void clear() { while (!empty()) pop_front(); } //While List is not empty, clears List

    Object &front() { //Beginning of List
        if(empty()) //If the first element is empty, says it's empty, if not, gives value
            throw std::logic_error("List is empty.");
        return *begin();
    }

    void push_front(const Object &x) { insert(begin(), x); } //Adds new element to List by copy
    void push_front(Object &&x) { insert(begin(), std::move(x)); } //Adds new element to List by reference

    void pop_front() { //Erases the first element unless List is empty
        if(empty())
            throw std::logic_error("List is empty.");
        erase(begin());
    }

    iterator insert(iterator itr, const Object &x) { //Inserts element where pointer is by copy
        Node *p = itr.current;
        head->next = new Node{x, head->next};
        theSize++;
        return iterator(head->next);
    }

    iterator insert(iterator itr, Object &&x) { //Inserts element where pointer is by reference
        Node *p = itr.current;
        head->next = new Node{std::move(x), head->next};
        theSize++;
        return iterator(head->next);
    }

    iterator erase(iterator itr) { //Erases element where pointer is
        if (itr == end())
            throw std::logic_error("Cannot erase at end iterator");
        Node *p = head;
        while (p->next != itr.current) p = p->next;
        p->next = itr.current->next;
        delete itr.current;
        theSize--;
        return iterator(p->next);
    }

    void printList() { //Prints List by obtaining the iterator's current position, then adds to iterator's position and repeats until List ends
        iterator itr = begin();
        while (itr != end()) {
            std::cout << *itr << " ";
            ++itr;
        }
        std::cout << std::endl;
    }

private:
    Node *head; //Beginning of List
    Node *tail; //Ending of List
    int theSize;
    void init() { //Initialize variables
        theSize = 0;
        head->next = tail;
    }
};

#endif
```

Sigo con un poco de dudas acerca del por qué o cuándo usar vectores y listas. Al igual que tengo dudas con la diferencia entre int++ e ++int, o en este caso ++this.