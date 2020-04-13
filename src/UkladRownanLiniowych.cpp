#include "UkladRownanLiniowych.hh"


/*
 *  Tutaj nalezy zdefiniowac odpowiednie metody
 *  klasy UkladRownanLiniowych, ktore zawieraja
 *  wiecej kodu niz dwie linijki.
 *  Mniejsze metody mozna definiwac w ciele klasy.
 */

UkladRownanL:: UkladRownanL()
{
  M=MacierzKw();
  W=Wektor();
}

UkladRownanL:: UkladRownanL(MacierzKw AA, Wektor BB)
{
  M=AA;
  W=BB;
}

istream & operator >> (istream &str, UkladRownanL &Ukl)
{
  Wektor  pom;
  for (int i=0; i<ROZMIAR; i++)
  {
    str >> pom;
    Ukl.M[i]=pom;
  }
  str >> pom;
  Ukl.W=pom;

  return str;
}

ostream & operator << (ostream  &str, const UkladRownanL &Ukl )
{
  MacierzKw mtx = Ukl.M;
  Wektor wek = Ukl.W;
    for (int i=0; i<ROZMIAR; i++)
  {
    for (int j=0; j<ROZMIAR+1; j++)
    {
      if(j==0)
        str<<"|";
      str<<mtx[i][j]<<" ";
      if(j==ROZMIAR)
      {
        str<<"|"<<" "<<"|"<<wek[i]<<"|"<<endl;
      }

    }
  }
}
