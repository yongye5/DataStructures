#ifndef ARRAYQUEUE_H
#define ARRAYQUEUE_H
#include "Array.h"
#include <iostream>
using namespace std;
template <typename T>
class ArrayQueue{
    friend ostream& operator<<(ostream &out, ArrayQueue<T>& queue){
        Array<T> *arr = queue.arr;
        cout << "Queue: front [";
        for (size_t i = 0; i < arr->getSize(); i++)
        {
            cout << arr->get(i);
            if(i != arr->getSize() - 1){
                cout << ", ";
            }
        }
        cout << "] tail" << endl;
    }
private:
    Array<T> *arr;
public:
    ArrayQueue(){
        arr = new Array<T>();
    }
    ArrayQueue(int capacity){
        arr = new Array<T>(capacity);
    }
    ~ArrayQueue(){
        delete arr;
    }
    int getSize() const{
        return arr->getSize();
    }
    bool isEmpty(){
        return arr->isEmpty();
    }
    int getCapacity() const{
        return arr->getCapacity();
    }
    // bool empty {
    //     return arr->isEmpty();
    // }
    void enqueue(T data){
        arr->addLast(data);
    }
    T dequeue(){
        return arr->removeFirst();
    }
    T front(){
        return arr->getFirst();
    }

};

#endif // ARRAYQUEUE_H