/**
 * @description: 
 * @author: zp
 * @date:2019-12-29 20:39:26
 **/

#include <iostream>
#include "CircularDoublyLinkedList.h"
using namespace std;

int main(){
    CircularDoublyLinkedList<int> *list = new CircularDoublyLinkedList<int>();
    list->add(1, 0);
    int value = list->get(0);
    cout << "value =  " << value << endl;
    list->set(0, 5);
    value = list->get(0);
    cout << "value =  " << value << endl;
    // list->add(2, 1);
    // list->addFirst(3);
    list->remove(0);
    list->traverse();

    system("pause");
    return 0;
}