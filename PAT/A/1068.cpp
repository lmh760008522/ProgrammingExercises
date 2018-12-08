/*
01��������̬�滮
��n��Ӳ�����ֵΪm�Ķ��������ʹ�÷�����ʹ�����ü���Ӳ�Ҽ�������ֵΪm����С�������У������С���Ǹ����з���
�������ˣ�˵�õ�����С�ڵ���10^4����10005�������жδ��󣬸ĳ�10010��û���ˣ����� 
���Ե�3�����󡣽������õ�main�� 
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
	int n, m; //Ӳ������<=10^4 ����Ҫ����Ǯ <=100
	cin>>n>>m;
	
	for(int i=1;i<=n;i++){
		cin>>w[i];
	} 
	
	//��Ӳ�ҴӴ�С���� 
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
