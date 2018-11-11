#include<cstdio>
#include<vector>
#include<queue>
using namespace std;

vector<int> edge[501];
queue<int> q;

int main(){
	int indegree[501];
	int n,m;
	scanf("%d %d",&n,&m);
	while(!(n==0 && m==0)){
		for(int i=0;i<n;i++){
			indegree[i]=0;
			edge[i].clear();
		}
		
		for(int i=0;i<m;i++){
			int a,b;
			scanf("%d %d",&a,&b);
			indegree[b]++;
			edge[a].push_back(b);
		}
		
		while(q.empty()==false) q.pop();
		
		for(int i=0;i<n;i++){
			if(indegree[i]==0){
				q.push(i);
			}
		}
		/*
		for(int i=0;i<n;i++){
			printf("%d ",indegree[i]);
		}
		printf("\n");
		*/
		int ans=0;
		while(q.empty()==false){
			int a=q.front();
			q.pop();
			ans++;
			//printf("%d \",ans);
			for(int i=0;i<edge[a].size();i++){
				//printf("indegree:%d ", indegree[edge[a][i]]);
				indegree[edge[a][i]]--;
				if(indegree[edge[a][i]]==0){
					//printf("edge[a][i]: %d \n" ,edge[a][i]);
					q.push(edge[a][i]);
				}
			}
		}
		
		printf("  -------%d ",ans);
		if(ans==n){
			printf("YES\n");
		}else{
			printf("NO\n");
		}
		
		scanf("%d %d",&n,&m);
	}
	return 0;
}
