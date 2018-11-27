/*
analogously ���Ƶ� 
A-C-D-B
�����ͬ��������ôҪ��֤a�ҵ����Ѳ�����b��b�ҵ����Ѳ�����a   3.4�������� 
���ǵ�0000֮��ģ���������string���� 
��5�����г�ʱ 
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

map<string, bool> gender;//��¼�Ա� 
map<string, vector<string> > relation;//��¼��ϵ 
bool e[10000][10000];//��¼�Ƿ���ڹ�ϵ 

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
