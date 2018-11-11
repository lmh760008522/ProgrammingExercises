#include<cstdio>
#include<string.h>
#include<algorithm>
using namespace std;
bool cmp(const int a,const int b){
	return a>b;
}
//0-1 bag
int main(){
	//int n=3;
	//int amount =11;
	//int a[100]={1,2,5};
	int dp[1000];
	int n=1;
	int amount =3;
	int a[100]={2};
	sort(a,a+n,cmp);
	for(int i=0;i<=amount;i++){
		dp[i]=99999;
	}
	//memset(dp,99999,sizeof(dp));
	dp[0]=0;
	for(int i=1;i<=amount;i++){
		for(int j=0;j<n;j++){
			if(i>=a[j] && dp[i-a[j]]!=99999){
				dp[i]=min(dp[i],dp[i-a[j]]+1);
			}
		}
	}
	/*
	for(int i=0;i<=amount;i++){
		printf("%d ",dp[i]);
	}*/
	if(dp[amount]==99999){
		printf("-1");
	}else{
		printf("%d",dp[amount]);
	}
	return 0;
}
