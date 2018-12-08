/*
二叉树建树 
给出插入序列，找到avl树的根节点 
*/ 
#include<iostream>
#include<algorithm>
using namespace std;

struct node{
	int val;
	struct node *left, *right;
};

int getheight(node *root){
	if(root == NULL) return 0;
	return max(getheight(root->left), getheight(root->right)) + 1;
}

node *rotater(node *root){
	node *t = root->left;
	root->left = t->right;
	t->right = root;
	return t;
}

node *rotatel(node *root){
	node *t = root->right;
	root->right = t->left;
	t->left = root;
	return t;
}

node *rotatelr(node *root){
	root->left = rotatel(root->left);
	return rotater(root);
}

node *rotaterl(node *root){
	root->right = rotater(root->right);
	return rotatel(root);
}

node *insert(node *root, int v){
	if(root == NULL){
		root = new node();
		root->val = v;
		root->left = root->right = NULL;
	}else if(root->val < v){
		root->right = insert(root->right, v);
		if(getheight(root->left)-getheight(root->right) == -2){
			root = v > root->right->val ? rotatel(root) : rotaterl(root);
		}
	}else{
		root->left = insert(root->left,v);
		if(getheight(root->left)-getheight(root->right) == 2){
			root = v < root->left->val ? rotater(root) : rotatelr(root);
		}
	}
	return root;
}

int main(){
	int n, x;
	cin>>n;
	node *root = NULL;
	for(int i=0;i<n;i++){
		cin>>x;
		root = insert(root, x);
	}
	cout<<root->val<<endl;
	return 0;
} 
