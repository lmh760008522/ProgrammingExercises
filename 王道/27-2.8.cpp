#include<cstdio>
#include<algorithm>
#include<stdlib.h>
using namespace std;
int main(){
	int n;
	char a,b;
	scanf("%d %c %c",&n, &a, &b);
	bool flag;
	if((n+1)/2 %2== 0){//×îÍâ²ãÎªb 
		swap(a,b);
	} 
	for(int i=1;i<=(n+1)/2;i++){
		if(i==1){
			printf(" ");
			for(int j=1;j<n-1;j++){
				printf("%c",a);
			}
			printf(" \n");
		}else{
			char c;
			int k;
			for(k=0;k<i-1;k++){
				if(k%2==0){
					printf("%c",a);
				}else{
					printf("%c",b);
				}
			}
			
			if(i%2==0){
				c=b;
			}else{
				c=a;
			}
			for( ; k< n-i ;k++){
				printf("%c",c);
			} 
			
			for( ;k<n;k++){
				if(k%2==0){
					printf("%c",a);
				}else{
					printf("%c",b);
				}
			}
		printf("\n");
		}
	}
	
	return 0;
}
