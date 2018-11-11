#include<iostream>
#include<string>
#include <algorithm>
#include<map>
#include<vector>
#include <set>
#include<queue>
using namespace std;
map<char,int> m;
set<char> visit;
int main(){
	int k;
	string s;
	cin>>k;
	cin>>s;
	for(int i=1;i<k;i++){
		s+="*";
	}
	for(int i=0;i<s.length()-k+1;i++){
		int j;
		for(j=1;j<k;j++){
			if(s[i]!=s[i+j]){
				break;
			}
		}
		if(j==k){
			m[ s[i] ]++;
			i+=k-1;
		}else{
			m[s[i]]=0;
			continue;
		}
	}
	
	for(int i=0;i<s.length()-k+1;i++){
		if(m[s[i]]>=2 && visit.find(s[i])==visit.end() ){
			cout<<s[i];
			i+=k-1;
			visit.insert(s[i]);
		}
	}
	cout<<endl;
	for(int i=0;i<s.length()-k+1;i++){
		if(m[s[i]]<2){
			cout<<s[i];
		}else{
			cout<<s[i];
			i+=k-1;
		}
	}
	return 0;
} 
