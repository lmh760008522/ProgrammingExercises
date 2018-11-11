#include<iostream>
#include<set>
using namespace std;
typedef struct edge{
	int n1,n2;
}edge;
//vector<edge> e;
int e[201][201];
int main(){
	int n,m;
	cin>>n>>m;
//	e.resize(m);
	for(int i=0;i<m;i++){
		//cin>>m[i].n1>>m[i].n2;
		int a,b;
		cin>>a>>b;
		e[a][b]=1;
		e[b][a]=1;
	}
	
	int k;
	cin>>k;
	set<int> s;
	for(int i=0;i<k;i++){
		int nn=0;
		cin>>nn;
		s.clear();
		int flag=true;
		
		if(nn!=n+1){
			flag=false;
		}
		
		int a,b,begin;
		cin>>begin;
		a=begin;
		for(int j=1;j<nn;j++){
			cin>>b;
			if(s.count(b)!=0 || e[a][b]==0 ||j!=nn-1 && b==begin || j==nn-1&&b!=begin){
				flag=false;
			}
			a=b;
			s.insert(b);
		}
		
		if(flag){
			cout<<"YES"<<endl;
		}else{
			cout<<"NO"<<endl;
		}
		
	}
	return 0;
} 
