#include <iostream>
#include <string.h>
#include <list>
#include <vector>

using namespace::std;

class Student {
private:
    string name;
    int sex; //jΜq:1  Μq:2
public:
    //RXgN^
    Student(string na, int se) {
        name = na;
        sex = se;
    }

    //Rs[RXgN^
    Student(const Student& stu ) {
        name = stu.name;
        sex = stu.sex;
    }

    string getName() {
        return name;
    }
    int getSex() {
        return sex;
    }
};

class StudentList {
protected:
    vector<Student> students;
public:
    StudentList() {};

    void add(Student student) {
        students.push_back(student);
    }

    Student getStudentAt(int index) {
        return students[index];
    }

    int getSize() {
        return students.size();
    }
};

class Teacher{
protected:
    StudentList studentList;
public:
    void createStudentList();
    void callStudent();
};

class MyTeacher : public Teacher{
private:
    StudentList* studentList;
public:
    MyTeacher() {
        this->studentList = new StudentList();
    }

    void createStudentList() {
        //StudentList* studentlist = new StudentList();
        this->studentList->add(Student("ΤδΊΎ", 1)); //Same Mean«

//        Student stu1("ΤδΊΎ", 1);
//        list->add(stu1);

        this->studentList->add(Student("ΤH’ό", 2));
        this->studentList->add(Student("ͺcΰY", 2));
        this->studentList->add(Student("ΌXrξ", 1));
        this->studentList->add(Student("ΜXζή", 2));
    }

    void callStudent() {
        int size = studentList->getSize();

        for (int i = 0; i < size; i++) {
            cout << studentList->getStudentAt(i).getName() << endl;
        }
    }
};

int main() {
    MyTeacher* you = new MyTeacher();
    you->createStudentList();
    you->callStudent();
}

