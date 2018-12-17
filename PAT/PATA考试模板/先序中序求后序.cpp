/*
排序二叉树
已知先序遍历，说明他是排序二叉树还是排序二叉树的镜像（即交换左右子数）； 
若是 排序二叉树还是排序二叉树的镜像 ，则输出 后序遍历。 
*/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int n; //<=1000
vector<int> pre, in, post;
bool flag = true; 
int is = 0;
 
void check1(int root, int end){
	if(root >= end) return;
	int p = root + 1, rst;
	while( p < end && pre[root] <= pre[p] ) p++;
	for(rst = p; p < end; p++){
		if(pre[root] <= pre[p]){
			flag = false;
			return;
		}
	}
	check1(root+1, rst); //检查左
	check1(rst, end); //检查右 
	return;
}

void check2(int root, int end){
	if(root >= end) return;
	int p = root + 1, rst;
	while( p < end && pre[root] > pre[p] ) p++;
	for(rst = p; p < end; p++){
		if(pre[root] > pre[p]){
			flag = false;
			return;
		}
	}
	check2(root+1, rst); //检查左
	check2(rst, end); //检查右 
}

void reverse(int prep,int preq, int inp, int inq){
	if(prep >= preq || inp >= inq) return;
	int inroot;
	for(inroot = inp; inroot < inq; inroot++){
		if(pre[prep] == in[inroot]){
			if(is == 1){ // 如果是镜像，找到相同的值得最后一个 
				for(int i = inroot+1; i<inq; i++){
					if(pre[prep] != in[i]){
						inroot = i-1;
						break;
					}
				}
			}
			break;
		}
	}
	reverse(prep+1, prep + 1 + inroot - inp , inp, inroot );
	reverse(prep + 1 + inroot - inp, preq, inroot +1, inq );
	post.push_back(pre[prep]);
}

int main(){
	
	cin>>n;
	pre.resize(n);
	in.resize(n);
	for(int i=0;i<n;i++){
		cin>>pre[i];
	}
	in = pre;
	
	if(pre[0] <= pre[1]){//是镜像 
		is = 1;
		sort(in.begin(), in.end(), greater<int>() ); //从大到小即是中序遍历。
		check1(0,n); 
	}else{
		sort(in.begin(), in.end()); //从小到大即是中序遍历。
		check2(0,n); 
	}
	if(!flag){
		cout<<"NO"<<endl;
	}else{
		cout<<"YES"<<endl;
		reverse(0,n,0,n);
		for(int i=0;i<n;i++){
			if(i!=0){
				cout<<" ";
			}
			cout<<post[i];
		}
	}	 
	return 0;
} 
