#include<cstdio>
#include<string.h>
using namespace std;
int main(){
	int n;
	int a[103];
	int dp[103];
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	int tempmax;
	for(int i=2;i<=n-1;i++){//·Ö½çÏß 
		memset(dp,0,sizeof(dp));
		for(int j=1;j<=i;j++){
			int temp=1;
			for(int k=1;k<=i;k++){
				if(a[k]>=a[j]){
					temp=temp>(dp[k]+1)?temp:(dp[k]+1);
				}
			}
		}
		int ans1=0;
		for(int p=1;p<=i;p++){
			ans1=ans1>dp[p]?ans1:dp[p];
		}
		for(int j=i;j<=n;j++){
			int temp=1;
			for(int k=i;k<=n;k++){
				if(a[k]<=a[j]){
					temp=temp>(dp[k]+1)?temp:(dp[k]+1);
				}
			}
		}
		int ans2=0;
		for(int p=i;p<=n;p++){
			ans2=ans2>dp[p]?ans2:dp[p];
		}
		tempmax=tempmax>(ans1+ans2)?tempmax:(ans1+ans2);
	}
	printf("%d\n",tempmax);
	return 0;
} 
