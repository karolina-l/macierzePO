#ifndef WEKTOR_HH
#define WEKTOR_HH


#include "rozmiar.h"
#include <iostream>

using namespace std;

/*
 *  Tutaj trzeba opisac klase. Jakie pojecie modeluje ta klasa
 *  i jakie ma glowne cechy.
 */
class Wektor {
  /*
   *  Tutaj trzeba wstawic definicje odpowiednich pol i metod prywatnych
   */


   double wek[ROZMIAR]; //4 tablica statyczna
  public:
  /*
   *  Tutaj trzeba wstawic definicje odpowiednich metod publicznych
   */

   Wektor();
   Wektor(double x,double y, double z);
   Wektor(double tablica[ROZMIAR]);

   Wektor  operator += (const Wektor & W); //W1 += W2  , W1 += W3 += W4
   Wektor  operator + (const Wektor & W) const; //W1 + W2
   Wektor  operator - (const Wektor & W) const;
   double operator * (const Wektor & W) const; //skalarnie
   Wektor operator * (double l) const; // W1 * 2
   Wektor  operator / (double l) const; // W1 / 2

   double dlugosc() const; //modul

   bool operator == (const Wektor & W) const;
   bool operator != (const Wektor & W) const;

   const double & operator[] (int index) const;
   double & operator[] (int index);


};


/*
 * To przeciazenie trzeba opisac. Co ono robi. Jaki format
 * danych akceptuje. Jakie jest znaczenie parametrow itd.
 * Szczegoly dotyczace zalecen realizacji opisow mozna
 * znalezc w pliku:
 *    ~bk/edu/kpo/zalecenia.txt
 */
istream & operator >> (istream & str, Wektor & W);//czy tu jest &?

/*
 * To przeciazenie trzeba opisac. Co ono robi. Jaki format
 * danych akceptuje. Jakie jest znaczenie parametrow itd.
 * Szczegoly dotyczace zalecen realizacji opisow mozna
 * znalezc w pliku:
 *    ~bk/edu/kpo/zalecenia.txt
 */
ostream & operator << (ostream & str, const Wektor & W);


#endif
