/*
��n�����������ֳ��������ཻ���ϣ�
�Ǽ��ϵ�Ԫ�������ֱ�Ϊn1��n2��Ԫ�غ�Ϊs1,s2��
����ʹ��|n1 - n2|��С�����ʹ��|s1-s2|��� 
�߼��� 
*/ 
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
	int n; // 2<= n <= 10^5
	cin>>n;
	vector<int> v(n); //������sort���Ͳ��ܳ�ʼ��Ϊn+1 
	for(int i=0;i<n;i++){
		cin>>v[i];
	}
	sort(v.begin(), v.end());
	if( n % 2 == 0){
		cout<<"0 ";
	}else{
		cout<<"1 ";
	}
	int sum1 = 0;
	for(int i=0;i<n/2;i++){
		sum1+=v[i];
	}
	int sum2=0;
	for(int i=n/2;i<n;i++){
		sum2+=v[i];
	}
	cout<<sum2-sum1<<endl;
	return 0;
} 
