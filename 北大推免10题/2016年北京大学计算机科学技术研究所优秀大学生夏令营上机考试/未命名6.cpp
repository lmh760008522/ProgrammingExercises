#include<cstdio>
#include<iostream>
using namespace std;

int n;
int numb=0;//Í³¼ÆºÚÆå 
char a[101][101];
int visit[101][101]={0}; 
int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};
int ans=0;

void dfs(int x,int y){
	visit[x][y]=1;
	ans++;
	if(a[x][y]=='W'||a[x][y]=='#'){
		return;
	}
	for(int i=0;i<4;i++){
		int u=x+dx[i],v=y+dy[i];
		if(u>=0 && v>=0 && u<n && v<n && visit[u][v]==0 && a[u][v]=='.'){
			dfs(u,v);
		}
	}
	
}

int main(){
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cin>>a[i][j];
		}
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(visit[i][j]==0 && a[i][j]=='B'){
				dfs(i,j);
			}
		}
	}
	printf("%d %d\n",ans,n*n-ans);
	return 0;
}
