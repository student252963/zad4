#ifndef MACIERZ_HH
#define MACIERZ_HH

#include "Wektor.hh"
#include <iostream>

using namespace std;



template<class Typ , int ROZMIAR>
class MacierzKw {

  Wektor<Typ , ROZMIAR>  tab[ROZMIAR];

public:

  MacierzKw() {
    
    for(int i=0 ; i < ROZMIAR ; i++) {
      this->tab[i] = Wektor<Typ , ROZMIAR>();
    }
  }

  
  MacierzKw(const Wektor<Typ , ROZMIAR> table[]) {
    
    for(int i=0 ; i < ROZMIAR ; i++) {
      this->tab[i] = table[i];
    }
  }
  
  /*******************************************/
  
  Typ wyznacznik() const {

  Typ det;
  det=1;
  MacierzKw<Typ , ROZMIAR> M;
  M=(*this);
  
  for(int i=0 ; i < ROZMIAR ; i++) {
    if(M[i][i] == 0) {
      for(int j=0 ; j < ROZMIAR ; j++) {
	if(M[j][i] != 0) {
	  swap(M[j] , M[i]);
	  det = det * -1;
	  j = ROZMIAR - 1;
	}
      }
      if(M[i][i] == 0) {
	cerr << "Macierz osobliwa" << endl;
	det = 0;
	return det;
      }
    }
  }
  for(int i=0 ; i < ROZMIAR ; i++) {
    for(int j=i+1 ; j < ROZMIAR ; j++) {
      for(int k=i+1 ; k < ROZMIAR ; k++) {
	M[j][k] = M[j][k] - (M[j][i] / M[i][i] * M[i][k]);
      }
    }
  }
  for(int i=0 ; i < ROZMIAR ; i++) {
    det = det * M[i][i];
  }
  return det;
}

  /************************************************/
  
  const MacierzKw<Typ , ROZMIAR> transponuj() const {

  MacierzKw<Typ , ROZMIAR> Mac;
  for(int i=0 ; i < ROZMIAR ; i++) {
    for(int j=0 ; j < ROZMIAR ; j++) {
      Mac[j][i]=(*this)[i][j];
    }
  }
  return Mac;
}

  /*********************************************/

  Wektor<Typ , ROZMIAR>  operator * (const Wektor<Typ , ROZMIAR> & W2) const {

  Wektor<Typ , ROZMIAR> W;
  for(int i=0 ; i < ROZMIAR ; i++) {
    W[i] = this->tab[i] * W2;
  }
  return W;
}

  /******************************************/
  
  MacierzKw<Typ , ROZMIAR>  operator * (MacierzKw<Typ , ROZMIAR> & M2) const {

  MacierzKw<Typ , ROZMIAR> MIM;
  for(int i=0 ; i < ROZMIAR ; i++) {
    for(int j=0 ; j < ROZMIAR ; j++) {
      MIM[i][j] = this->tab[i] * M2.zwrocKolumna(j);
    }
  }
  return MIM;
}

  /****************************************/
  
  MacierzKw<Typ , ROZMIAR>  operator + (const MacierzKw<Typ , ROZMIAR> & M2) const {

  MacierzKw<Typ , ROZMIAR> MSM;
  for(int i=0 ; i < ROZMIAR ; i++) {
    MSM[i] = this->tab[i] + M2[i];
  }
  return MSM;
}
  
  MacierzKw<Typ , ROZMIAR>  operator - (const MacierzKw<Typ , ROZMIAR> & M2) const {

  MacierzKw<Typ , ROZMIAR> MRM;
  for(int i=0 ; i < ROZMIAR ; i++) {
    MRM[i] = this->tab[i] - M2[i];
  }
  return MRM;
}

  /******************************************/
  
  MacierzKw<Typ , ROZMIAR>  operator * (double l) const {

  MacierzKw<Typ , ROZMIAR> mIloczyn;
  for(int i=0 ; i < ROZMIAR ; i++) {
    mIloczyn[i] = this->tab[i] * l;
  }
  return mIloczyn;
}
  
  MacierzKw<Typ , ROZMIAR>  operator / (double l) const {

  if(l != 0) {
    MacierzKw<Typ , ROZMIAR> mIloraz;
    for(int i=0 ; i < ROZMIAR ; i++) {
      mIloraz[i] = this->tab[i] / l;
    }
  }
    else {
      cerr << "Achtung! Es wurde versucht, die Matrix durch Null zu tailen!"
	   << endl
	   << "(   ogolnie to nie dziel przez zero >:(   )"
	   << endl;
      exit(1);
    }
}

  /********************************************/

  const Wektor<Typ , ROZMIAR> & operator[] (int index) const {

  if (index < 0 || index > ROZMIAR) {
      cerr << "indeks poza zakresem" << endl;
      exit(1);
    }
    else
      return this->tab[index];
}
  
  Wektor<Typ , ROZMIAR> & operator[] (int index)  {

  if (index < 0 || index > ROZMIAR) {
      cerr << "indeks poza zakresem" << endl;
      exit(1);
    }
    else
      return this->tab[index];
}

  /********************************************/

  const Wektor<Typ , ROZMIAR> zwrocKolumna (int index) {

  if(index < 0 || index >= ROZMIAR) {
    cerr << "Indeks jest poza zakresem ;-;" << endl;
    exit(1);
  }
  else {
    Wektor<Typ , ROZMIAR> wKol;
    for(int i=0 ; i < ROZMIAR ; i++) {
      wKol[i] = tab[i][index];
    }
    return wKol;
  }
}
  
  void zmienKolumna (int index, Wektor<Typ , ROZMIAR> W) {

  if(index < 0 || index >= ROZMIAR) {
    cerr << "Indeks jest poza zakresem ;-;" << endl;
    exit(1);
  }
  else {
    for(int i=0 ; i < ROZMIAR ; i++) {
      tab[i][index] = W[i];
    }
  }
} 

  /*************/
  
};

/**************/

template<class Typ , int ROZMIAR>
const MacierzKw<Typ , ROZMIAR> operator * (double l, const MacierzKw<Typ , ROZMIAR> & M2) {
  
  MacierzKw<Typ , ROZMIAR> mIloczyn;
  for(int i=0 ; i < ROZMIAR ; i++) {
    mIloczyn[i] = M2[i] * l;
  }
  return mIloczyn;
}

/************************************/

template<class Typ , int ROZMIAR>
istream& operator >> (istream &Strm, MacierzKw<Typ , ROZMIAR> &Mac) {

  for(int i=0 ; i < ROZMIAR ; i++) {
    Strm >> Mac[i];
  }
  return Strm;
}

template<class Typ , int ROZMIAR>
ostream& operator << (ostream &Strm, const MacierzKw<Typ , ROZMIAR> &Mac) {

  for(int i=0 ; i < ROZMIAR ; i++) {
    for(int j=0 ; j < ROZMIAR ; j++) {      
      Strm << Mac[i][j] << " ";
    }
    Strm << endl;
  }
  return Strm;
}


#endif
