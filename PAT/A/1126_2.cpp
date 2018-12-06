/*
Eulerian path:ŷ��·�� ��ÿ���߾���һ�Σ� 
Eulerian circuit��ŷ����·������յ���ͬһ�����ŷ��·���� 
��ͨͼ��ÿ����Ķ���Ϊż���������ŷ����·�����ͼ��Ϊŷ��ͼ��
�����������Ķ���Ϊ����������ŷ��·��������ŷ����·�����ͼ��Ϊ��ŷ��ͼ��
����һ������ͼ���ж���ŷ��ͼ����ŷ��ͼ ���� ����ŷ��ͼ�� 
˼·��ͳ��ÿ���ڵ�Ķ����������жϡ�
���Ե�3����ͼ��������ͨͼ������Ҫ��һ�������ж�һ����ͨ��
*/
#include<iostream>
#include<vector>
using namespace std;

int n, m;  //�ڵ�����<=500��,����
vector<int> nodeNum;
vector< vector<int> > v;
bool visit[505] = {false};
int sum = 0; //��¼���ѽڵ���� 

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
	if(sum != n){//������ͨ 
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
