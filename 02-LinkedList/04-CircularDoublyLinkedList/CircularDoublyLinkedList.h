#ifndef CIRCULARDOUBLYLINKEDLIST_H
#define CIRCULARDOUBLYLINKEDLIST_H
#include <iostream>
using namespace std;
template <typename T>
class CircularDoublyLinkedList{
private:
    class Node{
    public:
        T data;
        Node* next;
        Node* prev;
        Node(T data, Node* prev = nullptr, Node* next = nullptr): data(data), prev(prev), next(next){}
        ~Node(){
            delete next;
            delete prev;
        }
    };
private:
    int size;
    Node* head;
public:
    //CircularDoublyLinkedList() = default;
    CircularDoublyLinkedList(Node* node = nullptr, int size = 0): head(node), size(size){}
    ~CircularDoublyLinkedList(){
        delete head;
    }
    bool isEmpty() const{
        return size == 0;
    }
    int getSize() const {
        return size;
    }
    void addToEmpty(T data){
            Node* node = new Node(data);
            node->next = node;
            node->prev = node;
            head = node;
            size ++;
            
    }
    /**
     * 在链表末尾添加节点，或者
     *  为空链表添加节点
     */
    void addEnd(T data){
        if(head == nullptr){
            addToEmpty(data);
            return;
        }
        Node* tail = head->prev;

        Node* node = new Node(data);
        node->next = head;
        node->prev = tail;

        head->prev = node;
        tail->next = node;
        size ++;
    }
    void addFirst(T data){
        if(head == nullptr){
            addToEmpty(data);
            return ;
        }
        Node* tail = head->prev;
        Node* node = new Node(data);
        node->next = head;
        node->prev= tail;

        head->prev = node;
        tail->next = node;
        head = node;
        size ++;        
    }
    /**
     * 根据索引添加数据
     *
     */
    void add(T data, int index){
        if(index < 0 || index > size){
            throw "illegal index";
        }
        if(index == 0){
            addFirst(data);
            return ;
        }
        if(index == size){
            addEnd(data);
            return;
        }
        Node* curr = head;
        for(int i = 0; i < index; i++){
            curr = curr->next;
        }
        Node* prev = curr->prev;
        Node* node = new Node(data);
        node->next = curr;
        node->prev = prev;
        prev->next = node;
        curr->prev = node;
        size ++;
    }

    void traverse(){
        Node* curr = head;
        for(int i = 0; i < size; i++){
            cout << curr->data << endl;
            curr = curr->next;
        }
    }
    /**
     *  根据索引删除节点
     *
     */
    void remove(int index){
        if(index < 0 || index >= size){
            throw "illegal index";
        }
        if(size == 1){
            head = nullptr;
            size --;
            return;
        }
        Node* curr = head;
        for (size_t i = 0; i < index; i++)
        {
            curr = curr->next;
        }

        curr->prev->next = curr->next;
        size --;        
    }
    /**
     * 通过id 获取节点
     *
     */
    T get(int index){
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
    void set(int index, T data){
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
};

#endif // CIRCULARDOUBLYLINKEDLIST_H