/*
���ܶ�Ȧ ������ͼ�����еĽڵ��Ȧ 
����һ������ͼ���жϸ���Ȧ�Ƿ��ǹ��ܶ�Ȧ�� 
*/ 
#include<iostream>
#include<map>
using namespace std;
int main(){
	int n, m;
	cin>>n>>m;
	int e[205][205];
	for(int i=0;i<m;i++){
		int a,b;
		cin>>a>>b;
		e[a][b] = e[b][a] = 1;
	}
	int k;
	cin>>k;
	for(int i=0;i<k;i++){
		int q;
		cin>>q;
		bool flag = true;
		if(q != n+1) flag = false; //ÿ��������һ�����ջص��ص�ֻ����N+1���� 
		int sst;
		cin>>sst;
		map<int ,int> mp;
		int st,en;
		st = sst;
		for(int j=1;j<q;j++){
			cin>>en;
			if(en < 1 || en >n) flag = false; //����Ų��ڷ�Χ�� 
			mp[en]++;
			if(mp[en]>1) flag = false;  //������⣬ÿ��������ֻ�ܳ���һ�� 
			if(e[st][en] == 0) flag = false; //�������߲����� 
			st = en;
		}
		if(en != sst) flag = false; //����㲻�����ص� 
		flag ? cout<<"YES"<<endl : cout<<"NO"<<endl ;
	} 
	return 0;
} 

