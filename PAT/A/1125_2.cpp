/*
给出绳子的片段，将他们拼接成一条绳子；
每次可以将两段连成一段；
连接过后的绳子长度是之前两者相加的一半；
给N个片段，找到最大连接后的绳子长度。 
be rounded to 四舍五入
答案向下取整 
*/
#include<iostream>
#include<queue>
#include<math.h>
using namespace std;
int main(){
	int n;
	cin>>n;
	priority_queue<double , vector<double>, greater<double> > q;
	for(int i=0;i<n;i++){
		double x;
		cin>>x;
		q.push(x);
	}
	while(q.size() != 1){
		double a = q.top();
		q.pop();
		double b= q.top();
		q.pop();
		q.push((a+b)/2);
	}
	//cout<<q.top()<<endl;
	cout<<floor(q.top())<<endl;
	q.pop();
	return 0;
} 
