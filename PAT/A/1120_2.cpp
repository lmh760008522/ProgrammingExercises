/*
������������λ�ϵ����ּ�������ȣ���Ϊ�������� 
���磺1+2+3 = 5+1 = 6�����123��51��������
����һЩ���֣����㲻ͬ��������ֵ 
*/
#include<iostream>
#include<set>
using namespace std;

//������λ�� 
int count(int x){
	int sum = 0;
	while( x!=0 ){
		sum += x%10;
		x = x/10;
	} 
	return sum;
}

int main(){
	int n;
	cin>>n;
	set<int> s;
	for(int i=0;i<n;i++){
		int x;
		cin>>x;
		s.insert(count(x));
	} 
	cout<<s.size()<<endl;
	set<int>::iterator iter;
	for(iter = s.begin(); iter != s.end(); iter++){
		if(iter != s.begin()){
			cout<<" ";
		}
		cout<<*iter;
	}
	return 0;
} 
