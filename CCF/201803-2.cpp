#include<stdio.h>
#include<algorithm>
using namespace std;

typedef struct node{
	int id;
	int site;
	int dir;
}node;

bool cmp_site(node a, node b){
	if(a.site<b.site){
		return true;
	}
	return false;
}

bool cmp_id(node a,node b){
	if(a.id<b.id){
		return true;
	}
	return false;
}

int main(){
	int n, len, t;
	node tree[100];
	scanf("%d %d %d",&n,&len,&t);
	
	for(int i=0;i<n;i++){
		scanf("%d",&tree[i].site);
		tree[i].dir=1;
		tree[i].id=i+1; 
	}
	
	sort(tree,tree+n,cmp_site);
	
	for(int i=0;i<t;i++){
		//走路 
		for(int j=0;j<n;j++){
			tree[j].site += tree[j].dir;
		}
		//改方向 
		if(tree[0].site==0){//第一个球到头了 
			tree[0].dir= -tree[0].dir; 
		} 
		for(int j=0;j<n-1;j++){
			if(tree[j].site==tree[j+1].site){//发生碰撞 
				tree[j].dir= -tree[j].dir;
				tree[j+1].dir= -tree[j+1].dir;
			}	
		}
		if(tree[n-1].site==len){//最后一个球到头了 
			tree[n-1].dir= -tree[n-1].dir;
		}
		/*
		printf("\n=======");
		for(int j=0;j<n;j++){
			printf("%d ", tree[j].site);
		}*/
	}
	
	sort(tree,tree+n,cmp_id);
	//printf("\n");
	for(int i=0;i<n;i++){
		printf("%d ", tree[i].site);
	}
	return 0;
}
