#ifndef SINGLELINKEDLIST_H
#define SINGLELINKEDLIST_H

#include <iostream>
template <typename T>
class SingleLinkedList{
private:
    class Node {
    public:
        T data;
        Node* next;
        Node() = default;
        Node(T data): data(data), next(nullptr){}
    };
private:
    Node* head;
    int size;   // 记录链表的长度
public:
    SingleLinkedList():size(0), head(nullptr){

    }
    ~SingleLinkedList(){
        delete head;
    }
    /**
     * 获取链表的长度
     *
     */
    int getSize(){
        return size;
    }
    // 判断链表是否为空
    bool isEmpty(){
        return size == 0;
    }
    /**
     * 为链表插入节点
     * @data 节点的值
     * @index 要插入的位置
     */
    void insert(T data, int index){
        if(index < 0 || index > size){
            throw "index is illegal";
        }
        // 使用虚拟头结点的方式插入
        Node* dummyNode = new Node();
        dummyNode->next = head;
        Node* currentNode = dummyNode;
        Node* newNode = new Node(data);
        // while(index >= 0){
        //     if(index == 0){
        //         newNode->next = currentNode->next;
        //         currentNode->next = newNode;
        //     }
        //     currentNode = currentNode->next;
        //     index --;
        // }
        for(int i = 0; i < index; i ++){
            currentNode = currentNode->next;
        }
        newNode->next = currentNode->next;
        currentNode->next = newNode;
        head = dummyNode->next;
        size ++;        
    }
    /**
     * 遍历节点
     *
     */
    void reaverse(){
        Node* currentNode = head;
        while(currentNode != nullptr){
            std::cout << currentNode->data << std::endl;
            currentNode = currentNode->next;
        }
    }
    /**
     * 判断链表中是否包含该值
     *  在链表中找到第一个与该值相等的节点时，就返回true
     */
    bool contains(T data){
        Node* currentNode = head;
        while(currentNode != nullptr){
            if(currentNode->data == data){
                return true;
            }
            currentNode = currentNode->next;
        }
        return false;
    }
    /**
     * 删除第1个与该值相同的节点
     *
     */
    void remove(T data){
        Node* dummyNode = new Node();
        dummyNode->next = head;
        Node* prev = dummyNode;
        Node* curr = dummyNode->next;
        while(curr != nullptr){
            if(curr->data == data){
                prev->next = curr->next;                
                break;
            }
            curr = curr->next;
            prev = prev->next;
        }
        head = dummyNode->next;
    }
    /**
     * 获取第index个元素
     *
     */
    T get(int index){
        if(index < 0 || index >= size){
            throw "illegal index";
        }
        Node* cur = head;
        for (size_t i = 0; i < index; i++)
        {
            cur = cur->next;
        }
        return cur->data;
    }
    void set(int index, T data){
        if(index < 0 || index >= size){
            throw "illegal index";
        }
                Node* cur = head;
        for (size_t i = 0; i < index; i++)
        {
            cur = cur->next;
        }
        cur->data = data;
    }
};

#endif // SINGLELINKEDLIST_H