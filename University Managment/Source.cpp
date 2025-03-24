#include<iostream>
#include<string>
using namespace std;

class person {
protected:
    string name;
    int age;
public:
    person(string n, int a) : name(n), age(a) {}
    virtual void display() {
        cout << "-----Person Details-----\n";
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
    }

    string getName() const {  // Getter for name
        return name;
    }

    virtual ~person() {}
};

class professor : public person {
public:
    string subject;
public:
    professor(string n, int a, string s) : person(n, a), subject(s) {}
    void display() override {
        cout << "-----Professor Details-----\n";
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
        cout << "Subject: " << subject << endl;
    }
};

class student : public person {
public:
    int roll;
    string dep;
public:
    student(string n, int a, int r, string d) : person(n, a), roll(r), dep(d) {}
    void display() override {
        cout << "-----Student Details-----\n";
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
        cout << "Roll Number: " << roll << endl;
        cout << "Department: " << dep << endl;
    }
};

class Department {
private:
    string deptName;
    professor* professors[5];
    student* students[5];
    int profCount = 0;
    int studCount = 0;
public:
    Department(string d) : deptName(d) {}

    void addProfessor(professor* p) {
        if (profCount < 5) {
            professors[profCount++] = p;
        }
    }

    void addStudent(student* s) {
        if (studCount < 5) {
            students[studCount++] = s;
        }
    }

    void displayDep() {
        cout << "-----Department: " << deptName << "-----\n";
        cout << "Total Professors: "<<profCount<<endl;
        for (int i = 0; i < profCount; i++) {
            professors[i]->display();
        }
        cout << "Total Students: "<<studCount<<endl;
        for (int i = 0; i < studCount; i++) {
            students[i]->display();
        }
    }
};

class University {
private:
    string name;
    Department* departments[5];
    int deptCount = 0;
public:
    University(string n) : name(n) {}

    void addDepartment(Department& d) {
        if (deptCount < 5) {
            departments[deptCount++] = &d;  // Pass reference as pointer
        }
    }

    void displayUniversity() {
        cout << "-----University: " << name << "-----\n";
        for (int i = 0; i < deptCount; i++) {
            departments[i]->displayDep();
        }
    }
};

class Library {
public:
    void issueBook(student& st) {
        cout << "Book issued to: " << st.getName() << endl;  // Access name through getter
    }
};

int main() {
    person* p1;
    p1 = new professor("Dr. Zulqadar", 40, "COAL");
    p1->display();
    delete p1;

    person* p2;
    p2 = new student("Usman", 19, 710, "Computer Science");
    p2->display();
    delete p2;

    Department csDept("Computer Science");
    professor* prof1 = new professor("Dr. John", 45, "Data Structures");
    professor* prof2 = new professor("Dr. Sarah", 38, "Algorithms");
    csDept.addProfessor(prof1);
    csDept.addProfessor(prof2);

    student* student1 = new student("Alice", 21, 101, "Computer Science");
    student* student2 = new student("Bob", 22, 102, "Computer Science");
    csDept.addStudent(student1);
    csDept.addStudent(student2);

    University uni("XYZ University");
    uni.addDepartment(csDept);  // Pass by reference (no pointer needed)

    uni.displayUniversity();

    Library library;
    library.issueBook(*student1);

    delete prof1;
    delete prof2;
    delete student1;
    delete student2;

    return 0;
}
