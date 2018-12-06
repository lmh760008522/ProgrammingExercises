/*
给一个树，求是否是是一个完全二叉树 
*/
#include<iostream>
#include<map>
#include<string.h>
#include<vector>
#include<stdlib.h>
using namespace std;

typedef struct node{
	char l,r;
}node;

int n;
map<int, node> tree;
int root = 0;
int have[25] = {0};
int num,ans;

void dfs(int r, int index){
	if(index > num){
		num = index;
		ans = r;
	}
	if(tree[r].l != -1){
		dfs(tree[r].l,index*2);
	} 
	if(tree[r].r != -1){
		dfs(tree[r].r,index*2+1);
	}
	return ;
}

int main(){
	cin>>n; // <=20
	for(int i=0;i<n;i++){
		char a[5],b[5];
		cin>>a>>b;
		node temp;
		if(a[0] == '-'){
			temp.l = -1;
		}else{
			temp.l = atoi(a);
			have[temp.l] = 1;
		}
		if(b[0] == '-'){
			temp.r = -1;
		}else{
			temp.r = atoi(b);
			have[temp.r] = 1;
		}
		tree[i] = temp;
	}
	
	//没有指向的，就是root
	while(have[root] != 0) root++;  
	
	dfs(root, 1);
	
	if(num==n) cout<<"YES "<<ans<<endl;
	else cout<<"NO "<<root<<endl;
		
	return 0;
}
	
