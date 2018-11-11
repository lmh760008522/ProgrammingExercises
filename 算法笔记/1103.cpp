#include<cstdio>
#include<cmath>
#include<vector>
using namespace std;

int cun[401];
int n,k,p;
vector<int> ans;

bool dfs(int count,int sum,int start){
	if(count==k && sum==n){
		return true;
	}else if(count==k && sum!=n){
		return false;
	}else if(sum==n && count!=k){
		dfs(0,0,ans[0]);
		ans.clear();
	}else{
		for(int i=start;i<n;i++){
			if(sum+cun[i]<=n){
				sum+=cun[i];
				start=i;
				ans.push_back(n-i);
				//printf("%d\n",n-i);
				break;
			}
		}
		dfs(count+1,sum,start);
	}
}

int main(){
	scanf("%d %d %d",&n,&k,&p);
	for(int i=n;i>=0;i--){
		cun[n-i]=pow(i,p);
	}
	int flag=dfs(0,0,0);
	if(flag){
		for(int i=0;i<ans.size();i++){
			printf("%d ",ans[i]);
		}
	}else{
		printf("Impossible.\n");
	}
	return 0;
} 
