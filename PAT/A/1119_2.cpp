/*
给出后序和先序，输出中序。
若不唯一，输出任何一个可能值。 
*/
#include<iostream>
#include<vector>
#include<stack>
using namespace std;

int n; //<=30
vector<int> pre;
vector<int> post;
vector<int> in;
bool flag = true; // 标记是否唯一 
stack<int> s;

void reverse(int prep, int preq, int postp, int postq){
	if(prep > preq || postp > postq || prep<0 || preq>=n || postp<0 || postq >=n){
		return;
	}
	if(prep == preq){
		in.push_back(pre[prep]);
		if(s.size()!=0){
			in.push_back(s.top());
			s.pop();
		}
		return;
	}
	s.push(pre[prep]);//将根节点放入栈 
	if(pre[prep+1] == post[postq-1]){
		flag = false;
		reverse(prep+1, preq, postp, postq-1);
	}else{
		//寻找根节点 
		int rroot;
		for(int i = prep+2; i<=preq; i++){
			if(pre[i] == post[postq-1]){
				rroot = i;
				break;
			}
		}
		reverse(prep+1, rroot-1, postp, postp + rroot - prep -1 -1);
		reverse(rroot, preq, postp + rroot - prep -1, postq-1);
	}
}

int main(){
	
	cin>>n;
	
	pre.resize(n+1);
	for(int i=0;i<n;i++){
		int x;
		cin>>x;
		pre[i] = x; 
	}
	post.resize(n+1);
	for(int i=0;i<n;i++){
		int x;
		cin>>x;
		post[i] = x; 
	}
	//in.resize(n+1); 因为之前用的push_back所以初始化之后是在0后面添加 
	reverse(0,n-1,0,n-1);
	while(s.size()!=0){
		in.push_back(s.top());
		s.pop();
	}
	if(flag){
		cout<<"Yes"<<endl;
	}else{
		cout<<"No"<<endl;
	}
	for(int i=0;i<in.size();i++){
		if(i != 0){
			cout<<" ";
		}
		cout<<in[i];
	}
	return 0;
} 
