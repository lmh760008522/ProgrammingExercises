//最长上升子序列 :打印长度以及任意一个最长的序列 
#include<iostream>
#include<vector>
#define MAX 9
using namespace std;

int main(){
	int a[MAX] = {8,9,3,2,4,5,7,10,1};
	int dp[MAX];
	int lj[MAX]; //记录路径 
	fill(lj, lj+MAX, -1); 
	
	dp[0] = 1;
	for(int i = 2; i < MAX; i++){
		int temp = 0;
		for(int j = 1; j < i; j++){
			if(a[i] > a[j]){
				if(temp < dp[j]){
					temp = dp[j];
					lj[i] = j;
				}
			}
		}
		dp[i] = temp + 1;
	}
	
	//寻找最长中的最长 
	int max = 0, end = 0;
	for(int i = 0; i < MAX; i++){
		if(max < dp[i]){
			max = dp[i];
			end = i;
		}
	} 
	cout<<max<<" "<<end<<endl;

	//从后往前推路径 
	vector<int> ans;
	ans.push_back(a[end]);
	while(lj[end] != -1){
		end = lj[end];
		ans.push_back(a[end]);
	} 
	for(int i = ans.size()-1; i>=0 ;i--){
		cout<<ans[i]<<" "; 
	}
	
	return 0;
} 
