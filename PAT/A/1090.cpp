#include<stdio.h>
#include<iostream>
#include<vector>
#include<math.h>
using namespace std;

int tree[105];
int maxdepth=0,maxnum;
vector<int> v[100010];

void dfs(int index, int depth){
	if(v[index].size()==0){
		if(maxdepth<depth){
			maxdepth=depth;
			maxnum=1;
		}
		if(maxdepth == depth){
			maxnum++;
		}
		return;
	}
	for(int i=0;i<v[index].size();i++){
		dfs(v[index][i],depth+1);
	}
}

int main(){
	int n;
	double p,r;
	int root;
	for(int i =0;i<n;i++){
		int temp;
		cin>>temp;
		if( temp ==-1 ){
			root = i;
		}
		v[temp].push_back(i);
	}
	dfs(root,0);
	
	printf("%.2f %d", p * pow(1 + r/100, maxdepth), maxnum);
	return 0;
}
