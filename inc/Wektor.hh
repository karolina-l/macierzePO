#ifndef WEKTOR_HH
#define WEKTOR_HH


#include "rozmiar.h"
#include <iostream>

using namespace std;

/*
 Klasa Wektor:
  zawiera:
 - pole wek - tablice statyczna doubli,
   rozmiar zadany zewnetrznie
 - konstruktory elementow klasy Wektor
 - przeciazenia operatorow matematycznych
 - metode dlugosc() zwracajaca modul z wektora

 */
class Wektor {

   double wek[ROZMIAR]; // tablica statyczna


  public:
  /*
    Konstruktor klasy Wektor;
    tworzy Wektor w postaci: wek={0.0, 0.0, 0.0}
  */
   Wektor();

   /*
     Konstruktor klasy Wektor;
     tworzy Wektor, ktorego elementy maja wartosc
     rowna elementom danej tablicy tablica
   */
   Wektor(double tablica[ROZMIAR]);


   /*
     Przeciazenie operatora "[]"
     zwraca indeks obecnego elementu wektora
     lub zwraca komunikat: "indeks poza zakresem"
     i konczy dzialanie programu, by uchronic
     przed naruszeniem pamieci
   */
   const double & operator[] (int index) const;
   /*
     Przeciazenie operatora "[]"
     zwraca indeks obecnego elementu wektora
     lub zwraca komunikat: "indeks poza zakresem"
     i konczy dzialanie programu, by uchronic
     przed naruszeniem pamieci
   */
   double & operator[] (int index);
   /*
     Przeciazenie operatora "+"
     argumenty to 2 wektory
     zwraca nowy wektor, ktorego elementy sa
     suma poszczegolnych elementow wektorow skladowych
   */
   Wektor  operator + (const Wektor & W) const;
   /*
     Przeciazenie operatora "+="
     argumenty to 2 wektory
     zwraca wskaznik na zmieniony wektor podstawowy,
     ktorego elementy sa suma poszczegolnych elementow
     wektorow skladowych
   */
   Wektor  operator += (const Wektor & W);
   /*
   Przeciazenie operatora "-"
   argumenty to dwa wektory
   zwraca nowy wektor, ktorego elementy sa
   roznica poszczegolnych elementow wektorow skladowych
   */
   Wektor  operator - (const Wektor & W) const;
   /*
   Przeciazenie operatora "*"
   argumenty to dwa wektory
   zwraca wynik(double), ktory jest suma wymnozonych
    poszczegolnych elementow wektorow skladowych
   */
   double operator * (const Wektor & W) const;
   /*
   Przeciazenie operatora "*"
   argumenty to wektor i double
   zwraca nowy wektor, ktorego elementy sa
   iloczynem poszczegolnych elementow wektora skladowego
   i danej liczby double
   */
   Wektor operator * (double l) const;
   /*
   Przeciazenie operatora "/"
   argumenty to wektor i double
   zwraca nowy wektor, ktorego elementy sa
   ilorazem poszczegolnych elementow wektora skladowego
   i danej liczby double
   */
   Wektor  operator / (double l) const;
   /*
   Przeciazenie operatora "=="
   zwraca true jesli roznica wartosci bezwzglednych danych
   wektorow jest mniejsza niz epsilon
   zwraca true jesli roznica wartosci bezwzglednych danych
   wektorow jest wieksza niz epsilon
   */
   bool operator == (const Wektor & W) const;
   /*
   Przeciazenie operatora "!="
   zwraca true jesli roznica wartosci bezwzglednych danych
   wektorow jest wieksza niz epsilon
   zwraca true jesli roznica wartosci bezwzglednych danych
   wektorow jest mniejsza niz epsilon
   */
   bool operator != (const Wektor & W) const;
   /*
   metoda dlugosc zwraca liczbe double
   rowna modulowi danego wektora
   */
   double dlugosc() const; //modul
};

/*
  Przeciazenie operatora ">>"
  dla klasy Wektor
  zwraca strumien przesuniecia bitowego w prawo
*/
istream & operator >> (istream & str, Wektor & W);

/*
  Przeciazenie operatora "<<"
  dla klasy Wektor
  zwraca strumien przesuniecia bitowego w prawo
*/
ostream & operator << (ostream & str, const Wektor & W);


#endif
