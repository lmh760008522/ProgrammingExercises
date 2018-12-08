/*
每次只能调换序列中两个数字
求为了将序列从小到大排序，至少要调换几次
贪心 ：0 在哪个位置上，就让0和那个数字交换 
*/
#include<iostream>
using namespace std;

int main(){
	int n,x;
	cin>>n;
	int a[100005];
	for(int i=0;i<n;i++){
		cin>>x;
		a[x] = i;
	}
	int count = 0;
	for(int i = 0; i < n; i++){
		if(a[i] == i) continue;
		while(a[0]!=0){
			swap(a[0], a[a[0]]);
			count++;
		}
		if(i!=a[i]){
			swap(a[0],a[i]);
			count++;
		}
	} 
	cout<<count;
	return 0;
} 
