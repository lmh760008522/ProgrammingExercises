#include<cstdio>
#define INF 99999999
int main(){
	int t;
	scanf("%d",&t);
	while(t-- >0){
		int n;
		scanf("%d",&n);
		int a[105];
		int sum=0; 
		for(int i=1;i<=n;i++){
			scanf("%d",&a[i]);
			sum+=a[i];
		}
		int dp[105][4005];
		for(int i=0;i<=n;i++){//重量为0 
			dp[i][2000]=0;
		}
		for(int i=1;i<=n;i++){//重量为0 
			dp[i][2000]=0;
		}
		for(int i=2000-sum;i<=2000+sum;i++){//一件物品都不选 
			dp[0][i]=-INF;
		}
		for(int i=1;i<=n;i++){
			for(int j=2000-sum;j<=2000+sum;j++){
				//dp[i][j]=
			}
		}
		
	}
	return 0;
} 
