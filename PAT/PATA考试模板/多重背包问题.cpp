// ���ر�������
/* 
��01�����Ĳ�ͬ��ÿ����Ʒ��k��
�����������k����Ʒ���в�ֳɣ�1,2,4,...����Ʒ�ĺͣ�����µ���Ʒ
Ϊɶ�������? ��Ϊ�������ֶ������ö����Ʊ�ʾ��Ҳ�Ϳ�����a_1*2^0+a_2*2^1...��ʾ
��ֺ�ת����01�������⼴�� 
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
	int k[MAX] = {1,2,7,31,12,14}; //ÿ����Ʒ������ 
	int dp[VEC+1] = {0}; //��ʼֵΪ0 
	
	/*��������Ƭ*/  
	vector<int> ww,vv; //�µ�����ͼ�ֵ 
	for(int i=0;i<MAX;i++){
		int c = 1;
		while(k[i] - c > 0){
			k[i] -= c;
			ww.push_back(c*w[i]);
			vv.push_back(c*v[i]);
			c *= 2;
		}
	} 
	/*��������Ƭ*/
	
	for(int i = 0; i < ww.size(); i++ ){
		for(int j = VEC; j >= ww[i]; j--){ //����ÿһ�����أ���Ҫ����һ��ѡ��ѡ��Ʒi 
			dp[j] = max(dp[j-ww[i]]+vv[i], dp[j]); 
		}
	} 
	cout<<dp[VEC]; //��Ϊ29 
	
	return 0;
}
