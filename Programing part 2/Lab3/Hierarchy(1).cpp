// Implement classes "Human," "Citizen", "Student", and "Employee". 
// Each class must implement virtual function that shows related data on the screen. 
// Create an array of pointers to different objects of the class hierarchy. 
// Create a cycle and display data that represents objects of different types.
#include <iostream>
using namespace std;

class Human {
public:
    int Age;
    string Name;
    string FullName;
    void setAge(int age) { Age = age; }
    int getAge() { return Age; }
    void setName(string name) { Name = name; }
    string getName() { return Name; }
    void setFullName(string fullName) { FullName = fullName;}
    string getFullName() { return FullName; }

    virtual void Passport() {
        cout << "Human " << Name << ": Age = " 
        << Age << "; FullName = " << FullName << endl;
    }

    Human(int age, string name, string fullName) {
        Age = age;
        Name = name;
        FullName = fullName;
    }
};

class Citizen : public Human {
public:
    string Citizenship;

    void Passport() { 
        cout << "Citizen " << Name << ": citizenship = " << Citizenship << " Age = "
        << Age << "; FullName = " << FullName << endl;
    }
    Citizen(int age, string name, string fullName, string citizenship)
        :Human(age, name, fullName){
            Citizenship = citizenship;
        }
};

class Student: public Human {
public:
    string Uneversity;

    void Passport() { 
        cout << "Student " << Name << ": Uneversity = " << Uneversity << " Age = "
        << Age << "; FullName = " << FullName << endl;
    }
    Student(int age, string name, string fullName, string uneversity)
        :Human(age, name, fullName){
            Uneversity = uneversity;
        }
};

class Employee: public Human {
public:
    string Job;

    void Passport() { 
        cout << "Worker " << Name << ": Job = " << Job << "Age = "
        << Age << "; FullName = " << FullName << endl;
    }
    Employee(int age, string name, string fullName, string job)
        :Human(age, name, fullName){
            Job = job;
        }
    
};

int main(void) 
{
    int amountOfPeople = 3;

    Human* objects[amountOfPeople];
    objects[0] = new Human(18, "Joshua", "Smith");
    objects[1] = new Citizen(25, "John", "Smith", "Ukraine");
    objects[2] = new Student(20, "Alice", "Johnson", "Harvard");

    for (int i = 0; i < amountOfPeople; i++) {
        objects[i]->Passport();
        delete objects[i];
    }
    return 0;
}

