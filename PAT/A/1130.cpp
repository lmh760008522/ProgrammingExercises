//这题 DFS 循环有问题，无限循环 
#include<iostream>
using namespace std;

typedef struct node{
	char data[10];
	int lchild, rchild;
}node;

node Node[10];
bool visit[10];

void dfs(int root){
	cout<<root;
	if(Node[root].lchild!=-1){
		dfs(Node[root].lchild);
	}
	printf("%s",Node[root].data);
	if(Node[root].rchild!=-1){
		dfs(Node[root].rchild);
	}
	return;
}

int main(){
	int n;//total number of nodes
	int root;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>Node[i].data>>Node[i].lchild>>Node[i].rchild;
		if(Node[i].lchild!=-1){
			visit[Node[i].lchild] = true;
		}
		if(Node[i].rchild!=-1){
			visit[Node[i].rchild] = true;
		}
	}
	for(int i=0;i<n;i++){
		if(visit[i]==false){
			root=i;
			break;
		}
	}
	dfs(root);
	return 0;
}
