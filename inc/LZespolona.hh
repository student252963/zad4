#ifndef LZESPOLONA_HH
#define LZESPOLONA_HH


/*!
 *  Plik zawiera definicje struktury LZesplona oraz zapowiedzi
 *  przeciazen operatorow arytmetycznych dzialajacych na tej 
 *  strukturze.
 */


/*!
 * Modeluje pojecie liczby zespolonej
 */
struct  LZespolona {
  double   re;    /*! Pole repezentuje czesc rzeczywista. */
  double   im;    /*! Pole repezentuje czesc urojona. */

  LZespolona();
  LZespolona(double r, double i);

  LZespolona & operator = (double l);
};


/*
 * Dalej powinny pojawic sie zapowiedzi definicji przeciazen operatorow
 */



std::ostream & operator << (std::ostream & strm_wy, const LZespolona & Wynik);
std::istream & operator >> (std::istream & strm_we, LZespolona &Z1);

LZespolona  operator + (LZespolona  Skl1,  LZespolona  Skl2);
LZespolona  operator - (LZespolona  Skl1,  LZespolona  Skl2);
LZespolona  operator * (LZespolona  Skl1,  LZespolona  Skl2);
LZespolona  operator * (LZespolona  Skl1,  double  l);
LZespolona  operator / (LZespolona  Skl1,  LZespolona  Skl2);
LZespolona  operator / (LZespolona  Skl1,  double  l);

bool operator == (LZespolona  Skl1,  LZespolona  Skl2);
bool operator == (LZespolona  Skl1,  double  l);
bool operator != (LZespolona  Skl1,  LZespolona  Skl2);
bool operator != (LZespolona  Skl1,  double  l);


#endif
