/*
动态规划 :最长不下降子序列
给出一串数字A，和一串数字B；
想让A中的数字只能是B中的数字的最长子字符串。找最长不下降子字符串。 
结果不唯一，只需输出最长的长度。
例如给出A= {2 2 4 1 5 5 6 3 1 1 5 6},B= {2 3 1 5 6},
找出的最长字符串为 {2 2 1 1 1 5 6}, {2 2 1 5 5 5 6}, {2 2 1 5 5 6 6},和{2 2 3 1 1 5 6}。
因此答案为7。  
*/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
	int n, m, x;
	cin>>n>>m; //n<=200,颜色编号从1...n 
	vector<int> fav(n+1); 
	bool visit[205];
	for(int i=1;i<=m;i++){
		cin>>x;
		fav[x] = i; //存入编号 
		visit[x] = true;
	} 
	int l; // l<= 10^4
	cin>>l;
	vector<int> v(l+1);
	int num = 0;
	for(int i=0;i<l;i++){
		cin>>x;
		if(visit[x] == true){ //剔除不喜欢的 
			v[num++] = fav[x];
		}
	}
	
	//按照最长不下降子序列 
	int dp[10005];
	int ans = 0;
	for(int i = 0; i < num; i++){
		dp[i] = 1;
		for(int j = 0; j < i; j++){
			if(v[i] >= v[j]){
				dp[i] = max(dp[i], dp[j]+1);
			}
		}
		ans = max(dp[i], ans);
	}
	
	cout<<ans;
	
	return 0;
} 
