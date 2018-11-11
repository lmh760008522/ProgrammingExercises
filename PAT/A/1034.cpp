#include<cstdio>
#include<iostream>
#include<string>
#include<vector>
#include<map>
using namespace std;

typedef struct ans{
	string id;
	int max_id;
}ans;
int weight[1000][1000];
int num[1000];
map<string, int> change;
bool visit[1000];
int nn=0;
int head;
vector<ans> a;

void dfs(int x,int &total, int &head){
	visit[x]=true;
	if(num[x]>num[head]){
		head = x;
	}
	for(int v=0;v<nn;v++){
		if(weight[v]>0){
			total+=weight[x][v];
			if(visit[v]== false){
				dfs(v, total,head);
			}
		}
	}
}

bool cmp(ans a,ans b){
	if(a.id[0] != b.id[0]){
		return a.id[0]<b.id[0];
	}else if(a.id[1] != b.id[1]){
		return a.id[1]<b.id[1];
	}else{
		return a.id[2]<b.id[2];
	}
}
int main(){
	int n,k;
	cin>>n>>k;
	
	fill(num,num+1000,0);
	fill(weight, weight+1000*1000,0);
	fill(visit, visit+1000,false);
	
	
	for (int i=0;i<n;i++){
		string a,b;
		int c;
		cin>>a>>b>>c;
		if(change.find(a) != change.end()){
			m.insert(make_pair(a,nn++));
		}
		if(change.find(b) != change.end()){
			m.insert(make_pair(b,nn++));
		}
		weight[change[a]][change[b]] = c;
		num[change[a]]++;
		num[change[b]]++;
	}
	
	int bang_num=0;
	
//	vector<string>
	for(int i=0;i<nn;i++){
		if(visit[i] == false){
			bang_num++;
			head=i;
			int total=0;
			dfs(i,total,head);
			a.push_back(change[i],head);//?
		}
	}
	
	sort(a,a+a.size(),cmp);
	
	printf("%d\n", bang_num);
	for(int i=0;i<ans.size();i++){
		printf("%s %d\n", a[i].id,a[i].max_id );
	}
	return 0;
} 
