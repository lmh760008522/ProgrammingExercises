#include<stdio.h>
#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<string.h>
using namespace std;

typedef struct node{
	int l,r;
}node;
vector<node> v;
vector<int> in;
int visit[10];
int n;

void inorder(int index){
	if(index == -1) return;
	inorder(v[index].l);
	//printf("%d",index);
	in.push_back(index);
	inorder(v[index].r);
}

int main(){
	
	cin>>n;
	
	v.resize(n);
	memset(visit,0,sizeof(visit));
	
	for(int i=0;i<n;i++){
		v[i].l=-1;
		v[i].r=-1;
		char a,b;
		cin>>a>>b;
		if(a !='-'){
			v[i].r=a-'0';
			visit[a-'0'] = 1;
		}
		if(b!='-'){
			v[i].l=b-'0';
			visit[b-'0'] = 1;
		}
	}
	
	int root;
	for(int i=0;i<n;i++){
		if(visit[i] == 0){
			root = i;
			break;
		}
	}
	

	
	//层次遍历
	queue<int> q;
	q.push(root);
	int count =0;
	while(!q.empty()){
		int index=q.front();
		q.pop();
		if(v[index].l != -1){
			q.push(v[index].l);
		}
		if(v[index].r != -1){
			q.push(v[index].r);
		}
		printf("%d", index);
		if(count!=n-1){
			printf(" ");
		}else{
			printf("\n");
		}
		count++;
	}
	
	
	//中序遍历
	inorder(root);
	for(int i=0;i<in.size();i++){
		printf("%d",in[i]);
		if(i!=in.size()-1){
			printf(" ");
		}
	}
	return 0;
}
