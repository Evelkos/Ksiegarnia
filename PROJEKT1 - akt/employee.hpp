#ifndef employee_h
#define employee_h
#include "debug_head.hpp"
#include "book.hpp"  //moze cos sie da z tym zrobic?

/*
  dodac:
  1. sprawdzanie ilosci klientow
  2. analiza przychodu (jakie ksiazki sprzedaja sie najlepiej) - ogarnac enum
  3. ile typow ksiazek jest ogolem w ksiegarni - ogarnac pola statyczne dla klasy ksiazka
  4. dopracowac stanowiska pracownikow - jak sie da: enum
  5. moze uzaleznic analize od daty - sprzedarz, dostawy, itd. majace miejsce w czasie
*/

class Employee
{
  std::string name;
  std::string surname;
  int age;
  float salary;
  Employee *next;

  public:

  std::string get_name() {return name;}
  std::string get_surname() {return surname;}
  int get_age() {return age;}
  float get_salary() {return salary;}
  Employee* get_next() {return next;}

  void set_name(std::string n) {name = n;}
  void set_surname(std::string s) {surname = s;}
  void set_age(int a) {age = a;}
  void set_salary(float sal) {salary = sal;}
  void set_next(Employee *ne) {next = ne;}

  Employee(std::string = "BRAK", std::string = "BRAK", int = 30, float = 0);
  ~Employee();

//  void print();
  friend std::ostream& operator<< (std::ostream &os, Employee *e) {os << e->get_name()<<" "<<e->get_surname()
                <<" "<<e->get_age()<<" "<<e->get_salary()<<"zl"<<std::endl; return os;}
};

int show_employee_list(Employee *first);
Employee* delete_employee(Employee *first, int n);
Employee* new_employee();
Employee* add_to_list_employee(Employee *lastEmployee);

#endif
