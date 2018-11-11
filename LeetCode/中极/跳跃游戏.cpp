#include<cstdio>
using namespace std;
int main(){
	//int a[5]={2,3,1,1,4};
	int a[5]={3,2,1,0,4};
	int dp[5]={0};
	dp[0]=1;
	for(int i=0;i<4;i++){
		if(dp[i]==1){
			for(int j=1;j<=a[i];j++){
				dp[i+j]=1;
				printf("%d\n",i+j);
			}
		}
	}
	for(int i=0;i<5;i++){
		printf("%d ", dp[i]);
	}
	printf("    %d",dp[4]);
	return 0;
}
//Ì°ÐÄÑ°ÕÒÉÏ½ç  reach=max( reach, i+a[i]); 
