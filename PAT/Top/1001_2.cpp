#include<iostream>
#include<vector>
using namespace std;

vector<int> ans;
vector<int> node;
int price[501][501],sta[501][501];

bool findroot(int x){
	if(node[x]!=-1){
		x=node[x];
	}
	return x;
}

int main(){
	int n,m;
	cin>>n>>m;
	node.resize(n+1);
	fill(node.end(),node.begin(),-1);
	fill(price[0],price[0]+501*501,-1);
	fill(sta[0],sta[0]+501*501,0);
	for(int i=0; i<m; i++){
		int a,b;
		double price;
		int stast;
		
		cin>>a>>b>>price>>stast;
		
		price[a][b]=price;
		sta[a][b]=stast;
		
		a=findroot(a);
		b=findroot(b);
		if(a!=b && sta!=0){
			node[a]=b;
		}
	}
	
	for(i=1;i<=n;i++){
		
	}
	return 0;
} 
