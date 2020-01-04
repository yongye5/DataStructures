#ifndef ARRAYSTACK_H
#define ARRAYSTACK_H
#include "Array.h"
#include <iostream>
using namespace std;
template<typename T>
class ArrayStack{
    friend ostream& operator<<(ostream &out, ArrayStack<T>& stack){
        Array<T> *arr = stack.arr;
        cout << "Stack: [";
        for (size_t i = 0; i < arr->getSize(); i++)
        {
            cout << arr->get(i);
            if(i != arr->getSize() - 1){
                cout << ", ";
            }
        }
        cout << "] top" << endl;
    }
private:
    Array<T> *arr;
public:
    ArrayStack(){
        arr = new Array<int>();
    }
    ArrayStack(int capacity){
        arr = new Array<int>(capacity);
    }
    ~ArrayStack(){
        delete arr;
    }
    int getSize() const{
        return arr->getSize();
    }
    int getCapacity() const{
        return arr->getCapacity();
    }
    bool isEmpty() const{
        return arr->getSize() == 0;
    }
    void push(T data){
        arr->addLast(data);
    }
    void pop(){
        arr->removeLast();
    }
    T top() const{
        return arr->getLast();
    }

};

#endif // ARRAYSTACK_H