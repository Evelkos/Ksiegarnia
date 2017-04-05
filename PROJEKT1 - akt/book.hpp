#ifndef book_h
#define book_h

#include "debug_head.hpp"
#include<iostream>
#include<time.h>
#include<cstdlib>
#include<string.h>

class Book
{
  std::string title, author, publisher;
  float price;
  int year, pages, number, nOrd; //nOrd - ilosc zamowionych egzemplarzy
  Book *next, *previous;

  public:

  Book(std::string = "BRAK", float = 9.99, std::string = "BRAK", std::string = "BRAK", int = 2000, int = 100, int = 1, int = 0);
  ~Book();

  std::string get_title() {return title;}
  std::string get_author() {return author;}
  std::string get_publisher() {return publisher;}
  float get_price() {return price;}
  int get_year() {return year;}
  int get_pages() {return pages;}
  int get_number() {return number;}
  int get_nOrd() {return nOrd;}
  Book* get_next() {return next;}
  Book* get_previous() {return previous;}

  void set_title(std::string t) {title = t;}
  void set_author(std::string a) {author = a;}
  void set_publisher(std::string p) {publisher = p;}
  void set_price(float pr) {price = pr;}
  void set_year(int y) {year = y;}
  void set_pages(int pag) {pages = pag;}
  void set_number(int n) {number = n;}
  void set_nOrd(int nO) {nOrd = nO;}
  void set_next(Book *n) {next = n;}
  void set_previous(Book *p) {previous = p;}

  friend std::ostream& operator<< (std::ostream &os, Book *b) {os <<b->title<<"  "<<b->author<<"  "<<b->publisher;
  os <<"  "<<b->price<<"  "<<b->year<<"  "<<b->pages<<"  "<<b->number<<std::endl; return os;}

};

#endif
