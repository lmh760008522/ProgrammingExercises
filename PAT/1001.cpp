#include<iostream>
using namespace std;
#include<stdio.h>
#include<cmath> 
int main(){
	int n,count=0;
	scanf("%d",&n);
	while(n!=1){
		if(n%2==0){//Å¼Êý 
		n=n/2;
		}else{
		n=(3*n+1)/2;
		}
		count++;
	}
	printf("%d",count);
	return 0;
}
