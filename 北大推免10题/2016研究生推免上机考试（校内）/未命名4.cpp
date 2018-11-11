#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;

int m,n;
int x0,y0,x1,y1;
int min_;
int a[21][21];
int visit[21][21];
int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};

void dfs(int x,int y,int len){
	if( x==x1 && y==y1){
		if(min_ > len){
			min_ =len;
		}
		return;
	}
	if(x<0 || y<0 || x>=m || y>=n || visit[x][y]==1 || a[x][y]==1){
		return;
	}
	for(int i=0;i<4;i++){
		visit[x][y] = 1;
		dfs(x+dx[i],y+dy[i],len+1);
		visit[x][y] = 0;
	}
}

int main(){
	while(scanf("%d %d\n",&m,&n)!=EOF){
		if(m==n && m==0){
			break;
		}
		min_ = 99999999;
		memset(visit,0,sizeof(visit));
		for(int i=0;i<m;i++){
			for(int j=0;j<n;j++){
				char c;
				cin>>c;
				if(c=='@'){
					a[i][j]=0;
					x0=i,y0=j;
				}else if(c=='.'){
					a[i][j]=0;
				}else if(c=='#'){
					a[i][j]=1;
					visit[i][j]=1;
				}else{
					a[i][j]=0;
					x1=i,y1=j;
				}
			}
			//scanf("\n");
		}
		printf("%d %d £¬%d %d\n",x0,y0,x1,y1);
		dfs(x0,y0,0);
		if(min_ == 99999999){
			printf("-1\n");
		}else{
			printf("%d\n",min_ );
		}
	}
	return 0;
}
