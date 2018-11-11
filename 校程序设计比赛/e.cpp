#include<cstdio>
#include<algorithm>
#include<iostream>
using namespace std;
int main(){
	int n,m;
	char a[100],b[100];
	int dp[100][100];
	int i,j;
	
	scanf("%d %d\n",&n,&m);
	gets(a);
	gets(b);
	
	for(int i=0;i<=n;i++){
		dp[i][0]=0;
	}
	for(int j=0;j<=m;j++){
		dp[0][j]=0;
	}
	for(i=1;i<=n;i++){
		for(j=1;j<=m;j++){
			if(a[i-1]==b[j-1]){
				dp[i][j]=dp[i-1][j-1]+1;
			}else{
				dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
			}
		}	
	}
	printf("%d\n",(m-dp[n][m])+(n-dp[n][m]));
	return 0;
}
