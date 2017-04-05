#ifndef customer_h
#define customer_h

#include"book.hpp"
#include "debug_head.hpp"

//klient sklada zamowienie na konkretna ksiazke
class Customer
{
  std::string name;
  std::string surname;
  float money;
  Book *collection;
  Customer *next;

  public:

  Customer(std::string = "BRAK", std::string = "BRAK", float = 0);
  ~Customer();

  std::string get_name() {return name;}
  std::string get_surname() {return surname;}
  float get_money() {return money;}
  Book* get_collection() {return collection;}
  Customer* get_next() {return next;}

  void set_name(std::string n) {name = n;}
  void set_surname(std::string s) {surname = s;}
  void set_money(float m) {money = m;}
  void set_collection(Book *c) {collection = c;}
  void set_next(Customer* n) {next = n;}

  void add_to_collection(std::string t, std::string a, std::string p, int nO);
  void collection_list(Book *nBook);
  void operator +=(float m) {this->set_money(this->get_money() + m);}
  void show_collection();

  friend std::ostream& operator<< (std::ostream &os, Customer *c) {os << c->get_name()<<" "<<c->get_surname() <<" "<<c->get_money()<<std::endl; return os;}
};

#endif
