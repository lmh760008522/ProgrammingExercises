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
	while(n!=0){
		count=0;
		for(int i=n-2;i>=n/2;i--){
			if(prime[i]==true && prime[n-i]==true){
				count++;
			}
		}
		printf("%d\n",count);
		scanf("%d",&n);
	}
	return 0;
} 
