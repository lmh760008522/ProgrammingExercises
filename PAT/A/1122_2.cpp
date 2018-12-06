/*
哈密顿圈 ：经过图中所有的节点的圈 
给出一个无向图，判断给的圈是否是哈密顿圈。 
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
		if(q != n+1) flag = false; //每个都遍历一遍最终回到重点只能是N+1个点 
		int sst;
		cin>>sst;
		map<int ,int> mp;
		int st,en;
		st = sst;
		for(int j=1;j<q;j++){
			cin>>en;
			if(en < 1 || en >n) flag = false; //结点编号不在范围内 
			mp[en]++;
			if(mp[en]>1) flag = false;  //初起点外，每个点有且只能出现一次 
			if(e[st][en] == 0) flag = false; //若这条边不存在 
			st = en;
		}
		if(en != sst) flag = false; //若起点不等于重点 
		flag ? cout<<"YES"<<endl : cout<<"NO"<<endl ;
	} 
	return 0;
} 

