/*
若两个数的数位上的数字加起来相等，则为朋友数。 
例如：1+2+3 = 5+1 = 6，因此123和51是朋友数
给你一些数字，计算不同朋友数的值 
*/
#include<iostream>
#include<set>
using namespace std;

//计算数位和 
int count(int x){
	int sum = 0;
	while( x!=0 ){
		sum += x%10;
		x = x/10;
	} 
	return sum;
}

int main(){
	int n;
	cin>>n;
	set<int> s;
	for(int i=0;i<n;i++){
		int x;
		cin>>x;
		s.insert(count(x));
	} 
	cout<<s.size()<<endl;
	set<int>::iterator iter;
	for(iter = s.begin(); iter != s.end(); iter++){
		if(iter != s.begin()){
			cout<<" ";
		}
		cout<<*iter;
	}
	return 0;
} 
