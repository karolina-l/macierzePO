#include "Macierz.hh"
#include <cmath>

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

const MacierzKw MacierzKw:: operator + (const MacierzKw & M)
{
  Wektor W[ROZMIAR];
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

const MacierzKw MacierzKw::  operator * (const MacierzKw & M)
{
  MacierzKw MA=M.transponuj();
  MacierzKw(w);

  for (int i=0; i<ROZMIAR; i++)
  {
    for(int k=0; k<ROZMIAR; k++)
    {
      for(int j=0; j<ROZMIAR; j++)
      {
        w[i][k]+=mtx[i][j]*MA[k][j];
      }
    }
  }
  return w;
}

const Wektor MacierzKw::operator * (const Wektor & W)
{
  MacierzKw MA=*this;
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

const MacierzKw MacierzKw::  operator * (double l)
{
  Wektor w[ROZMIAR];
  for (int i=0; i<ROZMIAR; i++)
  {
    w[i]=mtx[i]*l;
  }
  return(MacierzKw(w));
}

MacierzKw MacierzKw::odwroc() const
{
 MacierzKw pom=*this;
 Wektor W[ROZMIAR], M[ROZMIAR];
 int licznik=0;
 for(int i=0; i<ROZMIAR; i++)
 {
   for (int j=0; j<ROZMIAR; j++)
   {
     if(i==j)
     W[i][j]=1;
     else
     W[i][j]=0;
   }
 }
 for(int i=0; i<ROZMIAR; i++)
 {
   for (int j=0; j<ROZMIAR; j++)
   {
     M[i][j]=pom[i][j];
   }
 }
 while(licznik<ROZMIAR)
 {
   W[0]=W[0]/M[0][licznik];
   M[0]=M[0]/M[0][licznik];

   for(int i=1; i<ROZMIAR; i++)
   {
     W[i]=W[i]-(W[0]*M[i][licznik]);
     M[i]=M[i]-(M[0]*M[i][licznik]);
   }
   licznik++;
   Wektor  buf;
   for(int x=0; x<ROZMIAR; x++)
   {
     if(x==0)
     buf=M[x];
     if(x!=(ROZMIAR-1))
     {
       M[x]= M[x+1];
     }
     else
     {
       M[x]= buf;
     }
   }
   for(int x=0; x<ROZMIAR; x++)
   {
     if(x==0)
     buf=W[x];
     if(x!=(ROZMIAR-1))
     {
       W[x]= W[x+1];
     }
     else
     {
       W[x]= buf;
     }
   }
 }

 return MacierzKw(W);
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

double MacierzKw:: wyznacznik()
{
  MacierzKw pom=*this;
  double mnoz=1.0; //kiedys LZespolona
  double wyn=1.0; //kiedys LZespolona
  int w, k, i;

  for (k=0; k<ROZMIAR-1; k++)
  {
    for (w=k+1; w<ROZMIAR; w++)
    {
        mnoz=pom[w][k]/pom[k][k];

      for (i=k; i<ROZMIAR; i++)
      {
        pom[w][i]=pom[w][i]-pom[k][i]*mnoz;
      }
    }
  }

 for(int j=0; j<ROZMIAR; j++)
  {
    wyn=wyn*pom[j][j];
  }

  return wyn;
}

MacierzKw MacierzKw::transponuj() const
{
  Wektor W[ROZMIAR];
  MacierzKw pom=*this;
  for (int i=0; i<ROZMIAR; i++)
  {
    W[i]=pom.zwroc_kolumne(i);
  }
  return(MacierzKw(W));
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
    if(i!= (ROZMIAR-1))
    str << endl;
  }
  return str;
}
