#include <string>
#include <vector>

class Student {
public:
  Student(std::string name, int age, int registrationID);

  std::string getName();
  int getAge();
  int getRegistrationID();
  std::vector<std::string> getClasses();
  void addClass(std::string className);
  void removeClass(std::string className);

private:
  std::string name;
  int age;
  int registrationID;
  std::vector<std::string> classes;
};
