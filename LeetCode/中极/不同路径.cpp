#include<cstdio>
#include<string.h>
int main(){
	int m,n;
	scanf("%d %d",&m,&n);
	//C(M+N,N);数量小 ，否则要公式
	//数量大 ：dp
	long long int dp[105][105];
	memset(dp,0,sizeof(dp)); 
	dp[0][0]=1;
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			if(i==0 && j!=0){
				dp[i][j]=dp[i][j-1];
			}else if(j==0 && i!=0){
				dp[i][j]=dp[i-1][j];
			}else if( i!=0 && j!=0){
				dp[i][j]=dp[i-1][j]+dp[i][j-1];
			}	
		}
	}
	printf("%I64d ",dp[m-1][n-1]);
	return 0;
} 
