#include<iostream>
#include<vector>
using namespace std;
int num[10001];

int findroot(int x){
	if(num[x]==-1) return x;
	x=num[x];
	findroot(x);
}
int main(){
	int n;
	cin>>n;
	fill(num,num+10001,-1);
	vector<int> v;
	int maxid=0;
	for(int i=0;i<n;i++){
		int k;
		cin>>k;
		v.resize(k);
		for(int j=0;j<k;j++){
			cin>>v[j];
			if(v[j]>maxid){
				maxid=v[j];
			}
		}
		for(int j=0;j<k-1;j++){
			int a = findroot(v[j]);
			int b = findroot(v[j+1]);
			if(a!=b){
				num[a]=b;
			}
		}
	}
	
	int count=0;
	for(int i=1;i<=maxid;i++){
		if(num[i]==-1){
			count++;
		}
	}
	cout<<count<<" "<<maxid<<endl;
	int q;
	cin>>q;
	for(int i=0;i<q;i++){
		int a,b;
		cin>>a>>b;
		if(findroot(a) == findroot(b)){
			cout<<"Yes"<<endl;
		}else{
			cout<<"No"<<endl;
		}
	}
	return 0;
} 
