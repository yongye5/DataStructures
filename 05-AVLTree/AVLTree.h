#ifndef AVLTREE_H
#define AVLTREE_H
#include <algorithm>
#include <vector>
using namespace std;
/**
 * 不处理重复元素
 *
 */
template <typename T>
class AVLTree{
private:
    struct Node{
        T data;
        Node* left;
        Node* right;
        int height; // 节点的高度
        Node(T data){
            this->height = 1;   // 每个新添加的节点都为叶子节点，初始值为1
            this->data = data;
            left = nullptr;
            right = nullptr;
        }
    };
private:
    Node* root; // 根节点
    int size;   // 树中节点的数目
public:
    AVLTree(){
        this->root = nullptr;
        this->size = 0;
    }
    ~AVLTree(){
        delete root;
    }
    int getSize() const{
        return size;
    }
    bool isEmpty() const{
        return size == 0;
    }
    // 返回节点的高度值
    int getHeight(Node* node) const{
        if(node == nullptr){
            return 0;
        }
        return node->height;
    }
    // 添加节点
    void add(T data){
        root = add(root, data);
    }
    // 删除节点
    void remove(T data){
        root = remove(root, data);
    }
    Node* minimum(Node* node){
        if(node == nullptr){
            return nullptr;
        }
        Node* curr = node;
        while(curr->left != nullptr){
            curr = curr->left;
        }
        return curr;
    }
    /**
     * 判断当前树是否还是一个二叉搜索树
     *
     */
    bool isBST(){
        vector<T> vec;
        inOrder(root, vec);// 中序遍历tree，
        for (int i = 1; i < vec.size(); i++)
        {
            if(vec[i] < vec[i - 1]){
                return false;
            }
        }
        return true;
    }
    /**
     * 判断当前tree 是否是一个平衡二叉树
     *
     */
    bool isBalanced(){
        return isBalanced(root);
    }
private:
    /**
     * 计算当前节点的平衡因子
     *
     */
    int getBalancedFactor(Node* node){
        if(node == nullptr){
            return 0;
        }
        return getHeight(node->left) - getHeight(node->right);
    }
    /**
     * 中序遍历并记录每个节点的值
     *
     */
    void inOrder(Node* node, vector<T>& vec){
        if(node == nullptr){
            return;
        }
        inOrder(node->left, vec);
        vec.push_back(node->data);
        inOrder(node->right, vec);
    }
    bool isBalanced(Node* node){
        if(node == nullptr){
            return true;
        }
        if(abs(getBalancedFactor(node)) > 1){
            return false;
        }
        return isBalanced(node->left) && isBalanced(node->right);
    }
    /**
     * 右旋转  
     *      y                          x
     *    /   \                      /   \
     *    x   T1                    Z    Y
     *   /  \           ----->    /  \   / \
     *  z   T2                  T3   T4 T2 T1
     * / \
     *T3  T4 
     * 
     */
    Node* rightRotate(Node* y){
        Node* x = y->left;
        Node* T2 = x->right;

        x->right = y;
        y->left = T2;

        x->height = 1 + max(getHeight(x->left), getHeight(x->right));
        y->height = 1 + max(getHeight(y->left), getHeight(y->right));

        return x;
    }
    /**
     * 左旋转
     *      y                           x
     *    /   \                      /     \
     *    T1    x                    Y      Z
     *        / \           ----->  /  \   / \
     *      T2   z                 T1 T2   T3 T4 
     *          / \
     *        T3  T4 
     *
     */
    Node* leftRotate(Node* y){
        Node* x = y->right;
        Node* T2 = x->left;

        x->left = y;
        y->right = T2;
        x->height = 1 + max(getHeight(x->left), getHeight(x->right));
        y->height = 1 + max(getHeight(y->left), getHeight(y->right));

        return x;
    }
    Node* add(Node* node, T data){
        if(node == nullptr){
            size ++;
            return new Node(data);
        }
        if(data < node->data){
            node->left = add(node->left, data);
        }else if(data > node->data){
            node->right = add(node->right, data);
        }
        // 更新当前节点的高度
        node->height = 1 + max(this->getHeight(node->left), this->getHeight(node->right));
        int balancedFactor = getBalancedFactor(node);
        // if(abs(balancedFactor) > 1){
        //     cout << "不平衡的, 且平衡因子为" <<  getBalancedFactor(node) << endl;
        // }

        // LL 
        if(balancedFactor > 1 && getBalancedFactor(node->left) >= 0){
            return rightRotate(node);
        }
        // RR 
        if(balancedFactor < 1 && getBalancedFactor(node->right) <= 0){
            return leftRotate(node);
        }
        // LR 
        if(balancedFactor > 1 && getBalancedFactor(node->left) < 0){
            node->left = leftRotate(node->left);
            return rightRotate(node);
        }
        // RL 
        if(balancedFactor < 1 && getBalancedFactor(node->right) > 0){
            node->right = rightRotate(node->right);
            return leftRotate(node);
        }
        return node;
    }

    Node* remove(Node* node, T data){
        if(node == nullptr){
            return nullptr;
        }
        Node* retNode = nullptr;
        if(data < node->data){
            retNode = remove(node->left, data);
        }else if(data > node->data){
            retNode = remove(node->right, data);
        }else   // 相等
        {
            if (node->left = nullptr)
            {
                size --;
                retNode = node->right;
            }else if(node->left == nullptr){
                size --;
                retNode = node->left;
            }else
            {
                Node* successor = minimum(node);
                successor->right = remove(node, successor->data);
                successor->left = node->left;
                size --;
                retNode = successor;
            }                        
        }
        if(retNode == nullptr)        {
            return nullptr;
        }
        return maintainBalace(retNode);
    }

    Node* maintainBalace(Node* node){
        // 更新当前节点的高度
        node->height = 1 + max(this->getHeight(node->left), this->getHeight(node->right));
        int balancedFactor = getBalancedFactor(node);

        // LL 
        if(balancedFactor > 1 && getBalancedFactor(node->left) >= 0){
            return rightRotate(node);
        }
        // RR 
        if(balancedFactor < 1 && getBalancedFactor(node->right) <= 0){
            return leftRotate(node);
        }
        // LR 
        if(balancedFactor > 1 && getBalancedFactor(node->left) < 0){
            node->left = leftRotate(node->left);
            return rightRotate(node);
        }
        // RL 
        if(balancedFactor < 1 && getBalancedFactor(node->right) > 0){
            node->right = rightRotate(node->right);
            return leftRotate(node);
        }
    }
};

#endif // AVLTREE_H