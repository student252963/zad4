#ifndef MACIERZ_HH
#define MACIERZ_HH

#include "Wektor.hh"
#include "rozmiar.h"
#include <iostream>


class MacierzKw {

  Wektor tab[ROZMIAR];

public:

  MacierzKw();
  MacierzKw(const Wektor table[]);
  MacierzKw(Wektor A, Wektor B, Wektor C);

  double wyznacznik() const;

  const MacierzKw transponuj() const;


  Wektor  operator * (const Wektor & W2) const;
  
MacierzKw  operator * (MacierzKw & M2) const;
  MacierzKw  operator + (const MacierzKw & M2) const;
  MacierzKw  operator - (const MacierzKw & M2) const;
  
  MacierzKw  operator * (double l) const;
  MacierzKw  operator / (double l) const;

  const Wektor & operator[] (int index) const;
  Wektor & operator[] (int index); // M[2][0] - zerowy element, drugiego wektora

 const Wektor zwrocKolumna (int index);
 void zmienKolumna (int index, Wektor W);
  
};


const MacierzKw operator * (double l, const MacierzKw & M2);

std::istream& operator >> (std::istream &Strm, MacierzKw &Mac);

std::ostream& operator << (std::ostream &Strm, const MacierzKw &Mac);


#endif
