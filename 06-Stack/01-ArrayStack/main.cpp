/**
 * @description: 
 * @author: zp
 * @date:2020-01-04 13:12:33
 **/

#include <iostream>
#include "ArrayStack.h"
using namespace std;

int main(){
    ArrayStack<int> *stack = new ArrayStack<int>();
    int data[12] = {1, 2, 3,4, 5,6,7,8,9,2,3,4};
    for (size_t i = 0; i < 12; i++)
    {
        stack->push(data[i]);
    }
    cout << *stack << endl;



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
    system("pause");
    return 0;
}