#include <iostream>
using namespace std;
template <typename T>
class Array
{
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
    int capacity; // 数组容量
public:
    Array(int capacity);      //构造函数，传入数组的容量来构造函数
    Array();                  // 无参构造函数，默认数组的容量为10
    ~Array();                 // 析构函数
    int getSize();            //获取数组中元素的个数
    int getCapacity();        //获取数组的容量
    bool isEmpty();           // 返回数组是否为空
    void add(int index, T e); //在第index个位置插入一个新元素
    void addLast(T e);
    void addFirst(T e);
    T get(int index);         //  获取索引位置的元素
    T front();                // 获取第一个元素
    T back();                 // 获取最后一个元素
    void set(int index, T e); // 修改index索引位置的元素
    bool contains(T e);       // 查找数组中是否有元素e
    int find(T e);            //查找数组中元素e的索引，如果不存在e，则返回-1
    T remove(int index);      // 从数组中删除Index位置的元素，返回删除的元素
    T removeFirst();          //从数组中删除第一个元素，返回删除的元素
    T removeLast();           //从数组中删除最后一个元素，返回删除的元素
    void removeElement(T e);  //从数组中删除元素e
private:
    void resize(int newCapacity); //为数组扩容
};
template <typename T>
Array<T>::Array(int capacity)
{
    data = new T[capacity];
    size = 0;
    this->capacity = capacity;
}
template <typename T>
Array<T>::Array()
{
    data = new T[10];
    size = 0;
    this->capacity = 10;
}
template <typename T>
Array<T>::~Array()
{
    delete[] data;
    data = NULL;
}
template <typename T>
int Array<T>::getSize() //获取数组中元素的个数
{
    return size;
}
template <typename T>
int Array<T>::getCapacity() //获取数组的容量
{
    return capacity;
}
template <typename T>
bool Array<T>::isEmpty() // 返回数组是否为
{
    return size == 0;
}
template <typename T>
void Array<T>::add(int index, T e) //在第index个位置插入一个新元素
{
    //assert(size < capacity);            //当数组已满的时候插入失败，程序被终止
    //assert(index >= 0 && index <= size); //index 要在范围之内

    if (index < 0 || index > size)
    {
        throw "Add failed";
    }
    if (size >= capacity)
    {
        resize(capacity * 2);
    }
    for (int i = size - 1; i >= index; i--)
    {
        data[i + 1] = data[i];
    }
    data[index] = e;
    size++;
}
template <typename T>
void Array<T>::addLast(T e)
{
    add(size, e);
}
template <typename T>
void Array<T>::addFirst(T e)
{
    add(0, e);
}
template <typename T>
T Array<T>::get(int index)
{
    if (index < 0 || index >= size)
    {
        throw "Get Failed. Index is illegal";
    }
    return data[index];
}
template <typename T>
T Array<T>::front(){
    return get(0);
}
template <typename T>
T Array<T>::back(){
    return get(this->size - 1);
}
template <typename T>
void Array<T>::set(int index, T e)
{
    if (index < 0 || index >= size)
    {
        throw "Get Failed. Index is illegal";
    }
    data[index] = e;
}
template <typename T>
bool Array<T>::contains(T e)
{
    for (int i = 0; i < size; i++)
    {
        if (data[i] == e)
        {
            return true;
        }
    }
    return false;
}

template <typename T>
int Array<T>::find(T e)
{
    for (int i = 0; i < size; i++)
    {
        if (data[i] == e)
        {
            return i;
        }
    }
    return -1;
}
// 从数组中删除Index位置的元素，返回删除的元素
template <typename T>
T Array<T>::remove(int index)
{
    if (index < 0 || index >= size)
    {
        throw "Remove failed. Index is illegal";
    }
    T ret = data[index];
    for (int i = index + 1; i < size; i++)
    {
        data[i - 1] = data[i];
    }
    size--;
    if(size == capacity / 4 && capacity >= 4){
        resize(capacity / 2);
    }

    // todo...释放空间
    // delete &data[size];
    // data[size] = NULL;
    return ret;
}
template <typename T>
T Array<T>::removeFirst() //从数组中删除第一个元素，返回删除的元素
{
    return remove(0);
}
template <typename T>
T Array<T>::removeLast() //从数组中删除最后一个元素，返回删除的元素
{
    return remove(size - 1);
}
template <typename T>
void Array<T>::removeElement(T e) //从数组中删除元素e
{
    int index = find(e);
    if (index != -1)
    {
        remove(index);
    }
}
template <typename T>
void Array<T>::resize(int newCapacity) //为数组扩容
{
    T *newData = new T[newCapacity];
    for (int i = 0; i < size; i++)
    {
        newData[i] = data[i];
    }
    data = newData;
    this->capacity = newCapacity;
}