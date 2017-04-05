#include"employee.hpp"

Employee::Employee(std::string n, std::string s, int a, float sal): name(n), surname(s), age(a), salary(sal), next(NULL)
{
  D(std::cout<<"Zatrudniamy pracownika"<<std::endl;)
}

Employee::~Employee()
{
  D(std::cout<<"Zwalniamy pracownika."<<std::endl;)
}
