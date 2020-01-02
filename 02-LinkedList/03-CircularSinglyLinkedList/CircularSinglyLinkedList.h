#ifndef CIRCULARSINGLYLINKEDLIST_H
#define CIRCULARSINGLYLINKEDLIST_H
#include <iostream>
using namespace std;
template <typename T>
class CircularSinglyLinkedList{
public:
    class Node{
    public:
        T data;
        Node *next;
        Node() = default;
        Node(T data, Node* next = nullptr):data(data), next(next){}
    };
private:
    Node* last; // 尾结点
    int size;   // 链表长度
public:

    CircularSinglyLinkedList():last(nullptr), size(0){};
    ~CircularSinglyLinkedList(){
        delete last;
    }
    int getSize() const {
        return size;
    }
    bool isEmpty() const {
        return size == 0;
    }
    void addToEmpty( T data){
        if(last != nullptr){
            return;
        }
        Node* node = new Node();
        node->data = data;
        last = node;
        last->next = last;

        size++;
    }
    void addBegin(T data){
        if(last == nullptr){
            addToEmpty(data);
            return ;
        }
        Node* node = new Node(data);
        node->next = last->next;
        last->next = node;

        size++;
    }
    void addEnd(T data){
        if(last == nullptr){
            addToEmpty(data);
            return;
        }
        Node* node = new Node();
        node->data = data;
        node->next = last->next;
        last->next = node;

        last = node;
        size ++;
    }
    /**
     * 在索引为index的位置添加节点
     *
     */
    void add(T data, int index){
        if(index < 0 || index > size){
            throw "illegal index"  ;
        }
        if(index == 0){
            addBegin(data);
            return ;
        }
        if(index == size ){
            addEnd(data);
            return ;
        }
        Node* prev = last;
        for(int i = 0; i < index; i++){
            prev = prev->next;            
        }
        Node* node = new Node(data);
        node->next = prev->next;
        prev->next = node;
        size ++;
    }
    /**
     * 遍历链表节点
     *
     */
    void traverse(){
        if(last == nullptr){
            cout << "list is empty" << endl;
            return;
        }
        Node* curr = last->next;
        do{
            cout << curr->data << endl;
            curr = curr->next;
        }while(curr != last->next);

    }
    /**
     * 根据索引删除对应元素
     *
     */
    void remove(int index){
        if(index < 0 || index > size){
            throw "illegal index"  ;
        }
        if(size == 1){
            last == nullptr;
            size --;
            return;
        }
        Node* prev = last;
        for(int i = 0; i < index; i ++){
            index --;
            prev = prev->next;
        }
        prev->next = prev->next->next;
        size --;
    }
    /**
     * 根据节点的值删除节点
     *
     */
    void removeByData(T data){
        if(size == 0){
            return;
        }
        Node* prev = last;
        for(int i = 0; i < size; i ++){
            if(prev->next->data == data){
                remove(i);
                return;
            }
            prev = prev->next;
        }
    }

    T get(int index){
        if(index < 0 || index > size){
            throw "illegal index"  ;
        }
        Node* curr = last->next;
        for(int i = 0; i < index; i ++){
            index --;
            curr = curr->next;
        }
        return curr->data;
    }
};

#endif //CIRCULARSINGLYLINKEDLIST_H