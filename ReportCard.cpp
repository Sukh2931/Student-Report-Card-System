#include <iostream>
#include <string>
using namespace std;

// ---------- Base Class ----------
class Student {
protected:
    string name;
    int rollNo;
    int age;
    string course;

public:
    void getStudentDetails() {
        cout << "\n===== Enter Student Details =====\n";
        cout << "Enter Name: ";
        cin.ignore();
        getline(cin, name);
        cout << "Enter Roll No: ";
        cin >> rollNo;
        cout << "Enter Age: ";
        cin >> age;
        cout << "Enter Course: ";
        cin.ignore();
        getline(cin, course);
    }

    void showStudentDetails() {
        cout << "\n===== Student Information =====\n";
        cout << "Name: " << name << endl;
        cout << "Roll No: " << rollNo << endl;
        cout << "Age: " << age << endl;
        cout << "Course: " << course << endl;
    }
};

// ---------- Derived Class ----------
class Marks : public Student {
protected:
    float marks[5];
    float total = 0, percentage = 0;

public:
    void getMarks() {
        cout << "\n===== Enter Marks for 5 Subjects =====\n";
        for (int i = 0; i < 5; i++) {
            cout << "Subject " << i + 1 << ": ";
            cin >> marks[i];
            total += marks[i];
        }
        percentage = total / 5;
    }

    void showMarks() {
        cout << "\n===== Marks Details =====\n";
        for (int i = 0; i < 5; i++)
            cout << "Subject " << i + 1 << ": " << marks[i] << endl;
        cout << "Total: " << total << endl;
        cout << "Percentage: " << percentage << "%" << endl;
    }
};

// ---------- Derived from Marks ----------
class Result : public Marks {
    char grade;

public:
    void calculateGrade() {
        if (percentage >= 90)
            grade = 'A';
        else if (percentage >= 75)
            grade = 'B';
        else if (percentage >= 60)
            grade = 'C';
        else if (percentage >= 50)
            grade = 'D';
        else
            grade = 'F';
    }

    void displayReportCard() {
        showStudentDetails();
        showMarks();
        cout << "\n===== Final Grade =====\n";
        cout << "Grade: " << grade << endl;
    }
};

// ---------- Main Function ----------
int main() {
    Result r;
    r.getStudentDetails();
    r.getMarks();
    r.calculateGrade();
    r.displayReportCard();
    return 0;
}
