#include <iostream>
#include "Wektor.hh"
#include "Macierz.hh"
#include "rozmiar.h"
#include "UkladRownanLiniowych.hh"



using namespace std;

/*
 * Tu definiujemy pozostale funkcje.
 * Lepiej jednak stworzyc dodatkowy modul
 * i tam je umiescic. Ten przyklad pokazuje
 * jedynie absolutne minimum.
 */


int main()
{
  UkladRownanL U;
  cout<< "Podaj uklad: ";
  cin>> U;
  cout<<endl<<U;



  return 0;
}
