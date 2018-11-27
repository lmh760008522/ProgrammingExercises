/*
analogously 类似的 
A-C-D-B
如果是同性恋，那么要保证a找的朋友不能是b，b找的朋友不能是a   3.4测试用例 
考虑到0000之类的，还是用了string读入 
第5个运行超时 
*/
#include<stdio.h>
#include<vector>
#include<algorithm>
#include<map>
#include<string>
#include<iostream>
using namespace std;

typedef struct node{
	string c,d;
}node;

map<string, bool> gender;//记录性别 
map<string, vector<string> > relation;//记录关系 
bool e[10000][10000];//记录是否存在关系 

bool cmp(node a, node b){
	if(a.c == b.c){
		return a.d < b.d;
	}
	return a.c < b.c;
}

int main(){
	int n,m;
	scanf("%d %d", &n, &m);
	for(int i=0;i<m;i++){
		string s1, s2;
		cin>>s1>>s2;
		if(s1.length() == 5){
			s1.erase(0,1);
			gender[s1] = true;
		}else{
			gender[s1] = false;
		}
		if(s2.length() == 5){
			s2.erase(0,1);
			gender[s2] = true;
		}else{
			gender[s2] = false;
		}
		relation[s1].push_back(s2); 
		relation[s2].push_back(s1);
		e[atoi(s1.c_str())][atoi(s2.c_str())] = e[atoi(s2.c_str())][atoi(s1.c_str())] = true;
	}
	
	int k;
	scanf("%d", &k);
	for(int i=0;i<k;i++){
		string s1, s2;
		cin>>s1>>s2;
		if(s1.length() == 5){
			s1.erase(0,1);
		}
		if(s2.length() == 5){
			s2.erase(0,1);
		}
		vector<node> ans;
		for(int j=0;j<relation[s1].size();j++){
			if(gender[relation[s1][j]] == gender[s1] && relation[s1][j] != s2){
				for(int p=0;p<relation[relation[s1][j]].size();p++){
					if(gender[relation[relation[s1][j]][p]] == gender[s2] && relation[relation[s1][j]][p]!=s1){
						if(e[ atoi(relation[relation[s1][j]][p].c_str()) ][ atoi(s2.c_str()) ] == true){
							node temp;
							temp.c = relation[s1][j];
							temp.d = relation[relation[s1][j]][p];
							ans.push_back(temp);
						}
					}
				} 
			}
		}
		sort(ans.begin(),ans.end(),cmp);
		printf("%d\n",ans.size());
		for(int j=0;j<ans.size();j++){
			cout<<ans[j].c<<" "<<ans[j].d<<endl;
		}
	}
	return 0;
} 
