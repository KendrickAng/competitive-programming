#include <iostream>
#include <string>

using namespace std;

class Person {
public:
  string name;
  Person(string name): name(name) {}
};

class Gamer: public Person {
public:
  int age;
  Gamer(string name, int age): Person(name), age(age) {}
};

int main() {
  Gamer joe("mama", 2);
  Person p = joe;
  cout << p.name << endl;
}