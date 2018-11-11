#include<stdio.h>
#include<queue>
using namespace std;

int maze[5][5] = {
	0, 1, 0, 0, 0,
	0, 1, 0, 1, 0,
	0, 0, 0, 0, 0,
	0, 1, 1, 1, 0,
	0, 0, 0, 1, 0,
};
typedef struct node{
	int x,y;
	int min;
}node;
int h[4] = {-1,1,0,0};
int l[4] = {0,0,-1,1};
int mmin = 999;
queue<node> q;
const int m = 5, n = 5;

void bfs(){
	node temp;
	temp.x = temp.y = 0;
	temp.min = 0;
	q.push(temp);
	maze[0][0] = 1;
	while(q.empty() != 1){
		node t = q.front();
		q.pop();
		
		for(int i=0;i<4;i++){
				node tt;
				tt.x = t.x + h[i];
				tt.y = t.y + l[i];
				if(t.x >=0 && t.x <m && t.y >=0 && t.y <n && maze[t.x][t.y] == 0){
					tt.min = t.min + 1;
					if(tt.x == m-1 && tt.y == n-1){
						if(tt.min < mmin){
							mmin = tt.min;
							printf("%d ",mmin);
						}
					}else{
						q.push(tt);
						//maze[t.x][t.y] = 1;
					}
				}
		}
	}
}

int main(){
	bfs();
	printf("%d", mmin);
	return 0;
} 
