#include<cstdio>
#include<vector>
#include<stdlib.h>
#include<windows.h>
using namespace std;
typedef struct node{
	int w;
	int v;
}node;
 
vector<node> v;

int main(){
	int t,m;
	scanf("%d %d",&t,&m);
	for(int i=0;i<m;i++){
		int time,value;
		scanf("%d %d",&time,&value);
		node temp;
		temp.v=value;
		temp.w=time;
		v.push_back(temp);
	} 
	int dp[101][1001];
	for(int i=0;i<t;i++){
		dp[0][i]=0;
	}
	for(int i=0;i<v.size();i++){
		for(int j=t;j>=v[i].w;j--){
			dp[i][j] = max ( dp[i-1][j-v[i].w]+v[i].v, dp[i-1][j]);
		}
		for(int j=v[i].w-1;j>=0;j--){
			dp[i][j]=dp[i-1][j]; 
		} 
	}
	printf("%d\n",dp[m-1][t]);
	return 0;
}
