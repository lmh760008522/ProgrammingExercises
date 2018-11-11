#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
#define MAXD 400 + 10
int n,m,x,y;
char maze[MAXD][MAXD];
int Sum;
int dir[8][2] = {{1,0},{-1,0},{0,1},{0,-1},
                 {1,1},{1,-1},{-1,1},{-1,-1}};
int vis[MAXD][MAXD];
void dfs(int a,int b){
    vis[a][b] = 1;
    for(int i = 0 ; i < 4 ; i++){
         int nx = a + dir[i][0];
         int ny = b + dir[i][1];
         if(nx < 0 || nx >= n || ny < 0 || ny >= m || maze[nx][ny] == '.') Sum++;
    }
    for(int i = 0 ; i < 8 ; i++){
         int nx = a + dir[i][0];
         int ny = b + dir[i][1];
         if(nx >= 0 && nx < n && ny >=0 && ny < m && !vis[nx][ny] &&maze[nx][ny] == 'X')
            dfs(nx,ny);
    }
}
int main(){
    while(scanf("%d%d%d%d",&n,&m,&x,&y)){
        if(!n&&!m&&!x&&!y) break;
        memset(vis,0,sizeof(vis));
        Sum = 0;
        for(int i = 0; i < n ; i++)
             scanf("%s",&maze[i]);
        dfs(x - 1,y - 1);
        printf("%d\n",Sum);
    }
    return 0;
}

