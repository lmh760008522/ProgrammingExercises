#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<string> dic;

int main(){
	while(1){
		string s;
		cin>>s;
		if(s=="#"){
			break;
		}
		dic.push_back(s);
	}
	//sort(dic.begin(),dic.end());
	for(int i=0;i<dic.size();i++){
		cout<<dic[i]<<" ";
	}
	
	while(1){
		string s;
		cin>>s;
		if(s=="#"){
			break;
		}
		for(int i=0;i<dic.size();i++){
			if(dic[i]==s){
				cout<<s<<" is correct"<<endl;
				break;
			}else{
				string s0=dic[i];
				for(int j=0,k=0;j<s0.length();j++){
					if( abs(s0.length()-s.length())<=1){
						
					}else{
						break;
					}
				}
			}
		}
	}
	
	return 0;
} 
