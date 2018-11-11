#include<iostream>
#include<vector>
using namespace std;
//死循环，大概思路不对 
typedef struct person{
	int id;
	int fa,ma;
	int k;
	int child[5];
	int num;
	double area;
}person;

person p[1000];
//bool e[10000][10000];
int visit[10000];
int m=0,sumset,sumarea,minid;

void dfs(int root){
	if(root<minid){
		minid=root;
	}
	if(visit[root]<=0){
		m++;
		return;
	}
	m++;
	sumset+=p[ visit[root] ].num;
	sumarea+=p[ visit[root] ].area;
	if(p[ visit[root] ].fa!=-1){
		dfs(p[ visit[root] ].fa);
	}
	if(p[ visit[root] ].ma!=-1){
		dfs(p[ visit[root] ].ma);
	}
	for(int i=0;i<p[ visit[root] ].k;i++){
		dfs(p[ visit[root] ].child[i]);
	}
	return;
}

int main(){
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		int k;
		cin>>p[i].id>>p[i].fa>>p[i].ma>>p[i].k;
		visit[p[i].id]=i;
		if(p[i].fa!=-1){
			//e[i][p[i].fa]=e[p[i].fa][i]=true;
			//visit[p[i].fa]=true;
		}
		if(p[i].ma!=-1){
			//e[i][p[i].ma]=e[p[i].ma][i]=true;
			//visit[p[i].ma]=true;
		}
		for(int j=0;j<p[i].k;j++){
			cin>>p[i].child[j];
			//e[i][p[i].child[j]]=e[p[i].child[j]][i]=true;
			//visit[p[i].child[j]]=true;
		}
		cin>>p[i].num>>p[i].area;
	}
	
	int num=0;
	for(int i=0;i<n;i++){
		if(visit[p[i].id] > 0){
			num++;
			m=0,sumset=0,sumarea=0,minid=100000;
			dfs(p[i].id);
			printf("%d %lf %lf\n",minid,sumset/m,sumarea/m);
		}
	}
	
	return 0;
}
