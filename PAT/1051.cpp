/*
1.用到三角函数sin(),cos();
2.if(-0.005<a&&a<0) cout<<"0.00"; //没有负号，不应该是-0.00，注意控制；
3.用double类型，不要用float，不准确，不会ac；
4.尽量不要写中间变量，直接带入最终式，这样减少误差；
5. 复数表示形式转换：a=rcos(p), b=rsin(p) 
*/ 
#include<stdio.h>
#include<math.h>
int main(){
	double r1,p1,r2,p2;
	double a,b,a1,b1,a2,b2;
	scanf("%lf %lf %lf %lf",&r1,&p1,&r2,&p2);
	/* 
	a1=r1*cos(p1);
	b1=r1*sin(p1);
	a2=r2*cos(p2);
	b2=r2*sin(p2);
	a=r1*r2-p1*p2;
	b=r1*p2+r2*p1;
	*/
	a=(r1*r2)*cos(p1+p2);
	b=(r1*r2)*sin(p1+p2); 
	//printf("%lf %lf\n",a,b);
	if(a!=0&&b>0){
		printf("%.2lf+%.2lfi",a,b);
	}else if(a!=0&&b<0){
		printf("%.2lf-%.2lfi",a,fabs(b));
	}else if(a!=0&&b==0){
		printf("%.2lf",b);
	}else if(a==0&&b>0){
		printf("%.2lf+%.2lfi",a,b);
	}else if(a==0&&b<0){
		printf("%.2lf-%.2lfi",a,abs(b));
	}else if(a==0&&b==0){
		printf("0.00");
	}
	
	return 0;
}

/*
#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;
int main(){
	double r1,p1,r2,p2;
	double a,b;
	cin>>r1>>p1>>r2>>p2;
	a=(r1*r2)*cos(p1+p2);
	b=(r1*r2)*sin(p1+p2);
	//cout<<fixed<<setprecision(2)<<"a="<<a<<" "<<"b="<<b;            
	if(-0.005<a&&a<0){
		cout<<"0.00";
	}else{
		cout<<fixed<<setprecision(2)<<a;
	}
	if(b>=0){
		cout<<fixed<<setprecision(2)<<"+"<<b<<"i";
	}else if(-0.005<b&&b<0){
		cout<<"+0.00i";
	}else{
		cout<<fixed<<setprecision(2)<<b<<"i";
	}	

	return 0;
}
*/ 
/*
#include<bits/stdc++.h>
#include<cmath> 
using namespace std;
int main(){
    double r1,r2,p1,p2,a,b;
    cin>>r1>>p1>>r2>>p2;
    a=r1*r2*cos(p1+p2);               //注意这步 
    b=r1*r2*sin(p1+p2);
    int aa=1,bb=1;
    if(fabs(a)<0.01) aa=0;				//注意这步
    if(fabs(b)<0.01) bb=0;				//注意这步
    if(aa==0&&bb==0)
    cout<<0<<endl;
    if(aa==0&&bb!=0)                  //从这开始好像不太对 
    printf("0.00%+.2fi",b);
    else if(aa!=0&&bb==0)
    printf("%.2f+0.00i",a);
    else
    printf("%.2f%+.2fi",a,b);
    return 0;
}
*/
