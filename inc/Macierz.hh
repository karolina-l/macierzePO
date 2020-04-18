#ifndef MACIERZ_HH
#define MACIERZ_HH

#include "rozmiar.h"
#include "Wektor.hh"
#include <iostream>

using namespace std;

/*
  Klasa MacierzKw:
   zawiera:
   - pole mtx - tablica wektorow,
     rozmiar zadany zewnetrznie
   - konstruktory elementow klasy MacierzKw
   - przeciazenia operatorow klasy MacierzKw
   - metode zwroc_kolumne(), zmien_kolumne(),
     odwroc(), wyznacznik(), transponuj()
*/

//reprezentacja wierszowa
class MacierzKw  {

  Wektor mtx[ROZMIAR];
  public:

  /*
    Komstruktor klasy MacierzKw;
    tworzy MacierzKw, której elementy
    sa rowne 0.0
  */
  MacierzKw();
  /*
    Konstruktor klasy MacierzKw;
    tworzy MacierzKw, ktorego elementy maja wartosc
    rowna elementom danej tablicy tab
  */
  MacierzKw(const Wektor  tab[ROZMIAR]);


  /*
    Przeciazenie operatora "[]"
    zwraca indeks obecnego elementu macierzy
    lub zwraca komunikat: "indeks poza zakresem"
    i konczy dzialanie programu, by uchronic
    przed naruszeniem pamieci
  */
  const Wektor & operator[] (int index) const;
  /*
    Przeciazenie operatora "[]"
    zwraca indeks obecnego elementu macierzy
    lub zwraca komunikat: "indeks poza zakresem"
    i konczy dzialanie programu, by uchronic
    przed naruszeniem pamieci
  */
  Wektor & operator[] (int index);
  /*
    Przeciazenie operatora "+"
    argumenty to 2 macierze
    zwraca nową macierz, ktorej elementy sa
    suma poszczegolnych elementow macierzy skladowych
  */
  const MacierzKw  operator + (const MacierzKw & M);
  /*
    Przeciazenie operatora "-"
    argumenty to 2 macierze
    zwraca nową macierz, ktorej elementy sa
    roznica poszczegolnych elementow macierzy skladowych
  */
  const MacierzKw  operator - (const MacierzKw & M);
  /*
    Przeciazenie operatora "*"
    argumenty to 2 macierze
    zwraca nową macierz, ktorej elementy sa
    iloczynem poszczegolnych elementow macierzy skladowych
  */
  const MacierzKw  operator * (const MacierzKw & M);
  /*
    Przeciazenie operatora "*"
    argumenty to macierz i wektor
    zwraca nowy wektor, ktorego elementy sa
    iloczynem poszczegolnych elementow wektora i macierzy skladowej
  */
  const Wektor operator * (const Wektor & W);
  /*
    Przeciazenie operatora "*"
    argumenty to macierz i double
    zwraca nowa macierz, ktorej elementy sa
    iloczynem poszczegolnych elementow macierzy skladowej
    i liczby l
  */
  const MacierzKw  operator * (double l);
  /*
    metoda odwroc zwraca nowa macierz
    odwrotna do danej
  */
  MacierzKw  odwroc() const;
  /*
    metoda zwroc_kolumne zwraca wektor,
    rowny i-tej kolumnie macierzy
    na podstawie przekazanego nr indeksu
  */
  Wektor  zwroc_kolumne(int ind); //dla interpretacji wierszowej
  /*
    metoda zmien_kolumne
    zmienia i-ta kolumne macierzy na dany wektor
    na podstawie przekazanego nr indeksu
  */
  void zmien_kolumne(int ind, Wektor W); //dla interpretacji wierszowej
  /*
  metoda wyznacznik zwraca liczbe double,
  ktora jest wyznacznikiem danej miacierzy
  */
  double wyznacznik();
  /*
    metoda transponuj zwraca nowa macierz
    ktorej kolumny zamienione zostaly z wierszami
    wzgledem danej macierzy
  */
  MacierzKw transponuj() const;
};


/*
  Przeciazenie operatora ">>"
  dla klasy MacierzKw
  zwraca strumien przesuniecia bitowego w prawo
*/
istream & operator >> (istream &str, MacierzKw &M);

/*
  Przeciazenie operatora "<<"
  dla klasy MacierzKw
  zwraca strumien przesuniecia bitowego w prawo
*/
ostream & operator << (ostream &str, const MacierzKw &M);

#endif
