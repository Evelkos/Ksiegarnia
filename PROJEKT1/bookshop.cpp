#include "bookshop.hpp"

Bookshop::Bookshop(std::string n, std::string c, float b, Bookshop **first, Bookshop **last): name(n), city(c), budget(b), firstB(NULL), firstE(NULL), lastE(NULL), firstC(NULL), next(NULL), order(NULL), ordActive(0)
{
//    CL_SR
  D(std::cout <<"Tworze ksigarnie"<<std::endl;)
  Bookshop *previous;
  previous = *last;
  *last = this;

  if(previous != NULL)
    previous->set_next(*last);

  if(*first == NULL)
    *first = *last;


}

Bookshop::~Bookshop()
{

  while(this->get_firstE() != NULL)
    this->delete_employee(1);
  while(this->get_firstC() != NULL)
    this->delete_customer(1);
  while(this->get_firstB() != NULL)
    this->delete_book(1);

    D(std::cout <<"Niszcze ksigarnie"<<std::endl;)
}

//wyswietla liste ksiazek, zwraca liczbe ksiazek "dostepnych" w zaleznosci od tego kto widzi liste
int Bookshop::show_book_list(int perspective)
{
  int i = 0;
  Book *current;
  current = firstB;

  if(perspective == 1 && current == NULL)  //klient
    std::cout<<std::endl<<"-Dziwne... w ksiegarni nie ma zadnych ksiazek?"<<std::endl<<std::endl;
    //UWAGA: jesli do ksiegarni przypisane sa ksiazki, ale ich ilosc jest rowna 0, to klientowi nie wyswietli sie zaden komunikat
  else if(perspective == 0 && current == NULL)  //pracownik
    std::cout<<std::endl<<"W naszej ksiegarni nie ma jeszcze zadnych ksiazek. Najwyzszy czas zlozyc zamowienie."<<std::endl<<std::endl;
  else
  {
    std::cout<<std::endl;
    if(perspective == 1){  //klient
      do
      {
        if(current->get_number() != 0)
        {
          std::cout<<++i<<". ";
          std::cout <<current;
        }
        current = current->get_next();
      }while(current != firstB);
    }

    else if(perspective == 0){  //pracownik
      do
      {
        std::cout<<++i<<". ";
        std::cout <<current;
        current = current->get_next();
      }while(current != firstB);
    }

    else
      std::cout<<"BLAD: show_book_list nie ma takiej perspektywy."<<std::endl;
  }
  return i;
}

//dodaje nowa ksiazke do listy
void Bookshop::add_to_list_book(std::string t, std::string a, std::string p, float pr, int nO)
{
  int y, pag;

  srand(time(NULL));
  y = rand()%50+1967;
  pag = rand()%400+154;

  Book *nBook = new Book(t, pr, a, p, y, pag, 0, nO);
  return (book_list(nBook));
}

//usuwa ksiazke o zadanym numerze
void Bookshop::delete_book(int n)
{
  Book *current;
  current = firstB;

  if(firstB == firstB->get_next())
    firstB = NULL;

  else if(n == 1)
  {
    (firstB->get_previous())->set_next(firstB->get_next());
    (firstB->get_next())->set_previous(firstB->get_previous());
    firstB = firstB->get_next();
  }

  else
  {
    for(int i = 1 ; i < n ; i++)
      current = current->get_next();

    (current->get_previous())->set_next(current->get_next());
    (current->get_next())->set_previous(current->get_previous());
  }

  delete(current);
}

//wyszukuje pozycje na liscie dla nowej ksiazki - tytuly maja byc ustawione rosnaco - zwraca wskaznik na pierwszy element listy ksiazek
void Bookshop::book_list(Book *nBook)
{
  int i = 0; //flaga
  if(firstB == NULL)
  {
    firstB = nBook;
    nBook->set_next(nBook);
    nBook->set_previous(nBook);
  }
  else{
    Book *current;
    current = firstB;

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
    }while(current != firstB);

    if(nBook->get_title() < firstB->get_title())  //nowa ksiazka staje sie pierwsza - ma najmlodszy tytul
      firstB = nBook;

    else if(i == 0)  //tytul nowej ksiazki jest najstarszy - ksiazka dodana na "koniec" listy
    {
      (firstB->get_previous())->set_next(nBook);
      nBook->set_previous(firstB->get_previous());
      firstB->set_previous(nBook);
      nBook->set_next(firstB);
    }
  }
}

//wyszukuje z listy ksiazke o zadanym tytule, autorze, wydawnictwie, kategorii i zwraca na nia wskaznik
Book* Bookshop::find_book(std::string t, std::string a, std::string p)
{
  int i = 0;
  Book *current = NULL;

  if(firstB != NULL)
  {
    current = firstB;
    do
    {
      if(t == current->get_title() && a == current->get_author() && p == current->get_publisher())
      {
        i++;
        break;
      }
      current = current->get_next();
    }while(current != firstB);

    if(i == 0)
      current = NULL;
  }

  return current;
}

