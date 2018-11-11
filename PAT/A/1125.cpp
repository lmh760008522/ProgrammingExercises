//每次都选最长两堆对折 

#include<iostream>
#include<cmath>
#include<queue> 
using namespace std;

int n;
priority_queue<int, vector<int>, greater<int> > q;//建立一个小顶堆 

int main(){
	
	cin>>n;
	for(int i=0;i<n;i++){
		int length;
		cin>>length;
		q.push(length); 
	}
	
	while(q.size()!=1){
		int a=q.top();
		q.pop();
		int b=q.top();
		q.pop();
		//cout<<a<<' '<<b<<' '<<(a+b)/2<<endl;
		q.push((a+b)/2);
	}
	
	int ans=q.top();
	q.pop();
	
	cout<<ans;
	return 0;
}
