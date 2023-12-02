//Develop student's record system all concepts of object oriented programming.

#include <iostream>
#include <vector>

using namespace std;

class Student {
private:
    string name;
    int rollNumber;
    float grade;

public:
    Student(string n, int roll, float g) : name(n), rollNumber(roll), grade(g) {}
    
    string getName() const {
        return name;
    }

    int getRollNumber() const {
        return rollNumber;
    }

    float getGrade() const {
        return grade;
    }

    void display() const {
        std::cout << "Name: " << name << "\nRoll Number: " << rollNumber << "\nGrade: " << grade << "\n\n";
    }
};

class StudentRecordsSystem {
private:
    vector<Student> students;

public:

    void addStudent(const Student& student) {
        students.push_back(student);
    }

    void displayAllStudents() const {
        cout << "----- Student Records -----\n";
        for (const auto& student : students) {
            student.display();
        }
    }

    void displayStudentByRollNumber(int rollNumber) const {
        for (const auto& student : students) {
            if (student.getRollNumber() == rollNumber) {
                cout << "----- Student Found -----\n";
                student.display();
                return;
            }
        }
        cout << "Student with Roll Number " << rollNumber << " not found.\n";
    }
};

int main() {
    StudentRecordsSystem recordsSystem;

    Student student1("Rahul", 12, 90.5);
    Student student2("Ramesh", 17, 85.0);
    Student student3("Raj", 35, 78.5);

    recordsSystem.addStudent(student1);
    recordsSystem.addStudent(student2);
    recordsSystem.addStudent(student3);

    while (true) {
        cout << "Menu:\n";
        cout << "1. Insert Student\n";
        cout << "2. Search Student\n";
        cout << "3. Display All Students\n";
        cout << "4. Exit\n";

        int choice;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                string name;
                int rollNumber;
                double grade;

                cout << "Enter student name: ";
                cin >> name;
                cout << "Enter roll number: ";
                cin >> rollNumber;
                cout << "Enter grade: ";
                cin >> grade;

                Student student(name, rollNumber, grade);
                recordsSystem.addStudent(student);
                cout << "Student inserted successfully.\n";
                break;
            }
            case 2: {
                int rollNumber;
                cout << "Enter roll number to search: ";
                cin >> rollNumber;
                recordsSystem.displayStudentByRollNumber(rollNumber);
                break;
            }
            case 3:
                recordsSystem.displayAllStudents();
                break;
            case 4:
                cout << "Exiting the Student Records System.\n";
                return 0;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    }

    return 0;
}