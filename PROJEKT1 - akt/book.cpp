#include"book.hpp"

Book::Book(std::string t, float pr, std::string a, std::string p, int y, int pag, int n, int nO): title(t), author(a), publisher(p), year(y), pages(pag), number(n), nOrd(nO)
{
  price = pr;
  next = NULL;
  previous = NULL;
  D(std::cout<<"Utworzono nowa ksiazke"<<std::endl;)
}

Book::~Book()
{
  if(previous != NULL)
  {
    (*next).set_previous(previous);
    (*previous).set_next(next);
  }
  D(std::cout<<"Usuwamy ksiazke!"<<std::endl;)
}
