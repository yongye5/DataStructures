#include <iostream>
#include "Array.h"
#include "Student.h"
using namespace std;
int main(){

    Array<Student> *arr = new Array<Student>(3);
    Student stu1("张三", 12);
    Student stu2("李四", 13);
    Student stu3("王五", 14);
    Student stu4("王liu", 15);
    Student stu5("李四", 13);
    Student stu6("王五", 14);
    Student stu7("王liu", 15);
    arr->addLast(stu1);
    cout << *arr;
    arr->addLast(stu2);
    cout << *arr;
    arr->addLast(stu3);
    cout << *arr;
    arr->addLast(stu4);
    arr->addLast(stu5);
    arr->addLast(stu6);
    arr->addLast(stu7);
    cout << *arr;
    
    arr->remove(3);
    arr->remove(3);
    arr->remove(3);
    arr->remove(3);
    cout << *arr;
    cout << "第0个学生" << endl;
    Student stu =  (*arr).get(0);
    cout << stu << endl;
    // set
    
    Student stu8("赵六", 89);    
    arr->set(0, stu8);
    Student stuT = arr->front();
    cout << stuT << endl;
    cout << "************************" << endl;
    cout << arr->find(stu1) << endl;
    cout << "contains :" << arr->contains(stu8) << endl;
    cout << arr->find(stu8) << endl;

    cout <<"****************************" << endl;
    cout << *arr << endl;
    arr->removeElement(stu8);
    cout << *arr << endl;
    cout << "Hello world" << endl;
    system("pause");
    return 0;
}