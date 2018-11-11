#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;

typedef struct node{
	int time;//100
	int num;//5
}node;

bool cmp(node a,node b){
	return a.time>b.time;
}

int main(){
	int t;//10
	int n;//20
	int i,j,k;
	int sum=0,ans=0;
	node hw[20];
	int dp[101][2001];
	scanf("%d",&t);
	while( (t--) > 0){
		scanf("%d",&n);
		sum=0;
		ans=0;
		for(i=0;i<n;i++){
			scanf("%d %d",&hw[i].time,&hw[i].num);
		}
		sort(hw,hw+n,cmp);//从大到小排序 
		dp[0][0]=0;
		
		for(i=0;i<n;i++){
			for(j=0;j<hw[i].num;j++){
				sum+=hw[i].time;
				for(k=0;k<sum;k++){
					dp[i+1][j+1]=dp[i][j+1]+hw[i].time;
					if(j>=hw[i].time){
						dp[i+1][j+1]=min(dp[i+1][j+1],dp[i][j-hw[i].time]);
					}
				}
			}
		}
		ans=sum+1;
		for(i=1;i<=sum;i++){
			ans=min(ans,max(i,dp[n][i]));
		} 
		cout<<ans<<endl;
	}
	
	return 0;
}
