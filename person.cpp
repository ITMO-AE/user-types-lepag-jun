#include <iostream>
#include <person.h>

using namespace std;

int main()
{
//    Person person;

//    person.ChangeFirstName(1965, "Polina");
//    person.ChangeLastName(1967, "Sergeeva");
//    for (int year : {1900, 1965, 1990}) {
//       cout << person.GetFullName(year) << endl;
//    }
//    person.ChangeFirstName(1970, "Appolinaria");
//    for (int year : {1969, 1970}) {
//       cout << person.GetFullName(year) << endl;
//    }
//    person.ChangeLastName(1968, "Volkova");
//    for (int year : {1969, 1970}) {
//       cout << person.GetFullName(year) << endl;
//    }


      Person person("Polina", "Sergeeva", 1960);
      for (int year : {1959, 1960}) {
        cout << person.GetFullNameWithHistory(year) << endl;
      }

      person.ChangeFirstName(1965, "Appolinaria");
      person.ChangeLastName(1967, "Ivanova");
      for (int year : {1965, 1967}) {
        cout << person.GetFullNameWithHistory(year) << endl;
      }

    return 0;
}
