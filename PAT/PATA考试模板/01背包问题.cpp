// 0-1背包问题
/* 
背包容量为m,物品的体积为w价值为v ,要求背包可以撞下价值尽可能多的物品，求最大价值，
背包可不被装满，每种物品只有一个
每种物品两种情况：存在和不存在 
逆序更新的原因 ：在更新 dp[j]时保证 dp[j-w[i]] 是没有放入物品i时候的数据 
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
	int dp[VEC+1] = {0}; //初始值为0 
	
	for(int i = 0; i < MAX; i++ ){
		for(int j = VEC; j >= w[i]; j--){ //对于每一个总重，都要计算一下选不选物品i 
			dp[j] = max(dp[j-w[i]]+v[i], dp[j]); 
		}
	} 
	cout<<dp[VEC]; //答案为18，即选择所有的物品，背包不可被装满，最大 
	
	return 0;
}
