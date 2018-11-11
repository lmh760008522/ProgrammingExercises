#include<cstdio>
#include<vector>
#include<algorithm>
#include<cstring>
#include<set>
using namespace std;

int father[100010];
vector<int> e[100010];
bool isroot[10010];
int maxh=0;
vector<int> temp,ans;

int findroot(int x){
	if(father[x]==-1){
		return x;
	}else{
		int temp=findroot(x);
		father[x]=temp;
		return temp;
	}
}

void dfs(int u,int h,int pre){
	if(h>maxh){
		maxh=h;
		temp.clear();
		temp.push_back(u);
	}else if(maxh == h){
		temp.push_back(u);
	}
	for(int i=0;i<e[u].size();i++){
		if(e[u][i]!=pre){
			dfs(e[u][i],h+1,i);
		}
	}
}

int main(){
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		father[i]=-1;
	}
	for(int i=1;i<=n;i++){
		int a,b;
		//printf("?");
		scanf("%d %d",&a,&b);
		e[a].push_back(b);
		e[b].push_back(a);
		a=findroot(a);
		b=findroot(b);
		//printf("?");
		if(a!=b){
			father[a]=b;
		}
		//printf("?");
	}
	int block=0;
	for(int i=1;i<=n;i++){
		isroot[ findroot(i) ]=true;
	}
	for(int i=1;i<=n;i++){
		block+=isroot[i];
	}
	if(block!=1){
		printf("ERROR:%d\n",block);
		return 0;
	}
	dfs(1,1,-1);
	ans=temp;
	dfs(ans[0],1,-1);
	set<int> s;
	for(int i=0;i<ans.size();i++){
		s.insert(ans[i]);
	}
	for(int i=0;i<temp.size();i++){
		s.insert(temp[i]);
	}
	set<int>::iterator iter;
	for(iter=s.begin();iter!=s.end();iter++){
		printf("%d ",*iter);
	}  
	return 0;
	
}
