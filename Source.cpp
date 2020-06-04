#include <iostream>
#include <string.h>
#include <list>
#include <vector>

using namespace::std;

class Student {
private:
    string name;
    int sex; //�j�̎q:1  ���̎q:2
public:
    //�R���X�g���N�^
    Student(string na, int se) {
        name = na;
        sex = se;
    }

    //�R�s�[�R���X�g���N�^
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
        this->studentList->add(Student("�Ԉ䗺��", 1)); //Same Mean��

//        Student stu1("�Ԉ䗺��", 1);
//        list->add(stu1);

        this->studentList->add(Student("�ԉH����", 2));
        this->studentList->add(Student("���c�Y", 2));
        this->studentList->add(Student("���X�r��", 1));
        this->studentList->add(Student("���̐X���", 2));
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

