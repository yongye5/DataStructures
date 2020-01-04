/**
 * @description: 
 * @author: zp
 * @date:2020-01-04 20:30:57
 **/

#include <iostream>
#include "LoopQueue.h"
#include <vector>
using namespace std;

int main(){
    LoopQueue<int> *q = new LoopQueue<int>();
    vector<int> v{1, 2, 4, 6,7,8,9, 34,2,2,3,5,6,7,3,2};
    for (size_t i = 0; i < v.size(); i++)
    {
        cout << "v[" << i << "] = " << v[i] << endl;
        q->enqueue(v[i]);
        cout << "queue :" << endl;
        q->traverse();
    }
    cout << "**************************************" << endl;
    cout << q->dequeue() << endl;
    cout << q->dequeue() << endl;
    cout << q->dequeue() << endl;
    int capacity = q->getCapacity();
    cout << "capacity = " << capacity << endl;
    system("pause");
    return 0;
}