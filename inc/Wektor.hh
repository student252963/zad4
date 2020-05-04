#ifndef WEKTOR_HH
#define WEKTOR_HH

#include "../inc/LZespolona.hh"
#include <iostream>
#include <math.h>

using namespace std;


template<typename Typ, int ROZMIAR>
class Wektor {

  Typ tab[ROZMIAR];
  
public:

  
  Wektor() {
    for (int i=0 ; i < ROZMIAR ; i++){
      this->tab[i]=0;
    }
  }

  
  Wektor(Typ table[]) {
  
    for (int i=0 ; i < ROZMIAR ; i++) {
      this->tab[i] = table[i];
    }
  }
  /**************************************/
  
  /*  double dlugosc() const {
  
    double modul;
    for (int i=0 ; i <ROZMIAR ; i++) {
      modul = modul + this->tab[i] * this->tab[i];
    }
    return sqrt(modul);
    } */

  /*************************************/
  
  Typ operator * (const Wektor<Typ, ROZMIAR> & W2) const {
  
    Typ skalar;
    skalar = 0;
    for(int i=0 ; i < ROZMIAR ; i++) {
      skalar = skalar + (this->tab[i] * W2[i]);
    }
    return skalar;
  }  

  /***************************************/
  
  Wektor<Typ, ROZMIAR> operator + (const Wektor<Typ, ROZMIAR> & W2) const {
    
    Wektor<Typ, ROZMIAR> wSuma;
    for(int i=0 ; i < ROZMIAR ; i++) {
      wSuma[i] = this->tab[i] + W2[i];
    }
    return wSuma;
  }
  
  Wektor<Typ, ROZMIAR> operator - (const Wektor<Typ, ROZMIAR> & W2) const {

    Wektor<Typ, ROZMIAR> wRoznica;
    for(int i=0 ; i < ROZMIAR ; i++) {
      wRoznica[i] = this->tab[i] - W2[i];
    }
    return wRoznica;
  }
  
  /***************************************/
  
  Wektor<Typ, ROZMIAR> operator * (Typ l) const {

    Wektor<Typ, ROZMIAR> wIloczyn;
    for(int i=0 ; i < ROZMIAR ; i++) {
      wIloczyn[i] = this->tab[i] * l;
    }
    return wIloczyn;
  }
  
  Wektor<Typ, ROZMIAR> operator / (Typ l) const {

    Wektor<Typ, ROZMIAR> wIloraz;
    if(l!=0) {
      for(int i=0 ; i < ROZMIAR ; i++) {
        wIloraz[i] = this->tab[i] / l;
      }
      return wIloraz;
    }
    else {
      cerr<<"Zakazana operacja >:( NIE DZIEL PRZEZ 0 !!!"<<endl;
      exit(1);
        }
  }

  /************************************************/
  
  bool operator == (const Wektor<Typ, ROZMIAR> & W2) const {

    for(int i=0 ; i < ROZMIAR ; i++) {
      if(this->tab[i] == W2[i]) {
        return true;
      }
      else   return false;
    }
  }
  
  bool operator != (const Wektor<Typ, ROZMIAR> & W2) const {

    return !(*this == W2);
  }

  /*********************************************/

  const Typ & operator[] (int index) const {

      if (index < 0 || index > ROZMIAR) {
        cerr << "indeks poza zakresem" << endl;
        exit(1);
      }
      else   return tab[index];

  }
  Typ & operator[] (int index) {

      if (index < 0 || index > ROZMIAR) {
        cerr << "indeks poza zakresem" << endl;
        exit(1);
      }
      else   return tab[index];
  }

  /*********************************************/
      
};


template<class Typ , int ROZMIAR>
Wektor<Typ, ROZMIAR> operator * (Typ l, Wektor<Typ, ROZMIAR> W2) {
  
  Wektor<Typ, ROZMIAR> wIloczyn;
  for(int i=0 ; i < ROZMIAR ; i++) {
    wIloczyn[i] = l * W2[i];
  }
  return wIloczyn;
}


template<class Typ , int ROZMIAR>
istream& operator >> (istream &Strm, Wektor<Typ, ROZMIAR> &Wek) {

  for(int i=0 ; i < ROZMIAR ; i++) {
    Strm >> Wek[i];
  }
  return Strm;
}


template<class Typ , int ROZMIAR>
ostream& operator << (ostream &Strm, const Wektor<Typ, ROZMIAR> &Wek) {

  for(int i=0 ; i < ROZMIAR ; i++) {
    Strm << Wek[i] << " ";
  }
  return Strm;
}



#endif
