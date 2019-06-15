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

class LongInt{
  private:
    short number[Maxlength];
    int length;
  public:
    void gets();
    void puts();
    friend LongInt operator + (const LongInt , const LongInt );
    friend LongInt operator - (const LongInt , const LongInt );
    friend LongInt operator * (const LongInt , const LongInt );
    friend LongInt operator / (const LongInt , const LongInt );
    friend LongInt operator % (const LongInt , const LongInt );
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
LongInt operator + (const LongInt A, const LongInt B){
  int i,j;
  LongInt ans;
  ans.length=Greater(A.length,B.length);
  for(i=0;i<ans.length;i++){
    ans.number[i]=A.number[i]+B.number[i]+ans.number[i];
    if(ans.number[i]>=10){
      ans.number[i+1]+=ans.number[i]/10;
      ans.number[i]%=10;
    }
  }
  if(ans.number[ans.length+1]!=0)ans.length++;
  return ans;
}

class fraction{
  private:
    int denominator;
    int molecule;
  public:
    void gets();
    void puts();
    void approximate();
    friend fraction operator + (const fraction ,const fraction );
    friend fraction operator - (const fraction ,const fraction );
    friend fraction operator * (const fraction ,const fraction );
    friend fraction operator / (const fraction ,const fraction );
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
  return ;
}

class HighPreNum{

};
