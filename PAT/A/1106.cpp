#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;

int node[1001];
int sum[1001];

int find(int y){
	if(node[y]!=-1){
		y=node[y];
		find(y);
	}
	return y;
}

bool cmp(int a,int b){
	return a>b;
}

int main(){
	memset(node,-1,sizeof(node));
	memset(sum,0,sizeof(sum));
	int n,k,j,x,i;
	scanf("%d",&n);;
	for(i=0;i<n;i++){
		scanf("%d:",&k);
		for(j=0;j<k;j++){
			scanf("%d",&x);
			int a = find(i);
			int b = find(x);
			if(a!=b){
				node[a] = b;
				sum[b]+=sum[a];
			}
		}
	}
	
	int count=0;
	for(i=0;i<n;i++){
		if(node[i]==-1){
			count++;
		}
	}
	
	sort(sum,sum+n,cmp);
	
	printf("%d\n",count);
	for(i=0;i<count;i++){
		printf("%d",sum[i]);
		if( i != count-1){
			printf(" ");
		}
	}
	return 0;
} 
