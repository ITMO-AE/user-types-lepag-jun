#ifndef PERSON_H
#define PERSON_H

#include <vector>
#include <string>
#include <map>


using std::string;
using std::vector;

struct FullName
{
    string FirstName;
    string LastName;
};

class Person {
public:
    Person(const string& first_name, const string& last_name, int year)
    {
        YearFullName[year] = {first_name, last_name};
        birth_year = year;
        for(auto i : YearFullName)
        {
            if(i.first < year)
                YearFullName.erase(i.first);
        }
    }

    void ChangeFirstName(int year, const string& first_name)
    {
        YearFullName[year].FirstName = first_name;
    }

    void ChangeLastName(int year, const string& last_name)
    {
        YearFullName[year].LastName = last_name;
    }

    string GetFullName(int year) const
    {
        for(auto i : YearFullName)
        {
            if(year < i.first)
                return "Incognito";
            break;
        }
        string f_name;
        string l_name;
        for(auto i : YearFullName)
        {
            if(i.first <= year && i.second.FirstName != "")
                f_name = i.second.FirstName;
            if(i.first <= year && i.second.LastName != "")
                l_name = i.second.LastName;
        }
        if(f_name.empty())
            return l_name + " with unknown first name";
        else if(l_name.empty())
            return f_name + " with unknown last name";
        else
            return f_name + " " + l_name;
    }

    string GetFullNameWithHistory(int year) const
    {
        if (birth_year != 0 && year < birth_year)
            return "No person";
        for(auto i : YearFullName)
        {
            if(year < i.first)
                return "Incognito";
            break;
        }
        string f_name;
        string l_name;
        vector<string> firstname;
        vector<string> lastname;
        for(auto i : YearFullName)
        {
            if(i.first <= year && i.second.FirstName != "")
            {
                firstname.push_back(f_name);
                f_name = i.second.FirstName;
            }
            if(i.first <= year && i.second.LastName != "")
            {
                lastname.push_back(l_name);
                l_name = i.second.LastName;
            }
        }
        //
        string s_f_name;
        string s_l_name;
        if(firstname.size() > 1)
        {
            s_f_name += "(" + firstname[firstname.size() - 1] + ")";
        }
        if(lastname.size() > 1)
        {
            s_l_name += "(" + lastname[lastname.size() - 1] + ")";
        }
        if(f_name.empty())
            return l_name + s_l_name + " with unknown first name";
        else if(l_name.empty())
            return f_name + s_f_name + " with unknown last name";
        else
            return f_name + s_f_name + " " + l_name + s_l_name;
    }

private:
    std::map<int, FullName> YearFullName;
    int birth_year;
};

#endif // PERSON_H
