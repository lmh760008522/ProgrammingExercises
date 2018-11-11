#include<cstdio>
#define M 200907
int main(){
	int n;
	scanf("%d",&n);
	while(n-- >0){
		long long int a,b,c,k,ans=1;
		scanf("%lld %lld %lld %lld",&a,&b,&c,&k);
		if(b-a == c-b){//是等差数列 
			printf("%lld\n",a+(k-1)*(b-a));
			continue; 
		}else{
			long long temp=b/a;
			k=k-1;
			while(k>0){
				if(k&1){
					ans*=temp;
					ans%=M;
				}
				temp*=temp;
				temp%=M;
				k=k>>1;
			}
			printf("%lld\n",ans);
		}
	}
	return 0;
}
