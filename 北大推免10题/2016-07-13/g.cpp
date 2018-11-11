#include<cstdio>
#include<string.h>
#include<iostream>
using namespace std;

int w,h;
int x1,y1,x2,y2;
char map[80][80];
int visit[80][80];
int len;
int dx[4]={0,0,1,-1}; 
int dy[4]={1,-1,0,0};

void dfs(int x,int y,int l){
	if(x==x1 && y==y1 && visit[x][y]==0){
	}else if(x==x2 && y==y2){
		if(l<len){
			len=l-1;
		}
		//printf("right!\n");
		return;
	}else{
		if(visit[x][y]==1 || map[x][y]=='X' || x<0 || y<0 || x>w+1 || y>h+1 ){
			//printf("wrong:%d %d %c\n",x,y,map[x][y]);
			return;
		}
	}
	visit[x][y]=1;
	//printf("right:%d %d %c\n",x,y,map[x][y]);
	for(int i=0;i<4;i++){
		dfs(x+dx[i],y+dy[i],l+1);
	}
}

int main(){
	
	while(true){
		
		scanf("%d %d\n",&h,&w);
		if(h==0 && w==0){
			break;
		}
		for(int i=0;i<=h+1;i++){
			map[0][i]='.';
		}
		for(int i=1;i<=w;i++){
			map[i][0]='.';
			char s[80];
			int p=0;
			gets(s);
			for(int j=1;j<=h;j++){
				//cin>>map[i][j];
				map[i][j]=s[p++];
			}
			map[i][h+1]='.';
		}
		for(int i=0;i<=h+1;i++){
			map[w+1][i]='.';
		}
		
		for(int i=0;i<=w+1;i++){
			for(int j=0;j<=h+1;j++){
				printf("%c",map[i][j]);
			}
			printf("\n");
		}
		
		while(true){
			scanf("%d %d %d %d",&y1,&x1,&y2,&x2);
			if(x1==0 && x2==0 && y1==0 &&y2==0){
				break;
			}
			len=9999;
			memset(visit,0,sizeof(visit));
			dfs(x1,y1,0);
			if(len==9999){
				printf("Pair 1: impossible.\n");
			}else{
				printf("Pair 2: %d segments.\n",len);
			}
		}
	}
	return 0;
} 
