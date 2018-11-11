#include<cmath>
#include<stdlib.h>
#include<stdio.h>
#include<iostream>
using namespace std;
typedef struct AVLTreeNode *AVLTree;
struct AVLTreeNode{
	int data;
	AVLTree left;
	AVLTree right;
	int Height;
};
int height(AVLTree t){
	if(t){
		int l=height(t->left);
		int r=height(t->right);
		int max=l>r?l:r;
		return max+1;
	}else{
		return 0;
	}
}

AVLTree SingleLeftRotate(AVLTree t){
	AVLTree temp = t->left;
	t->left=temp->right;
	temp->right=t;
	t->Height = height(t);
	temp->Height=height(temp);
	return temp;
}
AVLTree SingleRightRotate(AVLTree t){
	AVLTree temp = t->right;
	t->right = temp->left;
	temp->left = t;
	t->Height = height(t);
	temp->Height=height(temp);
	return temp;
}
AVLTree DoubleRightLeftRotation(AVLTree t){
        t->right = SingleLeftRotate(t->right);
        return SingleRightRotate(t);
}
AVLTree DoubleLeftRightRotation(AVLTree t){
	t->left = SingleRightRotate(t->left);
	return SingleLeftRotate(t);
}

AVLTree AVL_Insert(int data,AVLTree t){
	if(t==NULL){
		t = (AVLTree)malloc(sizeof(struct AVLTreeNode));//申请一个结点空间！ 
		t->data=data;
		t->left=NULL;
		t->right=NULL;
		t->Height=0;
	}else if(data<t->data){
		t->left = AVL_Insert(data,t->left);
		if(height(t->left)-height(t->right)==2){
			if(data<t->left->data){
				t=SingleLeftRotate(t);
			}else{
				t=DoubleLeftRightRotation(t);
			}
		}
	}else{
		t->right = AVL_Insert(data,t->right);
		if (height(t->right) - height(t->left) == 2){
			if (data > t->right->data){
					t = SingleRightRotate(t);
			}
			else{
					t = DoubleRightLeftRotation(t);
			}
		}
	}
	t->Height=height(t);
	return t;
}

int main(){
	int n;
	int data;
	AVLTree tree=NULL;
	cin>>n;
	while(n>0){
		cin>>data;
		tree = AVL_Insert(data,tree);
		n--;
	}
	cout << tree->data << endl;
	return 0;
} 
