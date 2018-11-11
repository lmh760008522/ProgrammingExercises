#include<iostream>
//代码写复杂了，当问题十分零散时，可以用整体的思想考虑 
using namespace std;
int main(){
	int a,b,c,d,e,f;
	cin>>a>>b>>c>>d>>e>>f;
	bool falg=true;
	count =0;
	while(flag){
		if (a==0 && b== 0 && c==0 && d==0 &&e==0 && f==0){
			falg=false;
		}
		count = f;
		
		count +=e;
		a > 11*e ? a=a-11*e : a=0;
		
		count+=d;
		if(5*d > b){
			a>5*d-b? a-=(5*d-b) : a=0;
		}
		b > 5*d ? b-=5*d : b=0;
		
		count+=e/4;
		e-=e/4;
		
		
		cin>>a>>b>>c>>d>>e>>f;
	}
	
	return 0;
} 
