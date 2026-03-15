#include <iostream>
using namespace std;


class Person {
protected:
    string name;
    int id;
    string address;
    string phoneNumber;
    string email;

public:
    Person(string n, int i, string addr, string phone, string mail) {
        name = n;
        id = i;
        address = addr;
        phoneNumber = phone;
        email = mail;
    }

    virtual void displayInfo() {
        cout << "Name: " << name << endl;
        cout << "ID: " << id << endl;
        cout << "Address: " << address << endl;
        cout << "Phone: " << phoneNumber << endl;
        cout << "Email: " << email << endl;
    }

    void updateInfo(string addr, string phone, string mail) {
        address = addr;
        phoneNumber = phone;
        email = mail;
    }

    string getName() {
        return name;
    }

    virtual ~Person() {}
};


class Student : public Person {
private:
    string coursesEnrolled[10];
    int courseCount;
    double GPA;
    int enrollmentYear;

public:
    Student(string n, int i, string addr, string phone, string mail,
            double gpa, int year)
        : Person(n, i, addr, phone, mail) {
        GPA = gpa;
        enrollmentYear = year;
        courseCount = 0;
    }

    void enrollCourse(string course) {
        if (courseCount < 10) {
            coursesEnrolled[courseCount++] = course;
        }
    }

    void displayInfo() override {
        Person::displayInfo();
        cout << "Enrollment Year: " << enrollmentYear << endl;
        cout << "GPA: " << GPA << endl;

        cout << "Courses Enrolled: ";
        for (int i = 0; i < courseCount; i++) {
            cout << coursesEnrolled[i] << " ";
        }
        cout << endl;
    }
};

class Professor : public Person {
private:
    string department;
    string coursesTaught[10];
    int courseCount;
    double salary;

public:
    Professor(string n, int i, string addr, string phone, string mail,
              string dept, double sal)
        : Person(n, i, addr, phone, mail) {
        department = dept;
        salary = sal;
        courseCount = 0;
    }

    void addCourse(string course) {
        if (courseCount < 10) {
            coursesTaught[courseCount++] = course;
        }
    }

    void displayInfo() override {
        Person::displayInfo();
        cout << "Department: " << department << endl;
        cout << "Salary: " << salary << endl;

        cout << "Courses Taught: ";
        for (int i = 0; i < courseCount; i++) {
            cout << coursesTaught[i] << " ";
        }
        cout << endl;
    }
};


class Staff : public Person {
private:
    string department;
    string position;
    double salary;

public:
    Staff(string n, int i, string addr, string phone, string mail,
          string dept, string pos, double sal)
        : Person(n, i, addr, phone, mail) {
        department = dept;
        position = pos;
        salary = sal;
    }

    void displayInfo() override {
        Person::displayInfo();
        cout << "Department: " << department << endl;
        cout << "Position: " << position << endl;
        cout << "Salary: " << salary << endl;
    }
};


class Course {
private:
    string courseId;
    string courseName;
    int credits;
    string instructor;
    string schedule;

    Student* registeredStudents[20];
    int studentCount;

public:
    Course(string id, string name, int cr, string instr, string sched) {
        courseId = id;
        courseName = name;
        credits = cr;
        instructor = instr;
        schedule = sched;
        studentCount = 0;
    }

    void registerStudent(Student* s) {
        if (studentCount < 20) {
            registeredStudents[studentCount++] = s;
            cout << s->getName() << " registered in " << courseName << endl;
        }
    }

    void calculateGrades() {
        cout << "Calculating grades for " << courseName << endl;
        cout << "Total Students: " << studentCount << endl;
    }

    void displayCourse() {
        cout << "\nCourse ID: " << courseId << endl;
        cout << "Course Name: " << courseName << endl;
        cout << "Credits: " << credits << endl;
        cout << "Instructor: " << instructor << endl;
        cout << "Schedule: " << schedule << endl;
    }
};


int main() {

    Student s1("hasssan Khan", 101, "Karachi", "03001234567", "hassan@email.com", 3.6, 2023);
    Professor p1("Dr Amir", 201, "Lahore", "03111234567", "amir@uni.edu", "Computer Science", 120000);
    Staff st1("Mehmood sahab", 301, "Islamabad", "03221234567", "mehmood@uni.edu", "Administration", "Manager", 80000);

    Course c1("CS101", "Programming Fundamentals", 3, "Dr Ahmed", "Mon-Wed 10AM");

    s1.enrollCourse("CS101");
    p1.addCourse("CS101");

    c1.registerStudent(&s1);

    cout << "\n--- Student Info ---\n";
    s1.displayInfo();

    cout << "\n--- Professor Info ---\n";
    p1.displayInfo();

    cout << "\n--- Staff Info ---\n";
    st1.displayInfo();

    cout << "\n--- Course Info ---\n";
    c1.displayCourse();

    c1.calculateGrades();

    return 0;
}