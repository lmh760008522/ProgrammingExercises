/*
ģ��
permutation ���� 
ϴ�� ��54���ơ� 
����i��λ�õ���Ų����a[i]��λ���ϡ� ѭ�������� 
*/
#include<iostream>
#include<vector>
using namespace std;

char s[5] = {'S','H', 'C', 'D', 'J'};
int k; //k<=20 �ظ�����
vector<int> v(55), a(55),temp;

void shuchu(){
	for(int i=1;i<=54;i++){
		if( i != 1 ){
			cout<<" ";
		}
		cout<<s[(a[i]-1)/13];
		a[i]%13 == 0? cout<<13 : cout<<a[i]%13;
	}
}

int main(){
	cin>>k;
	for(int i=1;i<=54;i++){
		cin>>v[i];
		a[i] = i;
	} 
	for(int i=1;i<=k;i++){
		temp.clear();
		temp.resize(55);
		for(int i = 1;i<=54;i++){
			temp[v[i]] = a[i];
		}
		for(int i = 1;i<=54;i++){
			a[i] = temp[i];
		}
	}
	shuchu();
	return 0;
} 
