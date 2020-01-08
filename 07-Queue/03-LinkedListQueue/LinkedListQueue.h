#ifndef LINKEDLISTQUEUE_H
#define LINKEDLISTQUEUE_H

template <typename T>
class LinkedListQueue{
private:
    struct Node{
        T data;
        Node* next;
        Node() = default;
        Node(T data, Node* node = nullptr):data(data), next(node){}
    };
private:
    Node* head;
    Node* tail;
    int size;
public:
    LinkedListQueue(){
        head = nullptr;
        tail = nullptr;
        size = 0;
    }
    ~LinkedListQueue(){
        delete head;
        delete tail;
    }
    int getSize() const{
        return size;
    }
    bool isEmpty() const {
        return size == 0;
    }
    /**
     * 入队
     *  链表尾部入队，链表头部出队
     */
    void enqueue(T data){
        if(tail == nullptr){
            tail = new Node(data);
            head = tail;
        }else {
            tail->next = new Node(data);
            tail = tail->next;
        }
        size ++;
    }
    T dequeue(){
        if(isEmpty()){
            throw "queue is empty";
        }
        Node* retNode = head;
        head = head->next;
        if(head == nullptr){
            tail = nullptr;
        }
        size --;
        return retNode->data;
    }
    T front() const {
        if(isEmpty()){
            throw "queue is empty";
        }
        return head->data;
    }
    T end() const {
        if(isEmpty()){
            throw "queue is empty";
        }
        return tail->data;
    }
};

#endif // LINKEDLISTQUEUE_H
