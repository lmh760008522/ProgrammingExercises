#include<cstdio>
int main(){
	int n;
	int n25,n5;
	scanf("%d",&n);
	n5=n/5;
	n25=n/25;
	printf("%d",n5+n25);
	
	/*
	int rvl=0;
	while(n>0){
		rvl+=n/5;
		n=n/5;
	}
	printf("  %d",rvl);*/
	return 0;
} 
