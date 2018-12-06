/*
��̬�滮 :����½�������
����һ������A����һ������B��
����A�е�����ֻ����B�е����ֵ�����ַ�����������½����ַ����� 
�����Ψһ��ֻ�������ĳ��ȡ�
�������A= {2 2 4 1 5 5 6 3 1 1 5 6},B= {2 3 1 5 6},
�ҳ�����ַ���Ϊ {2 2 1 1 1 5 6}, {2 2 1 5 5 5 6}, {2 2 1 5 5 6 6},��{2 2 3 1 1 5 6}��
��˴�Ϊ7��  
*/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
	int n, m, x;
	cin>>n>>m; //n<=200,��ɫ��Ŵ�1...n 
	vector<int> fav(n+1); 
	bool visit[205];
	for(int i=1;i<=m;i++){
		cin>>x;
		fav[x] = i; //������ 
		visit[x] = true;
	} 
	int l; // l<= 10^4
	cin>>l;
	vector<int> v(l+1);
	int num = 0;
	for(int i=0;i<l;i++){
		cin>>x;
		if(visit[x] == true){ //�޳���ϲ���� 
			v[num++] = fav[x];
		}
	}
	
	//��������½������� 
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
