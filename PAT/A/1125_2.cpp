/*
�������ӵ�Ƭ�Σ�������ƴ�ӳ�һ�����ӣ�
ÿ�ο��Խ���������һ�Σ�
���ӹ�������ӳ�����֮ǰ������ӵ�һ�룻
��N��Ƭ�Σ��ҵ�������Ӻ�����ӳ��ȡ� 
be rounded to ��������
������ȡ�� 
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
