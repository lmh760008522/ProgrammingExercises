#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;

int dis[510],cost[510][510],e[510][510];
bool visit[510];
vector<int> path,temppath;
vector<int> pre[510];
const int inf = 99999999;
int n, m, s, d;
int mincost = inf;

void dfs(int v){
	temppath.push_back(v);
	if( v == s){
		int tempcost = 0;
		for(int i=temppath.size()-1;i>0;i--){
			int id = temppath[i],nextid=temppath[i-1];
			tempcost +=cost[id][nextid];
		}
		if(tempcost < mincost){
			mincost = tempcost;
			path = temppath;
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
	fill(dis,dis+510,inf);
	fill(e[0],e[0]+510*510,inf);
	
	scanf("%d%d%d%d", &n, &m, &s, &d);
    for(int i = 0; i < m; i++) {
        int a, b;
        scanf("%d%d", &a, &b);
        scanf("%d", &e[a][b]);
        e[b][a] = e[a][b];
        scanf("%d", &cost[a][b]);
        cost[b][a] = cost[a][b];
    }
    
    pre[s].push_back(s);
    dis[s]=0;
    for(int i=0;i<n;i++){
    	int u=-1,minn = inf;
    	for(int j=0;j<n;j++){
    		if(visit[j]==false && dis[j]<minn){
    			u=j;
    			minn = dis[j];
			}
		}
		if(u==-1) break;
		visit[u]=true;
		for(int v=0;v<n;v++){
			if(visit[v]==false && e[u][v]!=inf){
				if(dis[v]>dis[u]+e[u][v]){
					dis[v] = dis[u]+e[u][v];
					pre[v].clear();
					pre[v].push_back(u);
				}else if(dis[v]==dis[u]+e[u][v]){
					pre[v].push_back(u);
				}
			}
		}
	}
	dfs(d);
	return 0;
}
