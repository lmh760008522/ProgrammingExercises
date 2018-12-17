// 多重背包问题
/* 
与01背包的不同：每个物品有k件
解决方法，将k件物品进行拆分成，1,2,4,...件物品的和，组成新的物品
为啥这样拆分? 因为所有数字都可以用二进制表示，也就可以用a_1*2^0+a_2*2^1...表示
拆分后转化成01背包问题即可 
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
	int k[MAX] = {1,2,7,31,12,14}; //每件物品的数量 
	int dp[VEC+1] = {0}; //初始值为0 
	
	/*新增代码片*/  
	vector<int> ww,vv; //新的体积和价值 
	for(int i=0;i<MAX;i++){
		int c = 1;
		while(k[i] - c > 0){
			k[i] -= c;
			ww.push_back(c*w[i]);
			vv.push_back(c*v[i]);
			c *= 2;
		}
	} 
	/*新增代码片*/
	
	for(int i = 0; i < ww.size(); i++ ){
		for(int j = VEC; j >= ww[i]; j--){ //对于每一个总重，都要计算一下选不选物品i 
			dp[j] = max(dp[j-ww[i]]+vv[i], dp[j]); 
		}
	} 
	cout<<dp[VEC]; //答案为29 
	
	return 0;
}
