//Coded by dst
#include<algorithm>
#include<iostream>
#include<cstdio>
#include<map>
using namespace std;
struct Formula{//y=mx+b
	double m,b;
};
struct Line{
	double l,r;
	int ml,mr;//ml:l after mapping
}a[100005];
struct Map{
	double d;
	int p;
	bool b;//0:l 1:r
}m[200005];
int n,num_m,c[200005],s,max_s,p_max;
double dabs(double);
Formula make_formula(double,double,double,double);
Line make_line(double,double,double,double);
bool cmp(Map,Map);
int main(){
	freopen("intersect.in","r",stdin);
	freopen("intersect.out","w",stdout);
	int i;
	long long xa,ya,xb,yb;
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		scanf("%lld%lld%lld%lld",&xa,&ya,&xb,&yb);
		a[i]=make_line(xa,ya,xb,yb);
		m[++num_m].d=a[i].l;
		m[num_m].p=i;
		m[++num_m].d=a[i].r;
		m[num_m].p=i;
		m[num_m].b=1;
	}
	sort(m+1,m+num_m+1,cmp);
	for(i=1;i<=num_m;i++)
		if(m[i].b)
			a[m[i].p].mr=i;
		else
			a[m[i].p].ml=i;
	for(i=1;i<=n;i++){
		c[a[i].ml]++;
		c[a[i].mr+1]--;
	}
	for(i=1;i<=num_m;i++){
		s+=c[i];
		if(m[i].d!=0&&(max_s<s||max_s==s&&dabs(m[i].d)>dabs(m[p_max].d)||max_s==s&&dabs(m[i].d)==dabs(m[p_max].d)&&m[i].d<m[p_max].d))
			max_s=s,p_max=i;
	}
	printf("%.2lf\n",m[p_max].d);
	return 0;
}
double dabs(double x){
	return x<0?-x:x; 
}
Formula make_formula(double xa,double ya,double xb,double yb){
	double m,b;
	m=(ya-yb)/(xa-xb);
	b=ya-m*xa;
	return (Formula){m,b};
}
Line make_line(double xa,double ya,double xb,double yb){
	if(xa==0&&xb==0||ya==0&&yb==0)//�߶����������غ� 
		return (Line){0,0,0,0};
	Formula tmp;
	Line line1,line2,line3;
	line1.l=line2.l=line3.l=1e12;
	line1.r=line2.r=line3.r=-1e12;
	double l,r;
	if(xa*xb<0||ya*yb<0){//�߶ο����� 
		if(xa==xb){//��������x=.. 
			line1=make_line(xa,ya,xa,0);
			line2=make_line(xb,yb,xb,0);
			l=min(line1.l,line2.l);
			r=max(line1.r,line2.r);
		}
		else if(ya==yb){//��������y=..
			line1=make_line(0,ya,xa,ya);
			line2=make_line(0,yb,xb,yb);
			l=min(line1.l,line2.l);
			r=max(line1.r,line2.r);
		}
		else{//һ�κ��� 
			double x,y;
			tmp=make_formula(xa,ya,xb,yb);
			y=tmp.b;
			x=-tmp.b/tmp.m;
			if(min(ya,yb)<y&&y<max(ya,yb)){//�߶ο�y�� 
				//��ֳ���������y����߶� 
				line1=make_line(0,y,xa,ya);
				line2=make_line(0,y,xb,yb);
				l=min(line1.l,line2.l);
				r=max(line1.r,line2.r);
			}
			else{//�߶ο�x�ᣬ�Ҳ���y�� 
				//��ֳ������������޵��߶� 
				line1=make_line(x,0,xa,ya);
				line2=make_line(x,0,xb,yb);
				l=min(line1.l,line2.l);
				r=max(line1.r,line2.r);
			}
		} 
		return (Line){l,r,0,0};
	}
	
	//�߶β������� 
	bool changed=0;
	if(xa>=0&&ya<=0&&xb>=0&&yb<=0||xa<=0&&ya>=0&&xb<=0&&yb>=0)//�߶��ڶ���������
		xa=-xa,xb=-xb,changed=1;//���߶���y�ᷭ�ۣ�ת��Ϊһ�������� 
	
	//�߶���һ�������� 
	//��l 
	if(xa==0||ya==0||xb==0||yb==0)//�߶ξ���������
		l=0;
	else//�߶β�����������
		l=min(xa*ya,xb*yb); 
	
	//��r 
	if(xa==xb||ya==yb)//�߶���������ƽ�У��߶�����ֱ��Ϊ�������� 
		r=max(xa*ya,xb*yb);
	else{ //�߶�����ֱ��Ϊһ�κ��� 
		double xi,ki;//xi:x of intersect
		tmp=make_formula(xa,ya,xb,yb);
		if(tmp.m>0)
			r=max(xa*ya,xb*yb);
		else{
			ki=-0.25*tmp.b*tmp.b/tmp.m;
			xi=-0.5*tmp.b/tmp.m;
			if(min(xa,xb)<=xi&&xi<=max(xa,xb))//�������߶���
				r=ki;
			else//�������߶��ӳ����� 
				r=max(xa*ya,xb*yb);	
		}
	}
	return changed?(Line){-r,-l,0,0}:(Line){l,r,0,0};
}
bool cmp(Map a,Map b){
	if(a.d!=b.d)
		return a.d<b.d;
	return a.b<b.b;//��˵����� 
}
