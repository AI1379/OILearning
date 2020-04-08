#ifndef _STRING_
#include <string>
#endif
#ifndef _CSTRING_
#include <cstring>
#endif
#ifndef _IOSTREAM_
#include <iostream>
#endif
#ifndef _VECTOR_
#include <vector>
#endif
#ifndef _MAP_
#include <map>
#endif
#ifndef _CMATH_
#include <cmath>
#endif
using namespace std;

#ifndef MATHEMATICS
#define MATHEMATICS
//Part I: Constant & Variable
const int MaxLength = 100;
const int Infinity = 2147483647; //MaxInt
const int Maxn = 300001;
vector<int> PrimeList;
map<int, bool> PrimeList_Visited;

//Part II: int operation
int Greater(int a, int b);
int gcd(const int x, const int y);
int lcm(const int x, const int y);
int power(const int base, const int exponent, const int modulus = Infinity);
double power(const double base, const int exponent);
double root(const int base, const int exponent, const double precision = 0.001);
int primelist(const int n);

//Part III: High Precision Integer
class LongInt
{
private:
  short number[MaxLength];
  int length;
  bool sign;

public:
  void gets();
  void puts();
  friend LongInt operator+(const LongInt, const LongInt);
  friend LongInt operator-(const LongInt, const LongInt);
  friend LongInt operator*(const LongInt, const LongInt);
  friend LongInt operator/(const LongInt, const LongInt);
  friend LongInt operator%(const LongInt, const LongInt);
  friend bool operator<(const LongInt, const LongInt);
  friend bool operator>(const LongInt, const LongInt);
  friend bool operator<=(const LongInt, const LongInt);
  friend bool operator>=(const LongInt, const LongInt);
  friend bool operator==(const LongInt, const LongInt);
  friend LongInt abs(const LongInt);
};

//Part IV: Fraction  Base: int
class fraction
{
private:
  int denominator;
  int molecule;
  bool sign; //true:positive  false:negative
public:
  void gets();
  void puts();
  void approximate();
  bool isinteger();
  friend fraction operator+(const fraction, const fraction);
  friend fraction operator-(const fraction, const fraction);
  friend fraction operator*(const fraction, const fraction);
  friend fraction operator/(const fraction, const fraction);
  friend fraction operator-(const fraction);
  friend bool operator<(const fraction, const fraction);
  friend bool operator>(const fraction, const fraction);
  friend bool operator<=(const fraction, const fraction);
  friend bool operator>=(const fraction, const fraction);
  friend bool operator==(const fraction, const fraction);
  friend bool operator!=(const fraction, const fraction);
  friend int fraction2int(const fraction);
};

//Part V: IrrationalNumber
//TODO: IrrationalNumber
class IrrationalNumber
{
private:
  int RootExponent, Base, multiple;
  bool sign;

public:
  void gets();
  void puts();
};

//TODO: RealNumber
//class {

//};

#endif //MATHEMATICS
