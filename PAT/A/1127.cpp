#include<iostream>
#include<vector>
#include<string.h>
using namespace std;
vector<int> post,in;
vector<int> level[30];
int numlevel[30];
int n;
int maxlevel=0;
//思路错误，因为不是完全二叉树，所以用Index的方法需要开很大的数组 
void levelorder(int il,int ir,int root,int l){
	if(il>ir) {
		return;
	}
	int right=ir;
	while(in[ir]!=post[root]&&ir>=0){
		ir--;
	}
	level[l].push_back(post[root]);
	levelorder(il,ir-1,root-1-right+ir,l+1);
	levelorder(ir+1,right,root-1,l+1);
}

void dfs(int il,int ir,int root,int l){
	if(il>ir) {
		return;
	}
	int right=ir;
	while(in[ir]!=post[root]&&ir>=0){
		ir--;
	}
	if(l>maxlevel) maxlevel=l;
	numlevel[l]=numlevel[l]+1;//统计每层节点个数 
	dfs(il,ir-1,root-1-right+ir,l+1);
	dfs(ir+1,right,root-1,l+1);
}

int main(){
	
	cin>>n;
	
	post.resize(n);
	in.resize(n);
	//level.resize(n);
	//numlevel.resize(n);
	//memset(level,0,sizeof(level));
	memset(numlevel,0,sizeof(numlevel));
	
	for(int i=0;i<n;i++){
		cin>>in[i];
	}
	for(int i=0;i<n;i++){
		cin>>post[i];
	}
	
	dfs(0,n-1,n-1,0);
	
	levelorder(0,n-1,n-1,0);
	
	int num=0;
	for(int i=0;i<=maxlevel;i++){
		if(i % 2 !=0 ){
			for(int j=0;j<level[i].size();j++){
				printf("%d",level[i][j]);
				num++;
				if(num!=n){
					printf(" ");
				}
			}
			
		}else{
			for(int j=level[i].size()-1;j>=0;j--){
				printf("%d",level[i][j]);
				num++;
				if(num!=n){
					printf(" ");
				}
			}
			
		}
		
	} 
	return 0;
}
