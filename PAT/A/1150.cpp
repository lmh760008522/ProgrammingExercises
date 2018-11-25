//combinatorial  组合的
//operations research 运筹学
//旅行商环路 
#include<stdio.h>
#include<set>
using namespace std;
int main(){
	int n,m,k;
	scanf("%d %d", &n, &m);
	int e[205][205];
	for(int i=0;i<m;i++){
		int a,b,t;
		scanf("%d %d %d", &a, &b, &t);
		e[a][b] = e[b][a] = t;
	}
	scanf("%d",&k);
	int minid = 0, mindis = 99999; //100*200=20000
	for(int i=1;i<=k;i++){
		int t, sum = 0, st,sst, en;
		scanf("%d", &t);
		bool flag = true, no = false;
		scanf("%d", &st);
		sst = st;
		set<int> s;
		for(int j=1; j<t; j++){
			scanf("%d", &en);
			s.insert(en);
			if(e[st][en] == 0){
				no = true;
				flag = false;
			}
			sum += e[st][en];
			st = en;
		}
		if(s.size() != n){//没有遍历所有节点 
			flag = false; 
		}
		if(no){
			printf("Path %d: NA (Not a TS cycle)\n",i);
		}else if(sst != en || flag == false){
			printf("Path %d: %d (Not a TS cycle)\n", i, sum);
		}else if( t == n+1){
			printf("Path %d: %d (TS simple cycle)\n", i, sum);
		}else{
			printf("Path %d: %d (TS cycle)\n", i, sum);
		}
		if(flag){
			if(mindis > sum){
				mindis = sum;
				minid = i;
			}
		}
	}
	printf("Shortest Dist(%d) = %d", minid, mindis);
	return 0;
} 
