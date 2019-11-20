

#include <ostream>
#include <string>
using namespace std;
class Student {
private:
    string name;
    int score;
public:
    Student(string studentName = "", int studentScore = 0):name(studentName), score(studentScore) {
    }

    friend ostream & operator<<(ostream &out, Student& stu){
        out << "Student(name: " <<stu.name << ", score: " << stu.score << ")" << endl;
        return out; 
    }
    friend bool operator== (Student& stu1, Student& stu2){
        if(stu1.name == stu2.name && stu1.score == stu2.score){
            return true;
        }
        return false;
    }
};