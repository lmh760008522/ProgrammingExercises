// ��ȫ��������
/* 
��������Ϊm,��Ʒ�����Ϊw��ֵΪv ,Ҫ�󱳰�����ײ�¼�ֵ�����ܶ����Ʒ��������ֵ��
�����ɲ���װ����ÿ����Ʒ����**����** 
ÿ����Ʒ������������ںͲ����� 
��01�����Ĳ�ͬ��˳����£���Ϊÿ����Ʒ���Զ��ѡ�� 
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
		for(int j = w[i]; j <= VEC; j++){ //����ÿһ�����أ���Ҫ����һ��ѡ��ѡ��Ʒi 
			dp[j] = max(dp[j-w[i]]+v[i], dp[j]); 
		}
	} 
	cout<<dp[VEC]; //��Ϊ66 
	
	return 0;
}
