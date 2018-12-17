// 0-1背包问题拓展 
/* 
背包容量为m,物品的体积为w价值为v ,要求背包可以撞下价值尽可能多的物品，求最大价值，
背包**必须**被装满，每种物品只有一个 
*/ 
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
#define MAX 6
#define VEC 22

int main(){
	int w[MAX] = {1,2,3,4,5,6};
	int v[MAX] = {3,4,2,5,1,3};
	int dp[VEC+1];
	 
	fill (dp, dp+VEC+1, -1); //初始值为-1
	dp[0] = 0;
	 
	for(int i = 0; i < MAX; i++ ){
		for(int j = VEC; j >= w[i]; j--){ //对于每一个总重，都要计算一下选不选物品i 
			if( dp[j-w[i]] != -1 || dp[j] != -1){
				dp[j] = max(dp[j-w[i]]+v[i], dp[j]);
			} 
		}
	} 
	cout<<dp[7]; //答案为12，即选择重量为1，2，4的物品
	cout<<endl<<dp[VEC]; //答案为-1， 不存在 
	
	return 0;
}
