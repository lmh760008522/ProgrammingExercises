/*
01背包，动态规划
用n个硬币买价值为m的东西，输出使用方案，使得正好几个硬币加起来价值为m。从小到大排列，输出最小的那个排列方案
纳了闷了，说好的数据小于等于10^4，开10005的数组有段错误，改成10010就没有了？？？ 
测试点3：错误。将数组拿到main外 
*/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int w[10010], dp[10010];
bool choice[10010][110];

bool cmp(int a,int b){
	return a>b;
}

int main(){
	int n, m; //硬币总数<=10^4 、需要付的钱 <=100
	cin>>n>>m;
	
	for(int i=1;i<=n;i++){
		cin>>w[i];
	} 
	
	//将硬币从大到小排序 
	sort(w+1, w+n+1,cmp);
	
	for(int i = 1;i <= n; i++){
		for(int j = m; j >= w[i]; j--){
			if(dp[j] <= dp[j-w[i]] + w[i]){
				choice[i][j] = true;
				dp[j] = dp[j-w[i]] + w[i];
			}
		}
	}
	if(dp[m] != m) cout<<"No Solution";
	else{
		vector<int> ans;
		int v = m, index = n;
		while(v>0){
			if(choice[index][v] == true){
				ans.push_back(w[index]);
				v -= w[index];
			}
			index--;
		}
		for(int i=0; i < ans.size(); i++){
			if( i != 0) cout<<" ";
			cout<<ans[i];
		}
	}
	return 0;
}
