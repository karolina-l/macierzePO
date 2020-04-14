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
const MacierzKw UkladRownanL::zwroc_macierz() const
{
  return this->M;
}
const Wektor UkladRownanL::zwroc_wektor() const
{
  return this->W;
}
void UkladRownanL:: zmien_macierz(MacierzKw mat)
{
    M=mat;
}
void UkladRownanL::zmien_wektor(Wektor wek)
{
  W=wek;
}


istream & operator >> (istream &str, UkladRownanL &Ukl)
{
  MacierzKw mat;
  Wektor  wek;

  str >> mat;
  Ukl.zmien_macierz(mat);
  str >> wek;
  Ukl.zmien_wektor(wek);

  return str;
}

ostream & operator << (ostream  &str,  const UkladRownanL &Ukl )
{
  MacierzKw mat=Ukl.zwroc_macierz();
  Wektor  wek=Ukl.zwroc_wektor();
    for (int i=0; i<ROZMIAR; i++)
  {
    for (int j=0; j<ROZMIAR+1; j++)
    {
      if(j==0)
        str<<"|";

      if(j==ROZMIAR)
      {
        str<<"|"<<" "<<"|x_"<<i+1<<"|";

        if(i==(ROZMIAR/2))
        str<<" = |"<<wek[i]<<"|";
        else
        str<<"   |"<<wek[i]<<"|";
        str<<endl;
      }
      else
      str<<mat[i][j]<<" ";

    }
  }
}

Wektor UkladRownanL:: oblicz()
{
  UkladRownanL pom=*this;
  MacierzKw mat=pom.zwroc_macierz();
  Wektor wyn, temp, wek=pom.zwroc_wektor();
  double wyznacznik[ROZMIAR], wyzn;

  wyzn=mat.wyznacznik();
  cout<<wyzn<<endl;

  for(int i=0; i<ROZMIAR; i++)
  {
    temp=mat.zwroc_kolumne(i);
    mat.zmien_kolumne(i, wek);
    wyznacznik[i]=mat.wyznacznik();
    mat.zmien_kolumne(i, temp);
    cout<<"wyzn"<<i<<" "<<wyznacznik[i]<<endl;
  }

  for (int i=0; i<ROZMIAR; i++)
  {
    wyn[i]=wyznacznik[i]/wyzn;
  }

return wyn;
}

double UkladRownanL:: blad(Wektor wyn)
{
    Wektor eps, mnoz;
    double bl;

    mnoz=M*wyn;
    cout<<"mnoz"<<mnoz<<endl;
    eps=mnoz-W;
    cout<<"eps"<<eps<<endl;
    bl=eps.dlugosc();

    return bl;
}
