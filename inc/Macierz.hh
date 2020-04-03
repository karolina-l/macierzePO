#ifndef MACIERZ_HH
#define MACIERZ_HH

#include "rozmiar.h"
#include "Wektor.hh"
#include <iostream>

using namespace std;

/*
 *  Tutaj trzeba opisac klase. Jakie pojecie modeluje ta klasa
 *  i jakie ma glowne cechy.
 */
class MacierzKw {
  /*
   *  Tutaj trzeba wstawic definicje odpowiednich pol i metod prywatnych
   */
   Wektor tab[ROZMIAR]; //tablica wektorow
  public:
  /*
   *  Tutaj trzeba wstawic definicje odpowiednich metod publicznych
   */

   MacierzKw();
  //MacierzKw(const Wektor & tab[ROZMIAR]);
  MacierzKw(Wektor A, Wektor B, Wektor C);

  double wyznacznik();// rozwiniecje laplace'a, gaussa, sarrusa
  // double wyznacznikGauss(); double wyznacznik(metoda met = Gauss) <- enum
  int rzad();

  const MacierzKw & transponuj() const;
  void transponuj();

  const MacierzKw & odwroc() const;
  void odwroc();

  const MacierzKw & operator*(const MacierzKw & M2);
  const MacierzKw & operator+(const MacierzKw & M2);
  const MacierzKw & operator-(const MacierzKw & M2);
  const MacierzKw & operator*(double l);
  const Wektor & operator*(const Wektor & W2);

  const Wektor & operator[] (int index) const;//wg. 2. propozycji
  Wektor & operator[] (int index); // M[2][0] - zerowy element, drugiego wektora

  const double & operator() (int ind1, int ind2) const;//wg. 1. propozycji
  double & operator() (int ind1, int ind2); //M(2,0)

  const Wektor & zwroc_kolumne(int ind); //dla interpretacji wierszowej
  void zmien_kolumne(int ind, Wektor W); //dla interpretacji wierszowej

};


/*
 * To przeciazenie trzeba opisac. Co ono robi. Jaki format
 * danych akceptuje. Jakie jest znaczenie parametrow itd.
 * Szczegoly dotyczace zalecen realizacji opisow mozna
 * znalezc w pliku:
 *    ~bk/edu/kpo/zalecenia.txt
 */
istream & operator >> (istream &Strm, MacierzKw &Mac);

/*
 * To przeciazenie trzeba opisac. Co ono robi. Jaki format
 * danych akceptuje. Jakie jest znaczenie parametrow itd.
 * Szczegoly dotyczace zalecen realizacji opisow mozna
 * znalezc w pliku:
 *    ~bk/edu/kpo/zalecenia.txt
 */
ostream & operator << (ostream &Strm, const MacierzKw &Mac);


#endif
