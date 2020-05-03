#include "UkladRownanLiniowych.hh"
#include <iostream>

using namespace std;

/*
 *  Tutaj nalezy zdefiniowac odpowiednie metody
 *  klasy UkladRownanLiniowych, ktore zawieraja 
 *  wiecej kodu niz dwie linijki.
 *  Mniejsze metody mozna definiwac w ciele klasy.
 */


/*******************************************/

Wektor UkladRownanL::oblicz() const {

  UkladRownanL Oblicz = (*this);
  MacierzKw a = Oblicz.get_A();
  Wektor b = Oblicz.get_B();
  Wektor Wynik;
  double det = a.wyznacznik();

  if(det==0) {
    cerr << "Uklad nie ma rozwiazan lub zawiera nieskonczona ilosc rozwiazan" << endl;
  }
  else {
    for(int i=0 ; i < ROZMIAR ; i++) {

      a = Oblicz.get_A();
      a[i] = b;
      double det_w = a.wyznacznik();
      Wynik[i] = det_w / det;
    }
  }
  return Wynik;
  } 


Wektor UkladRownanL::Blad() const {

  UkladRownanL Uk=(*this);
  MacierzKw Mac;
  Wektor Blad;
  Mac = Uk.get_A();
  Blad = Mac.transponuj() * Uk.oblicz() - Uk.get_B();
  return Blad;
}

  
/************************************************/

istream& operator >> (istream &Strm, UkladRownanL &UklRown) {

  MacierzKw a;
  Wektor b;
  Strm >> a >> b;
  UklRown.set_A(a);
  UklRown.set_B(b);
  return Strm;
}


ostream& operator << (ostream &Strm, const UkladRownanL &UklRown) {

  Strm << UklRown.get_A() << UklRown.get_B() << endl;
  return Strm;
}
  
