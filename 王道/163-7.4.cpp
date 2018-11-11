#include<cstdio>
#include<cstring> 
#include<windows.h>
int main(){
	char a[101],b[101];
	int dp[101][101];
	gets(a);
	gets(b);
	for(int i=0;i<strlen(a);i++){
		dp[i][0]=0;
	}
	for(int i=0;i<strlen(b);i++){
		dp[0][i]=0;
	}
	for(int i=0;i<strlen(a);i++){
		for(int j=0;j<strlen(b);j++){
			if(a[i]!=b[j]){
				dp[i][j] = dp[i][j-1] > dp[i-1][j] ? dp[i][j-1] : dp[i-1][j] ;
			}else{
				dp[i][j]=dp[i-1][j-1]+1;
			}
		}
	}
	printf("%d\n",dp[strlen(a)-1][strlen(b)-1]);
	return 0;
}
