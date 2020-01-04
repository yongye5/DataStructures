#ifndef ARRAY_H
#define ARRAY_H
#include <iostream>
using namespace std;
/**
 * 动态数组的实现
 *
 */
template <typename E>
class Array{
       //重载输入运算符，将数组打印为字符串
    friend ostream &operator<<(ostream &out, Array<E> &arr)
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
    E *data;
    int size;   // 元素的数目
    int capacity;   // 数组的容量
public:
    Array(){
        // 默认容量为10
        data = new E[10];
        capacity = 10;
        size  = 0;
    }
    Array(int capacity){
        data = new E[capacity];
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
    int getCapacity() const {
        return this->capacity;
    }
    /**
     * 在指定的索引位置添加元素
     *
     */
    void add(int index, E e){
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
        data[index] = e;
        size ++;
    }
    void addFirst(E e){
        add(0, e);
    }
    /**
     *
     * 在数组的最后一个元素的后边添加元素
     */
    void addLast(E e){
        add(size, e);
    }
    bool contains(E data) const{
        for (size_t i = 0; i < size; i++)
        {
            if(data[i] == data){
                return true;
            }
        }
        return false;
    }
    E get(int index){
        if(index < 0 || index >= size){
            throw "illegal index";
        }
        return data[index];
    }
    E getFirst(){
        return get(0);
    }
    E getLast(){
        return get(size - 1);
    }
    E remove(int index){
        if(index < 0 || index >= size){
            throw "illegal index";
        }
        E ret = data[index];
        for (size_t i = index + 1; i < size; i++)
        {
            this->data[i - 1] = data[i];
        }
        size --;
        if(size * 4 == capacity && capacity > 4){
            resize(capacity / 2);
        }
        return ret;
    }
    void removeLast(){
        remove(size - 1);
    }
    void removeFirst(){
        remove(0);
    }
    void removeElement(E e){
        for (size_t i = 0; i < size - 1; i++)
        {
            if(e == this->data[i]){
                remove(i);
                break;
            }
        }        
    }
    void set(int index, E e){
        if(index < 0 || index >= size){
            throw "illegal index";
        }
        this->data[index] = e;
    }
private:
    void resize(int newCapacity){
        E* newData = new E[newCapacity];
        for (size_t i = 0; i < size; i++)
        {
            newData[i] = this->data[i];
        }
        this->data = newData;
        capacity = newCapacity;
    }   
};

#endif // ARRAY_H