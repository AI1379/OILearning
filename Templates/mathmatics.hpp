#ifndef _STRING_
#include <string>
#endif
#ifndef _CSTRING_
#include <cstring>
#endif
#ifndef _IOSTREAM_
#include <iostream>
#endif

const int MaxLength=100;
const int Infinity=

int Greater(int a,int b){
  return a>b?a:b;
}
int swap(int* a,int* b){
  (*a)^=(*b);
  (*b)^=(*a);
  (*a)^=(*b);
  return ;
}
int gcd(const int x,const int y){//Maximum common divisor
  int a,b,q,r;
  if(a==1||b==1)return 1;
  if(a<b){
    swap(&a,&b);
  }
  q=a/b;r=a%b;
  if(r==0)return b;
  else return gcd(b,r);
}
int lcm(const int x,const int y){//Least common multiple
  int g,a,b;
  a=x;b=y;
  g=gcd(a,b);
  return a*b/g;
}
int power(const int base,const int exponent,const int modulus=0){

}

class LongInt{
  private:
    short number[Maxlength];
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
  string num;
  int i;
  memset(number,0,sizeof(number));
  std::cin>>num;
  length=num.length();
  for(i=0;i<len;i++)
    number[i]=(int)(num[len-i-1])-(int)('0');
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

class fraction{
  private:
    int denominator;
    int molecule;
    bool sign;
  public:
    void gets();
    void puts();
    void approximate();
    friend fraction operator + (const fraction ,const fraction );
    friend fraction operator - (const fraction ,const fraction );
    friend fraction operator * (const fraction ,const fraction );
    friend fraction operator / (const fraction ,const fraction );
    friend bool operator < (const fraction , const fraction );
    friend bool operator > (const fraction , const fraction );
    friend bool operator <= (const fraction , const fraction );
    friend bool operator >= (const fraction , const fraction );
    friend bool operator == (const fraction , const fraction );
    friend bool operator != (const fraction , const fraction );
};
void fraction::approximate(){
  int g;
  g=gcd(denominator,molecule);
  denominator/=g;
  molecule/=g;
  return ;
}
void fraction::gets(){
  //std::cout<<"enter denominator first\n";
  std::cin>>denominator>>molecule;
  approximate();
  return ;
}
void fraction::puts(){
  std::cout<<' '<<molecule<<'/'<<denominator<<' ';
  return 0;
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
fraction operator * (const fraction A,const fraction B){
  fraction ans;
  ans.denominator=A.denominator*B.denominator;
  ans.molecule=A.molecule*B.molecule;
  ans.approximate();
  return ;
}
fraction operator / (const fraction A,const fraction B){
  fraction ans;
  ans.denominator=A.denominator*B.molecule;
  ans.molecule=A.molecule*B.denominator;
  ans.approximate();
  return ans;
}
fraction operator + (const fraction A,const fraction B){
  fraction ans;
  ans.denominator=lcm(A.denominator,B.denominator);
  ans.molecule=A.molecule*(ans.denominator/A.denominator)+B.molecule*(ans.denominator/B.denominator);
  return ans;
}

class IrrationalNumber{
  private:
    int RootExponent,Base,multiple;
    bool sign;
  public:
    void gets();
    void puts();
}
class HighPreNum{

};
