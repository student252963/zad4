#ifndef UKLADROWNANLINIOWYCH_HH
#define UKLADROWNANLINIOWYCH_HH

#include <iostream>
#include "Macierz.hh"

using namespace std;

/*
 *  Tutaj trzeba opisac klase. Jakie pojecie modeluje ta klasa
 *  i jakie ma glowne cechy.
 */
template<class Typ , int ROZMIAR>
class UkladRownanL {
  MacierzKw<Typ,ROZMIAR> A;
  Wektor<Typ,ROZMIAR> B;
public:
  UkladRownanL() {A=MacierzKw<Typ,ROZMIAR>(); B=Wektor<Typ,ROZMIAR>();}
  UkladRownanL(MacierzKw<Typ,ROZMIAR> AA, Wektor<Typ,ROZMIAR> BB) {A=AA; B=BB;}

  MacierzKw<Typ,ROZMIAR> get_A() const {return this->A;}
  void set_A(const MacierzKw<Typ,ROZMIAR> & AA) {this->A=AA;}

  Wektor<Typ,ROZMIAR> get_B() const {return this->B;}
  void set_B(const Wektor<Typ,ROZMIAR> & BB) {this->B=BB;}

  /**********************************************/
  
  Wektor<Typ,ROZMIAR> oblicz() const {

  UkladRownanL<Typ,ROZMIAR> Oblicz = (*this);
  MacierzKw<Typ,ROZMIAR> a = Oblicz.get_A();
  Wektor<Typ,ROZMIAR> b = Oblicz.get_B();
  Wektor<Typ,ROZMIAR> Wynik;
  Typ det = a.wyznacznik();

  if(det==0) {
    cerr << "Uklad nie ma rozwiazan lub zawiera nieskonczona ilosc rozwiazan" << endl;
  }
  else {
    for(int i=0 ; i < ROZMIAR ; i++) {

      a = Oblicz.get_A();
      a[i] = b;
      Typ det_w = a.wyznacznik();
      Wynik[i] = det_w / det;
    }
  }
  return Wynik;
}

  /************************************************/
  
  Wektor<Typ,ROZMIAR> Blad() const {

  UkladRownanL<Typ,ROZMIAR> Uk=(*this);
  MacierzKw<Typ,ROZMIAR> Mac;
  Wektor<Typ,ROZMIAR> Blad;
  Mac = Uk.get_A();
  Blad = Mac.transponuj() * Uk.oblicz() - Uk.get_B();
  return Blad;
}

  /*******************/
};
/******************/

template<class Typ , int ROZMIAR>
istream& operator >> (istream &Strm, UkladRownanL<Typ,ROZMIAR> &UklRown) {

  MacierzKw<Typ,ROZMIAR> a;
  Wektor<Typ,ROZMIAR> b;
  Strm >> a >> b;
  UklRown.set_A(a);
  UklRown.set_B(b);
  return Strm;
}

template<class Typ , int ROZMIAR>
ostream& operator << (ostream &Strm, const UkladRownanL<Typ,ROZMIAR> &UklRown) {

  Strm << UklRown.get_A() << UklRown.get_B() << endl;
  return Strm;
}


#endif
