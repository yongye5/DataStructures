#ifndef BST_H
#define BST_H
#include <iostream>
#include <stack>
#include <queue>
using namespace std;
/**
 * 不包含重复元素
 *
 */
template <typename T>
class BST{
private:
    struct Node{
        T data;
        Node* left;
        Node* right;
        Node(T data){
            this->data = data;
            left = nullptr;
            right = nullptr;
        }        
    };
private:
    Node* root;
    int size;
public:
    BST(){
        this->root = nullptr;
        size = 0;
    }
    ~BST(){
        delete root;
    }
    int getSize(){
        return size;
    }        
    bool isEmpty(){
        return size == 0;
    }
    // 插入一个元素
    void insert(T data)        
    {        
        root = insert(root, data);        
    }
    // 是否包含一个元素,递归查找
    bool contains(T data){
        return containsRecursion(root, data);
    } 
    // 迭代查找
    bool containsNR(T data){
        return containsNR(root, data);
    }
    // 前序遍历 递归
    void preOrder(){
        preOrder(root);
    }
    // 前序遍历 非递归
    void preOrderNR(){
        preOrderNR(root);
    }        
    // 中序遍历  
    void inOrder(){
        inOrder(root);
    }     
    // 后序遍历       
    void postOrder(){
        postOrder(root);
    }          
     // 找最小值 递归
    T minimum(){
        if(size == 0){
            throw "tree is empty";
        }
        return minimum(root)->data;
    }    
    // 找最小值 非递归
    T minmumNR(){
        if(size == 0){
            throw "tree is empty";
        }
        Node *curr = root;
        while(curr->left != nullptr){
            curr = curr->left;
        }
        return curr->data;
    }       
    // 最大值 递归
    T maximum(){
        if(size == 0){
            throw "tree is empty";
        }
        return maximum(root)->data;
    }    
    // 找最大值 非递归
    T maxmumNR(){
        if(size == 0){
            throw "tree is empty";
        }
        Node *curr = root;
        while(curr->right != nullptr){
            curr = curr->right;
        }
        return curr->data;
    }   
    // 删除最小值的节点
    T removeMin(){
        T ret = minimum(root)->data;
        root = removeMin(root);
        return ret;
    }        
    // 删除最大值的节点
    T removeMax(){
        T ret = maximum(root)->data;
        root = removeMax(root);
        return ret;
    }         
    // 删除节点
    void remove(T data){
        root = remove(root, data);
    }      
    // 层序遍历
    void levelOrder(){
        levelOrder(root);
    }        
private:
    Node* insert(Node* node, T data){
        if(node == nullptr){
            size ++;
            return new Node(data);
        }
        if(data < node->data){
            node->left = insert(node->left, data);
        }else if(data > node->data){
            node->right = insert(node->right, data);
        }
        return node;
    }
    /**
     * 递归的方式 查找
     *
     */
    bool containsRecursion(Node* node, T data){
        if(node == nullptr){
            return false;
        }
        if(data < node->data){
            return containsRecursion(node->left, data);
        }else if(data > node->data){
            return containsRecursion(node->right, data);
        }else   // 相等
        {
            return true;
        }        
    }
    /**
     * 非递归的方式 查找
     *
     */
    bool containsNR(Node* root, T data){
        Node *curr = root;
        while(curr != nullptr){
            if(data < curr->data){
                curr = curr->left;
            }else if(data > curr->data){
                curr = curr->right;
            }else   // 等于
            {
                return true;
            }
        }
        return false;
    }
    void preOrder(Node* node){
        if(node == nullptr){
            return;
        }
        cout << node->data << " " << endl;
        preOrder(node->left);
        preOrder(node->right);
    }
    void inOrder(Node* node){
        if(node == nullptr){
            return;
        }        
        inOrder(node->left);
        cout << node->data << " " << endl;
        inOrder(node->right);
    }
    void postOrder(Node* node){
        if(node == nullptr){
            return;
        }        
        postOrder(node->left);        
        postOrder(node->right);
        cout << node->data << " " << endl;
    }
    void preOrderNR(Node* root){        
        stack<Node*> s;
        s.push(root);
        while(s.size() > 0){
            Node* curr = s.top();
            cout << curr->data << endl;
            s.pop();
            if(curr->right != nullptr){
                s.push(curr->right);
            }
            if(curr->left != nullptr){
                s.push(curr->left);
            }
        }
    }
    Node* minimum(Node* node){
        if(node->left == nullptr){
            return node;
        }
        return minimum(node->left);
    }
    Node* maximum(Node* node){
        if(node->right == nullptr){
            return node;
        }
        return maximum(node->right);
    }
    Node* removeMin(Node* node){
        if(node->left == nullptr){
            size ++;
            return node->right;
        }
        node->left = removeMin(node->left);
        return node;
    }
    Node* removeMax(Node* node){
        if(node->left == nullptr){
            size --;
            return node->right;
        }
        node->left = removeMax(node->left);
        return node;
    }
    Node* remove(Node* node, T data){
        if(node == nullptr){
            return nullptr;
        }
        if(data < node->data){
            node->left = remove(node->left, data);
            return node;
        }else if(data > node->data){
            node->right = remove(node->right, data);
            return node;
        }else   // 相等，找到了
        {
            if(node->left == nullptr){
                size --;
                return node->right;
            }
            if(node->right == nullptr){
                size --;
                return node->left;
            }
            Node* successor = minimum(node->right);
            successor->right = removeMin(node->right);
            successor->left = node->left;
            size --;
            return successor;
        }
        
    }
    void levelOrder(Node* root){
        queue<Node*> q;
        q.push(root);
        while(q.size() > 0){
            Node* curr = q.front();
            q.pop();
            cout << curr->data << endl;
            if(curr->left != nullptr){
                q.push(curr->left);
            }
            if(curr->right != nullptr){
                q.push(curr->right);
            }
        }
    }
};

#endif // BST_H