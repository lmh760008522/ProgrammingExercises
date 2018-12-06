/*
给n个正整数，分成两个不相交集合；
记集合的元素数量分别为n1和n2，元素和为s1,s2；
首先使得|n1 - n2|最小，其次使得|s1-s2|最大 
逻辑题 
*/ 
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
	int n; // 2<= n <= 10^5
	cin>>n;
	vector<int> v(n); //后面有sort，就不能初始化为n+1 
	for(int i=0;i<n;i++){
		cin>>v[i];
	}
	sort(v.begin(), v.end());
	if( n % 2 == 0){
		cout<<"0 ";
	}else{
		cout<<"1 ";
	}
	int sum1 = 0;
	for(int i=0;i<n/2;i++){
		sum1+=v[i];
	}
	int sum2=0;
	for(int i=n/2;i<n;i++){
		sum2+=v[i];
	}
	cout<<sum2-sum1<<endl;
	return 0;
} 
