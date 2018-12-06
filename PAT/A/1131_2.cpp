/*
DFS
给出乘客的起点，找到途经停站最少的路线;
如果经停站一样多，则取需要换乘线路次数最少的路线.
站点可能成圈
没有单个站点作为线路 
不同线路无重复的一段路线 
每个站点最多同时在5条线路上 
*/ 
#include<stdio.h>
#include<vector>
#include<map>
#include<string>
using namespace std;

typedef struct node{
	int line;  //属于哪条线路
	int id;  //下一个站点名 
}node;

int n;  //n<=100  地铁线数
int start, endd;
map<int, bool> mp;
vector< vector<node> > v(10000);
int min_stations, min_lines;
vector<node> temp;//记录路径
vector<node> ans;//记录最终路径 

void dfs(node x, int stations, int lines, int old_line){
	if(mp[x.id] == true){
		return;
	}
	if(x.id == endd){
		if(x.line != old_line){
			lines++;
		}
		bool flag = false;
		if(stations < min_stations){
			min_stations = stations;
			min_lines = lines;
			flag = true;
		}else if(stations == min_stations && lines < min_lines){
			min_lines = lines;
			flag = true;
		}
		if(flag){
			ans.clear();
			node t;
			t.id = start;
			t.line = -1;
			ans.push_back(t);
			for(int i=0;i<temp.size();i++){
				ans.push_back(temp[i]);
			}
			ans.push_back(x);
		}
		return;
	}
	mp[x.id] = true;
	temp.push_back(x);
	if(x.line != old_line){
		lines++;
	}
	for(int i=0;i<v[x.id].size();i++){
		dfs(v[x.id][i], stations+1, lines, x.line);
	}
	mp[x.id] = false;
	temp.pop_back();
}

int main(){
	scanf("%d", &n);
	for(int i=1;i<=n;i++){
		int m;  //m<=100 站点数
		scanf("%d", &m);
		int st;
		scanf("%d", &st);
		for(int j=1;j<m;j++){
			int end;
			scanf("%d", &end);
			node temp;
			temp.id = end;
			temp.line = i;
			v[st].push_back(temp);
			temp.id = st;
			v[end].push_back(temp);
			st = end;
		}
	}
	int k;  //k<=10  query
	scanf("%d", &k); 
	for(int i=0;i<k;i++){
		scanf("%d %d", &start, &endd);
		min_stations = 99999, min_lines = 999;
		mp.clear();
		mp[start] = true;
		for(int j=0;j<v[start].size();j++){
			dfs(v[start][j], 1, 1, v[start][j].line);
		}
		printf("%d\n", min_stations);
		int first = start;
		for(int j=1;j<ans.size();j++){
			if(ans[j-1].line != ans[j].line && j != 1){
				printf("Take Line#%d from %04d to %04d.\n", ans[j-1].line, first, ans[j-1].id);
				first = ans[j-1].id;
			}
		}
		printf("Take Line#%d from %04d to %04d.\n", ans[ans.size()-1].line, first, ans[ans.size()-1].id);
	}
	return 0;
} 
