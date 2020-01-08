/**
 * @description: 
 * @author: zp
 * @date:2020-01-08 14:44:17
 **/

#include <iostream>
#include "LinkedListQueue.h"
#include <vector>
using namespace std;

int main(){
    LinkedListQueue<int> *q = new LinkedListQueue<int>();
    vector<int> v{1, 2, 3, 4,5,6,7,8,98,9};
    for (size_t i = 0; i < v.size(); i++)
    {
        q->enqueue(v[i]);
    }
    cout << "队头 = " << q->front() << endl;
    cout << "队尾 = " << q->end() << endl;
    for (size_t i = 0; i < v.size() - 1; i++)
    {
        q->dequeue();
    }
    cout << "队头 = " << q->front() << endl;
    cout << "队尾 = " << q->end() << endl;
    q->dequeue();
    system("pause");
    return 0;
}