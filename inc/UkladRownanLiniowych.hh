#ifndef UKLADROWNANLINIOWYCH_HH
#define UKLADROWNANLINIOWYCH_HH

#include <iostream>
#include "Macierz.hh"

/*
 *  Tutaj trzeba opisac klase. Jakie pojecie modeluje ta klasa
 *  i jakie ma glowne cechy.
 */
class UkladRownanL {
  MacierzKw A;
  Wektor B;
public:
  UkladRownanL() {A=MacierzKw(); B=Wektor();}
  UkladRownanL(MacierzKw AA, Wektor BB) {A=AA; B=BB;}

  MacierzKw get_A() const {return this->A;}
  void set_A(const MacierzKw & AA) {this->A=AA;}

  Wektor get_B() const {return this->B;}
  void set_B(const Wektor & BB) {this->B=BB;}

  Wektor oblicz() const;
  Wektor Blad() const;
};


std::istream& operator >> (std::istream &Strm, UkladRownanL &UklRown);


std::ostream& operator << (std::ostream &Strm, const UkladRownanL &UklRown);


#endif
