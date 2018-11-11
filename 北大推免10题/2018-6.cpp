#include<cstdio>
#include<queue>
#define INF 99999999
using namespace std;

typedef struct node{
	int x,y;
}node;

int movex[4]={0,0,1,-1};
int movey[4]={1,-1,0,0};
int visit[301][301]={0};
int d[301][301];
int x0,y0,x1,y1;
int m,n;
queue<node> q;

bool judgeb(int x,int y){//ÊÇ·ñ³ö½ç 
	if(x<0 || x>=m || y<0 || y>=m){
		return true;
	}
	return false;
}

void bfs(int x0,int y0){
	node temp;
	temp.x=x0;
	temp.y=y0;
	q.push(temp);
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			d[i][j]=0;
		}
	}
	d[temp.x][temp.y]=0;
	visit[x0][y0]=1;
	while(q.empty()==false){
		node temp=q.front();
		q.pop();
		visit[temp.x][temp.y]=1;
		if(temp.x==x1 && temp.y==y1){
			return;
		}
		for(int i=0;i<4;i++){
			if( judgeb(temp.x+movex[i], temp.y+movey[i])==false && visit[temp.x+movex[i]][temp.y+movey[i]]==0){
				node t;
				t.x=temp.x+movex[i];
				t.y=temp.y+movey[i];
				q.push(t);
				d[t.x][t.y]=d[temp.x][temp.y]+1;
			}
		}
	}
	
}

int main(){
	while(scanf("%d %d",&m,&n)!=EOF){
		if(m==0 && n==0){
			return 0;
		}
		char c;
		for(int i=0; i<m; i++){
			for(int j=0; j<n; j++){
				scanf("%c",&c);
				if(c=='Y'){
					x0=i, y0=j;
				}else if(c=='T'){
					x1=i, y1=j;	
				}else if(c=='R' || c=='S'){
					visit[i][j]=1;
				}
			}
		}
		printf("%d %d %d %d\n",x1, y1,x0,y0);
		
		bfs(x0,y0);
		for(int i=0;i<m;i++){
			for(int j=0;j<n;j++){
				printf("%d ",d[i][j]);
			}
			printf("\n");
		}
		printf("%d %d :%d\n",x1, y1,d[x1][y1]);
	}
	
	
	return 0;
}
