#include "Wektor.hh"
#include <iostream>
#include <cmath>

using namespace std;

/************************************************/

Wektor::Wektor() {
  
  for (int i=0 ; i < ROZMIAR ; i++){
    this->tab[i]=0;
  }
}


Wektor::Wektor(double x, double y, double z) {
  
  int i=0;
  this->tab[i] = x;
  this->tab[++i] = y;
  this->tab[++i] = z;
}


Wektor::Wektor(double table[]) {
  
  for (int i=0 ; i < ROZMIAR ; i++) {
    this->tab[i] = table[i];
  }
}

/*************************************************/

double Wektor::dlugosc()const {
  
  double modul=0;
  for (int i=0 ; i <ROZMIAR ; i++) {
    modul += pow(this->tab[i],2);
  }
  return sqrt(modul);
}


double Wektor::operator * (const Wektor & W2) const {
  
  double skalar=0;
  for(int i=0 ; i < ROZMIAR ; i++) {
    skalar += this->tab[i] * W2[i];
  }
  return skalar;
}
  
/*************************************************/

Wektor Wektor::operator + (const Wektor & W2) const {

  Wektor wSuma;
  for(int i=0 ; i < ROZMIAR ; i++) {
    wSuma[i] = this->tab[i] + W2[i];
  }
  return wSuma;
}


Wektor Wektor::operator - (const Wektor & W2) const {

  Wektor wRoznica;
  for(int i=0 ; i < ROZMIAR ; i++) {
    wRoznica[i] = this->tab[i] - W2[i];
  }
  return wRoznica;
}


Wektor Wektor::operator * (double l) const {

  Wektor wIloczyn;
  for(int i=0 ; i < ROZMIAR ; i++) {
    wIloczyn[i] = this->tab[i] * l;
  }
  return wIloczyn;
}


Wektor Wektor::operator / (double l) const {

  Wektor wIloraz;
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

/*************************************************/

bool Wektor::operator == (const Wektor & W2) const {

  for(int i=0 ; i < ROZMIAR ; i++) {
    if(this->tab[i] == W2[i]) {
      return true;
    }
    else   return false;
  }
}
      
  
bool Wektor::operator != (const Wektor & W2) const {
  return !(*this == W2);
}

/*************************************************/

const double & Wektor::operator[] (int index) const {
    
    if (index < 0 || index > ROZMIAR) {
      cerr << "indeks poza zakresem" << endl;
      exit(1);
    }
    else   return tab[index];
}

double & Wektor::operator[] (int index) {
  
    if (index < 0 || index > ROZMIAR) {
      cerr << "indeks poza zakresem" << endl;
      exit(1);
    }
    else   return tab[index];
}

/************************************************/

Wektor operator * (double l, Wektor W2) {

  Wektor wIloczyn;
  for(int i=0 ; i < ROZMIAR ; i++) {
    wIloczyn[i] = l * W2[i];
  }
  return wIloczyn;
}

/**********************************************/

istream& operator >> (istream &Strm, Wektor &Wek) {

  for(int i=0 ; i < ROZMIAR ; i++) {
    Strm >> Wek[i];
  }
  return Strm;
}

ostream& operator << (ostream &Strm, const Wektor &Wek) {

  for(int i=0 ; i < ROZMIAR ; i++) {
    Strm << Wek[i] << " ";
  }
  return Strm;
}
