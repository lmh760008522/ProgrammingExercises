/*
Eulerian path:欧拉路径 （每条边经过一次） 
Eulerian circuit：欧拉回路（起点终点是同一个点的欧拉路径） 
连通图中每个点的度数为偶数，则存在欧拉回路。这个图成为欧拉图。
如果有两个点的度数为奇数，存在欧拉路径不存在欧拉回路。这个图称为半欧拉图。
给你一个无向图，判断是欧拉图、半欧拉图 还是 不是欧拉图。 
思路：统计每个节点的度数，就能判断。
测试点3错误：图必须是连通图，所以要用一个深搜判断一下连通性
*/
#include<iostream>
#include<vector>
using namespace std;

int n, m;  //节点数（<=500）,边数
vector<int> nodeNum;
vector< vector<int> > v;
bool visit[505] = {false};
int sum = 0; //记录深搜节点个数 

void dfs(int x){
	if(visit[x] == true){
		return;
	}
	if(sum == n){
		return;
	} 
	visit[x] = true;
	sum++; 
	for(int i=0;i<v[x].size();i++){
		dfs(v[x][i]);
	}
}

int main(){
	cin>>n>>m;
	v.resize(n+1);
	nodeNum.resize(n+1);
	for(int i=1;i<=m;i++){
		int a,b;
		cin>>a>>b;
		nodeNum[a]++;
		nodeNum[b]++;
		v[a].push_back(b);
		v[b].push_back(a);
	} 
	dfs(1);
	int oddNum = 0, evenNum = 0;
	for(int i=1;i<=n;i++){
		if(i != 1){
			cout<<" ";
		}
		cout<<nodeNum[i];
		if(nodeNum[i] %2 ==0){
			evenNum++;
		}else{
			oddNum++;
		}
	}
	cout<<endl;
	//cout<<sum<<endl;
	if(sum != n){//若不联通 
		cout<<"Non-Eulerian"<<endl;
	}else if(evenNum == n){
		cout<<"Eulerian"<<endl;
	}else if(oddNum == 2){
		cout<<"Semi-Eulerian"<<endl;
	}else{
		cout<<"Non-Eulerian"<<endl;
	}
	return 0;
} 
