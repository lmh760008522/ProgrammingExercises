/*
坏的键盘可能会连续打出K个字母。
给你一个字符串(由a-z, 0-9 和 '_' 组成，不超过1000个字符)， 
指出可能坏了的键，以及原始的字符串。 
*/
#include<iostream>
#include<string>
#include<vector> 
#include<set>
#include<map>
using namespace std;

int main(){
	int k;
	cin>>k;
	string s;
	cin>>s;
	map<char, vector<int> > mp;
	for(int i=0;i<s.length(); ){
		int count = 0;
		while( i+ count < s.length() && s[i] == s[i+count]) count++;
		mp[s[i]].push_back(count);
		i += count;
	}
	
	set<char> wrong; //记录错误字母 
	map<char, vector<int> >::iterator iter;
	for(iter = mp.begin(); iter != mp.end(); iter++){
		bool flag = true;
		for(int j=0; j < mp[iter->first].size(); j++){
			if(mp[iter->first][j] % k != 0){ //但凡有一个值不为k都不是错的 
				flag = false;
				break;
			}
		}
		if(flag) wrong.insert(iter->first);
	}
	
	set<char> exist; //记录已输出字母 
	for(int i = 0;i<s.length();i++){
		if(wrong.find(s[i]) != wrong.end()){ //若是错误字母 
			s.erase(i+1,k-1); //删除后面k-1个
			if(exist.find(s[i]) == exist.end()){
				cout<<s[i];
				exist.insert(s[i]);
			}
		}
	} 
	cout<<endl<<s;
	return 0;
} 
