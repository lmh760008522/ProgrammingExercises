/*
给出所有情侣和参加派对的人，找出参加派对的人哪些是单身。
(情侣必须两个人都到才可以) 
用int会把0和00000混淆，所以还是用string吧 
*/
#include<iostream>
#include<vector>
#include<algorithm> 
#include<map>
#include<set>
#include<string> 
using namespace std;
int main(){
	int n; //n<=50000,情侣总数
	cin>>n;
	map<string ,string> coupleList;
	for(int i=0;i<n;i++){
		string a,b;
		cin>>a>>b;
		coupleList[a] = b;
		coupleList[b] = a;
	} 
	int m; //<=10000,参加派对的人数
	cin>>m; 
	set<string> option;
	vector<string> ans; 
	for(int i=0;i<m;i++){
		string x;
		cin>>x;
		if(coupleList[x] == ""){//若不存在 
			ans.push_back(x);
		}else{
			option.insert(x);
		}
	} 
	set<string>::iterator iter;
	for(iter = option.begin(); iter != option.end(); iter++){
		if(option.find(coupleList[*iter]) == option.end()){//若找不到 
			ans.push_back(*iter);
		}
	}
	sort(ans.begin(), ans.end());
	cout<<ans.size()<<endl;
	for(int i=0;i<ans.size();i++){
		if( i != 0){
			cout<<" ";
		}
		cout<<ans[i];
	}
	return 0;
}
