#include<cstdio>
#define M 9973
long mi(int d,int k){
	long long ans=1;
	long temp=d;
	while(k>0){
		if(k&1){
			ans*=temp;
			ans%=M;
		}
		temp*=temp;
		temp%=M;
		k=k>>1;
	}
	return ans;
}
int main(){
	int t;
	scanf("%d",&t);
	while(t-- >0){
		int n,k;
		scanf("%d %d",&n,&k);
		long long ans=0;
		int temp;
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				scanf("%d",&temp);
				if(i==j){
					ans+=mi(temp,k);
					ans%=M;
				}
			}
			//scanf("\n");
		}
		printf("%d\n",ans);
	}
	return 0;
}
