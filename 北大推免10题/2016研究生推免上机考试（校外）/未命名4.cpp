#include<cstdio>
#include<string.h>

int n,k,num,count;
char a[8][8];
int visit[8];

void judge(int x){
	if(k==count){
		num++;return;
	}
	if(x>=n){
		return ;
	}
	for(int j=0;j<n;j++){
		if(a[x][j]=='#' && visit[j]==0){
			visit[j]=1;
			count++;
			judge(x+1);
			visit[j]=0;
			count--;
		}
	}
	judge(x+1);//i行不放棋子 
}

int main(){

	while(scanf("%d %d\n",&n,&k)!=EOF){
		if(n==-1 && k==-1){
			break;
		}
		memset(visit,0,sizeof(visit));
		num=0,count=0;
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				scanf("%c",&a[i][j]);
			}
		}
		judge(0);
		printf("%d\n",num);
	}
	return 0;
}
