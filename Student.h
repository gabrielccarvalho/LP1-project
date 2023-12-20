#include <string>
#include <sstream>
#include <vector>
#include <memory>
#include <cstring>
#include <algorithm>

class Person {
public:
  Person(std::string name, int age) : name(name) {};

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

  static bool doesStudentExist(const std::vector<std::unique_ptr<Student>>& studentList, int regID) {
    for (const auto& student : studentList) {
      if (student->getRegistrationID() == regID) {
        return true;
      }
    }
    return false;
  }

  ~Student() {
    classes.clear();
  }

private:
  int registrationID;
  std::vector<std::string> classes;
};

std::string Student::getName() {
  return Person::getName();
}

int Student::getAge() {
  return Person::getAge();
}

int Student::getRegistrationID() {
  return this->registrationID;
}

std::vector<std::string> Student::getClasses() {
  return this->classes;
}

void Student::addClass(std::string className) {
  this->classes.push_back(className);
}

void Student::editClass(std::string oldClassName, std::string newClassName) {
  std::replace(this->classes.begin(), this->classes.end(), oldClassName, newClassName);
}

void Student::removeClass(std::string className) {
  this->classes.erase(std::remove(this->classes.begin(), this->classes.end(), className), this->classes.end());
}
