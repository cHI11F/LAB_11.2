#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <locale>
#include <fstream>

using namespace std;

struct Grades {
    union {
        double programming;
        double numerical_methods;
        double pedagogy;
    };

    Grades() : programming(0) {}
};

struct Student {
    string surname;
    int course = 0;
    string specialty;
    double physics_grade = 0;
    double math_grade = 0;
    double programming_grade = 0; 
};

void inputStudentData(Student& student, int number) {
    cout << "Student surname " << number << ": ";
    cin >> student.surname;
    cout << "Physics grade: ";
    cin >> student.physics_grade;
    cout << "Math grade: ";
    cin >> student.math_grade;

    cout << "Programming grade: "; 
    cin >> student.programming_grade;
}

void inputCourseAndSpecialty(Student& student) {
    cout << "Course: ";
    cin >> student.course;
    cout << "Specialty: ";
    cin.ignore();
    getline(cin, student.specialty);
}

void inputStudentsData(vector<Student>& students, int number_of_students) {
    for (int i = 0; i < number_of_students; ++i) {
        Student new_student;
        inputStudentData(new_student, i + 1);
        inputCourseAndSpecialty(new_student);
        students.push_back(new_student);
    }
}

void printStudentsTable(const vector<Student>& students) {
    cout << setw(5) << "No" << setw(15) << "Surname" << setw(7) << "Course" << setw(15) << "Specialty"
        << setw(10) << "Physics" << setw(10) << "Math" << setw(15) << "Programming" << endl;

    for (size_t i = 0; i < students.size(); ++i) {
        cout << setw(5) << i + 1 << setw(15) << students[i].surname << setw(7) << students[i].course
            << setw(15) << students[i].specialty << setw(10) << students[i].physics_grade
            << setw(10) << students[i].math_grade << setw(15) << students[i].programming_grade << endl;
    }
}

int countStudentsWithoutThrees(const vector<Student>& students) {
    int count = 0;
    for (const auto& student : students) {
        if (student.physics_grade >= 4 && student.math_grade >= 4 && student.programming_grade >= 4) {
            ++count;
        }
    }
    return count;
}

double calculatePercentageOfStudentsWithAverageBelowFour(const vector<Student>& students) {
    int total_students = students.size();
    int count = 0;
    for (const auto& student : students) {
        double average = (student.physics_grade + student.math_grade + student.programming_grade) / 3.0;
        if (average < 4) {
            ++count;
        }
    }
    return (count * 100.0) / total_students;
}

int main() {
    setlocale(LC_ALL, "ukr");
    vector<Student> students;
    int number_of_students;
    string filepath;
    cout << "Enter the file path to save the data: ";
    getline(cin, filepath);

    ofstream outputFile(filepath);
    if (!outputFile) {
        cerr << "Error: Unable to open file for writing data!" << endl;
        return 1;
    }

    cout << "Number of students: ";
    cin >> number_of_students;
    cin.ignore();

    inputStudentsData(students, number_of_students);

    cout << "\nStudents table:\n";
    printStudentsTable(students);

    int without_threes = countStudentsWithoutThrees(students);
    cout << "\nNumber of students without threes: " << without_threes << endl;

    double percentage_below_four = calculatePercentageOfStudentsWithAverageBelowFour(students);
    cout << "Percentage of students with an average below 4: " << fixed << setprecision(2) << percentage_below_four << "%" << endl;

    for (const auto& student : students) {
        outputFile << student.surname << " " << student.course << " " << student.specialty << " "
            << student.physics_grade << " " << student.math_grade << " " << student.programming_grade << endl;
    }

    outputFile.close();

    cout << "Data successfully saved to file: " << filepath << endl;

    return 0;
}
