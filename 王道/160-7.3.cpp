#include<cstdio>
//#include<algorithm>
#include<windows.h>
#include<stdlib.h>
using namespace std;
int max(int a, int b){
	return a>b?a:b;
}
int main(){
	int k;
	scanf("%d",&k);
	int a[30];
	int dp[30];
	for(int i=1;i<=k;i++){
		scanf("%d",&a[i]);
	}
	int max=0;
	for(int i=1;i<=k;i++){
		int tmax=1;
		for(int j=1;j<=k;j++){
			if(a[j]>=a[i]){
				tmax = max(dp[j]+1,tmax);
			}
		}
		dp[i]=tmax;
	}
	int ans=0;
	for(int i=1;i<=k;i++){
		ans = max(dp[i],ans);
	}
	printf("%d\n",ans);
	return 0;
}
