/*
��������A,B,C,��Χ��[-2^63, 2^63]���ж��Ƿ�a+b>c 
*/ 
#include<iostream>
using namespace std;
int main(){
	int t;
	cin>>t;
	for(int i=1;i<=t;i++){
		long double a, b, c;
		cin>>a>>b>>c;
		if(a+b>c){
			cout<<"Case #"<<i<<": true"<<endl;
		}else{
			cout<<"Case #"<<i<<": false"<<endl;
		}
	}
	return 0;
} 
