#include <iostream>
#include <cstring>

const int MAX_STUDENTS = 50;

class Group;

class Student {
private:
    unsigned int id;
    char* lastName;
    int* grades;
    Group* group;
public:
    Student() : id(0), lastName(nullptr), grades(nullptr), group(nullptr) {}
    Student(unsigned int id, const char* lastName, const int* grades, Group* group) : id(id), group(group) {
        this->lastName = new char[strlen(lastName) + 1];
        strcpy(this->lastName, lastName);
        this->grades = new int[5];
        memcpy(this->grades, grades, sizeof(int) * 5);
    }
    Student(const Student& other) : id(other.id), group(other.group) {
        this->lastName = new char[strlen(other.lastName) + 1];
        strcpy(this->lastName, other.lastName);
        this->grades = new int[5];
        memcpy(this->grades, other.grades, sizeof(int) * 5);
    }
    ~Student() {
        delete[] lastName;
        delete[] grades;
    }
    unsigned int getId() const {
        return id;
    }
    const char* getLastName() const {
        return lastName;
    }
    const int* getGrades() const {
        return grades;
    }
    Group* getGroup() const {
        return group;
    }
    void setId(unsigned int id) {
        this->id = id;
    }
    void setLastName(const char* lastName) {
        delete[] this->lastName;
        this->lastName = new char[strlen(lastName) + 1];
        strcpy(this->lastName, lastName);
    }
    void setGrades(const int* grades) {
        memcpy(this->grades, grades, sizeof(int) * 5);
    }
    void setGroup(Group* group) {
        this->group = group;
    }
    Student& operator=(const Student& other) {
        if (this != &other) {
            id = other.id;
            group = other.group;
            delete[] lastName;
            lastName = new char[strlen(other.lastName) + 1];
            strcpy(lastName, other.lastName);
            delete[] grades;
            grades = new int[5];
            memcpy(grades, other.grades, sizeof(int) * 5);
        }
        return *this;
    }
    friend std::ostream& operator<<(std::ostream& os, const Student& student) {
        os << "ID: " << student.id << ", Last Name: " << student.lastName << ", Grades: ";
        for (int i = 0; i < 5; i++) {
            os << student.grades[i] << " ";
        }
        return os;
    }
    bool operator<(const Student& other) const {
        return id < other.id;
    }
    bool operator>(const Student& other) const {
        return id > other.id;
    }
};

class Group {
private:
    int index;
    Student* students[MAX_STUDENTS];
    int numStudents;
public:
    Group() : index(0), numStudents(0) {}
    Group(int index) : index(index), numStudents(0) {}
    int getIndex() const {
        return index;
    }
    void setIndex(int index) {
        this->index = index;
    }
    Student* operator[](int index) {
        return students[index];
    }
    Group& operator=(const Group& other) {
        if (this != &other) {
            index = other.index;
            numStudents = other.numStudents;
            for (int i = 0; i < numStudents; i++) {
                students[i] = new Student(*other.students[i]);
            }
        }
        return *this;
    }
    void addStudent(const Student& student) {
        if (numStudents < MAX_STUDENTS) {
            students[numStudents++] = new Student(student);
        }
    }
    void sortByLastName() {
        for (int i = 0; i < numStudents - 1; i++) {
            for (int j = i + 1; j < numStudents; j++) {
                if (strcmp(students[i]->getLastName(), students[j]->getLastName()) > 0) {
                    std::swap(students[i], students[j]);
                }
            }
        }
    }
    Student* findStudentById(unsigned int id) {
        for (int i = 0; i < numStudents; i++) {
            if (students[i]->getId() == id) {
                return students[i];
            }
        }
        return nullptr;
    }
    friend std::ostream& operator<<(std::ostream& os, const Group& group) {
        os << "Group " << group.index << ":\n";
        for (int i = 0; i < group.numStudents; i++) {
            os << *group.students[i] << "\n";
        }
        return os;
    }
};


int main(void) {
    Group group(1);
    Student s1(1, "Smith", new int[5]{80, 90, 85, 95, 75}, &group);
    Student s2(2, "Johnson", new int[5]{90, 85, 95, 80, 85}, &group);
    Student s3(3, "Williams", new int[5]{75, 80, 70, 85, 90}, &group);
    group.addStudent(s1);
    group.addStudent(s2);
    group.addStudent(s3);
    std::cout << "Unsorted:\n" << group << "\n";
    group.sortByLastName();
    std::cout << "Sorted by last name:\n" << group << "\n";
    Student* foundStudent = group.findStudentById(2);
    if (foundStudent) {
        std::cout << "Found student by id: " << *foundStudent << "\n";
    } else {
        std::cout << "Student not found\n";
    }
    return 0;
}
