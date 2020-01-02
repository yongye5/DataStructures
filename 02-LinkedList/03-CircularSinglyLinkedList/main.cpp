/**
 * @description: 
 * @author: zp
 * @date:2019-12-29 13:40:04
 **/

#include <iostream>
#include "CircularSinglyLinkedList.h"
using namespace std;

/**
 * 测试循环单链表
 *
 */
int main(){
    CircularSinglyLinkedList<int> *list = new CircularSinglyLinkedList<int>();
    list->addToEmpty(1);
    list->addBegin(2);
    // list->addBegin(3);
    // list->addEnd(4);

    //list->add(5, 1);
    list->traverse();
    //list->remove(0);
    cout << "size =" << list->getSize() << endl;
    //list->traverse();
    list->removeByData(1);    
    list->traverse();
    cout << "*******************************" << endl;
    cout << list->get(0) << endl;
    system("pause");
    return 0;
}