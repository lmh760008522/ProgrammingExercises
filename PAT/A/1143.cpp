//在二叉搜索树中的最近祖先 
//转化成知道先序、中序（从小到大顺序）求最近祖先 
#include<stdio.h>
#include<vector>
#include<map>
using namespace std;

int main(){
	int m,n;
	scanf("%d %d", &m, &n);
	vector<int> preorder(n);
	map<int, bool> mp;
	for(int i=0;i<n;i++){
		scanf("%d", &preorder[i]);
		mp[preorder[i]] = true;
	}
	
	for(int i=0;i<m;i++){
		int u,v;
		scanf("%d %d", &u, &v);
		if(mp[u] == false && mp[v] == true){
			printf("ERROR: %d is not found.\n", u);
			continue;
		}else if(mp[v] == false && mp[u] == true){
			printf("ERROR: %d is not found.\n", v);
			continue;
		}else if(mp[v] == false && mp[u] == false){
			printf("ERROR: %d and %d are not found.\n", u, v);
			continue;
		}
		int anc;
		for(int j=0;j<n;j++){
			anc = preorder[j];
			if( (anc >=u && anc <=v ) || (anc >=v && anc <=u )){
				break;
			}
		}
		if(anc == u){
			printf("%d is an ancestor of %d.\n", u, v);
		}else if(anc == v){
			printf("%d is an ancestor of %d.\n", v, u);
		}else{
			printf("LCA of %d and %d is %d.\n", u, v, anc);
		}
	}
	return 0;
} 
