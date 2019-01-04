#include <iostream>
#include <vector>
#include <iomanip>
#include <employee.h>

using namespace std;

Employee::Employee(string f_name, string l_name, Gender in_sex, unsigned int in_age, unsigned int in_category):
    first_name(f_name),
    last_name(l_name),
    sex(in_sex),
    age(in_age),
    category(in_category)
{
}

Employee::~Employee()
{
}

void Employee::promote()
{
    category++;
}

void Employee::demote()
{
    category--;
}

string Employee::getGender()
{
    if(sex == Gender::male)
        return "мужской";
    else
        return "женский";
}

void Employee::printInfo()
{
    cout << setw(14) << left << "Имя: " << first_name << endl;
    cout << setw(18) << left << "Фамилия: " << last_name << endl;
    cout << setw(14) << left << "пол: " << getGender() << endl;
    cout << setw(18) << left << "возраст: " << age << endl;
    cout << "категория: " << category << endl;
    cout << "--------------------" << endl;
}

int main()
{
    Gender male = Gender::male;
    Gender female = Gender::female;

    vector<Employee> umichWorks;
    Employee User0("Александр", "Пушкин", male, 37, 10);
    Employee User1("Михаил", "Лермонтов", male, 26, 15);
    Employee User2("Екатерина", "Вторая", female, 67, 55);
    umichWorks.push_back(User0);
    umichWorks.push_back(User1);
    umichWorks.push_back(User2);

    cout << endl << "Welcome to umichWorks! Here are our loyal employees: " << endl;
    for( auto employee: umichWorks)
    {
        employee.printInfo();
    }

    umichWorks[0].promote();
    umichWorks[1].demote();
    umichWorks[2].demote();
    cout << "Here is the new info for the employees of umichWorks: " << endl;
    for( auto employee: umichWorks)
    {
        employee.printInfo();
    }
    return 0;
}
