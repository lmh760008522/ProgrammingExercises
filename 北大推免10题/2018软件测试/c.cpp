#include<cstdio>

int count=0;
int n,m;
int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,1,-1};
int map[105][105]={0};
int visit[105][105]={0};

void dfs(int x,int y){
	if(visit[x][y]==1 || map[x][y]==0){
		return;
	}
	visit[x][y]=1;
	for(int i=0;i<4;i++){
		if(x+dx[i]<0 || x+dx[i]>=n || y+dy[i]<0 ||  y+dy[i]>=m){
			count++;
		}else if(map[x+dx[i]][y+dy[i]]==0){
			count++;
		}else{
			dfs(x+dx[i],y+dy[i]);
		}
	}
}

int main(){

	scanf("%d %d",&n,&m);
	
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			scanf("%d",&map[i][j]);
		}
	}
	dfs(0,0);
	printf("%d",count);
	return 0;
} 
