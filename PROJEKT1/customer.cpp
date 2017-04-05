#include "customer.hpp"

Customer::Customer(std::string n, std::string s, float m): name(n), surname(s), money(m), collection(NULL), next(NULL)
{
  D(std::cout<<"Tworzymy klienta"<<std::endl;)
}

Customer::~Customer()
{
  Book *current;
  if(collection != NULL)
  {
    current = collection;
    while(collection != NULL)
    {
      current = collection;
      collection = collection->get_next();
      if(current == collection)
        collection = NULL;
      delete(current);
    }
  }

  D(std::cout<<"Usuwamy kilenta"<<std::endl;)
}

//dodaje nowa ksiazke do listy
void Customer::add_to_collection(std::string t, std::string a, std::string p, int nO)
{
  int y, pag;

  srand(time(NULL));
  y = rand()%50+1967;
  pag = rand()%400+154;

  Book *nBook = new Book(t, 0, a, p, y, pag, 1, nO);
  return (collection_list(nBook));
}

//wyszukuje pozycje na liscie dla nowej ksiazki - tytuly maja byc ustawione rosnaco - zwraca wskaznik na pierwszy element listy ksiazek
void Customer::collection_list(Book *nBook)
{
  int i = 0; //flaga
  if(collection == NULL)
  {
    collection = nBook;
    nBook->set_next(nBook);
    nBook->set_previous(nBook);
  }
  else{
    Book *current;
    current = collection;

    do
    {
      if(current->get_title() > nBook->get_title()){  //ustawianie ksiazki na wlasciwym miejscu
        (current->get_previous())->set_next(nBook);
        nBook->set_previous(current->get_previous());
        current->set_previous(nBook);
        nBook->set_next(current);
        i++;
        break;
      }
      current = current->get_next();
    }while(current != collection);

    if(nBook->get_title() < collection->get_title())  //nowa ksiazka staje sie pierwsza - ma najmlodszy tytul
      collection = nBook;

    else if(i == 0)  //tytul nowej ksiazki jest najstarszy - ksiazka dodana na "koniec" listy
    {
      (collection->get_previous())->set_next(nBook);
      nBook->set_previous(collection->get_previous());
      collection->set_previous(nBook);
      nBook->set_next(collection);
    }
  }
}

void Customer::show_collection()
{
  Book *current;
  if(collection == NULL)
    std::cout<<"Nie mam jeszcze zadnych ksiazek. Najwyzszy czas kilka kupic!"<<std::endl;
  else
    {
      std::cout<<std::endl<<"KOLEKCJA:"<<std::endl;
      current = collection;
      do
      {
        std::cout<<current->get_title()<<" "<<current->get_author()<<" "<<current->get_publisher()<<std::endl;
        current = current->get_next();
      }while(current != collection);
    }
}
