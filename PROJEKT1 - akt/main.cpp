#include"functions.hpp"

int main()
{
  Bookshop *firstBookshop, *lastBookshop;
  firstBookshop = lastBookshop = NULL;

  cout<<"KSIEGARNIA"<<endl;
  main_menu(&firstBookshop, &lastBookshop);

  if(firstBookshop != NULL)
  {
    while(firstBookshop != NULL)
    {
      lastBookshop = firstBookshop;
      firstBookshop = firstBookshop->get_next();
      delete(lastBookshop);
    }
  }
  return 0;
}
