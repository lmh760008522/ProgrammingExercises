/*
ÿ��ֻ�ܵ�����������������
��Ϊ�˽����д�С������������Ҫ��������
̰�� ��0 ���ĸ�λ���ϣ�����0���Ǹ����ֽ��� 
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
