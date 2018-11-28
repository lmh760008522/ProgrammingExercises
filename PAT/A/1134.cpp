/*
vertex cover 顶点覆盖：一组顶点，使得图的每个边与该集合的至少一个顶点相关联。
indices: index 的复数 
*/ 
#include<stdio.h>
#include<vector>
#include<set>
using namespace std;

int main(){
	int n, m;
	scanf("%d %d", &n, &m);
	map<int, bool> mp;
	for(int i=0;i<m;i++){
		int a,b;
		scanf("%d %d",&a, &b);
		mp[a] = false;
	}
	int k;
	scanf("%d", &k);
	bool table[10005];
	for(int i=0;i<k;i++){
		int nv;
		scanf("%d",&nv);
		int num = 0;
		for(int j=0;j<nv;j++){
			int x;
			scanf("%d", &x);
			if(table[x] == false){
				table[x] = true;
				num ++;
			}
		}
		if(num == n){
			printf("Yes\n");
		}else{
			printf("No\n");
		}
	}
	return 0;
} 
