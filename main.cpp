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
  addClass(studentList, 2023001, {"IMD0030", "IMD0031"});
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
