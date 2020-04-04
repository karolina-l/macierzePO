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
///////WEKTOR////////
  /* Wektor W1, W2, W3;
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
  dl=W1.dlugosc();
  cout<<"Dlugosc W1: "<<dl<<endl;
  cout<<"KONIEC"<<endl;*/

////////MACIERZ////////
MacierzKw mat1, mat2, mat3;
Wektor w1,w4;
//Wektor w2, w3;
Wektor tw[ROZMIAR];
double tab1[ROZMIAR]={3.3, 2.2, 1.1};
//double t1={1, 2, 3}
//double t2={4, 5, 6};
//double t3={7, 8, 9};

w1=Wektor(tab1);
//w2=Wektor(t2);
//w3=Wektor(t3);

for(int i=0; i<ROZMIAR; i++)
{
  for (int j=0; j<ROZMIAR; j++)
  {
    tw[i][j]=i*2+j;
  }
}

cout<<"mat1 po init: "<<endl<<MacierzKw(mat1)<<endl;
cout<<"mat2 po init : "<<endl<<MacierzKw(mat2)<<endl;
cout<<"Podaj mat1: ";
cin>>mat1;
cout<<"mat1 po wpisaniu recznym: "<<endl<<mat1<<endl;
mat2=MacierzKw(tw);
cout<<"mat2 po init tw: "<<endl<<mat2<<endl;
mat1.zmien_kolumne(1, w1);
cout<<"mat1 po zmianie kolumny 1: "<<endl<<mat1<<endl;
w4=mat2.zwroc_kolumne(1);
cout<<"kolumna 1 mat2: "<<endl<<w4<<endl;
mat3=mat2.transponuj();
cout<<"mat2 po transpozycji: "<<endl<<mat3<<endl;
cout<<"dodawanie :"<<endl<<mat1+mat2<<endl;
cout<<"odejmowanie :"<<endl<<mat1-mat2<<endl;
cout<<"KONIEC"<<endl;





}
