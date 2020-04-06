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
/*double MacierzKw:: wyznacznik(int wiersz, int kolumna)
{
    MacierzKw pom=*this;
    //Wektor wktr[ROZMIAR], buf, bufk;
    double wyn=1.0;
    int licznik=0;
    while(licznik<ROZMIAR)
    {
      for (int i=wiersz; i<ROZMIAR; i++)
      {
        for(int j=kolumna; j<ROZMIAR; j++)
        {

          if((i<(ROZMIAR-1))&&(j<(ROZMIAR-1)))
          {
            wyn+=pow((-1),i+j+2)*pom[i][j]*pom.wyznacznik(i+1,j+1);

          }
          if(i==(ROZMIAR-1)&&(j==(ROZMIAR-1)))
          {
            wyn*=pom[i][j];
          }
          if(i==(ROZMIAR-2)&&(j==(ROZMIAR-1)))
          {
            wyn+=pow((-1),i+j+2)*pom[i][j]*pom.wyznacznik(i+1,j-1);
          }
          if(i==(ROZMIAR-1)&&(j==(ROZMIAR-2)))
          {
            wyn*=pom[i][j];
            j++;
          }
        }
      }
      pom=pom.zamieno1();
      licznik++;
    }

      return wyn;
}*/
double MacierzKw:: wyznacznik(int wiersz, int kolumna)
{
  MacierzKw pom=*this;
  Wektor buf, buf1;
  double wyn=1.0;
  for (int i=0; i<ROZMIAR; i++)
  {
    if(i==1)
    {
      buf=pom.zwroc_kolumne(i-1);
      buf1=pom.zwroc_kolumne(i);
      pom.zmien_kolumne(i,buf);
      pom.zmien_kolumne(i-1,buf1);
    }
    if(i==2)
    {
      buf=pom.zwroc_kolumne(i-2);
      buf1=pom.zwroc_kolumne(i);
      pom.zmien_kolumne(i,buf);
      pom.zmien_kolumne(i-2,buf1);
    }

    wyn+=pow((-1),2)*pom[0][0]*(pow((-1),2)*pom[1][1]*pom[2][2]+pow((-1),3)*pom[1][2]*pom[2][1]);

  }
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

      /*  M[licznik]=M[licznik]/M[licznik][licznik];
        W[licznik]=W[licznik]/M[licznik][licznik];
        M[licznik+1]=M[licznik+1]-(M[licznik]*M[licznik+1][licznik]);
        W[licznik+1]=W[licznik+1]-(M[licznik]*W[licznik+1][licznik]);
        M[licznik+2]=M[licznik+2]-(M[licznik]*M[licznik+2][licznik]);
        W[licznik+2]=W[licznik+2]-(M[licznik]*W[licznik+2][licznik]);
        licznik++;
        M[licznik]=M[licznik]/M[licznik][licznik];
        W[licznik]=W[licznik]/M[licznik][licznik];
        M[licznik+1]=M[licznik+1]-(M[licznik]*M[licznik+1][licznik]);
        W[licznik+1]=W[licznik+1]-(M[licznik]*W[licznik+1][licznik]);
        M[licznik-1]=M[licznik-1]-(M[licznik]*M[licznik-1][licznik]);
        W[licznik-1]=W[licznik-1]-(M[licznik]*W[licznik-1][licznik]);
        licznik++;
        M[licznik]=M[licznik]/M[licznik][licznik];
        W[licznik]=W[licznik]/M[licznik][licznik];
        M[licznik-1]=M[licznik-1]-(M[licznik]*M[licznik-1][licznik]);
        W[licznik-1]=W[licznik-1]-(M[licznik]*W[licznik-1][licznik]);
        M[licznik-2]=M[licznik-2]-(M[licznik]*M[licznik-2][licznik]);
        W[licznik-2]=W[licznik-2]-(M[licznik]*W[licznik-2][licznik]);*/

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
