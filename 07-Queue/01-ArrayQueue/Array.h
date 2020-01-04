#ifndef ARRAY_H
#define ARRAY_H
#include <iostream>
using namespace std;
template <typename T>
class Array{
           //重载输入运算符，将数组打印为字符串
    friend ostream &operator<<(ostream &out, Array<T> &arr)
    {
        int size = arr.getSize();
        int capacity = arr.getCapacity();
        out << "Array: size = " << size << " , capacity = " << capacity << endl;
        out << "[";
        for (int i = 0; i < size; i++)
        {
            out << arr.data[i];
            if (i != size - 1)
            {
                out << ',';
            }
        }
        out << "]" << endl;
        return out;
    }
private:
    T *data;
    int size;
    int capacity;
public:
    Array(){
        data = new T[10];
        this->capacity = 10;
        size = 0;
    }
    Array(int capacity){
        data = new T[capacity];
        this->capacity = capacity;
        size = 0;
    }
    ~Array(){
        delete data;
    }
    int getSize() const{
        return size;
    }
    bool isEmpty() const{
        return size == 0;
    }
    int getCapacity() const{
        return this->capacity;
    }
    T get(int index) const{
        if(index < 0 || index >= size){
            throw "illegal index";
        }
        return data[index];
    }
    T getLast() const{
        return get(size - 1);
    }
    T getFirst() const{
        return get(0);
    }
    void add(int index, T elem){
        if(index < 0 || index > size){
            throw "illegal index";
        }
        if(size == capacity){
            resize(capacity * 2);
        }
        for (int i = size - 1; i >= index; i--)
        {
            data[i + 1] = data[i];
        }
        data[index] = elem;
        size ++;
    }
    void addLast(T elem){
        add(size , elem);
    }
    void addFirst(T elem){
        add(0, elem);
    }
    T remove(int index){
        if(index < 0 || index >= size){
            throw "illegal index";
        }
        T ret = data[index];
        for (size_t i = index + 1; i < size; i++)
        {
            data[i - 1] = data[i];
        }
        size --;
        if(size == this->capacity / 4 && this->capacity >= 4){
            resize(capacity / 2);
        }
        return ret;
    }
    T removeFirst(){
        return remove(0);
    }
    T removeLast(){
        return remove(size - 1);
    }
    void set(int index, T elem){
        if(index < 0 || index >= size){
            throw "illegal index";
        }
        data[index] = elem;
    }
private:
    void resize(int newCapacity){
        T * newData = new T[newCapacity];
        for (size_t i = 0; i < size; i++)
        {
            newData[i] = data[i];
        }
        capacity = newCapacity;
        data = newData;
    }
};

#endif // ARRAY_H