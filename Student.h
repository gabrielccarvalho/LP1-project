#include <string>
#include <vector>

class Person {
public:
    Person(std::string name, int age) : name(name), age(age) {}

    std::string getName() const { return name; }
    int getAge() const { return age; }

protected:
    std::string name;
    int age;
};

class Student: public Person {
public:
  Student(std::string name, int age, int registrationID) : Person(name, age), registrationID(registrationID) {};

  std::string getName();
  int getAge();
  int getRegistrationID();
  std::vector<std::string> getClasses();
  void addClass(std::string className);
  void removeClass(std::string className);
  void editClass(std::string oldClassName, std::string newClassName);

private:
  std::string name;
  int age;
  int registrationID;
  std::vector<std::string> classes;
};
