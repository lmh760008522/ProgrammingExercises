#include<cstdio>
int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};
int n;
int a[1001][1001];

void dfs(int x,int y){
	if(x<0 || y<0 || x>=n || y>=n || a[x][y]==255 ){
		return;
	}
	a[x][y]=255;
	for(int i=0;i<4;i++){
		dfs(x+dx[i],y+dy[i]);
	}
	return;
}

int main(){
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			scanf("%d",&a[i][j]);
		}
	}
	int ans=0;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(a[i][j]==0){
				dfs(i,j);
				ans++;
			}
		}
	}
	printf("%d\n",ans);
	return 0;
}
