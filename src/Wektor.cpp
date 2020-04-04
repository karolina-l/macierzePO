#include "Wektor.hh"
#include <cmath>


using namespace std;

/*
 *  Tutaj nalezy zdefiniowac odpowiednie metody
 *  klasy Wektor, ktore zawieraja wiecej kodu
 *  niz dwie linijki.
 *  Mniejsze metody mozna definiwac w ciele klasy.
 */

Wektor::Wektor()
{
  for(int i=0; i<ROZMIAR; i++)
  {
    wek[i]=0.0;
  }
}

Wektor::Wektor(double tablica[ROZMIAR])
{
  for(int i=0; i<ROZMIAR; i++)
  {
    wek[i]=tablica[i];
  }
}


Wektor Wektor::  operator += (const Wektor & W)
{
  for(int i=0; i<ROZMIAR; i++)
  {
    this->wek[i]+=W.wek[i];
  }
  return *this;
}

Wektor Wektor::  operator + (const Wektor & W) const
{
  double nowy[ROZMIAR]={0.0};
  for(int i=0; i<ROZMIAR; i++)
  {
    nowy[i]=this->wek[i]+W.wek[i];
  }
  return Wektor(nowy);
}

Wektor Wektor::  operator - (const Wektor & W) const
{
  double nowy[ROZMIAR]={0.0};
  for(int i=0; i<ROZMIAR; i++)
  {
    nowy[i]=this->wek[i]-W.wek[i];
  }
  return Wektor(nowy);
}

double Wektor::  operator * (const Wektor & W) const
{
  double nowy[ROZMIAR]={0.0};
  double wynik=0.0;
  for(int i=0; i<ROZMIAR; i++)
  {
    nowy[i]=this->wek[i]*W.wek[i];
    wynik+=nowy[i];
  }
  return wynik;
}

Wektor Wektor::  operator * (double l) const
{
  double nowy[ROZMIAR]={0.0};
  for(int i=0; i<ROZMIAR; i++)
  {
    nowy[i]=this->wek[i]*l;
  }
  return Wektor(nowy);
}

Wektor Wektor::  operator / (double l) const
{
  double nowy[ROZMIAR]={0.0};
  for(int i=0; i<ROZMIAR; i++)
  {
    nowy[i]=this->wek[i]/l;
  }
  return Wektor(nowy);
}

double Wektor:: dlugosc() const
{
  double wynik, a=0.0;
  for (int i=0; i<ROZMIAR; i++)
  {
    a+=this->wek[i]*this->wek[i];
  }
  wynik=sqrt(a);
  return wynik;
}

bool Wektor:: operator == (const Wektor & W) const
{
  double epsilon=0.000001;
  int licznik =0;
  for (int i=0; i<ROZMIAR; i++)
  {
    if(this->wek[i]-W.wek[i]<epsilon)
    {
      licznik++;
    }
  }
  if(licznik==ROZMIAR)
  {
    return true;
  }
  else
  {
    return false;
  }
}

bool Wektor:: operator != (const Wektor & W) const
{
    //return !(this->wek==W.wek);
    double epsilon=0.000001;
    int licznik =0;
    for (int i=0; i<ROZMIAR; i++)
    {
      if(this->wek[i]-W.wek[i]<epsilon)
      {
        licznik++;
      }
    }
    if(licznik==ROZMIAR)
    {
      return false;
    }
    else
    {
      return true;
    }
}

const double & Wektor:: operator[] (int index) const
{
  if (index < 0 || index > ROZMIAR)
  {
    cerr << "indeks poza zakresem" << endl;
    exit(1);
  }
  else
  {
    return wek[index];
  }
}

double & Wektor:: operator[] (int index)
{
   if (index < 0 || index > ROZMIAR)
   {
     cerr << "indeks poza zakresem" << endl;
     exit(1);
   }
   else
   {
     return wek[index];
   }
 }

istream & operator >> (istream & str, Wektor & W)
{
  double pom[ROZMIAR]={0};
  for(int i=0; i<ROZMIAR; i++)
  {
    str >> pom[i];
  }
  W=Wektor(pom);
  return str;
}

ostream & operator << (ostream & str, const Wektor & W)
{
  for (int i=0; i<ROZMIAR; i++)
  {
    str << W[i]<<" ";
  }

  return str;
}
