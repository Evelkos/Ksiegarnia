#include"functions.hpp"

int main()
{
  Bookshop *firstBookshop, *lastBookshop;
  firstBookshop = lastBookshop = NULL;

  cout<<"KSIEGARNIA"<<endl;
  main_menu(&firstBookshop, &lastBookshop);
  return 0;
}
