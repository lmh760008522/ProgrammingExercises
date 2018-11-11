#include<iostream>
#include<string>
using namespace std;
int main(){
	int a,b,c;
	int cc[10];
	cin>>a>>b;
	c=a+b;
	int len=0;
	if(c==0){//一开始这里忘记了 
		cout<<'0';
		return 0;
	}
	if(c<0){
		cout<<"-";
		c=-c;
	}
	while(c>0){
		cc[len]=c%10;
		c=c/10;
		len++;
	}
	for(int i=len-1; i>=0;i--){
		cout<<cc[i];
		if(i%3==0 && i!=0 ){
			cout<<",";
		}	
	} 
	return 0;
} 
