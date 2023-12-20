#include "Student.h"
#include <algorithm>

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
