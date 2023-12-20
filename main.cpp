#include<iostream>
#include<fstream>
#include<vector>
#include<memory>
#include "Student.h"
#include<sstream>
#include<algorithm>

// Function to find a student by registration ID
int findStudent(std::vector<std::unique_ptr<Student>>& studentList, int regID) {
  for(size_t i = 0; i < studentList.size(); i++) {
    if(studentList[i]->getRegistrationID() == regID)
      return i;
    }
  return -1;
}

// Function to add a student with classes
void addStudent(std::vector<std::unique_ptr<Student>>& studentList, std::string name, int age, int regID, std::vector<std::string> classes) {
  std::unique_ptr<Student> student = std::make_unique<Student>(name, age, regID);
  for(auto& className : classes) {
    student->addClass(className);
  }
  studentList.push_back(std::move(student));
}

// Function to remove a student
void removeStudent(std::vector<std::unique_ptr<Student>>& studentList, int regID) {
  for(auto it = studentList.begin(); it != studentList.end(); ++it) {
    if((*it)->getRegistrationID() == regID) {
      studentList.erase(it);
      break;  // Once the student is found and erased, terminate the loop
    }
  }
}

void addClass(std::vector<std::unique_ptr<Student>>& studentList, int regID, std::vector<std::string> newClasses) {
  int index = findStudent(studentList, regID);
  if(index != -1) {
    studentList[index]->getClasses().clear();  // Incorrect - doesn't affect the actual classes
    
    // Clear the actual classes and add new classes
    studentList[index]->removeClass(""); // Clear all existing classes
    
    for(auto& className : newClasses) {
      studentList[index]->addClass(className);
    }
  }
}

void displayInfo() {
std::vector<std::unique_ptr<Student>> studentList;

  // Load File
  std::string line;
  std::ifstream readFile("studentData.txt");
  if (readFile.is_open()) {
    while (std::getline(readFile, line)) {
      std::istringstream ss(line);
      std::string name, className;
      int age, id;
      ss >> name >> age >> id;
      std::unique_ptr<Student> student = std::make_unique<Student>(name, age, id);
      while(ss >> className)
          student->addClass(className);
      studentList.push_back(std::move(student));
    }
    readFile.close();
  }
  else {
    std::cout << "Unable to open file";
  }

  for(size_t i = 0; i < studentList.size(); i++) {
    std::cout << "Nome: " << studentList[i]->getName() << ", Idade: " << studentList[i]->getAge() << ", Matricula: " << studentList[i]->getRegistrationID() << std::endl;
    std::cout << "Classes: ";
    for (const auto& className : studentList[i]->getClasses()) {
      std::cout << className << " ";
    }
    std::cout << std::endl;
  }
}

// Sobrecarga da função para exibir informações específicas
void displayInfo(bool showName, bool showAge, bool showID, bool showClasses) {
  std::vector<std::unique_ptr<Student>> studentList;

  // Load File
  std::string line;
  std::ifstream readFile("studentData.txt");
  if (readFile.is_open()) {
    while (std::getline(readFile, line)) {
      std::istringstream ss(line);
      std::string name, className;
      int age, id;
      ss >> name >> age >> id;
      std::unique_ptr<Student> student = std::make_unique<Student>(name, age, id);
      while(ss >> className)
          student->addClass(className);
      studentList.push_back(std::move(student));
    }
    readFile.close();
  }
  else {
    std::cout << "Unable to open file";
  }

  for(size_t i = 0; i < studentList.size(); i++) {
    if(showName)
      std::cout << "Nome: " << studentList[i]->getName() << std::endl;
    if(showAge)
      std::cout << "Idade: " << studentList[i]->getAge() << std::endl;
    if(showID)
      std::cout << "Matricula: " << studentList[i]->getRegistrationID() << std::endl;
    if(showClasses) {
      std::cout << "Classes: ";
      for (const auto& className : studentList[i]->getClasses()) {
        std::cout << className << " ";
      }
      std::cout << std::endl;
    }
  }
}

void studentExists(std::vector<std::unique_ptr<Student>>& studentList, int regID) {
  if(Student::doesStudentExist(studentList, regID)) {
    std::cout << "Student exists" << std::endl;
  } else {
    std::cout << "Student doesn't exist" << std::endl;
  }
}

// Main Function
int main() {
  std::vector<std::unique_ptr<Student>> studentList;

  // Load File
  std::string line;
  std::ifstream readFile("studentData.txt");
  if (readFile.is_open()) {
    while (std::getline(readFile, line)) {
      std::istringstream ss(line);
      std::string name, className;
      int age, id;
      ss >> name >> age >> id;
      std::unique_ptr<Student> student = std::make_unique<Student>(name, age, id);
      while(ss >> className)
          student->addClass(className);
      studentList.push_back(std::move(student));
    }
    readFile.close();
  }
  else {
    std::cout << "Unable to open file";
    return -1;
  }

  // Manipulate data
  // addClass(studentList, 2023001, {"IMD0030", "IMD0031"});
  displayInfo();
  // displayInfo(true, false, false, false);
  // studentExists(studentList, 2023001);
  // editAge(studentList, 2023001, "20");
  // addStudent(studentList, "John", 25, 2025001, {"IMD0030", "IMD0031"});
  // removeStudent(studentList, 2025001);
  
  // Update File
  std::ofstream writeFile("studentData.txt");
  if (writeFile.is_open()) {
    for(auto& student : studentList) {
      writeFile << student->getName() << " " << student->getAge() << " " << student->getRegistrationID();
      std::vector<std::string> classes = student->getClasses();
      for(auto& className : classes) {
        writeFile << " " << className;
      }
      writeFile << "\n";
    }
    writeFile.close();
  }
  else {
    std::cout << "Unable to open file";
    return -1;
  }

  return 0;
}
