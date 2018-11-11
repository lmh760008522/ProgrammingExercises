#include<map>
#include<iostream>
#include<algorithm>
#include<vector>
#include<cstdio>
using namespace std;

bool cmp(int a, int b){
	return a>=b;
}
int main(){
	int n,k;
	cin>>n>>k;
	map<int ,int> m;
	vector< pair<int ,int> >  v;//注意 两个> 之间要有空格 
	for(int i=0;i<n;i++){
		int j=0;
		cin>>j;
		
		if(i>=1&&i<=k){
			cout<<"%d:%d"<<j<<v.begin()->first;
			int p=2;
			for(auto it = v.begin() ; p<i; p++){
				it++;
				cout<<" %d"<<it->first;
			}
			cout<<endl;
		}else{
			auto it=v.begin();
			cout<<"%d:%d"<<j<<it->first;
			for(int p=2;p<k;p++){
				it++;
				cout<<" %d"<<it->first;
			}
			cout<<endl;
		}
		
		if(m.count(j)==0){
			m.insert(make_pair(j, 1));
		}else{
			m[j]++;
		}
		//sort(m.begin(),m.end(),cmp); 错误的，只能排线性，而map是树形
	
		for(auto it=m.begin();it!=m.end();it++){
			v.push_back(make_pair(it->first,it->second));
		}
		sort(v.begin(),v.end(),
		     [](const pair<int ,int>&x, const pair<int, int> &y)->int{
		     	if(x.second == y.second){
		     		if(x.first < y.first){
		     			return x.second > y.second;
					 }else{
					 	return x.second < y.second;
					 }
				 }else{
				 		return x.second > y.second;
				 }
     	 });
	}
	return 0;
}
