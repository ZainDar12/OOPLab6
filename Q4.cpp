#include <iostream>
#include <string>
using namespace std;
class Person {
protected:
    string name;
    int age;

public:
    Person(string n, int a) : name(n), age(a) {}

    // Display basic info
    virtual void display() const {
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
    }

    virtual ~Person() {}
};

class Student : virtual public Person {
protected:
    string studentID;
    int gradeLevel;

public:
  
    Student(string n, int a, string id, int grade)
        : Person(n, a), studentID(id), gradeLevel(grade) {}

    void display() const override {
        cout << "\n=== Student Information ===" << endl;
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
        cout << "Student ID: " << studentID << endl;
        cout << "Grade Level: " << gradeLevel << endl;
    }
};

class Teacher : virtual public Person {
protected:
    string subject;
    int roomNumber;

public:

    Teacher(string n, int a, string subj, int room)
        : Person(n, a), subject(subj), roomNumber(room) {}

    // Display teacher info
    void display() const override {
        cout << "\n=== Teacher Information ===" << endl;
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
        cout << "Subject: " << subject << endl;
        cout << "Room Number: " << roomNumber << endl;
    }
};

// Derived class: GraduateStudent (Multiple Inheritance)
// Uses virtual inheritance to avoid diamond problem
class GraduateStudent : public Student, public Teacher {
private:
    string researchTopic;

public:
    GraduateStudent(string n, int a, string id, int grade, string subj, int room, string research)
        : Person(n, a), Student(n, a, id, grade), Teacher(n, a, subj, room), 
          researchTopic(research) {}

    // Display graduate student info
    void display() const override {
        cout << "\n=== Graduate Student Information ===" << endl;
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
        cout << "Student ID: " << studentID << endl;
        cout << "Grade Level: " << gradeLevel << endl;
        cout << "Teaching Subject: " << subject << endl;
        cout << "Room Number: " << roomNumber << endl;
        cout << "Research Topic: " << researchTopic << endl;
    }
};

int main() {
    // Create a GraduateStudent object
    GraduateStudent gradStudent("Emma Wilson", 26, "GS001", 12, "Advanced Physics", 
                                 305, "Quantum Computing Applications");
    
    // Display the graduate student details
    gradStudent.display();

    cout << "\n School system operational! " << endl;

    return 0;
}
