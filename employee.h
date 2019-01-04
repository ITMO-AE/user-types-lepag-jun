#ifndef EMPLOYEE_H
#define EMPLOYEE_H

enum class Gender
{
    male,
    female
};

class Employee
{
private:
    std::string first_name;
    std::string last_name;
    Gender sex;
    unsigned int age;
    unsigned int category;

public:
    Employee(std::string f_name, std::string l_name, Gender in_sex, unsigned int in_age, unsigned int in_category);

    ~Employee();

    void promote();

    void demote();

    void printInfo();

    std::string getGender();
};

#endif // EMPLOYEE_H
