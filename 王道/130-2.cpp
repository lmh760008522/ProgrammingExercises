#include<cstdio>
#include<set>
#include<string>
#include<vector>
#include<map> 
#include<set>
#include<queue>
using namespace std;

//int tree[1001];
/* 
typedef struct node{
	string name;
	int id;
}node;
*/ 
int main(){
	int n;
	while(scanf("%d",&n)!=EOF){
		if(n==0){
			break;
		}
		//memset(indegree,0,sizeof(indegree));
		map<string,string> tree;
		map<string,int> indegree;
		set<string> visit;
		/* 
		set<string> s;
		for(int i=0;i<n;i++){
			tree[i]=-1;
		}*/ 
		for(int i=0;i<n;i++){
			string a,b;
			a.resize(20);
			b.resize(20);
			scanf("%s %s",&a[0],&b[0]);
			if(visit.find(a)==visit.end()){
				indegree[a]=0;
			}
			if(visit.find(b)==visit.end()){
				indegree[b]=0;
			}
			indegree[b]++;
			tree[a]=b;
		}
		int count=0;
		map<string,int>::iterator iter;
		for(iter=indegree.begin();iter!=indegree.end();iter++){
			if(iter->second==0){
				count++;
			}
		}
		if(count==1){
			printf("YES\n");
		}else{
			printf("NO\n");
		}
		
	}
	return 0;
}
