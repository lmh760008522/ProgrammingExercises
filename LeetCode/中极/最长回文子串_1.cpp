#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

int main(){
	char s[101];
	gets(s);
	int dp[101][101]={0};
	for(int i=0;i<strlen(s);i++){
		dp[i][i]=1;
	}
	for(int i=1;i<strlen(s);i++){
		if(s[i]==s[i-1]){
			dp[i-1][i]=2;
		}
	}
	for(int i=3;i<=strlen(s);i++){
		for(int j=0;j+i-1<strlen(s);j++){
			if(s[j]==s[j+i-1] && dp[j+1][j+i-2]){
				dp[j][j+i-1]=dp[j-1][j+i-2]+2;
			}
		}
	}
	printf("%d\n",dp[0][strlen(s)-1]);
	return 0;
}