//wyswietla liste klientow zwraca liczbe klientow ksiegarni
int Bookshop::show_customer_list()
{
  int i = 1;
  Customer *current;

  if(firstC == NULL){
    std::cout<<std::endl<<"W tej ksiegarni nie ma jeszcze zadnych klientow."<<std::endl;
    i = 1;
  }

  else
  {
  current = firstC;
  std::cout<<std::endl<<"Lista klientow:"<<std::endl;
    while(current != NULL){
      std::cout<<i++<<". ";
      cout<<current; //tu poczatkowo bylo print
      current = current->get_next();
    }
  }
  return --i;
}

//tworzy nowego klienta na podstawie wprowadzonych danych, umieszcza go na koncu listy klientow, zwraca nan wskaznik
void Bookshop::add_to_list_customer()
{
  Customer *nCustomer;
  std::string n, s;
  float m;

  std::cout<<"Imie: ";
  std::cin>>n;
  std::cout<<"Nazwisko: ";
  std::cin>>s;
  std::cout<<"Pieniadze: ";
  std::cin>>m;

  nCustomer = new Customer(n, s, m);
  if(lastC != NULL)
    lastC->set_next(nCustomer);
  lastC = nCustomer;

  if(firstC == NULL)
    firstC = nCustomer;
}

//usuwa klienta, ktorego numer zostal dany
void Bookshop::delete_customer(int n)
{
  Customer *current, *previous = NULL;
  current = firstC;
  if(n == 1)
    firstC = firstC->get_next();

  else
  {
    for(int i = 1 ; i < n ; i++)
    {
      previous = current;
      current = current->get_next();
    }
    previous->set_next(current->get_next());
  }

  if(lastC == current)
    lastC = previous;

  delete(current);
}

//wyswietla liste pracownikow, zwraca ich liczbe
int Bookshop::show_employee_list()
{
  Employee *current;
  int i = 0;

  if(firstE == NULL)
    std::cout<<std::endl<<"W tej ksiegarni nie ma jeszcze zadnych pracownikow.";

  else
  {
  std::cout<<std::endl<<"Lista pracownikow:"<<std::endl;
  current = firstE;

    while(current != NULL){
      std::cout<<++i<<". ";
      cout<<current;
      current = current->get_next();
    }
  }
  std::cout<<std::endl;
  return i;
}

//usuwa pracownika, ktorego numer zostal dany
void Bookshop::delete_employee(int n)
{
  Employee *current, *previous = NULL;
  current = firstE;
  if(n == 1)
    firstE = firstE->get_next();

  else
  {
    for(int i = 1 ; i < n ; i++)
    {
      previous = current;
      current = current->get_next();
    }
    previous->set_next(current->get_next());
  }

  if(lastE == current)
    lastE = previous;

  delete(current);
}

//tworzy nowego pracownika na podstawie wybranych przez uzytkonika danych
//(zakladamy, ze do wlasciciela zglaszaja sie osoby chetne do pracy - mozemy wybrac tylko jedna z nich)
void Bookshop::add_to_list_employee()
{
  Employee *nEmployee;
  std::string cName[5], cSurname[5];
  int cAge[5];
  int n, choice;
  float sal;

  srand(time(NULL));
  std::string names[] = {"Anna", "Magdalena", "Monika", "Ewelina", "Sylwia", "Pawel", "Lukasz", "Maciej", "Zbigniew", "Andrzej"};
  std::string surnames[] = {"Dlugopis", "Pazurek", "Olowczyk", "Gicka", "Kluczyn", "Liczydlo", "Kucharczyk", "Truskawka", "Miodzio", "Czapla"};

  std::cout<<std::endl<<"LISTA KANDYDATOW:"<<std::endl;
  for(int i = 0 ; i < 5 ; i++)
  {
    n = rand()%10;
    cName[i] = names[n];
    n = rand()%10;
    cSurname[i] = surnames[n];
    n = rand()%30+20;
    cAge[i] = n;
    std::cout<<i+1<<". "<<cName[i]<<"  "<<cSurname[i]<<"  "<<cAge[i]<<std::endl;
  }

  std::cout<<std::endl<<"Wybierz numer kandydata, ktorego chcesz zatrudnic."<<std::endl;

  std::cin>>choice;
  if(--choice >= 0 && choice <= 4)
  {
    std::cout<<"Wpisz pensje pracownika: ";
    std::cin>>sal;

    nEmployee = new Employee(cName[choice], cSurname[choice], cAge[choice], sal);

    if(lastE != NULL)
      lastE->set_next(nEmployee);
    lastE = nEmployee;
    if(firstE == NULL)
      firstE = lastE;
  }
}
