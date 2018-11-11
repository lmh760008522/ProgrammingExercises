#include<cstdio>
#include<cstring>
#include<iostream>
#include<queue>
using namespace std;

int m,n;
int x0,y0,x1,y1;
int min_;
int a[21][21];
int visit[21][21];
int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};

typedef struct node{
	int x,y;
	int len;
}node;

void bfs(){
	queue<node> q;
	node temp;
	temp.x = x0;
	temp.y = y0;
	temp.len = 0;
	q.push(temp);
	while(q.size()!=0){
		node t;
		t=q.front();
		q.pop();
		if( t.x==x1 && t.y==y1 ){
			if(min_ > t.len){
				min_ =t.len;
			}
		}
		for(int i=0;i<4;i++){
			int x = t.x+dx[i], y = t.y+dy[i];
			if(x<0 || y<0 || x>m || y>n || visit[x][y]== 1 || a[x][y] == 1){
				continue;
			}
			visit[t.x][t.y]=1;
			node tt;
			tt.len=t.len+1;
			tt.x=x;
			tt.y=y;
			q.push(tt);
		}
	}
	return ;
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
		bfs();
		if(min_ == 99999999){
			printf("-1\n");
		}else{
			printf("%d\n",min_ );
		}
	}
	return 0;
}
