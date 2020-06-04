#include <iostream>
#include <string.h>
#include <list>
#include <vector>

using namespace::std;

class Student {
private:
    string name;
    int sex; //男の子:1  女の子:2
public:
    //コンストラクタ
    Student(string na, int se) {
        name = na;
        sex = se;
    }

    //コピーコンストラクタ
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
        this->studentList->add(Student("赤井亮太", 1)); //Same Mean↓

//        Student stu1("赤井亮太", 1);
//        list->add(stu1);

        this->studentList->add(Student("赤羽里美", 2));
        this->studentList->add(Student("岡田澪", 2));
        this->studentList->add(Student("西森俊介", 1));
        this->studentList->add(Student("中の森玲奈", 2));
    }

    void callStudent() {
        int size = studentList->getSize();

        for (int i = 0; i < size; i++) {
            cout << studentList->getStudentAt(i).getName() << endl;
        }
    }
};

class Iterator {
    bool hasNext();
    virtual Student next();
};

class Aggregate {
    Iterator iterator();
};

class MyStudentListIterator : public Iterator {

private:
    MyStudentList* myStudentList;
    int index;
public:
    //コンストラクタ
    MyStudentListIterator(MyStudentList* list) {
        this->myStudentList = list;
        this->index = 0;
    }

    bool hasNext() {
        if (this->myStudentList->getSize() > index) {
            return true;
        }
        else {
            return false;
        }
    }

    Student next() override {
        Student s = myStudentList->getStudentAt(index);
        index++;
        return s;
    }
};

class MyStudentList : public StudentList, public Aggregate {
public:
    MyStudentList() {
    }

    Iterator iterator() {
        return MyStudentListIterator(this);
    }
};

class VeteranTeacher :public Teacher {
    private MyStudentList list;

    public void createStudentList() {
        list = new MyStudentList(3);
        list.add(new Student("中川雄介", 1));
        list.add(new Student("板東恵美", 2));
        list.add(new Student("水島太郎", 1));
    }

    public void callStudents() {
        Iterator itr = list.iterator();
        while (itr.hasNext()) {
            System.out.println(((Student)itr.next()).getName());
        }
    }
}


int main() {
    MyTeacher* you = new MyTeacher();
    you->createStudentList();
    you->callStudent();
}

