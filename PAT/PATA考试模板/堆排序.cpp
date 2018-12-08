//������ ���ȶ� 
/*
��һ����������С���󣩶�  
�ڶ����� ���£��ϣ�����   O(log_2 n)
*/
#include<iostream>
#include<vector>
using namespace std;
#define MAX 9

int a[MAX+1] = {0,5,3,1,7,4,2,0,6,8}; //��9�������� 

void swap(int x, int y){
	int t = a[x];
	a[x] = a[y];
	a[y] = t;
}
 
void adjustDown(int r, int n){
	int child = 2*r;
	int val = a[r];
	while(child <= n){
		if(child < n && a[child] > a[child+1]) child++;//ѡȡ���ӽ�С���Ǹ�
		if(val < a[child]) break; //�����ڵ���С������Ҫ����
		a[child/2] = a[child];
		child *= 2; //����һ�� 
	}
	a[child/2] = val;
}

int main(){
	
	/*����С��*/ 
	for(int i = MAX/2; i > 0; i--){//�ӵ�һ����Ҷ�ӽڵ㿪ʼ 
		adjustDown(i, MAX); 
	} 
	cout<<"���ѣ�"; 
	for(int i=1;i<=MAX;i++){
		cout<<a[i]<<" ";
	}
	cout<<endl;
	
	/*����*/
	for(int i = MAX; i > 1; i--){
		swap(1,i);
		adjustDown(1,i-1); 
	} 
	cout<<"����"; 
	for(int i = MAX;i > 0; i--){
		cout<<a[i]<<" ";
	}
	cout<<endl;
	
	return 0;
}  
