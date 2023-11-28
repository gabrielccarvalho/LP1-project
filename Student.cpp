#include "Student.h"
#include <algorithm>

Student::Student(std::string name, int age, int registrationID) 
  : name(name), age(age), registrationID(registrationID) {}

std::string Student::getName() {
  return this->name;
}

int Student::getAge() {
  return this->age;
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

void Student::removeClass(std::string className) {
  this->classes.erase(std::remove(this->classes.begin(), this->classes.end(), className), this->classes.end());
}
