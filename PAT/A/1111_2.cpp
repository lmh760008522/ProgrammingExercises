/*
给出起点和终点，找出最短路和最快路 
一个求最短路径（如果相同求时间最短的那条），一个求最快路径（如果相同求结点数最小的那条）
*/ 
#include<iostream>
#include<cstdio>
#include<vector>
#define inf 99999999
using namespace std;

int n, m;
int cost[505][505],time0[505][505];
int dis[505];
bool visit[505];
vector<int> temppath,path, pathcopy;
vector<int> pre[510];
int minnode, mintime;
int s,d; 

void dfscost(int v){
	//cout<<v<<" ";
	temppath.push_back(v);
	if(v == s){
		int tempcost = 0;
		for(int i=temppath.size()-1; i>0; i--){
			int id = temppath[i], nextid = temppath[i-1];
			tempcost += time0[id][nextid];
		}
		if(tempcost < mintime){
			mintime = tempcost;
			path = temppath;
		}
		temppath.pop_back();
		return;
	}
	for(int i = 0;i<pre[v].size();i++){
		dfscost(pre[v][i]);
	}
	temppath.pop_back();
}

void dfstime(int v){
	temppath.push_back(v);
	if(v==s){
		if(temppath.size() < minnode){
			minnode = temppath.size();
			path = temppath;
		}
		temppath.pop_back();
		return ;
	}
	for(int i=0;i<pre[v].size();i++){
		dfstime(pre[v][i]);
	}
	temppath.pop_back();
}

int main(){
	
	cin>>n>>m;
	
	fill(cost[0],cost[0]+505*505,inf);
	fill(time0[0],time0[0]+505*505,inf);
	fill(dis, dis+505, inf);
	
	for(int i=0;i<m;i++){
		int u,v, flag, l,t;
		cin>>u>>v>>flag>>l>>t;
		cost[u][v] = l;
		time0[u][v] = t;
		if(flag == 0){
			cost[v][u] = l;
			time0[v][u] = t;
		}
	}	
	cin>>s>>d;
	
	pre[s].push_back(s);
	dis[s] = 0;
	for(int i=0;i<n;i++){
		int u = -1 , minn = inf;
		for(int j=0;j<n;j++){
			if(visit[j] == false && dis[j] < minn ){
				u = j;
				minn = dis[j];
			}
		}
		if(u == -1) break;
		visit[u] = true;
		for(int v = 0;v<n;v++){
			if(visit[v] == false && cost[u][v]!=inf){
				if(dis[v] > dis[u] + cost[u][v]){
					dis[v] = dis[u]+cost[u][v];
					pre[v].clear();
					pre[v].push_back(u);
				}else if(dis[v] == dis[u] + cost[u][v]){
					pre[v].push_back(u);
				}
			}
		}
	}
	mintime = inf;
	dfscost(d); 
	pathcopy = path;
	int disans = dis[d];
	
	fill(dis, dis+505, inf);
	fill(visit, visit+505, false);
	for(int i=0;i<510;i++){
		pre[i].clear();
	}
	temppath.clear();
	path.clear();
	pre[s].push_back(s);
	dis[s] = 0;
	for(int i=0;i<n;i++){
		int u = -1 , minn = inf;
		for(int j=0;j<n;j++){
			if(visit[j] == false && dis[j] < minn){
				u = j;
				minn = dis[j];
			}
		}
		if(u == -1) break;
		visit[u] = true;
		for(int v = 0;v<n;v++){
			if(visit[v] == false && time0[u][v]!=inf){
				if(dis[v] > dis[u] + time0[u][v]){
					dis[v] = dis[u] + time0[u][v];
					pre[v].clear();
					pre[v].push_back(u);
				}else if(dis[v] == dis[u] + time0[u][v]){
					pre[v].push_back(u);
				}
			}
		}
	}
	minnode = inf;
	dfstime(d); 
	
	cout<<"Distance = "<<disans;
	if(pathcopy == path){
		cout<<"; ";
	}else{
		cout<<": ";
		for(int i = pathcopy.size()-1; i>=0; i--){
			if( i != pathcopy.size()-1){
				cout<<" -> ";
			}
			cout<<pathcopy[i];
		}
		cout<<endl;
	}
	
	cout<<"Time = "<<dis[d]<<": ";
	for(int i = path.size()-1; i>=0; i--){
		if( i != path.size()-1){
			cout<<" -> ";
		}
		cout<<path[i];
	}
	cout<<endl;
	
	return 0;
} 
