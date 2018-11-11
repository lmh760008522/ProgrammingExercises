#include<cstdio>
#include<string.h>

int a[201][201]={0};
int visit[201][201]={0};
int m,n;
int i0,j0;
int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};
bool flag=false; 

void dfs(int x,int y){
	if(x<0 || y<0 || x>m|| y>n){
		return ;
	}
	if(visit[x][y]==1){
		return ;
	}
	if(x==i0-1 && y==j0-1 ){
		flag=true;
		return ;
	} 
	visit[x][y]=1;
	for(int i=0;i<4;i++){
		if(a[x][y]>=a[x+dx[i]][y+dx[y]] && visit[x+dx[i]][y+dx[y]]==0){
			dfs(x+dx[i],y+dx[y]);
		}
	} 
}

int main(){
	int k;
	scanf("%d",&k);
	while(k-- >0){
		scanf("%d %d",&m,&n);
		memset(a,0,sizeof(a)); 
		memset(visit,0,sizeof(visit)); 
		flag=false;
		for(int i=0;i<m;i++){
			for(int j=0;j<n;j++){
				scanf("%d",&a[i][j]);
			}
		}
		scanf("%d %d",&i0,&j0);
		int p;
		scanf("%d",&p);
		for(int i=0;i<p;i++){
			int x,y;
			scanf("%d %d",&x,&y);
			dfs(x-1,y-1);
		}
		if(flag){
			printf("Yes\n");
		}else{
			printf("No\n");
		}
	}
	return 0;
}
