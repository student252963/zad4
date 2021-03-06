#include <iostream>
#include <fstream>
#include <cstdlib>
#include "../inc/LZespolona.hh"
#include "../inc/Wektor.hh"
#include "../inc/Macierz.hh"
#include "../inc/UkladRownanLiniowych.hh"

using namespace std;


int main()
{  
  cout << endl << " Start programu " << endl << endl;

  fstream plik;
  plik.open("daneZ.dat" , ios::in);
  if(plik.good()==false) {
    cout << "Nie znaleziono pliku :<"<<endl;
    return 0;
  }
  char typ;
  plik >> typ;

  if(typ=='r')
    {

      UkladRownanL<double,5> UklRown;
  plik >>UklRown; 
  plik.close();

  cout<< "Macierz A^T:" << endl
      << endl;
  cout<< UklRown.get_A() << endl;

  cout<< "Wektor wyrazow wolnych b:" << endl
      << endl;
  cout<< UklRown.get_B() << endl
      << endl;

  Wektor<double,5> Wynik = UklRown.oblicz();
  
  cout << "Rozwiazanie x = (x1 , x2, x3):" << endl
       << endl;
  cout << Wynik <<endl
       << endl;

  //MacierzKw<double,5> Mc;
  //cout<<"Macierz A:"<<endl;
  //Mc = (UklRown.get_A()).transponuj();
  //cout<<Mc<<endl;

  Wektor<double,5> Blad = UklRown.Blad();

  cout << "Wektor bledu:" << endl
       << "Ax-b = " << "( " << Blad << ')' << endl
       << endl;
    }
  else if(typ=='z') {
    
    UkladRownanL<LZespolona,5> UklRown;
  plik >>UklRown; 
  plik.close();

  cout<< "Macierz A^T:" << endl
      << endl;
  cout<< UklRown.get_A() << endl;

  cout<< "Wektor wyrazow wolnych b:" << endl
      << endl;
  cout<< UklRown.get_B() << endl
      << endl;

  Wektor<LZespolona,5> Wynik = UklRown.oblicz();
  
  cout << "Rozwiazanie x = (x1 , x2, x3):" << endl
       << endl;
  cout << Wynik <<endl
       << endl;

  //MacierzKw<LZespolona,5> Mc;
  //cout<<"Macierz A:"<<endl;
  //Mc = (UklRown.get_A()).transponuj();
  //cout<<Mc<<endl;

  Wektor<LZespolona,5> Blad = UklRown.Blad();

  cout << "Wektor bledu:" << endl
       << "Ax-b = " << "( " << Blad << ')' << endl
       << endl; 
  }
  else {
    cerr << "Dane nie zawierają prawidłowej informacji o ich typie :( " << endl;
    exit(1);
  }
    



  return 0;
}
  
