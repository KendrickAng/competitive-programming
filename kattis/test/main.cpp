  #include <iostream>
  #include <string>
  #include <unordered_set>

  using namespace std;

  class Person {
  public:
    string name;
    Person(string name): name(name) {}

    bool operator==(const Person &other) const {
      return name == other.name;
    }
  };

  class Gamer: public Person {
  public:
    int age;
    Gamer(string name, int age): Person(name), age(age) {}

    bool operator==(const Gamer &other) const {
      return other.age == age && (static_cast<Person>(other) == static_cast<Person>(*this));
    }
  };

  // custom specialisation of std::hash inject into standard namespace
  template<>
  struct std::hash<Gamer> {
    std::size_t operator()(Gamer const& g) const noexcept {
      return std::hash<int>()(g.age) ^ std::hash<std::string>()(g.name);
    }
  };

  int main() {
    Gamer joe("mama", 2);
    Gamer joeDup("mama", 2);
    Gamer mama("joe", 3);
    unordered_set<Gamer> gamers;
    gamers.insert(joe);
    gamers.insert(joeDup);
    gamers.insert(mama);
    cout << gamers.size() << endl; // 2
  }