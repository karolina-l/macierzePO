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
    if(i!=(ROZMIAR-1))
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

MacierzKw MacierzKw:: zamieno1()
{
  MacierzKw pom=*this;
  Wektor buf, bufk;
  int i=0, j=0;

      for(int x=0; x<ROZMIAR; x++)
      {
        if(x==0)
        buf=pom[x];

        if(x!=(ROZMIAR-1))
        {
          pom[x]= pom[x+1];
        }
        else
        {
          pom[x]= buf;
        }
      }
     pom=pom.transponuj();
      for(int x=0; x<ROZMIAR; x++)
      {
        if(x==0)
        buf=pom[x];

        if(x!=(ROZMIAR-1))
        {
          pom[x]= pom[x+1];
        }
        else
        {
          pom[x]= buf;
        }
      }
      return pom.transponuj();
}
/*double MacierzKw:: wyznacznik(int it)
{
  MacierzKw pom=*this;
  double wyn=0.0;
  int wiersz=ROZMIAR- it-1, pot;

  if(wiersz==0)
  {
    return pom[0][0];
  }
  else
  {
    for(int i=wiersz; i>=0; i--)
    {
      pot=pow((-1), wiersz+i);
      cout<<pot<<" ";
      wyn=wyn+pot*pom[wiersz][i]*pom.wyznacznik(it+1);
    }

}
cout<<"wy "<<wyn<<endl;
return wyn;
}*/

double MacierzKw:: wyznacznik()
{
  MacierzKw pom=*this;
  cout<<"pom0: "<<endl<<pom<<endl;
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
    cout<<"pom for: "<<endl<<pom<<endl;
  }

 for(int j=0; j<ROZMIAR; j++)
  {
    wyn=wyn*pom[j][j];
  }
  cout<<"po wyn"<<endl;
  return wyn;
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

          cout<<"W "<<W[0]<<endl;
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
