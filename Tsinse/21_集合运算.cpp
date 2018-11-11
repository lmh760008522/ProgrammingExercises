#include<stdio.h>
#include <string.h>
#include<iostream>
using namespace std;
int main(){
	int num_a,num_b,ta=0,tb=0,i=0,j=0;
	string a,b;
	const char *c=" ,*";
	char n[1000],u[1000];
	scanf("%d",&num_a);
	cin>>a;
	scanf("%d",&num_b);
	cin>>b;
	
	a=strtok(&a,c);
	b=strtok(b,*c);
	 
	ta=0;
	tb=0;
	while(ta<num_a&&tb<num_b){
		if(a[ta]<b[tb]){
			u[i]=a[ta];
			ta++;
			i++;
		}else if(a[ta]>b[tb]){
			u[i]=b[tb];
			tb++;
			i++;
		} else{
			n[j]=a[ta];
			j++;
			ta++;
			tb++;
		}
	}
	if(ta<num_a){
		for(;ta<num_a;i++,ta++){
			u[i]=a[ta];
		}
	}
	if(tb<num_b){
		for(;tb<num_b;i++,tb++){
			u[i]=a[ta];
		}
	}
	
	cout<<u<<'\n'<<n<<endl;
	return 0;
} 
