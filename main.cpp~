#include <iostream>
#include <fstream>
#include <cstdlib>
#include "Wektor.hh"
#include "Macierz.hh"
#include "UkladRownanLiniowych.hh"

using namespace std;


int main()
{
  UkladRownanL UklRown;


  
  cout << endl << " Start programu " << endl << endl;

  fstream plik;
  plik.open("dane.dat" , ios::in);
  if(plik.good()==false) {
    cout << "Nie znaleziono pliku :<"<<endl;
    return 0;
  }
  
  plik >>UklRown; 
  plik.close();

  cout<< "Macierz A^T:" << endl
      << endl;
  cout<< UklRown.get_A() << endl;

  cout<< "Wektor wyrazow wolnych b:" << endl
      << endl;
  cout<< UklRown.get_B() << endl
      << endl;

  Wektor Wynik = UklRown.oblicz();
  
  cout << "Rozwiazanie x = (x1 , x2, x3):" << endl
       << endl;
  cout << Wynik <<endl
       << endl;

  //MacierzKw Mc;
  //cout<<"Macierz A:"<<endl;
  //Mc = (UklRown.get_A()).transponuj();
  //cout<<Mc<<endl;

  Wektor Blad = UklRown.Blad();

  cout << "Wektor bledu:" << endl
       << "Ax-b = " << "( " << Blad << ')' << endl
       << endl;
  cout << "Dlugosc wektora bledu:" << endl
       << "||Ax-b|| = " << Blad.dlugosc() << endl
       << endl;




  return 0;
}
  
