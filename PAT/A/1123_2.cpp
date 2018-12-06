/*
���ղ���˳���������֣����AVL���Ĳ�α�������˵�����ǲ���һ����ȫ������.
*/ 
#include<iostream>
#include<vector>
#include<map>
#include<queue>
using namespace std;

typedef struct node{
	int val;
	int left, right;
	int hl, hr;
}node;

map<int, node> ist;
int root = -1;
vector<int> ans;
//bool flag = false;//�ж��Ƿ�����ȫ������ 

void ll(int p ,int r, int s){
	ist[s].left = -1;
	ist[r].right = s;
	ist[r].hr = ist[r].hl = 0;
	ist[s].hr = ist[s].hl = 0;
	if(s == root) root = r;
}

void rr(int p ,int r, int s){
	ist[s].right = -1;
	ist[r].left = s;
	ist[r].hr = ist[r].hl = 0;
	ist[s].hr = ist[s].hl = 0;
	if(s == root) root = r;
}

void lr(int p ,int r, int s, int t, int qr){
	ist[qr].left = -1;
	ist[r].left = s;
	ist[r].right = qr;
	ist[s].right = p;
	//�����߶� 
	if(root == qr)	root = r;
}

void rl(int p ,int r, int s, int t, int ql){
	ist[ql].right = -1;
	ist[r].right = s;
	ist[r].left = ql;
	ist[s].left = p;
	//�����߶�
	ist[ql].hr = 0; 
	ist[r].hl = ist[r].hr = 0;
	ist[s].hl = 1;
	if(root == ql)	root = r;
}

void insert0(int value){
	node temp;
	temp.val = value;
	temp.left = temp.right = -1;
	temp.hl = temp.hr = 0;
	ist[value] = temp;
	if(root == -1){
		root = value;
	}else{
		int p = root, ql = -1, qr = -1, r = -1, s = -1, t = -1;
		bool flaglr = false, flagrl = false, flagrr = false, flagll = false; 
		while(p != -1){
			r = s; s = t; t = p;//��¼���3������·���Ľڵ� 
			if(value > p){
				ist[p].hr++;
				if(ist[p].hr - ist[p].hl == 2){//��-��=2 
					qr = p;
				}
				p = ist[p].right;
				if(value < p) flagrl = true;//���� 
				if(value > p) flagrr = true;//����	 
			}else if(value < p){
				ist[p].hl++;
				if(ist[p].hl - ist[p].hr == 2){//��-��=2 
					ql = p;
				}
				p = ist[p].left;
				if(value > p) flagll = true;//���� 
				if(value < p) flaglr = true;//���� 
			}else{
				return;
			}
		}
		p = value;
		if(ist[t].val < value) ist[t].left = value;
		if(ist[t].val > value) ist[t].right = value;
		if(flagll) ll(p,r,s);
		if(flagrr) ll(p,r,s);
		if(flaglr) lr(p , r,  s,  t,  qr);
		if(flagrl) lr(p , r,  s,  t,  ql);
	}
	return;
}

void level(int x){
	queue<int> q;
	q.push(x);
	while(q.size()!=0){
		int y = q.front();
		q.pop();
		ans.push_back(y);
		if(ist[y].left != -1){
			q.push(ist[y].left);
		}
		if(ist[y].right != -1){
			q.push(ist[y].right);
		}
	}
}

int main(){
	int n;
	cin>>n;
	
	for(int i=0;i<n;i++){
		int x;
		cin>>x;
		insert0(x);
	}
	level(root);
	for(int i=0;i<ans.size();i++){
		if(i!=0){
			cout<<" "; 
		}
		cout<<ans[i];
	}
	return 0;
} 
