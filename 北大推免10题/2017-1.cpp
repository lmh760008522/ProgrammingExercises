#include<cstdio>
#include<cmath>
int prime[100001];
void pre(){
	prime[1]=0;
	prime[2]=1;
	prime[3]=1;
	for(int i=4;i<=100000;i++){
		int j;
		for(j=2;j<=sqrt(i);j++){
			if(i%j==0){
				break;
			}
		}
		if(j>sqrt(i)){
			prime[i]=1;
		}
	}
}
int main(){
	int a,b;
	scanf("%d %d",&a,&b);
	pre();
	int ans=0;
	for(int i=a;i<=b;i++){
		if(prime[i]==1){
			ans++;
		}
	}
	printf("%d\n",ans);
	return 0;
} 
