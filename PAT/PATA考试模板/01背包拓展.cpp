// 0-1����������չ 
/* 
��������Ϊm,��Ʒ�����Ϊw��ֵΪv ,Ҫ�󱳰�����ײ�¼�ֵ�����ܶ����Ʒ��������ֵ��
����**����**��װ����ÿ����Ʒֻ��һ�� 
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
	int dp[VEC+1];
	 
	fill (dp, dp+VEC+1, -1); //��ʼֵΪ-1
	dp[0] = 0;
	 
	for(int i = 0; i < MAX; i++ ){
		for(int j = VEC; j >= w[i]; j--){ //����ÿһ�����أ���Ҫ����һ��ѡ��ѡ��Ʒi 
			if( dp[j-w[i]] != -1 || dp[j] != -1){
				dp[j] = max(dp[j-w[i]]+v[i], dp[j]);
			} 
		}
	} 
	cout<<dp[7]; //��Ϊ12����ѡ������Ϊ1��2��4����Ʒ
	cout<<endl<<dp[VEC]; //��Ϊ-1�� ������ 
	
	return 0;
}
