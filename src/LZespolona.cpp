#include <iostream>
#include <math.h>
#include "../inc/LZespolona.hh"

using namespace std;



/*!
 * Realizuje dodanie dwoch liczb zespolonych.
 * Argumenty:
 *    Skl1 - pierwszy skladnik dodawania,
 *    Skl2 - drugi skladnik dodawania.
 * Zwraca:
 *    Sume dwoch skladnikow przekazanych jako parametry.
 */

LZespolona::LZespolona() {
  
  re=0;
  im=0;
}

LZespolona::LZespolona(double r, double i) {

  re=r;
  im=i;
}


LZespolona & LZespolona::operator = (double l) {

  this->re = l;
  this->im = 0;
  return *this;
}


LZespolona  operator + (LZespolona  Skl1,  LZespolona  Skl2)
{
  LZespolona  Wynik;

  Wynik.re = Skl1.re + Skl2.re;
  Wynik.im = Skl1.im + Skl2.im;
  return Wynik;
}

LZespolona operator - (LZespolona Skl1,  LZespolona Skl2)
{
  LZespolona Wynik;

  Wynik.re = Skl1.re - Skl2.re;
  Wynik.im = Skl1.im - Skl2.im;
  return Wynik;
}

LZespolona  operator * (LZespolona  Skl1,  LZespolona  Skl2)
{
  LZespolona  Wynik;

  Wynik.re = Skl1.re * Skl2.re - Skl1.im * Skl2.im;
  Wynik.im = Skl1.re * Skl2.im + Skl2.re * Skl1.im;
  return Wynik;
}

LZespolona  operator * (LZespolona  Skl1,  double  l) {

  LZespolona Wynik;

  Wynik.re = Skl1.re * l;
  Wynik.im = Skl1.im * l;
  return Wynik;
}
  

LZespolona  operator / (LZespolona  Skl1,  LZespolona  Skl2)
{
  LZespolona  Wynik;
  double h = Skl2.re * Skl2.re + Skl2.im * Skl2.im; //zdefiniowana pomocnicz do rownan nizej

  if(h!=0) {
  Wynik.re = (Skl1.re * Skl2.re + Skl1.im * Skl2.im) / h;
  Wynik.im = (Skl2.re * Skl1.im - Skl1.re * Skl2.im) / h;
  return Wynik;
  }
  else {
    cerr << "Nie można wykonać operacji dzielenia. Dzielenie przez zero!";
    exit(1);
  }
}

LZespolona  operator / (LZespolona  Skl1,  double  l) {

  LZespolona Wynik;

  if (l!=0) {
    Wynik.re = Skl1.re / l;
    Wynik.im = Skl1.im /l;
    return Wynik;
  }
  else {
    cerr << "Nie można wykonać operacji dzielenia. Dzielenie przez zero!";
    exit(1);
  }
}


istream & operator >> (istream & strm, LZespolona &Z1) //w przypadku bledu wczytanych liczb da informacje o bledzie i w mainie pojdzie informacja o niepoprawnosci zapisu
{
  char znak;
  strm>>znak;
  if(znak!='(')
    strm.setstate(std::ios::failbit);
  strm>>Z1.re;
  strm>>Z1.im;
  strm>>znak;
  if(znak!='i')
    strm.setstate(std::ios::failbit);
  strm>>znak;
  if(znak!=')')
    strm.setstate(std::ios::failbit);
  return strm;
}


ostream & operator << (ostream & strm_wy, const LZespolona & Wynik)
{
  return cout << '(' << Wynik.re << showpos << Wynik.im << 'i' << ')' << noshowpos; //pilnuje znak
}


bool operator == (LZespolona  Skl1,  LZespolona  Skl2) //porownuje czesci urojone i rzeczywiste
{
  if ( (Skl1.re==Skl2.re) && (Skl1.im==Skl2.im) )
    return true;
  else   return false;
}

bool operator == (LZespolona  Skl1,  double  l) {

  if( (Skl1.re==l) && (Skl1.im==0) )
    return true;
  else return false;
}


bool operator != (LZespolona  Skl1,  LZespolona  Skl2)
{
  if (Skl1==Skl2)
    return false;
  else   return true;
}

bool operator != (LZespolona  Skl1,  double  l) {
  if (Skl1==l)
    return false;
  else return true;
}
  
