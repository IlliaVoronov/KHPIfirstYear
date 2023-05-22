#include <iostream>
#include <cstring>

const int MAX_STUDENTS = 100;

struct Student
{
    unsigned int id;
    char surname[50];
    int marks[5]; // assuming 5 subjects per student
};

// Function to display the data of a single student
void displayStudentData(Student s)
{
    std::cout << "ID: " << s.id << "\n";
    std::cout << "Surname: " << s.surname << "\n";
    std::cout << "Marks: ";
    for (int i = 0; i < 5; i++)
    {
        std::cout << s.marks[i] << " ";
    }
    std::cout << "\n";
}

// Function to sort the array of pointers to students alphabetically by surname
void sortStudentsAlphabetically(Student* students[], int length)
{
    for (int i = 0; i < length - 1; i++)
    {
        for (int j = 0; j < length - i - 1; j++)
        {
            if (strcmp(students[j]->surname, students[j + 1]->surname) > 0)
            {
                // swap the pointers
                Student* temp = students[j];
                students[j] = students[j + 1];
                students[j + 1] = temp;
            }
        }
    }
}

// Function to search for students with an average score in the interval [64, 74]
void searchStudentsByAverageScore(Student* students[], int length)
{
    for (int i = 0; i < length; i++)
    {
        int sum = 0;
        for (int j = 0; j < 5; j++)
        {
            sum += students[i]->marks[j];
        }
        double average = static_cast<double>(sum) / 5.0;
        if (average >= 64 && average <= 74)
        {
            displayStudentData(*students[i]);
        }
    }
}

// Function to display all the students in the array of pointers
void displayAllStudents(Student* students[], int length)
{
    for (int i = 0; i < length; i++)
    {
        displayStudentData(*students[i]);
    }
}

int main()
{
    Student students[MAX_STUDENTS] = {
        {1, "Ilya", {75, 80, 70, 85, 90}},
        {2, "Nick", {60, 65, 70, 75, 80}},
        {3, "Olya", {90, 85, 80, 75, 70}},
        {4, "Yana", {85, 80, 75, 70, 65}},
        {5, "Dima", {75, 70, 65, 60, 55}},
        {6, "Polina", {90, 67, 88, 79, 90}},
    };

    int numStudents = 6;

    Student* studentPointers[MAX_STUDENTS];
    for (int i = 0; i < numStudents; i++)
    {
        studentPointers[i] = &students[i];
    }

    std::cout << "All students:\n";
    displayAllStudents(studentPointers, numStudents);

    std::cout << "\nStudents sorted alphabetically by surname:\n";
    sortStudentsAlphabetically(studentPointers, numStudents);
    displayAllStudents(studentPointers, numStudents);

    std::cout << "\nStudents with average score in the interval [64, 74]:\n";
    searchStudentsByAverageScore(studentPointers, numStudents);

    return 0;
}
