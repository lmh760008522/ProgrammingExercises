#include<cstdio>
#include<vector>
#include<algorithm>
#include<stack>
using namespace std;

int indegree[505];//出去的边 
vector<int> edge[505];//初度数 

int main() {
	int n,m;
	scanf("%d %d",&n,&m);
	for(int i=0;i<=n;i++){
		indegree[i]=0;
		edge[i].clear();
	}
	for(int i=0;i<m;i++){
		int a,b;
		scanf("%d %d",&a,&b);
		indegree[a]++;
		edge[b].push_back(a);
	}
	
	stack<int> q,ans;
	//while(q.empty()==false) q.pop();
	/*
	for(int i=1;i<=n;i++){
		printf("%d ",indegree[i]);
	}
	printf("\n");
	*/
	for(int i=1;i<=n;i++){
		if(indegree[i]==0){
			q.push(i);
		}
	}
	
	while(q.empty()==false){
		int a=q.top();
		q.pop();
		ans.push(a);
		sort(edge[a].begin(),edge[a].end());
		for(int i=0;i<edge[a].size();i++){
			indegree[ edge[a][i] ]--;
			if(indegree[edge[a][i]]==0){
				q.push(edge[a][i]);
			}
		}
	}
	while(ans.empty()==false){
		int a=ans.top();
		ans.pop();
		printf("%d ",a);
	} 
	return 0;
}

