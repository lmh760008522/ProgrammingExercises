//���һ������û����һ�����У���next_permutation�᷵��false
#include<iostream>
#include<vector>
#include <algorithm> 
#define MAX 7
using namespace std;

int a[MAX] = {2,1,4,7,6,3,5};
vector<int> v(a, a+MAX);

void shuchu(){
	for(int i=0;i<v.size();i++){
		cout<<v[i]<<" ";
	}
	cout<<endl;
}

int main(){
	shuchu();
	next_permutation(v.begin(), v.end());
	shuchu();
	prev_permutation(v.begin(), v.end());
	shuchu();
	return 0;
} 
