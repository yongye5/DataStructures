/**
 * @description: 
 * @author: zp
 * @date:2019-12-28 14:54:45
 **/

#include <iostream>
#include "DoubleLinkedList.h"
using namespace std;

int main(){
    DoubleLinkedList<int> list;
    list.insert(1, 0);
    list.insert(2, 0);
    list.insert(3, 0);
    list.insert(4, 3);
    list.traverse();
    cout << "*******************************" << endl;
    list.remove(0);
    list.traverse();
    list.remove(1);
    cout << "****************************" << endl;
    list.traverse();

    cout << "size = " << list.getSize() << endl;
    system("pause");
    return 0;
}