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
const int MaxLength=100;
const int Infinity=2147483647;//MaxInt
const int Maxn=300001;
vector<int> PrimeList;
map<int,bool> PrimeList_Visited;

//Part II: int operation
int Greater(int a,int b){
  return a>b?a:b;
}
int gcd(const int x,const int y){//Greatest common divisor
  int a=x,b=y,r;
  if(a<b){
    int tmp;
    tmp=a;a=b;b=tmp;
  }
  while(1){
    r=a%b;
    if(r==0)  return b;
    else a=b,b=r;
  }
  return 1;
}
int lcm(const int x,const int y){//Least common multiple
  int g,a,b;
  a=x;b=y;
  g=gcd(a,b);
  return a*b/g;
}
int power(const int base,const int exponent,const int modulus=Infinity){
  if(exponent==0)return 1;
  int ans=power(base,exponent>>1,modulus);
  ans=ans*ans%modulus;
  if(exponent&1)ans=ans*base%modulus;
  return ans;
}
double power(const double base,const int exponent){
  int i;
  double ans=1.00;
  for(i=0;i<exponent;i++)
    ans=ans*base;
  return ans;
}
double root(const int base,const int exponent,const double precision=0.001){
  double left=0.00,right=(double)(base),mid=(left+right)/2.00;
  while(fabs(power(mid,exponent)-base)>precision){
    mid=(left+right)/2.00;
    if(power(mid,exponent)-base<=0)left=mid;
    else right=mid;
  }
  return left;
}
int primelist(const int n){
  int i,j,NumOfPrime;
  for(i=1;i<=n;i++)
    PrimeList_Visited.insert(make_pair(i,false));
  for(i=2;i<=n;i++){
    if(!PrimeList_Visited[i])
      PrimeList.push_back(i);
    NumOfPrime=PrimeList.size();
    for(j=0;j<NumOfPrime && i*PrimeList[j]<n;j++){
      PrimeList_Visited[i*PrimeList[j]]=true;
      if(i%PrimeList[j]==0)
        break;
    }
  }
  return NumOfPrime;
}

//Part III: High Precision Integer
class LongInt{
  private:
    short number[MaxLength];
    int length;
    bool sign;
  public:
    void gets();
    void puts();
    friend LongInt operator + (const LongInt , const LongInt );
    friend LongInt operator - (const LongInt , const LongInt );
    friend LongInt operator * (const LongInt , const LongInt );
    friend LongInt operator / (const LongInt , const LongInt );
    friend LongInt operator % (const LongInt , const LongInt );
    friend bool operator < (const LongInt , const LongInt );
    friend bool operator > (const LongInt , const LongInt );
    friend bool operator <= (const LongInt , const LongInt );
    friend bool operator >= (const LongInt , const LongInt );
    friend bool operator == (const LongInt , const LongInt );
    friend LongInt abs(const LongInt );
};
void LongInt::gets(){
  std::string num;
  int i;
  memset(number,0,sizeof(number));
  std::cin>>num;
  length=num.length();
  for(i=0;i<length;i++)
    number[i]=(int)(num[length-i-1])-(int)('0');
  return ;
}
void LongInt::puts(){
  int i;
  for(i=length-1;i>=0;i--)
    std::cout<<number[i];
  std::cout<<' ';
  return ;
}
LongInt abs(const LongInt A){
  LongInt ans;
  int i;
  memset(ans.number,0,sizeof(ans.number));
  for(i=0;i<A.length;i++)ans.number[i]=A.number[i];
  ans.length=A.length;
  ans.sign=true;
  return ans;
}
bool operator < (const LongInt A, const LongInt B){
  if(!A.sign&&B.sign)return true;
  if(A.length<B.length)return true;
  int i;
  for(i=A.length-1;i>=0;i--)if(A.number[i]<B.number[i])return true;
  return false;
}
LongInt operator + (const LongInt A, const LongInt B){
  int i,j;
  LongInt ans;
  ans.length=Greater(A.length,B.length);
  if(A.sign^B.sign){
    for(i=0;i<ans.length;i++){
      ans.number[i]=A.number[i]+B.number[i]+ans.number[i];
      if(ans.number[i]>=10){
        ans.number[i+1]+=ans.number[i]/10;
        ans.number[i]%=10;
      }
    }
    if(ans.number[ans.length+1]!=0)ans.length++;
    ans.sign=A.sign;
  }
  else{
    LongInt x=A,y=B;
    if(x<y){
      LongInt tmp=x;
      x=y;
      y=tmp;
    }
    for(i=0;i<ans.length;i++){
      ans.number[i]=A.number[i]+B.number[i]+ans.number[i];
      if(ans.number[i]>=10){
        ans.number[i+1]+=ans.number[i]/10;
        ans.number[i]%=10;
      }
    }
    if(ans.number[ans.length+1]!=0)ans.length++;
    ans.sign=A.sign;
  }
  return ans;
}

