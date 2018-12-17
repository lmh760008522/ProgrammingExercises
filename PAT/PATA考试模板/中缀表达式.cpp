/*
�����������������׺���ʽ ,���������ű�ʾ��������ȼ� 
syntax���﷨ 
parentheses��Բ���� 
precedences������  

��Ŀ��˵ data is a string of no more than 10 characters 
����������Ϊ10ʱ�ͳ���������ʱ���󣬽����鷶Χ����15��ȫ���ˡ��� 
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
	//�����ҵ����ڵ� 
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
