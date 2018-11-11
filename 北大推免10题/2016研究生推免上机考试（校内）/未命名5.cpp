#include<cstdio>
#include<iostream>
#include<cmath>
#include<string.h>
using namespace std;

#define n 5
#define m 6

int a[5][6]={0};
int visit[5][6]={0};
int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};

void push(int x,int y){
	a[x][y] == 1 ? a[x][y] =0 : a[x][y] =1;
	for(int i=0;i<4;i++){
		int tx=x+dx[i],ty=y+dy[i];
	    if(tx<0 || ty<0 || tx>=n || ty>=m){
	    	continue;
		}else{
			a[tx][ty] == 1 ? a[tx][ty] =0 : a[tx][ty] =1;
		}
	}
	return;
}

int main(){
	
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin>>a[i][j];
		}
	}
	
	bool flag=true;
	for(int i=0;i<pow(2,6);i++){
		int k=i;
		memset(visit,0,sizeof(visit));
		
		if(i==41){
			printf("k\n");
			for(int p=0;p<6;p++){
				printf("%d ",visit[0][p]);
			}
			printf("k\n");
		}
		
		for(int j=0;j<6;j++){
			if( k&1==1 ){
				push(0,j);
				visit[0][j]=1;
				if(i==41){
					for(int p=0;p<6;p++){
						printf("%d ",a[0][p]);
					}
					printf("\n");
				}
			}
			k=k>>1;
		}
		
		/*
		for(int p=0;p<6;p++){
			printf("%d ",visit[0][p]);
		}
		printf("\n");
		for(int p=0;p<6;p++){
			printf("%d ",a[0][p]);
		}
		printf("\n\n");
		*/
		for(int p=1;p<=4;p++){
			for(int q=0;q<6;q++){
				if(a[p-1][q]==1){
					push(p,q);
					visit[p][q]=1;
				}
				//printf("%d ",a[p][q]);
			}
			//printf("\n");
		}
		
		/*
		for(int p=0;p<5;p++){
			for(int q=0;q<6;q++){
				printf("%d ",a[p][q]);
			}
			printf("\n");
		}
		printf("\n");
		for(int p=0;p<5;p++){
			for(int q=0;q<6;q++){
				printf("%d ",visit[p][q]);
			}
			printf("\n");
		}*/
		printf("\n\n");
		
		for(int p=0;p<6;p++){
			if(a[4][p]==1){
				flag=false;
				break;
			}
		}
		
		if(flag){
			for(int i=0;i<n;i++){
				for(int j=0;j<m;j++){
					printf("%d ",visit[i][j]);
				}
				printf("\n");
			}
			break;
		}
	}
	return 0;
}
