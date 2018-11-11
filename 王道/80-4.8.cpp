#include<cstdio>
#include<string.h>
using namespace std;
bool prime[50000];

void init(){
	memset(prime,true,sizeof(prime));
	prime[1]=false;
	for(int i=2;i<49999;i++){
		for(int j=i*2;j<49999;j+=i){
			prime[j]=false;
		}
	}
}
int main(){
	init();
	int n;
	int count=0;
	scanf("%d",&n);
	while(n!=1){
		//printf("n:%d ",n);
		for(int i=2; i<=n; i++){
			//printf("i:%d ",i);
			if(prime[i]==true && n%i==0){
				while(n%i==0){
					n=n/i;
					count++;
					//printf("%d ",i);
				}
				break;
			}else{
				continue;
			}
		}
		
	}
	printf("%d",count);
	return 0;
} 
