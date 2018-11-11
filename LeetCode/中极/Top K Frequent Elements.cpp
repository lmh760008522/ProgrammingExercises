#include<cstdio>
#include<queue>
using namespace std;
int main(){
	int a[6]={1,1,1,2,2,3};
	int n=6;
	int hash[4];
	priority_queue<pair<int ,int > > qq;
	int k=2;
	int max=0;
	for(int i=0;i<n;i++){
		hash[ a[i] ]++;
	}
	for(int i=0;i<4;i++){
		qq.push( make_pair(hash[i],i));
	}
	for(int i=0;i<k;i++){
		printf("%d ",qq.top().second);
		qq.pop();
	}
	return 0;
}
