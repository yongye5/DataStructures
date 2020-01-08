/**
 * @description: 
 * @author: zp
 * @date:2020-01-05 21:11:19
 **/

#include <iostream>
#include "LinkedListStack.h"
#include <vector>
using namespace std;

int main(){
    LinkedListStack<int>* stack = new LinkedListStack<int>();
    vector<int> v{1, 2, 3, 4,5, 6, 7,8 };
    for (size_t i = 0; i < v.size(); i++)
    {
        stack->push(v[i]);
    }
    stack->traverse();
    cout << "top = " << stack->top() << endl;
    stack->pop();
    cout << "top = " << stack->top() << endl;
    // LinkedList<int> *list = new LinkedList<int>();
    // vector<int> v{1, 2, 3, 4,5, 6, 7,8 };
    // for (size_t i = 0; i < v.size(); i++)
    // {
    //     list->insert(0, v[i]);
    // }
    // list->traverse();
    // cout << "**********************" << endl;
    // list->removeFirst();
    // list->traverse();
    system("pause");
    return 0;
}