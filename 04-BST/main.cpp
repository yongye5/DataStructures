/**
 * @description: 
 * @author: zp
 * @date:2020-01-02 16:20:01
 **/

#include <iostream>
#include "BST.h"
#include <vector>
using namespace std;

int main(){
    BST<int> bst;
    vector<int> v{5, 3, 9, 1, 34, 2, 4};
    for (size_t i = 0; i < v.size(); i++)
    {
        bst.insert(v[i]);
    }
    cout << "size = " << bst.getSize() << endl;
    bool flag = bst.contains(3);
    bool flag2 = bst.contains(10);
    bool flag3 = bst.containsNR(3);
    bool flag4 = bst.containsNR(10);

    cout << "********递归先序遍历*************************" << endl;
    bst.preOrder();
    cout << "(********迭代先序遍历*************************************" << endl;
    bst.preOrderNR();
    cout << "(********中序遍历*************************************" << endl;
    bst.inOrder();
    cout << "(********后序遍历*************************************" << endl;
    bst.postOrder();
    cout << "**********最小值 递归****************************************" << endl;
    cout << bst.minimum() << endl;
    cout << "**********最小值 非递归****************************************" << endl;
    cout << bst.minmumNR() << endl;
    cout << "**********最大值 递归****************************************" << endl;
    cout << bst.maximum() << endl;
    cout << "**********最大值 非递归****************************************" << endl;
    cout << bst.maxmumNR() << endl;
    cout << "*********************************************" << endl;
    bst.removeMin();
    cout << "(********中序遍历*************************************" << endl;
    bst.inOrder();
    bst.remove(9);
    cout << "(********中序遍历*************************************" << endl;
    bst.inOrder();
    cout << "(********层序遍历*************************************" << endl;
    bst.levelOrder();
    system("pause");
    return 0;
}