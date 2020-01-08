#ifndef LINKEDLISTSTACK_H
#define LINKEDLISTSTACK_H
#include "LinkedList.h"
#include <iostream>
using namespace std;
template <typename T>
class LinkedListStack{
private:
    LinkedList<T> * list;
public:
    LinkedListStack() {
        list = new LinkedList<T>();
    };
    ~LinkedListStack(){
        delete list;
    }
    int getSize() const{
        return list->getSize();
    }
    bool isEmpty() const{
        return list->isEmpty();
    }
    void push(T data){
        list->insertFirst(data);
    }
    void pop(){
        list->removeFirst();
    }
    T top(){
        return list->get(0);
    }
    void traverse(){
        list->traverse();
    }
};


#endif /// LINKEDLISTSTACK_H