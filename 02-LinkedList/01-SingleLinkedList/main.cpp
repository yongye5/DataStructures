/**
 * @description: 
 * @author: zp
 * @date:2019-12-27 13:05:15
 **/

#include <iostream> 
#include "SingleLinkedList.h"
using namespace std;

int main(){
    SingleLinkedList<int> *linkedList = new SingleLinkedList<int>();
    linkedList->insert(1, 0);
    linkedList->insert(2, 0);
    linkedList->insert(3, 1);
    linkedList->insert(4, 3);

    linkedList->reaverse();

    linkedList->remove(1);
    cout << "***************************************" << endl;
    linkedList->reaverse();

    cout << "**************************************" << endl;
    int size = linkedList->getSize();
    int first = linkedList->get(0);
    cout << "size = " << size << " " << "first = " << first << endl;
    
    system("pause");
    return 0;
}