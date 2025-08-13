#include <iostream>
using namespace std;

class Person
{
public:
  string name;
  int age;
  Person(string n, int a)
  {
    name = n;
    age = a;
  }
  ~Person()
  {
    cout << "Person object destroyed\n";
  }
  void introduce()
  {
    cout << name << " " << age << endl;
  }
  void birthday()
  {
    age += 1;
    cout << "you just turned " << age << " " << endl;
  }
};

int main()
{
  Person p1("uday", 19);
  p1.introduce();
  p1.birthday();
}