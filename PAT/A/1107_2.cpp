/*
并查集 
*/
#include<iostream>
#include<cstdio>
#include<vector>
#include<map>
#include<set>
#include<algorithm>
using namespace std;

int n;  //<=1000
int table[1005];

int find(int x){
	if(table[x] == -1) return x;
	return table[x] = find(table[x]);
}

bool cmp(int a, int b){
	return a >= b;
}

int main(){
	
	cin>>n;
	fill(table,table+1005, -1);
	set<int> hobby; //爱好数不重复 
	int ren[1005];
	for(int i=1;i<=n;i++){
		int k,st,en;
		scanf("%d:",&k);
		cin>>st;
		ren[i] = st;
		hobby.insert(st); 
		for(int j=1;j<k;j++){
			cin>>en;
			hobby.insert(en); 
			if(find(st) != find(en)){
				table[find(st)] = find(en);
			}
			st = en;
		}	
	}
	
	int count = 0;
	set<int>::iterator iter;
	for(iter = hobby.begin(); iter != hobby.end(); iter++){
		if(table[*iter] == -1){
			count++;
		}
	} 
	
	map<int, int> num; //用于统计每从的人数 
	for(int i=1;i<=n;i++){
		num[find(ren[i])]++;
	}
	
	vector<int> ans;
	map<int ,int>::iterator it;
	for(it = num.begin(); it!=num.end();it++){
		ans.push_back(it->second);
	}
	sort(ans.begin(), ans.end(), cmp);
	cout<<count<<endl;
	for(int i=0;i<ans.size();i++){
		if(i!=0){
			cout<<" ";
		}
		cout<<ans[i];
	}
	return 0;
}
 
