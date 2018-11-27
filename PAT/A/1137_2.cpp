/*
网上编程至少获得200分 
期末考试至少60分（100分制）
按照公式计算最终得分 
*/ 
#include<stdio.h>
#include<iostream>
#include<string>
#include<map>
#include<vector>
#include<algorithm>
using namespace std;

typedef struct node{
	string id;
	int p, mid, final;
	int g;
}node;

bool cmp(node a, node b){
	if(a.g == b.g){
		return a.id < b.id;
	}
	return a.g > b.g;
}

int main(){
	int p, m, n;
	cin>>p>>m>>n;
	map<string, int> mp;
	vector<node> v;
	int count = 0;
	for(int i=0;i<p;i++){
		string id;
		int score;
		cin>>id>>score;
		if(score >= 200){
			count++;
			mp[id] = count;
			node temp;
			temp.id = id;
			temp.p = score;
			temp.mid = temp.final = temp.g = -1;
			v.push_back(temp);
		}
	}
	for(int i=0;i<m;i++){
		string id;
		int score;
		cin>>id>>score;
		if(mp[id]!=0){
			v[mp[id]-1].mid = score;
		}
	}
	for(int i=0;i<n;i++){
		string id;
		int score;
		cin>>id>>score;
		if(mp[id]!=0){
			v[mp[id]-1].final = score;
			v[mp[id]-1].g = v[mp[id]-1].mid > v[mp[id]-1].final ? 0.4*v[mp[id]-1].mid+0.6*v[mp[id]-1].final + 0.5 : v[mp[id]-1].final;
		}
	}
	sort(v.begin(), v.end(), cmp);
	for(int i=0;i<count && v[i].g >=60; i++){
		cout<<v[i].id<<" "<<v[i].p<<" "<<v[i].mid<<" "<<v[i].final<<" "<<v[i].g<<endl;
	}
	return 0;
} 
