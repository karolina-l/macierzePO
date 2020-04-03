#include <iostream>
#include "Wektor.hh"
#include "Macierz.hh"
#include "rozmiar.h"
#include "UkladRownanLiniowych.hh"



using namespace std;

/*
 * Tu definiujemy pozostale funkcje.
 * Lepiej jednak stworzyc dodatkowy modul
 * i tam je umiescic. Ten przyklad pokazuje
 * jedynie absolutne minimum.
 */


int main()
{
  //UkladRownanL   UklRown;   // To tylko przykladowe definicje zmiennej
  Wektor W1, W2, W3;
  double tab[ROZMIAR]={1.0,2.0,3.0};
  double a=0, b=2;
  double dl=0;
  cout<<"tab: ";
  for(int i=0;i<ROZMIAR;i++)
  {
    cout<<tab[i]<<" ";
  }
  cout<<endl;
  cout<<"Wektor 1 po init: "<<Wektor (W1)<<endl;
  cout<<"Wektor 2 po init: "<<Wektor (W2)<<endl;
  cout<<"Wektor 3 po init: "<<Wektor (W3)<<endl;
  W1=Wektor(tab);
  cout<<"Wektor 1 po init tab: "<<W1<<endl;
  cout<<"podaj w2: ";
  cin>>W2;
  cout<<"wektor 2 po wpisaniu: "<<W2<<endl;
  if(W1==W2)
  {
    cout<<"==Wektory są rowne"<<endl;
  }
  else
  {
    cout<<"== Rozne"<<endl;
  }
  if(W1!=W2)
  {
    cout<<"!=Wektory sa rozne"<<endl;
  }
  else
  {
    cout<<"!=rowne"<<endl;
  }
  W3=W1+W2;
  cout<<"W3 - suma W1 i W2: "<<W3<<endl;
  W3=Wektor(tab);
  W3+=W2;
  cout<<"W3 - suma W1 i W2: "<<W3<<endl;
  W3=W1-W2;
  cout<<"W3 - roznica W1 i W2: "<<W3<<endl;
  a=W1*W2;
  cout<<"W3 - iloczyn W1 i W2: "<<a<<endl;
  W3=W1*b;
  cout<<"W3 - W1*2: "<<W3<<endl;
  W3=W3/b;
  cout<<"W3 - W3/2: "<<W3<<endl;
  dl=dlugosc(W1);
  cout<<"Dlugosc W1: "<<dl<<endl;
  cout<<"KONIEC"<<endl;


}
