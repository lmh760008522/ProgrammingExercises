/* 
给前序和中序遍历，输出后序遍历的第一个值 
*/#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<int> preorder;
vector<int> inorder;
bool flag = false;
	
void find(int prest, int inst, int inen){
	if(inst > inen || flag == true){
		return;
	}
	int root = inst;
	while(inorder[root] != preorder[prest]){
		root++;
	}
	find(prest+1, inst, root-1);
	find(prest+root-inst+1, root+1, inen);
	if(flag == false){
		printf("%d", inorder[root]);
		flag = true;
	}
}

int main(){
	int n;
	cin>>n;
	preorder.resize(n);
	inorder.resize(n);
	for(int i=0;i<n;i++){
		cin>>preorder[i];
	}
	for(int i=0;i<n;i++){
		cin>>inorder[i];
	}
	find(0, 0, n-1);
	return 0;
} 

