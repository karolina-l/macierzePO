#include "Macierz.hh"
#include <cmath>

/*
 *  Tutaj nalezy zdefiniowac odpowiednie metody
 *  klasy Macierz, ktore zawieraja wiecej kodu
 *  niz dwie linijki.
 *  Mniejsze metody mozna definiwac w ciele klasy.
 */

MacierzKw:: MacierzKw()
{
  for (int i=0; i<ROZMIAR; i++)
  {
    mtx[i]=Wektor();
  }
}

MacierzKw:: MacierzKw(const Wektor tab[ROZMIAR])
{
  for(int i=0; i<ROZMIAR; i++)
  {
      mtx[i]=tab[i];
  }
}

Wektor MacierzKw:: zwroc_kolumne(int ind)
{
  Wektor zwr;
  zwr=mtx[ind];
  return zwr;
}

void MacierzKw::zmien_kolumne(int ind, Wektor W)
{
  mtx[ind]=W;
}

istream & operator >> (istream &str, MacierzKw &M)
{
  double pom[ROZMIAR]={0};
  Wektor W;
  for (int i=0; i<ROZMIAR; i++)
  {
    str >> pom[i];
    W=Wektor(pom);
    M[i]=W;
  }
  return str;
}

ostream & operator << (ostream &str, const MacierzKw &M)
{
  for (int i=0; i<ROZMIAR; i++)
  {
    str << M[i];
    str << endl;
  }
  return str;
}



/*const MacierzKw:: transponuj() const
{
  double pom[ROZMIAR][ROZMIAR]={0};
  for (int i=0; i<r; i++)
  {
    for (int j=0; j<ROZMIAR; j++)
    {
      pom[j][i]=mtx[i][j];
    }
  }
  return MacierzKw(pom);
}*/
