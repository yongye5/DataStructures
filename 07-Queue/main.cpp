/**
 * @description: 
 * @author: zp
 * @date:2020-01-04 16:04:20
 **/

#include <iostream>
#include "ArrayQueue.h"
using namespace std;

int main(){
    ArrayQueue<int> *q = new ArrayQueue<int>();
    
    int data[12] = {1, 2, 3,4, 5,6,7,8,9,2,3,4};
    for (size_t i = 0; i < 12; i++)
    {
        q->enqueue(data[i]);
    }
    cout << *q<< endl;
    cout << "size = " << q->getSize() << endl;
    cout << "isEmpty = " << q->isEmpty() << endl;
    // Array<int> * arr = new Array<int>();
    // int data[12] = {1, 2, 3,4, 5,6,7,8,9,2,3,4};
    // for (size_t i = 0; i < 12; i++)
    // {
    //     arr->addFirst(data[i]);
    // }
    // arr->addLast(100);
    // arr->addLast(200);
    // cout << *arr << endl;

    // arr->removeLast();
    // cout << *arr << endl;
    // arr->removeFirst();
    // cout << *arr << endl;
    // arr->remove(4);
    // cout << *arr << endl;
    system("pause");
    return 0;
}