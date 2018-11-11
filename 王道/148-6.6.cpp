#include<cstdio>

char a[500][500];
int n,m;

void dfs(int x,int y){
	if(x<0 || y<0 || x>=n || y>=m){
		return;
	}
	if(a[x][y]=='*') return;
	a[x][y]='*';
	dfs(x+1,y);
	dfs(x-1,y);
	dfs(x,y+1);
	dfs(x,y-1);
	return ;
}

int main(){
	while( scanf("%d %d\n",&n,&m)!=EOF){
		if(n==0 && m==0){
			break;
		}
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				//printf("?");
				scanf("%c",&a[i][j]);
			}
		}
		int ans=0;
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				if(a[i][j]=='@'){
					ans++;
					dfs(i,j);
				}
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
