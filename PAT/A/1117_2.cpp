/*
�ҵ���������E��ʹ����E�죨��һ���������ﳵ����EӢ�
����һ����N��ÿ���ߵĹ��������ҵ�E 
*/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
bool cmp(int a,int b){
	return a >= b;
}
int main(){
	int n, i; //n<=10^5
	cin>>n;
	vector<int> v(n);
	for(i=0;i<n;i++){
		cin>>v[i];	
	}
	sort(v.begin(), v.end(),cmp);
	i = 0;
	while(i<n && v[i] > i+1) i++;
	/* ���� 
	for(int i = 0; i<n; i++){
		if( v[i] < i+1){
			break;
		}
	}
	*/
	cout<<i;
	return 0;
} 
