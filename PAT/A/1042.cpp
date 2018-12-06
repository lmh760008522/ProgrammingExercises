/*
模拟
permutation 排列 
洗牌 。54张牌。 
将第i个位置的牌挪到第a[i]个位置上。 循环往复。 
*/
#include<iostream>
#include<vector>
using namespace std;

char s[5] = {'S','H', 'C', 'D', 'J'};
int k; //k<=20 重复次数
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
