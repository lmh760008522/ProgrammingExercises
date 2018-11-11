#include<cstdio>
int a[101][101];
int visit[101][101]={0};
int xx[4]={1,0,0,-1};
int yy[4]={0,1,-1,0};
int ans=0;
int n,m;

void dfs(int x,int y){
	if(x<0 || y<0 || x>=n || y>=m ){
		return;
	}
	if( visit[x][y]==1 || a[x][y]==0){
		return ;
	}
	visit[x][y]=1;
	for(int i=0;i<4;i++){
		if(x+xx[i]>=0 && x+xx[i]<n && y+yy[i]>=0 && y+yy[i]<m ){
			if(a[x+xx[i]][y+yy[i]] == 0){
				ans++;
			}		
		}else {
			ans++;
		}
	}
	//printf("%d %d : %d\n",x,y,ans);
	for(int i=0;i<4;i++){
		dfs(x+xx[i],y+yy[i]);	
	}
	return;
}
int main(){

	scanf("%d %d",&n,&m);
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			scanf("%d",&a[i][j]);
		}
	}
	dfs(0,0);
	printf("%d\n",ans);
	return 0;
}
