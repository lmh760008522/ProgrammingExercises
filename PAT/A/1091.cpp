#include<iostream>
#include<vector>
#include<queue>
using namespace std;

#define MAX 1286*128*60
bool visit[MAX];
int a[60][1286][128];
int m,n,l,I;
int v;

//µÝ¹é×ö³¬Ê± 
/*
void dfs(int i,int j, int k){
	if(i<0||j<0||k<0||i>=l||j>=m||k>=n){
		return;
	}
	if(visit[i*m*n+j*m+k+1]==true){
		return;
	}
	visit[i*m*n+j*m+k+1]==true;
	if(a[i][j][k] == 1){
		v++;
		for(int x=i-1;x<=i+1;x++){
			for(int y=j-1;y<=j+1;j++){
				for(int z=k-1;z<=k+1;k++){
					dfs(x,y,z);
				}
			}
		}
	}
	return;
}*/


//void bfs(int i,int j,int k){
//	queue<int> q;
//	if(i<0||j<0||k<0||i>=l||j>=m||k>=n|| visit[i*m*n+j*m+k+1]==true || a[i][j][k]==0){
//		int index=q.front();
//		q.pop();
//		for(int x=i-1;x<=i+1;x++){
//			for(int y=j-1;y<=j+1;j++){
//				for(int z=k-1;z<=k+1;k++){
//					q.push()
//				}
//			}
//		}
//	}
//}

int main(){
	cin>>m>>n>>l>>I;
	
	for(int i=0;i<l;i++){
		for(int j=0;j<m;j++){
			for(int k=0;k<n;k++){
				cin>>a[i][j][k];
			}
		}
	}
	
	//int count=0;
	int max_v=0;
	for(int i=0;i<l;i++){
		for(int j=0;j<m;j++){
			for(int k=0;k<n;k++){
				if(visit[i*m*n+j*m+k+1]==false && a[i][j][k]==1){//¼ôÖ¦ 
					v=0;
					bfs(i,j,k);
					if(v>I){
						max_v+=v;
					}
				}
			}
		}
	}
	printf("%d",max_v);
	return 0;
}
