
#include<iostream>
using namespace std;
int main(){
	int a,b;
	scanf("%d %d",&a,&b);
	while( !(a==0 && b==0)){
		long long int temp=a,ans=1;
		while(b!=0){
			if(b&1){
				ans*=temp;
				//printf("%lld\n",ans);
				ans=ans%1000;
			}
			b=b>>1;
			temp*=temp;
			temp%=1000;
		}
		printf("%lld\n",ans);
		scanf("%d %d",&a,&b);
	}
	return 0;
} 
