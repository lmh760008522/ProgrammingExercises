/*
树中每个节点的值都是不同的正整数。
后序遍历和中序遍历可以唯一的确定一棵树。
知道 后序遍历和中序遍历，先从左到右打印一层的节点，再从右到做打印一层的节点 
*/
#include<iostream>
#include<vector>
#include<map>
#include<queue>
using namespace std;

typedef struct node{
	int root;
	int inp, inq, postp, postq, l;	
	int val;
}node;

int n;
vector<int> in;
vector<int> post;
vector<int> level;
map<int, int> lNum;
queue<node> qu;

//递归转先序 
/*
void ChangePreorder(int inp, int inq, int postp, int postq, int l){
	if(inp > inq || postp > postq){
		return;
	}
	int root = inp;
	while( in[root] != post[postq] && root <= inq){ //后序最后一个值是根的值 
		root++;
	}
	//找到根,加入到层次遍历的序列 
	level.push_back(in[root]);
	//统计每层几个节点 
	lNum[l]++;
	//递归看左右子树
	ChangePreorder(inp, root-1, postp, root-1, l+1); //左子树 
	ChangePreorder(root+1, inq, root, postq-1, l+1); //右子树 
}*/ 

//递归转层次 
void ChangeLevelorder(){
	node temp;
	temp.val = post[n-1]; 
	temp.inp = 0; temp.inq = n-1; temp.postp = 0; temp.postq = n-1;
	temp.l = 0;
	int root = temp.inp;
	level.push_back(post[n-1]);
	lNum[temp.l]++;
	while(in[root] != post[n-1]) root++;
	temp.root = root;
	qu.push(temp);
	while(qu.size() != 0){
		temp = qu.front();
		qu.pop();
		//找左孩子 
		for(int p = temp.inp; p < temp.root; p++){
			if(in[p] == post[temp.postq-(temp.inq-temp.root)-1]){
				node tt;
				tt.l = temp.l + 1;
				tt.val = in[p];
				tt.inp = temp.inp; tt.inq = temp.root-1; tt.postp = temp.postp; tt.postq = temp.postq-(temp.inq-temp.root)-1;	
				tt.root = p;
				qu.push(tt);
				level.push_back(in[p]);
				lNum[tt.l]++;
			}
		}
		//找右孩子 
		for(int p = temp.root+1; p <= temp.inq; p++){
			if(in[p] == post[temp.postq-1]){
				node tt;
				tt.l = temp.l + 1;
				tt.val = in[p];
				tt.inp = temp.root+1; tt.inq = temp.inq; tt.postp = temp.root; tt.postq = temp.postq-1;	
				tt.root = p;
				qu.push(tt);
				level.push_back(in[p]);
				lNum[tt.l]++;
			}
		}
	}
}

int main(){
	cin>>n;
	
	in.resize(n);
	for(int i=0;i<n;i++){
		cin>>in[i];
	}
	post.resize(n);
	for(int i=0;i<n;i++){
		cin>>post[i];
	}

	ChangeLevelorder();
	/* 
	for(int i=0; i<n;i++){
		cout<<level[i]<<" ";
	}
	cout<<endl;
	*/ 
	
	cout<<level[0];//输出根节点 
	int p = 1;
	map<int, int>::iterator iter = lNum.begin();//先让他等于第0层 
	//从第一层开始挨个输出 
	for(iter++; iter != lNum.end(); iter++){
		//cout<<iter->first<<" "<<iter->second<<endl; 
		if(iter->first % 2 ==1){//奇数层从左到右遍历 
			for(int q = p; q < p+iter->second; q++){
				cout<<" "<<level[q];
			} 
		}else{//偶数层从右到左遍历
			for(int q = p+iter->second-1; q >= p; q--){
				cout<<" "<<level[q];
			} 
		}
		p += iter->second;
		//cout<<endl;
	}
	return 0;
} 
