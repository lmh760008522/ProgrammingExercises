#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int dis[501];
vector<int> sec,temppath,pre[501];
bool visit[501];
int e[501][501];
int n,m,c1,c2;
int minsum=9999999;
int maxsum=0;
int c =0;

void dfs(int v){
	temppath.push_back(v);
	if(v == c2){
		c++;
		int sum=0;
		for(int i=0;i<temppath.size();i++){
			sum+=sec[i];
		}
		if(sum>maxsum){
			maxsum=sum;
		}
		temppath.pop_back();
		return ;
	}
	for(int i=0;i<pre[v].size();i++){
		dfs(pre[v][i]);
	}
	temppath.pop_back();
}
int main(){
	cin>>n>>m>>c1>>c2;
	sec.resize(n);
	fill(e[0],e[0]+501*501,-1);
	fill(dis,dis+501,9999999);
	for(int i=0;i<n;i++){
		cin>>sec[i];
	}
	for(int i=0;i<m;i++){
		int a,b,l;
		cin>>a>>b>>l;
		e[a][b]=e[b][a]=l;
	}
	cout<<"hh"; 
	pre[c1].push_back(c1);
	dis[c1] = 0;
	for(int i=0;i<n;i++){
		int u=-1,minn=9999999;
		for(int j=0;j<n;j++){
			if(dis[j]<minn && visit[j]==false){
				u=j;
				minn=dis[j];
			}	
		}
		if(u==-1) break;
		visit[u]=true;
		for(int v=0;v<n;v++){
			if(e[u][v]!=-1 && visit[v]==false){
				if(dis[v]>dis[u]+e[u][v]){
					dis[v]=dis[u]+e[u][v];
					pre[v].clear();
					pre[v].push_back(u);
				}else if(dis[v]==dis[u]+e[u][v]){
					pre[v].push_back(u);
				}
			}
		}
	} 
	
	dfs(c1);
	cout<<c<<" "<<maxsum;
	return 0;
} 
