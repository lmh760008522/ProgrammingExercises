#include<iostream>
#include<string>
#include<set>
#include<vector>
using namespace std;

int main(){
	int m, n, s;//总人数，跳过人数，第一个赢家的编号 
	cin>>m>>n>>s;
	int count = 0, p = 0;
	set<string> winners;
	vector<string> ans;//要按照输入的顺序输出，set本身自带排序 
	for(int i=1;i<=m;i++){
		string name;
		cin>>name;
		if(i == count*n + s + p){
			if(winners.find(name) == winners.end()){
				winners.insert(name);
				ans.push_back(name); 
				count++;
			}else{
				p++; 
			}
		}
	}
	for(int i=0;i<ans.size();i++){
		cout<<ans[i]<<endl;
	}
	if(ans.size()==0){
		cout<<"Keep going..."<<endl;
	}
	return 0;
} 
