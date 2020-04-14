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
  //UkladRownanL U;
  Wektor w;
  double blad;
  //MacierzKw m;
  UkladRownanL(U);
  cout<< "Podaj uklad: ";
  cin>> U;
  //cout<<"podaj wektor: ";
  //cin>>w;
  //cout<<"podaj Macierz: ";
  //cin>>m;
//  U=UkladRownanL(m,w);

  cout<<endl<<U<<endl;
  w=U.oblicz();

  cout<<w<<endl;
  blad=U.blad(w);
  cout<<blad;
  //cout<<U.zwroc_wektor()<<endl;
  //cout<<U.zwroc_macierz();



  return 0;
}
