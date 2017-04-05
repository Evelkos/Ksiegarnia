#ifndef bookshop_h
#define bookshop_h

#include "debug_head.hpp"
#include "book.hpp"
#include "customer.hpp"
#include "employee.hpp"

using namespace std;
class Bookshop
{
  std::string name, city;
  float budget;
  Book *firstB;
  Employee *firstE, *lastE;
  Customer *firstC, *lastC;
  Bookshop *next;
  Book *order;
  int ordActive;

  protected:
  static int numBookshops;  //liczba ksiegarni ogolem

  public:
  Bookshop(std::string n, std::string c, float b, Bookshop **first, Bookshop **last);
  ~Bookshop();

  static int get_numBookshops(){return numBookshops;}
  std::string get_name() {return name;}
  std::string get_city() {return city;}
  float get_budget() {return budget;}
  Book* get_firstB() {return firstB;}
  Employee* get_firstE() {return firstE;}
  Employee* get_lastE() {return lastE;}
  Customer* get_firstC() {return firstC;}
  Customer* get_lastC() {return lastC;}
  Bookshop* get_next() {return next;}
  Book* get_order() {return order;}
  int get_ordActive() {return ordActive;}

  void set_name(std::string n) {name = n;}
  void set_city(std::string c) {city = c;}
  void set_budget(float b) {budget = b;}
  void set_firstB(Book *fB) {firstB = fB;}
  void set_firstE(Employee *fE) {firstE = fE;}
  void set_lastE(Employee *lE) {lastE = lE;}
  void set_firstC(Customer *fC) {firstC = fC;}
  void set_lastC(Customer *lC) {lastC = lC;}
  void set_next(Bookshop *n) {next = n;}
  void set_order(Book* o) {order = o;}
  void set_ordActive(int oA) {ordActive = oA;}

  int show_book_list(int perspective);
  void book_list(Book *nBook);
  void add_to_list_book(std::string t, std::string a, std::string p, float pr, int nO);
  void delete_book(int n);
  Book* find_book(std::string t, std::string a, std::string p);

  int show_customer_list();
  void add_to_list_customer();
  void delete_customer(int n);

  int show_employee_list();
  void delete_employee(int n);
  void add_to_list_employee();

  friend std::ostream& operator<< (std::ostream &os, Bookshop *b) {os << b->get_name();
  os << " " << b->get_city() <<" " << b->get_budget() << std::endl; return os;}

  void operator +(float p){this->budget+=p;}

  void  operator -(float n) { this->budget-=n;}

};

#endif
