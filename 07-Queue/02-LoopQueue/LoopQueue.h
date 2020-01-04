#ifndef LOOPQUEUE_H
#define LOOPQUEUE_H
#include <iostream>
using namespace std;
/**
 * 循环队列
 *
 */
template <typename T>
class LoopQueue{
private:
    T* data;
    int front;
    int tail;
    int capacity;
public:
    LoopQueue(){
        data = new T[10];
        front = 0;
        tail = 0;
        capacity = 10;
    }
    ~LoopQueue(){
        delete data;
    }
    int getSize() const {
        return tail >= front ? tail - front : tail - front + getCapacity();
    }
    int getCapacity() const {
        return capacity;
    }
    bool isEmpty() const {
        return front == tail;
    }
    bool full() const {
        return (tail + 1 - front) % capacity == 0;
    }
    T getFront(){
        return data[front];
    }
    void enqueue(T elem){
        if(full()){
            resize(capacity * 2);
        }
        data[tail] = elem;
        tail = (tail + 1) % capacity;
    }
    T dequeue(){
        if(isEmpty()){
            throw "cann't dequeue from an empty queue";
        }
        T ret = data[front];
        this->front = (front + 1) % capacity;

        return ret;
    }
    void traverse(){
        for (size_t i = 0; i < this->getSize(); i++)
        {
            cout << data[(front + i) % capacity] << endl;
        }
        
    }
private:
    void resize(int newCapacity){
        T* newData = new T[newCapacity];
        for (size_t i = 0; i < this->getSize(); i++)
        {
            newData[i] = data[(front + i) % capacity];
        }
        capacity = newCapacity;
        data = newData;
    }
};

#endif // LOOPQUEUE_H