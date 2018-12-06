/*
二叉搜索树 (可插入重复节点，重复加点插入在左子树)
给你二叉搜索树节点的插入顺序，求最低两层的节点总数 
结点数范围：[1,1000],结点值范围：[-1000,1000] 
第一次：错了一个答案 
*/ 
#include<iostream>
#include<vector>
#include<map> 
using namespace std;

typedef struct node{
	int val;
	int left,right;
}node;

map<int ,node> tree;
map<int, int> height; 
int maxh = 0;
int n;
int root;

void insert(int r, int val, int h){
	if(val <= r && tree[r].left == -1){
		tree[r].left = val;
		node temp;
		temp.val = val; temp.left = -1; temp.right = -1;
		tree[val] = temp;
		height[h+1]++;
		if(h+1>maxh){
			maxh = h+1; 
		}
		return;
	}else if(val > r && tree[r].right == -1){
		tree[r].right = val;
		node temp;
		temp.val = val; temp.left = -1; temp.right = -1;
		tree[val] = temp;
		height[h+1]++;
		if(h+1>maxh){
			maxh = h+1; 
		}
		return;
	}else if(val > r && tree[r].right != -1){
		insert(tree[r].right, val, h+1);
	}if(val <= r && tree[r].left != -1){
		insert(tree[r].left, val, h+1);
	}
	
}

int main(){
	cin>>n;
	cin>>root;
	node temp;
	temp.val = root; temp.left = -1; temp.right = -1;
	tree[root] = temp;
	height[0] = 1;
	for(int i=1;i<n;i++){
		int x;
		cin>>x;	
		insert(root, x, 0);
	}
	cout<<height[maxh]<<" + "<<height[maxh-1]<<" = "<<height[maxh] + height[maxh-1]<<endl;
	return 0;
} 
