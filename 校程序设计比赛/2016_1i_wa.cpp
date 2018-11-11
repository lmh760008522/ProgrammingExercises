#include<cstdio>
int main(){
	int t;
	int s[2000005];
	scanf("%d",&t);
	while(t-- >0){
		int n;
		scanf("%d",&n);
		for(int i=0;i<n;i++){
			scanf("%d",&s[i]);
		}
		long long sum=0,maxsum=0;
		long long dp[2000005];
		for(int i=0;i<n;i++){
			if(s[i]<0){
				sum=0;
			}else{
				sum+=s[i];
				if(sum>maxsum){
					maxsum=sum;
				}
			}
		}
		
	}
	return 0;
} 
