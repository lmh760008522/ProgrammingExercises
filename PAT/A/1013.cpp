#include<stdio.h>
#include<string.h>
int node[1001];
int num[1001];

int find(int x){
	while(node[x]!=-1){
		x=node[x];
	}
	return x;
}
int main(){
	int n,m,k;
	scanf("%d %d %d",&n,&m,&k);//城市数量，道路数量，检查的城市 
	
	memset(node,-1,sizeof(node));
	memset(num,0,sizeof(num));
	int i=0;
	while(i<m){
		int x,y;
		scanf("%d %d",&x,&y);
		x=find(x);
		y=find(y);
		if(x!=y){
			node[x]=y;
		}
		i++;
	}
	
	for(i=1;i<=k;i++){
		printf("%d ",node[i]);
	}
	printf("\n");
	
	i=0;
	int concern;
	int ii=0;
	while(i<k){
		scanf("%d", &concern);
		for(int j=1;j<=k;j++){
			if(node[j]==1){
				node[j]=-1;
			}
		}	
		for(int j=1;j<=k;j++){
			if(node[j]==-1&&j!=concern){
				num[ii]++;
			} 
		}
		i++;
		ii++;
	}
	
	for(int j=0;j<k;j++){
		printf("%d\n",num[j]);
	}
	
	return 0;
}
