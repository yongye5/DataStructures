#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include <iostream>
using namespace std;
template <typename T>
class LinkedList{
private:
    struct Node{
        T data;
        Node* next;
        Node() = default;
        Node(T data, Node* next = nullptr):data(data), next(next){}
    };
private:
    Node* head;
    int size;
public:
    LinkedList():head(nullptr), size(0){
    }
    ~LinkedList(){
        delete head;
    }
    int getSize() const{
        return size;
    }
    bool isEmpty() const{
        return size == 0;
    }
    /**
     * 在索引为index的位置，插入值为data的节点
     *
     */
    void insert(int index, T data){
        Node* dummyNode = new Node();
        dummyNode->next = head;
        Node* prev = dummyNode;
        Node* curr = dummyNode->next;
        for (size_t i = 0; i < index; i++)
        {
            prev = prev->next;
            curr = curr->next;
        }
        Node* newNode = new Node(data);
        newNode->next = curr;
        prev->next = newNode;
        head = dummyNode->next;
        size ++;
    }
    void insertFirst(T data){
        insert(0, data);
    }
    
    /**
     * 遍历
     *
     */
    void traverse(){
        Node* curr = head;
        while(curr != nullptr){
            cout << curr->data << endl;

            curr = curr->next;
        }
    }
    void remove(T data){
        Node* dummyNode = new Node();
        dummyNode->next = head;
        Node* prev = dummyNode;
        Node* curr = head;
        while(curr != nullptr){      
            if(data == curr->data){
                prev->next = curr->next;
                break;
            }
            prev = prev->next;
            curr = curr->next;
        }
        head = dummyNode->next;
        size --;
    }
    void removeByIndex(int index){
        Node* dummyNode = new Node();
        dummyNode->next = head;
        Node* prev = dummyNode;
        Node* curr = head;
        for (size_t i = 0; i < index; i++)
        {
            prev = prev->next;
            curr = curr->next;
        }
        prev->next = curr->next;
        head = dummyNode->next;
        size --;
    }
    void removeFirst(){
        removeByIndex(0);
    }
    /**
     * 通过索引获取该节点的值
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
};


#endif  // LINKEDLIST_H