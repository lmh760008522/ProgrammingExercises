#include<stdio.h>
#include<string.h>
char str[1010];
int dp[1010][1010];
int main(){
	int ans=1;
	int i;
	gets(str);
	
	//≥ı ºªØ 
	memset(dp,0,sizeof(dp));
	for(i=0;i<strlen(str)-1;i++){
		dp[i][i]=1;
		if(str[i]==str[i+1]){
			dp[i][i+1]=1;
			ans=2;
		}
	}
	dp[i][i]=1;
	
	for(i=2;i<=strlen(str)-1;i++){
		//printf("i=%d",i);
		for(int j = 0;j<=strlen(str)-1-i;j++){
			if(str[j]==str[j+i]){
				dp[j][j+i]=dp[j+1][j+i-1];
				if(dp[j][j+i]==1){
					//printf("[%d,%d]\n",j,j+i);
					ans=i+1;
				}
			}
		}
	}
	
	printf("%d",ans);
	return 0;
}
