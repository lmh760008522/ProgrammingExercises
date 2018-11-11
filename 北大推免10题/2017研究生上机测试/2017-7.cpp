#include<cstdio>
#include<vector>
#include<string.h>
#include<algorithm>
using namespace std;

int main(){
	int v,a;
	scanf("%d %d",&v,&a);
	vector<int> visit,rudu;
	vector<vector<int> > e;
	rudu.resize(v+1);
	e.resize(v+1);
	for(int i=0;i<a;i++){
		int s,b;
		scanf("%d %d",&s,&b);
		rudu[b]++;
		e[s].push_back(b);
	}
	for(int i=1;i<v+1;i++){
		if(rudu[i]==0){
			for(int j=0;i<e[i].size();j++){
				rudu[j]--;
			}
			visit.push_back(i);
		}
	}
	printf("%d",visit.size());
	while(visit.size()!=0){
		sort(visit.begin(),visit.end());
		for(int i=0;i<visit.size();i++){
			printf("v%d ",visit[i]);
		}
		visit.clear();
		for(int i=1;i<v+1;i++){
			if(rudu[i]==0){
				for(int j=0;i<e[i].size();j++){
					rudu[j]--;
				}
				visit.push_back(i);
			}
		}
		printf("%d",visit.size());
	}
	return 0;
}
