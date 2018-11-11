#include<cstdio>
#include<cstring>
#include<map>
#include<string>
#include<vector>
#include<algorithm>
#include<iostream>
using namespace std;

typedef struct node{
	int a,b;
	double dis;
}node; 
vector<node> v;
int visit[200]={0};

bool cmp(node a,node b){
	return a.dis < b.dis;
}

int main(){
	int len;
	scanf("%d",&len);
	int n;
	scanf("%d",&n);
	map<string,int> ma;
	for(int i=0;i<n;i++){
		string s;
		cin>>s;
		ma.insert(make_pair(s,i));
	} 
	int m;
	scanf("%d",&m);
	for(int i=0;i<m;i++){
		string a,b;
		double dis;
		cin>>a>>b>>dis;
		node temp;
		temp.a = ma[a];
		temp.b = ma[b];
		temp.dis = dis;
		v.push_back(temp);
	}
	sort(v.begin(),v.end(),cmp);
	double ans=0;
	for(int i=0;i<v.size();i++){
		if(visit[v[i].a]==0 || visit[v[i].b]==0){
			visit[v[i].a]=1;
			visit[v[i].b]=1;
			ans+=v[i].dis;
		}
	}
	printf("%.1lf\n",ans);
	return 0;
}
