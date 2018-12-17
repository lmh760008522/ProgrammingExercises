/*
DFS
一个网络有零售商，经销商和供应商。每个人都将商品从供应商交到顾客手中。
从一个 源供应商 开始， 每个人从一个供应商那里以P价格买入商品，以（1+r%）*P的价格卖出。
只有零售商面对顾客销售。
假设每个在供应链上的人（除了 源供应商 外）只有一个供应商。 
给你这个供应链，求出顾客能得到的最低价格
思路：转化成求有向图中经过结点最少的路径 
*/
#include<iostream>
#include<vector>
#include<iomanip>
using namespace std;

int n; //节点数，源节点编号为0， <=10^5 
double p, r; //源供应商提供的价格，升价比率 
vector< vector<int> > v;
int num = 0;
double minprice = 9999999;
	
void dfs(int index, double price){
	if(v[index].size()==0){//说明是零售商 
		if(price < minprice){
			minprice = price;
			num = 1;
		}else if(price == minprice){
			num++;
		}
	}
	//cout<<price<<endl;
	for(int i=0;i<v[index].size();i++){
		dfs(v[index][i], price*(1+r)); 
	} 
	return;
}

int main(){
	cin>>n>>p>>r;
	r = r*0.01;
	v.resize(n);
	for(int i=0;i<n;i++){
		int k;
		cin>>k;
		for(int j=0;j<k;j++){
			int x;
			cin>>x;
			v[i].push_back(x);
		}
	}	
	dfs(0, p);
	cout.setf(ios::fixed);
	cout<<fixed<<setprecision(4)<<minprice<<" "<<num<<endl;
	return 0;
} 
