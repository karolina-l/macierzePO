#ifndef UKLADROWNANLINIOWYCH_HH
#define UKLADROWNANLINIOWYCH_HH

#include <iostream>
#include"Macierz.hh"
#include "Wektor.hh"
#include "rozmiar.h"
using namespace std;


/*
  Klasa UkladRownanL:
   zawiera:
   - pole M - MacierzKw
   - pole W - Wektor
   - konstruktory elementow klasy UkladRownanL
   - przeciazenia strumieni dla klasy UkladRownanL
   - metody zwroc_macierz(), zmien_macierz(),
     zwroc_wektor(), zmien_wektor(), oblicz(), blad()

 */
class UkladRownanL    {

  MacierzKw M;
  Wektor W;

  public:

  /*
    Komstruktor klasy UkladRownanL;
    tworzy MacierzKw, której elementy
    sa rowne 0.0 i Wektor w postaci:
    wek={0.0, 0.0, 0.0}
  */
  UkladRownanL();
  /*
    Komstruktor klasy UkladRownanL;
    tworzy MacierzKw i Wektor, których elementy
    sa rowne zadanej macierzy i wektorowi
  */
  UkladRownanL(MacierzKw AA, Wektor BB);
  /*
    metoda zwroc_macierz zwraca macierz
    danego ukladu rownan
  */
  const MacierzKw zwroc_macierz() const;
  /*
    metoda zmien_macierz zmienia macierz
    danego ukladu rownan na podana do metody
  */
  void zmien_macierz(MacierzKw mat);
  /*
    metoda zwroc_wektor zwraca wektor
    danego ukladu rownan
  */
  const  Wektor zwroc_wektor() const;
  /*
    metoda zmien_wektor zmienia wektor
    danego ukladu rownan na podany do metody
  */
  void zmien_wektor(Wektor wek);
  /*
    metoda oblicz rozwiazuje dany uklad rownan
    zwraca wektor wynikow
  */
  Wektor oblicz();
  /*
    metoda blad oblicza blad wyniku w stosunku
    do wektora ukladu rownan
    zwraca liczbe double rowna dlugosci wektora bledu
  */
  double blad(Wektor wyn);
};


/*
  Przeciazenie operatora ">>"
  dla klasy UkladRownanL
  zwraca strumien przesuniecia bitowego w prawo
*/
istream & operator >> (istream &str, UkladRownanL &Ukl);

/*
  Przeciazenie operatora "<<"
  dla klasy UkladRownanL
  zwraca strumien przesuniecia bitowego w prawo
*/
ostream & operator << (ostream  &str, const UkladRownanL &Ukl );


#endif
