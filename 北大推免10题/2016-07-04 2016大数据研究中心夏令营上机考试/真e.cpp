#include<cstdio>
#include<algorithm>
#include<string.h> 
using namespace std;

int main(){
	int n,m,w[12885],d[12885],dp[12885];
	while( scanf("%d %d",&n,&m) != EOF){
		for(int i=0;i<n;i++){
			scanf("%d %d", &w[i], &d[i]);
		}
		memset(dp,0,sizeof(dp));
		for(int i=0;i<n;i++){
			for(int j=m;j>=w[i];j--){
				dp[j] = max( dp[j], dp[j-w[i]]+d[i]);
			}
		}
		printf("%d\n",dp[m]);
	}
	return 0;
} 
