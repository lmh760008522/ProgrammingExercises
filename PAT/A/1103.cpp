#include<iostream>
#include<vector>
#include<cmath>
//可以看作一个完全背包问题？？而不是一个树？？ 
using namespace std;
int main(){
	int n,k,p;//n<=400  k<=n   1<p<=7
	cin>>n>>k>>p;
	vector<int> v;
	vector<int> dp;
	dp.resize(n+1); 
	for(int i=floor( sqrt(n) ); i>=1;i--){
		v.push_back(pow(i,p));
	}
	for(int i=0;i<=n;i++){
		dp[i]=0;
	}
	for(int i=1;i<=n;i++){
		for(int j=n;j>=v[i];j--){
			if(dp[j-v[i]]!=-1){
				dp[j]=max(dp[j],dp[j-v[i]]+v[i]);
			}
		}
	}
	if(dp[n]!=-1){
		printf("%d",dp[n]);
	}
	return 0;
} 
