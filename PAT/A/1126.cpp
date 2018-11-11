#include<iostream>
#include<vector>
#include<string.h>
using namespace std;

typedef struct EDGE{
	int start,end;
	bool visit;
}edge;

int n,m;
vector<edge> e;
int num_node[510];

int main(){
	
	memset(num_node,0,sizeof(num_node));
	
	cin>>n>>m;
	e.resize(m);
	
	for(int i=0;i<m;i++){
		cin>>e[i].start>>e[i].end;
		e[i].visit=false;
		num_node[e[i].start]++;
		num_node[e[i].end]++;
	}
	
	int count=0;
	for(int i=1;i<=n;i++){
		cout<<num_node[i];
		if(num_node[i] %2 != 0 ){
			count++;
		}
		if(i!=n){
			cout<<" ";
		}else{
			cout<<endl;
		}
	}
	
	if(count != 2 &&count != 0){
		printf("Non-Eulerian");
		return 0;
	}
	
	bool flag = true;
	int s = e[0].start;
	int d = e[0].end;
	int numedge=0;
	e[0].visit = true;
	numedge++;
	while( d!= s && numedge == m){
		int i;
		for(i=1;i<m;i++){
			if(e[i].visit == false && e[i].start==d){
				if(numedge <m){
					d=e[i].end;
					break;
				}
				else{
					continue;
				}
			}
		}
		if(i==m){//ÈôÃ»ÕÒµ½ 
			flag == false;
		}	
	}
	
	if(flag){
		if(count == 0){
			cout<<"Eulerian";
		}else{
			cout<<"Semi-Eulerian";
		}
	}else{
		cout<<"Non-Eulerian";
	}
	
	return 0;
} 
