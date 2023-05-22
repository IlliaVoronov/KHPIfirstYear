#include <iostream>
using namespace std;

class AbstractEmployee {
    virtual void AskForPromotion() = 0;
};

class Employee:AbstractEmployee {
protected:
    string Name;
private:
    string Company;
    int Age; 
public:
    void setName(string name) {
        Name = name;
    }
    string getName() {
        return Name;
    }
    
    void setCompany(string company) {
        Company = company;
    }
    string getCompany() {
        return Company;
    }

    void setAge(int age) {
        if (age >= 18) {
            Age = age;
        }
    }   
    int getAge() {
        return Age;
    }

    void IntroduceYourself() {
        cout << endl << "Employee name: " << Name << endl;
        cout << "Employee Company: " << Company << endl;
        cout << "Employee age: " << Age << endl;
    }
    Employee(string name, string company, int age) {    
        Age = age;
        Name = name;
        Company = company;
    }
    void AskForPromotion() {
        if(Age > 30)
            cout << Name << " got promoted!" << endl;
        else
            cout << Name << " sorry, no promotion for you :(" << endl;
    }
    virtual void Work() {
        cout << Name << " is checking Email, task backlog, performing tasks" << endl;
    }

};

class Developer: public Employee {
public:
    string FavProgrammingLanguage;    
    Developer(string name, string company, int age, string favProgrammingLanguage) 
        :Employee(name, company, age)
    {
        FavProgrammingLanguage = favProgrammingLanguage;
    }
    void FixBug() {
        cout << getName() << " fixed bug using " << FavProgrammingLanguage << endl;
    }
    void Work() {
        cout << Name << " is writing " << FavProgrammingLanguage << " code." << endl;
    }
};

class Teacher: public Employee {
public:
    string Subject;
    void PrepareLesson() {
        cout << Name << " is preparing " << Subject << " lesson" << endl;
    }
    Teacher(string name, string company, int age, string subject) 
        :Employee(name, company, age) // inharense constructor propertiesfrom empoyee class
    {
        Subject = subject;
    } 
    void Work() {
        cout << Name << " is teaching " << Subject << endl;
    }
};

int main(void)
{
    Developer d = Developer("Illia", "VORONOV", 17, "c++");
    Teacher t = Teacher("Jack", "Cool School", 35, "History");
    Employee *e1 = &d;
    Employee *e2 = &t;

    e1->Work();
    e2->Work();

    return 0;
}