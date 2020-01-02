#ifndef DOUBLE_LINKED_LIST_H
#define DOUBLE_LINKED_LIST_H
#include <iostream>
using namespace std;
// 双向链表
template <typename T>
class DoubleLinkedList{
private:
    class Node{
    public:
        T data;
        Node* prev;
        Node* next;
        Node() = default;
        Node(T data, Node* prev = nullptr, Node* next = nullptr): data(data){}
    };
private:
    Node* head; // 头结点
    int size;   // 链表的长度
public:
    DoubleLinkedList(Node* head = nullptr, int size = 0): head(head), size(size){}
    ~DoubleLinkedList(){
        cout << "析构" << endl;
        delete head;
    }
    void insert(T data, int index);// 在指定的索引添加节点
    bool contains(T data);  // 是否包含该节点
    void remove (int index);    // 根据索引删除节点
    T get(int index);           // 根据索引查询节点
    void set(int index, T data);// 更改节点的值
    int getSize();              // 获取链表长度
    bool isEmpty();             // 链表是否为空
    void traverse();            // 遍历整个链表
};

template <typename T>
void DoubleLinkedList<T>::insert(T data, int index){
    if(index < 0 || index > size){
        throw "illegal index";
    }
    Node* dummyNode = new Node();
    dummyNode->next = head;
    if(head != nullptr){
        head->prev = dummyNode;
    }
    Node* curr = dummyNode->next;
    Node* prev = dummyNode;
    for(int i = 0; i < index; i ++){
        curr = curr->next;
        prev = prev->next;
    }
    
    Node* newNode = new Node(data);
    newNode->next = curr;
    if(curr != nullptr){
        curr->prev = newNode;
    }
    newNode->prev = prev;
    prev->next = newNode;
    head = dummyNode->next;
    size ++;
}

template <typename T>
void DoubleLinkedList<T>::traverse(){
    Node* curr = head;
    while(curr != nullptr){
        cout << curr->data << endl;
        curr = curr->next;
    }
}
template <typename T>
bool DoubleLinkedList<T>::contains(T data){
    Node* curr = head;
    while(curr != nullptr){
        if(curr->data == data){
            return true;
        }
    }
    return false;
}
/**
 * 根据索引删除节点
 *
 */
template <typename T>
void DoubleLinkedList<T>::remove (int index){
    if(index < 0 || index >= size){
        throw "illegal index";
    }
    if(head == nullptr){
        return;
    }
    Node* dummyNode = new Node();
    dummyNode->next = head;

    Node* prev = dummyNode;
    Node* curr = dummyNode->next;
    for (size_t i = 0; i < index; i++)
    {
        curr = curr->next;
        prev = prev->next;
    }
    prev->next = curr->next; 
    prev = prev->next->prev;
    head = dummyNode->next;
    size --;
}

template <typename T>
T DoubleLinkedList<T>::get(int index){
    if(index < 0 || index >= size){
        throw "illegal index";
    }
    Node* curr = head;
    for (size_t i = 0; i < index; i++)
    {
        curr = curr->next;
    }
    return curr->data;
}
template <typename T>
void DoubleLinkedList<T>::set(int index, T data){
    if(index < 0 || index >= size){
        throw "illegal index";
    }
    Node* curr = head;
    for (size_t i = 0; i < index; i++)
    {
        curr = curr->next;
    }
    curr->data = data;
}

template <typename T>
int DoubleLinkedList<T>::getSize(){
    return size;
}
template <typename T>
bool DoubleLinkedList<T>::isEmpty(){
    return size == 0;
}

#endif  // DOUBLE_LINKED_LIST_H