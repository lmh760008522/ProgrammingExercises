/*
给出二叉树，输出中缀表达式 ,并加上括号表示运算的优先级 
syntax：语法 
parentheses：圆括号 
precedences：优先  

题目中说 data is a string of no more than 10 characters 
当我数组设为10时就出现了运行时错误，将数组范围扩大到15就全对了。。 
*/
#include<vector>
#include<string.h>
#include<string>
#include<iostream>
using namespace std;

typedef struct node{
	char data[15];
	int left,right;
}node;

int n;
vector<node> v;
bool table[100] = {false};
string ans = "";
int root;

void inorder(int x){
	if(v[x].left != -1){
		if( x!= root ) ans += "(";
		inorder(v[x].left);
	}else if(v[x].right != -1 && x!= root){
		ans += "(";
	}
	ans += v[x].data;
	if(v[x].right != -1){
		inorder(v[x].right);
		if( x!= root ) ans += ")";
	}
	return;
}

int main(){
	cin>>n;
	v.resize(n+5);
	for(int i=1;i<=n;i++){
		char d[15];
		int l,r;
		cin>>d>>l>>r;
		strcpy(v[i].data, d);
		v[i].left = l;
		v[i].right = r;
		table[l] = table[r] = true;
	}
	//首先找到根节点 
	for(int i=1; i<=n; i++){
		if(table[i] == false){
			root = i;
			break;
		}
	} 
	inorder(root);
	cout<<ans;
	return 0;
} 
