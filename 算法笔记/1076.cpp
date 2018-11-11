#include<cstdio>
#include<vector>
#include<cstring>
#include<queue>
using namespace std;

typedef struct node{
	int id;
	int layer;
}node;

vector<node> e[1010];
bool vis[1010]=false;

void bfs(int s,int l){
	queue<node> q;
	int ans=0;
	node temp;
	temp.id=s;
	temp.layer=0;
	q.push(temp);
	vis[s]=true;
	while(q.empty()==false){
		
	}
	
}

int main(){
	int n,l,numfollow,idfollow;
	node user;
	scanf("%d %d",&n,&l);
	for(int i=1;i<=n;i++){
		user.id=i;
		scanf("%d",&numfollow);
		for(int j=0;j<numfollow;j++){
			scanf("%d",&idfollow);
			e[idfollow].push_back(user);
		}
	}
	int numq,s;
	scanf("%d",&numq);
	for(int i=0;i<numq;i++){
		memset(vis,false,sizeof(vis));
		scanf("%d",&s);
		int numforward=bfs(s,0);
		printf("%d\n",numforward);
	}
	return 0;
}
