#include<stdio.h>
#include<cmath>
#include<iostream>
using namespace std;

//特殊情况考虑 !!
int main(){
	int n,t,count1=2,count2=1,c=0,e=0;
	long int a=0,b=0;
	double d=0;
	scanf("%d ",&n);
	while(n>0){
		cin>>t;
		if(t%5==0){
			if(t%2==0){
				a+=t;
			}
		}else if(t%5==1){
			b+=pow(-1,count1)*t;
			count1++;
		}else if(t%5==2){
			c++;
		}else if(t%5==3){
			d+=t;
			count2++;
		}else{
			if(e<t){
				e=t;
			}
		}
		n--;
	}
	
	if(count2!=1){
		d=d/(count2-1);
	}
	
	if(a==0){
		printf("N ");
	}else{
		printf("%ld ",a);
	}
	if(b==0&&count1==2){//A2也有可能相加后为0！！ 
		printf("N ");
	}else{
		printf("%ld ",b);
	}
	if(c==0){
		printf("N ");
	}else{
		printf("%d ",c);
	}
	if(d==0){
		printf("N ");
	}else{
		printf("%.1lf ",d);
	}
	if(e==0){
		printf("N");
	}else{
		printf("%d",e);
	}
	return 0;
} 
