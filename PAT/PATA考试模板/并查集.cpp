/*
鸟的编号不连续 
并查集 
*/
#include<iostream>
using namespace std;

int a[10005];
int n; // <= 10^4
bool visit[10005];

int find(int x){
	if(a[x] == -1) return x;
	return a[x] = find(a[x]); // 路径压缩 
}

int main(){
	
	cin>>n;
	fill(a, a+10005, -1);
	for(int i=0;i<n;i++){
		int k;
		cin>>k;
		int s,t;
		cin>>s;
		visit[s] = true;
		for(int j=1;j<k;j++){
			cin>>t;
			visit[t] = true;
			int ss = find(s);
			int tt = find(t);
			if(ss != tt){
				a[ss] = tt;
			}
			s = t;
		}
	}
	
	int sum = 0, birdnum = 0;
	for(int i=0;i<10005;i++){
		if(visit[i] == true && a[i] == -1){
			sum++;
		}
		if(visit[i] == true){
			birdnum++;
		}
	}

	cout<<sum<<" "<<birdnum<<endl;
	
	int q; // <= 10^4
	cin>>q;
	for(int i=0;i<q;i++){
		int a,b;
		cin>>a>>b;
		if(find(a) == find(b)){
			cout<<"Yes"<<endl;
		}else{
			cout<<"No"<<endl;
		}
	}
	return 0;
}
