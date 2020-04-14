#ifndef UKLADROWNANLINIOWYCH_HH
#define UKLADROWNANLINIOWYCH_HH

#include <iostream>
#include"Macierz.hh"
#include "Wektor.hh"
#include "rozmiar.h"
using namespace std;


/*
 *  Tutaj trzeba opisac klase. Jakie pojecie modeluje ta klasa
 *  i jakie ma glowne cechy.
 */
class UkladRownanL    {
  /*
   *  Tutaj trzeba wstawic definicje odpowiednich pol i metod prywatnych
   */
  MacierzKw M;
  Wektor W;

  public:
  /*
   *  Tutaj trzeba wstawic definicje odpowiednich metod publicznych
   */
  UkladRownanL();
  UkladRownanL(MacierzKw AA, Wektor BB);

  const MacierzKw zwroc_macierz() const;
  void zmien_macierz(MacierzKw mat);
  /*analogicznie dla wektora */

  const  Wektor zwroc_wektor() const;
  void zmien_wektor(Wektor wek);
  Wektor oblicz();
  double blad(Wektor wyn);
};


/*
 * To przeciazenie trzeba opisac. Co ono robi. Jaki format
 * danych akceptuje. Jakie jest znaczenie parametrow itd.
 * Szczegoly dotyczace zalecen realizacji opisow mozna
 * znalezc w pliku:
 *    ~bk/edu/kpo/zalecenia.txt
 */
istream & operator >> (istream &str, UkladRownanL &Ukl);

/*
 * To przeciazenie trzeba opisac. Co ono robi. Jaki format
 * danych akceptuje. Jakie jest znaczenie parametrow itd.
 * Szczegoly dotyczace zalecen realizacji opisow mozna
 * znalezc w pliku:
 *    ~bk/edu/kpo/zalecenia.txt
 */
ostream & operator << (ostream  &str, const UkladRownanL &Ukl );


#endif
