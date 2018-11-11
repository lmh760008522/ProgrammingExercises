#include<iostream>
#include<string>
#include<algorithm>
#include<cmath>
using namespace std;
bool isprime(int x){
	if(x==1){
		return false;
	}
	for(int i=2;i<=sqrt(x);i++){
		if( x% i ==0){
			return false;
		}	 
	}
	return true;
}
int main(){
	int a,b;
	cin>>a;
	while(a>0){
		cin>>b;
		if( !isprime(a) ){
			cout<<"No"<<endl;
			cin>>a;
			continue;
		}
		if( b!= 10){
			int c=0;
			int index=1;
			while(a!=0){
				c+=(a%10)*index;
				a=a/10;
				index=index*b;
			}
			a=c;
		}
		
		
		
		int c=0;
		int index=1;
		while( a!=0 ){
			c*=index;
			c+=(a%10);
			a=a/10;
			index*=10;
		}
		//cout<<c<<endl;
		if ( !isprime(c) ){
			cout<<"No"<<endl;
		}else{
			cout<<"Yes"<<endl;
		}
		cin>>a;
	}
	return 0;
} 
