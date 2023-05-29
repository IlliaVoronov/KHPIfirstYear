#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>

const int MAX_STUDENTS = 50;

class Group;

class Student {
private:
    unsigned int id;
    std::string* lastName;
    std::vector<int>* grades;
    Group* group;

public:
    Student() : id(0), lastName(nullptr), grades(nullptr), group(nullptr) {}
    Student(unsigned int id, std::string lastName, std::vector<int> grades, Group* group) : id(id), group(group) {
        this->lastName = new std::string(lastName);
        this->grades = new std::vector<int>(grades);
    }
    Student(const Student& other) : id(other.id), group(other.group) {
        this->lastName = new std::string(*other.lastName);
        this->grades = new std::vector<int>(*other.grades);
    }
    ~Student() {
        delete lastName;
        delete grades;
    }

    unsigned int getId() const { return id; }
    void setId(unsigned int id) { this->id = id; }
    std::string getLastName() const { return *lastName; }
    void setLastName(std::string lastName) { *this->lastName = lastName; }
    std::vector<int> getGrades() const { return *grades; }
    void setGrades(std::vector<int> grades) { *this->grades = grades; }
    Group* getGroup() const { return group; }
    void setGroup(Group* group) { this->group = group; }

    Student& operator=(const Student& other) {
        if (this != &other) {
            id = other.id;
            group = other.group;
            delete lastName;
            lastName = new std::string(*other.lastName);
            delete grades;
            grades = new std::vector<int>(*other.grades);
        }
        return *this;
    }

    friend std::ostream& operator<<(std::ostream& os, const Student& student) {
        os << "ID: " << student.id << ", Last Name: " << *student.lastName << ", Grades: ";
        for (int grade : *student.grades) {
            os << grade << " ";
        }
        return os;
    }

    bool operator<(const Student& other) const {
        return getAverageGrade() < other.getAverageGrade();
    }
    bool operator>(const Student& other) const {
        return getAverageGrade() > other.getAverageGrade();
    }

    double getAverageGrade() const {
        double sum = 0;
        for (int grade : *grades) {
            sum += grade;
        }
        return sum / grades->size();
    }

    bool hasGrade(int grade) const {
        return std::find(grades->begin(), grades->end(), grade) != grades->end();
    }
};

class Group {
private:
    int index;
    Student* students[MAX_STUDENTS];
    int numStudents;

public:
    Group() : index(0), numStudents(0) {
        for (int i = 0; i < MAX_STUDENTS; i++) {
            students[i] = nullptr;
        }
    }
    Group(int index) : index(index), numStudents(0) {
        for (int i = 0; i < MAX_STUDENTS; i++) {
            students[i] = nullptr;
        }
    }
    ~Group() {
        for (int i = 0; i < numStudents; i++) {
            delete students[i];
        }
    }

    int getIndex() const { return index; }
    void setIndex(int index) { this->index = index; }
    int getNumStudents() const { return numStudents; }

    Student* operator[](int index) const {
        if (index < 0 || index >= numStudents) {
            return nullptr;
        }
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

    void sortByAverageGrade() {
        std::sort(students, students + numStudents, [](Student* a, Student* b) {
            return *a > *b;
        });
    }

    std::vector<Student*> findStudentsWithGrade(int grade) const {
        std::vector<Student*> result;
        std::for_each(students, students + numStudents, [&](Student* student) {
            if (student->hasGrade(grade)) {
                result.push_back(student);
            }
        });
        return result;
    }

    bool addStudent(Student* student) {
        if (numStudents >= MAX_STUDENTS) {
            return false;
        }
        students[numStudents++] = student;
        student->setGroup(this);
        return true;
    }

    // friend function for outputting data to stream
    friend std::ostream& operator<<(std::ostream& os, const Group& group) {
        os << "Group " << group.index << ":\n";
        for (int i = 0; i < group.numStudents; i++) {
            os << *group.students[i] << "\n";
        }
        return os;
    }
};

int main() {
    Group group(1);
    Student* student1 = new Student(1, "Vasuk", { 80, 90, 85 }, nullptr);
    Student* student2 = new Student(2, "Voronov", { 75, 85, 90 }, nullptr);
    Student* student3 = new Student(3, "Palkosh", { 90, 95, 85 }, nullptr);
    Student* student4 = new Student(4, "Johnson", { 70, 80, 75 }, nullptr);
    group.addStudent(student1);
    group.addStudent(student2);
    group.addStudent(student3);
    group.addStudent(student4);

    // demonstrate sorting by average grade
    group.sortByAverageGrade();
    std::cout << "Students sorted by average grade:\n";
    for (int i = 0; i < group.getNumStudents(); i++) {
        std::cout << *group[i] << "\n";
    }

    // demonstrate finding students with a certain grade
    std::vector<Student*> studentsWith85 = group.findStudentsWithGrade(85);
    std::cout << "Students with grade 85:\n";
    for (Student* student : studentsWith85) {
        std::cout << *student << "\n";
    }

    // demonstrate placing students into priority queue
    std::priority_queue<Student*> pq;
    pq.push(student1);
    pq.push(student2);
    pq.push(student3);
    pq.push(student4);
    std::cout << "Students in descending order of average grade:\n";
    while (!pq.empty()) {
        std::cout << *pq.top() << "\n";
        pq.pop();
    }

    delete student1;
    delete student2;
    delete student3;
    delete student4;

    return 0;
}
