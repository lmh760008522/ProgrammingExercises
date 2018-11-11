#include<stdio.h>
#include<iostream>
using namespace std;

int main(){
	int n,i=0;
	long int a,b,c;  //2µÄ32´Î·½ 
	bool aa[10]={false};	
	cin>>n;
	while(n>0){
		scanf("%ld %ld %ld",&a,&b,&c);
		if(a+b>c){
			aa[i]=true;
		}
		i++;
		n--;
	}
	n=i;
	for(i=0;i<n;i++){
		printf("Case #%d: ",i+1);
		if(aa[i]==1){
			printf("true\n");
		}else{
			printf("false\n");
		}
	}
	return 0;
} 
