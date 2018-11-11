#include<cstdio>
#include<cstring>
using namespace std;
char s[7];
int visit[3][4];
bool flag=false;

char c[3][4]={{'A','B','C','E'},
				  {'S','F','C','S'},
				  {'A','D','E','E'}};
				  
void search(int x,int y,int n){
	if(x<0 || x>=3 || y<0 || y>=4){
		return;
	}
	if(n==strlen(s)-1 && s[n]==c[x][y] && visit[x][y]==0){
		flag=true;
		return;
	}
	if(visit[x][y]==0 && s[n]==c[x][y]){
		visit[x][y]=1;
		search(x+1,y,n+1);
		search(x-1,y,n+1);
		search(x,y+1,n+1);
		search(x,y-1,n+1);
	}
	visit[x][y]=0;
	return;
}
int main(){
	
	
	
	gets(s);
	for(int i=0;i<3;i++){
		for(int j=0;j<4;j++){
			if(c[i][j]==s[0]){
				//visit[i][j]=1;
				search(i,j,0) ;
				if( flag ){
					printf("true");
					return 0;
				}
				//visit[i][j]=0;
			}
		}
	}
	printf("false");
	return 0;
}
