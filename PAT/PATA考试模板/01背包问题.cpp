// 0-1��������
/* 
��������Ϊm,��Ʒ�����Ϊw��ֵΪv ,Ҫ�󱳰�����ײ�¼�ֵ�����ܶ����Ʒ��������ֵ��
�����ɲ���װ����ÿ����Ʒֻ��һ��
ÿ����Ʒ������������ںͲ����� 
*/ 
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
#define MAX 6
#define VEC 22 

int main(){
	int w[MAX] = {1,2,3,4,5,6};
	int v[MAX] = {3,4,2,5,1,3};
	int dp[VEC+1] = {0}; //��ʼֵΪ0 
	
	for(int i = 0; i < MAX; i++ ){
		for(int j = VEC; j >= w[i]; j--){ //����ÿһ�����أ���Ҫ����һ��ѡ��ѡ��Ʒi 
			dp[j] = max(dp[j-w[i]]+v[i], dp[j]); 
		}
	} 
	cout<<dp[VEC]; //��Ϊ9����ѡ������Ϊ1��2��4����Ʒ 
	
	return 0;
}
