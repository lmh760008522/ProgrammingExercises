#include<cstdio>
/*
int a[4][5]={{1,1,1,1,0},
	             {1,1,0,1,0},
				 {1,1,0,0,0},
				 {0,0,0,0,0}};
				 */
	
	int a[4][5]={{1,1,0,0,0},
	             {1,1,0,0,0},
				 {0,0,1,0,0},
				 {0,0,0,1,1}};
	
	

void dfs(int x,int y){
	a[x][y]=0;
	if(x>=4 || x<0 || y>=5 || y<0){
		return ;
	}
	if(a[x+1][y]){ dfs(x+1,y); }
	if(a[x-1][y]){ dfs(x-1,y); }
	if(a[x][y+1]){ dfs(x,y+1); }
	if(a[x][y-1]){ dfs(x,y-1); }
}

int main(){
	int num=0;
	for(int i=0;i<4;i++){
		for(int j=0;j<5;j++){
			if(a[i][j]==1){
				dfs(i,j);
				num++;
			}
		}
	}
	printf("%d",num);
	return 0;
}
