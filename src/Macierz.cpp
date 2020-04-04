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
  double zwr[ROZMIAR];
  for (int i=0; i<ROZMIAR; i++)
  {
    zwr[i]=mtx[i][ind];
  }
  return Wektor(zwr);
}

void MacierzKw::zmien_kolumne(int ind, Wektor W)
{
  for (int i=0; i<ROZMIAR; i++)
  {
    mtx[i][ind]=W[i];
  }
}

istream & operator >> (istream &str, MacierzKw &M)
{
  double pom[ROZMIAR]={0};
  Wektor W;
  for (int i=0; i<ROZMIAR; i++)
  {
    str >> W;
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

const Wektor & MacierzKw:: operator[] (int index) const
{
  if (index < 0 || index > ROZMIAR)
  {
    cerr << "indeks poza zakresem" << endl;
    exit(1);
  }
  else
  {
    return mtx[index];
  }
}

Wektor & MacierzKw::operator[] (int index)
{
  if (index < 0 || index > ROZMIAR)
  {
    cerr << "indeks poza zakresem" << endl;
    exit(1);
  }
  else
  {
    return mtx[index];
  }
}

const MacierzKw MacierzKw::transponuj() const
{
  Wektor W[ROZMIAR];
  MacierzKw pom=*this;
  for (int i=0; i<ROZMIAR; i++)
  {
    W[i]=pom.zwroc_kolumne(i);
  }
  return(MacierzKw(W));
}

const MacierzKw MacierzKw::  operator * (const MacierzKw & M)
{
  MacierzKw MA=M.transponuj();
  Wektor w[ROZMIAR];
  for(int i=0; i<ROZMIAR; i++)
  {
    for (int j=0; j<ROZMIAR; j++)
    {
      w[i][j]=mtx[i][j]*MA[i][j];
    }
  }

  return (MacierzKw(w));
}

const MacierzKw MacierzKw::  operator * (double l)
{
  Wektor w[ROZMIAR];
  for (int i=0; i<ROZMIAR; i++)
  {
    w[i]=mtx[i]*l;
  }
  return(MacierzKw(w));
}

const Wektor MacierzKw::operator * (const Wektor & W)
{
  MacierzKw MA=*this;
  //MA=MA.transponuj();
  Wektor wyn;
  for (int i=0; i<ROZMIAR; i++)
  {
    for (int j=0; j<ROZMIAR; j++)
    {
      wyn[i]+=MA[i][j]*W[j];
    }
  }
  return(wyn);
}

const MacierzKw MacierzKw:: operator + (const MacierzKw & M)
{
  Wektor W[ROZMIAR];
  //MacierzKw pom=*this;
  for (int i=0; i<ROZMIAR; i++)
  {
    for (int j=0; j<ROZMIAR; j++)
    {
        W[i][j]=mtx[i][j]+M[i][j];
    }
  }
  return(MacierzKw(W));
}

const MacierzKw MacierzKw:: operator - (const MacierzKw & M)
{
  Wektor W[ROZMIAR];
  //MacierzKw pom=*this;
  for (int i=0; i<ROZMIAR; i++)
  {
    for (int j=0; j<ROZMIAR; j++)
    {
        W[i][j]=mtx[i][j]-M[i][j];
    }
  }
  return(MacierzKw(W));
}
