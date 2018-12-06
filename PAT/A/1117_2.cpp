/*
找到最大的整数E，使得有E天（不一定连续）骑车超过E英里。
给你一个人N天每天走的公里数，找到E 
*/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
bool cmp(int a,int b){
	return a >= b;
}
int main(){
	int n, i; //n<=10^5
	cin>>n;
	vector<int> v(n);
	for(i=0;i<n;i++){
		cin>>v[i];	
	}
	sort(v.begin(), v.end(),cmp);
	i = 0;
	while(i<n && v[i] > i+1) i++;
	/* 错误 
	for(int i = 0; i<n; i++){
		if( v[i] < i+1){
			break;
		}
	}
	*/
	cout<<i;
	return 0;
} 
