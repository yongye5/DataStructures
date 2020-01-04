/**
 * @description: 
 * @author: zp
 * @date:2020-01-03 20:53:24
 **/

#include <iostream>
#include "AVLTree.h"
#include <vector>
using namespace std;

int main(){
     AVLTree<int> *avl = new AVLTree<int>();
    vector<int> v{1, 4, 7, 2, 9, 5};
    for(const auto& item : v){
        avl->add(item);
    }
    cout << "isBST "  << avl->isBST() << endl;
    cout << "isBalanced " << avl->isBalanced() <<  endl;
    cout << "***************************************" << endl;
    avl->remove(2);
    cout << "isBST "  << avl->isBST() << endl;
    cout << "isBalanced " << avl->isBalanced() <<  endl;
    system("pause");
    return 0;
}