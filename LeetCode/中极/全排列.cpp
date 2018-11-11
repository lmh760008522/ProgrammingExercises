#include<cstdio>
#include<vector>
using namespace std;

vector<int> v,visit;
int n;
void shengcheng(int m,vector<int> v,vector<int> visit){
	if(n==m){
		for(int i=0;i<v.size();i++){
			printf("%d ",v[i]);
		}
		printf("\n");
		return;
	}
	for(int i=1;i<=n;i++){
		if(visit[i]==0){
			visit[i]=1; 
			v.push_back(i);
			shengcheng(m+1,v,visit);
			v.pop_back();
			visit[i]=0;
		}
	}
}

int main(){
	scanf("%d",&n);
	visit.resize(n+1);
	shengcheng(0,v,visit);
	return 0;
}  