//Part IV: Fraction  Base: int
class fraction{
  private:
    int denominator;
    int molecule;
    bool sign;//true:positive  false:negative
  public:
    void gets();
    void puts();
    void approximate();
    bool isinteger();
    friend fraction operator + (const fraction ,const fraction );
    friend fraction operator - (const fraction ,const fraction );
    friend fraction operator * (const fraction ,const fraction );
    friend fraction operator / (const fraction ,const fraction );
    friend fraction operator - (const fraction );
    friend bool operator < (const fraction , const fraction );
    friend bool operator > (const fraction , const fraction );
    friend bool operator <= (const fraction , const fraction );
    friend bool operator >= (const fraction , const fraction );
    friend bool operator == (const fraction , const fraction );
    friend bool operator != (const fraction , const fraction );
    friend int fraction2int (const fraction);
};
void fraction::approximate(){
  int g;
  g=gcd(denominator,molecule);
  denominator=denominator/g;
  molecule=molecule/g;
  return ;
}
void fraction::gets(){
  //std::cout<<"enter denominator first\n";
  char c;
  std::cin >> c;
  if(c=='-')sign=false;
  else sign=true;
  std::cin >> denominator >> molecule;
  if(denominator==0)std::cout << "error";
  int g;
  g=gcd(denominator,molecule);
  denominator=denominator/g;
  molecule=molecule/g;
  return ;
}
void fraction::puts(){
  if(!sign)std::cout << " -";
  else std::cout << ' ';
  std::cout << molecule << '/' << denominator << ' ';
  return ;
}
bool fraction::isinteger(){
  if(molecule%denominator==0)return true;
  else return false;
}
bool operator == (const fraction A, const fraction B){
  fraction x=A,y=B;
  x.approximate();
  y.approximate();
  return x.denominator==y.denominator&&x.molecule==y.molecule;
}
bool operator != (const fraction A, const fraction B){
  return !(A==B);
}
bool operator < (const fraction A, const fraction B){
  fraction x=A,y=B;
  x.approximate();
  y.approximate();
  int SimplestDenominator,multipleA,multipleB;
  SimplestDenominator=lcm(x.denominator,y.denominator);
  multipleA=SimplestDenominator/x.denominator;
  multipleB=SimplestDenominator/y.denominator;
  return x.molecule*multipleA<y.molecule*multipleB;
}
bool operator <= (const fraction A, const fraction B){
  return A<B||A==B;
}
bool operator > (const fraction A, const fraction B){
  fraction x=A,y=B;
  x.approximate();
  y.approximate();
  int SimplestDenominator,multipleA,multipleB;
  SimplestDenominator=lcm(x.denominator,y.denominator);
  multipleA=SimplestDenominator/x.denominator;
  multipleB=SimplestDenominator/y.denominator;
  return x.molecule*multipleA>y.molecule*multipleB;
}
bool operator >= (const fraction A, const fraction B){
  return A>B||A==B;
}
fraction operator - (const fraction A){
  fraction tmp=A;
  tmp.sign=!A.sign;
  return tmp;
}
fraction operator * (const fraction A,const fraction B){
  fraction ans;
  ans.denominator=A.denominator*B.denominator;
  ans.molecule=A.molecule*B.molecule;
  ans.approximate();
  ans.sign=A.sign^B.sign;
  return ans;
}
fraction operator / (const fraction A,const fraction B){
  fraction ans;
  ans.denominator=A.denominator*B.molecule;
  ans.molecule=A.molecule*B.denominator;
  ans.approximate();
  ans.sign=A.sign^B.sign;
  return ans;
}
fraction operator + (const fraction A,const fraction B){
  fraction ans;
  ans.denominator=lcm(A.denominator,B.denominator);
  ans.sign=true;
  if(!(A.sign^B.sign)){
    ans.molecule=A.molecule*(ans.denominator/A.denominator)+B.molecule*(ans.denominator/B.denominator);
    ans.sign=A.sign;
  }
  else{
    if(A.sign==true){
      ans.molecule=A.molecule*(ans.denominator/A.denominator)-B.molecule*(ans.denominator/B.denominator);
      if(ans.molecule<0){
        ans.molecule=-ans.molecule;
        ans.sign=false;
      }
    }
    else{
      ans.molecule=B.molecule*(ans.denominator/B.denominator)-A.molecule*(ans.denominator/A.denominator);
      if(ans.molecule<0){
        ans.molecule=-ans.molecule;
        ans.sign=false;
      }
    }
  }
  ans.approximate();
  return ans;
}
fraction operator - (const fraction A,const fraction B){
  fraction tmp=B;
  tmp.sign=(!B.sign);
  return A+tmp;
}
int fraction2int(fraction A){
  if(!A.isinteger())return -1;
  fraction tmp=A;
  int ans;
  tmp.approximate();
  ans=tmp.molecule;
  if(!tmp.sign)ans=-ans;
  return ans;
}

//Part V: IrrationalNumber
class IrrationalNumber{
  private:
    int RootExponent,Base,multiple;
    bool sign;
  public:
    void gets();
    void puts();
};


//class {

//};

#endif //MATHEMATICS
