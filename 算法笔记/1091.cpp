#include<cstdio>
#include<queue>
#include<vector>
using namespace std;

typedef struct node{
	int x,y,z;
}node;

int n,m,slice,T;
int a[1290][130][61];
//int visit[1290][130][61]={false};
int X[6]={0,0,0,0,1,-1};
int Y[6]={0,0,1,-1,0,0};
int Z[6]={1,-1,0,0,0,0};

bool judge(int x,int y ,int z){
	if(x<0 || y<0 || z<0 || x>=n || z>=slice || y>=m){
		return false;
	}
	if(a[x][y][z]==0){
		return false;
	}
	return true;
}

int bfs(int x,int y,int z,int tempsum){
	queue<node> q;
	node temp;
	temp.x=x;
	temp.y=y;
	temp.z=y;
	q.push(temp);
	a[x][y][z]=0;
	tempsum++;
	while(q.empty()==false){
		node top=q.front();
		tempsum++;
		q.pop();
		for(int i=0;i<6;i++){
			node temp;
			temp.x=x+X[i];
			temp.y=y+Y[i];
			temp.z=z+Z[i];
			if(judge(x+X[i],y+Y[i],temp.z=z+Z[i])){
				q.push(temp);
				a[x][y][z]=0;
			}
		}
	}
	if(tempsum>=T){
		return tempsum;
	}else{
		return 0;
	}
}

int main(){
	scanf("%d %d %d %d",&n,&m,&slice,&T);
	for(int z=0;z<slice;z++){
		for(int x=0;x<n;n++){
			for(int y=0;y<m;y++){
				scanf("%d",&a[x][y][z]);
			}
		}
	}
	int ans=0;
	for(int z=0;z<slice;z++){
		for(int x=0;x<n;n++){
			for(int y=0;y<m;y++){
				if(a[x][y][z]==1 ){
					ans+=bfs(x,y,z,0);
				}
			}
		}
	}
	return 0;
}
