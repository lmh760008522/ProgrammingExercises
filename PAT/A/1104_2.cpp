/*
数学 
已知一个正数序列， 求出它所有连续子序列元素之和。 
第i个数，出现i*(n-i+1)次 
*/ 
#include<iomanip>
#include<iostream>
using namespace std;
int main(){
	int n;
	cin>>n;
	double sum = 0;
	for(int i=1;i<=n;i++){
		double x;
		cin>>x;
		sum += x*i*(n-i+1); 
	} 
	cout.setf(ios::fixed);
	cout<<fixed<<setprecision(2)<<sum<<endl;
	return 0;
} 
