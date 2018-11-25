//知道先序中序，找出最近祖先
#include<stdio.h>
#include<vector>
#include<map> 
using namespace std;

int m,n;
int p_in, q_in;
int p_pre, q_pre;
int anc;
map<int, bool> mp;
vector<int> inorder;
vector<int> preorder;

int find(int st_in, int en_in, int st_pre, int en_pre){
	//首先找到根节点
	int root;
	for(int i=st_in; i<=en_in; i++){
		if(inorder[i] == preorder[st_pre]){
			root = i;
			break;
		}
	}
	if(p_in < root && q_in < root){//都在左子树 
		find(st_in, root-1, st_pre+1, st_pre+(root-st_in)+1);
	}else if(p_in > root && q_in > root){//都在右子树 
		find(root+1, en_in, root+1, en_pre-(en_in-root)+1);
	}else{
		return inorder[root];
	}
} 

int main(){
	
	scanf("%d %d", &m, &n);
	
	inorder.resize(n);
	preorder.resize(n);
	
	for(int i=0;i<n;i++){
		scanf("%d", &inorder[i]);
		mp[inorder[i]] = true;
	}
	for(int i=0;i<n;i++){
		scanf("%d", &preorder[i]);
	}
	for(int i=0;i<m;i++){
		int u, v;
		scanf("%d %d", &u, &v);
		//先判断u,v是否存在 
		bool exist_u = true, exist_v = true;
		if( mp[u] != true ){
			exist_u = false;
		}
		if( mp[v] != true ){
			exist_v = false;
		}
		if(exist_u == false && exist_v == false){
			printf("ERROR: %d and %d are not found.\n", u, v);
			continue;
		}else if(exist_u == false){
			printf("ERROR: %d is not found.\n", u);
			continue;
		}else if(exist_v == false){
			printf("ERROR: %d is not found.\n", v);
			continue;
		}
		//首先在序列中定位
		for(int i=0;i<n;i++){
			if(inorder[i] == u){
				p_in = i;
			}
			if(inorder[i] == v){
				q_in = i;
			}
		}
		for(int i=0;i<n;i++){
			if(preorder[i] == u){
				p_pre = i;
			}
			if(preorder[i] == v){
				q_pre = i;
			}
		} 
		 
		anc = find(0,n-1,0,n-1);
		
		if( anc != u && anc != v){
			printf("LCA of %d and %d is %d.\n", u, v, anc);
		}else if(anc == u){
			printf("%d is an ancestor of %d.\n", u, v);
		}else{
			printf("%d is an ancestor of %d.\n", v, u);
		}
	}
	
	return 0;
} 
