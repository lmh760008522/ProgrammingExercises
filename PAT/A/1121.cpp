#include<iostream>
#include<vector>
#include<map>
#include<set>
using namespace std;
//别写了 思路不对 
int main(){
	int n;
	cin>>n;

	map<int ,int> id;
	for(int i=0;i<n;i++){
		int a,b;
		cin>>a>>b;
		id[a]=b;
		id[b]=a;
	}
	/*
	map<int ,int>::iterator it3=id.begin(); 
	for( ;it3!=id.end();it3++){
		cout<<it3->first<<" "<<it3->second<<" "<<endl;
	}*/
	
	int m;
	cin>>m;
	map<int,bool> v;
	for(int i=0;i<m;i++){
		int x;
		cin>>x;
		v[x]=false;
	}
	
	int count=m;
	map<int ,bool>::iterator it1,it2;
	for(int i=0;i<m-1;i++){
		it1=it1+i;
		if(id.find(it1)== id.end()){
			cout<<"no"<<endl;
			continue;
		}
		for(int j=i+1;j<m;j++){
			it2=it1+j;
			//cout<<"1:"<<id.find(v[i])->first<<" 2:"<<id.find(v[i])->second<<endl;
			if(id.find(it2)->second==j ){
				count-=2;
				v[i]=true;
				v[j]=true;
			}
		}
	}
	
	cout<<count<<endl;
	
	set<int> s;
	it1=v.begin(); 
	for( ;it1!=v.end();it1++){
		if(it1->second ==false){
			s.insert(it1->first);
		}
	}
	set<int>::iterator it2=s.begin();
	int k=0;
	for( ;it2!=s.end();it2++,k++){
		cout<<*it2;
		if(k!=count-1){
			cout<<" ";
		}else{
			cout<<endl;
		}
	}
	return 0;
}
