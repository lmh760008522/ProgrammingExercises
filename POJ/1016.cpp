//不知道哪里错了 
#include<iostream>
#include<string>
#include<string.h>
#include<vector>
using namespace std;
int a[10];
vector<string> v;

string yasuo(string s){
	memset(a,0,sizeof(a));
	string s1="";
	for(int i=0;i<s.length();i++){
		a[ s[i]-'0' ]++;
	}
	for(int i=0;i<10;i++){
		if(a[i]!=0){
			//cout<<i<<" "<<a[i]<<endl;
			char c=a[i]+'0';
			s1 = s1 +c;
			c=i+'0';
			s1 = s1 + c;
		}
	}
	//cout<<"s1:"<<s1<<endl;
	return s1;
}

int main(){
	string s,s0;	
	while(1){
		cin>>s;
		if(s=="-1"){
			break;
		}
		v.clear();
		int count=0;
		v.push_back(s);
		int length;
		s0=s;
		while(count<=15){
			length=0;
			s0=yasuo(s0);
			count++;
			cout<<count<<" :  s0: "<<s0<<endl;
			int i;
			if(count ==1 ){
				i=0;
			}else{
				i=1;
			}
			for( ;i<v.size();i++){
				if(s0==v[i]){
					break;
				}
			}
			if(i==0 && count == 1){//与原先一样 
				break;
			}else if(i==v.size()-1 && count >2){//与上一个一样 
				break;
			}else if(i<v.size()-1){
				length = v.size()-i;
				break;
			}
			v.push_back(s0);
		}
		if(count == 16){//没找到 
			cout<<s<<" can not be classified after 15 iterations"<<endl;
		}else if(count == 1){
			cout<<s<<" is self-inventorying"<<endl;
		}else if(length == 0){
			cout<<s<<" is self-inventorying after "<<count-1<<" steps"<<endl;
		}else{
			cout<<s<<" enters an inventory loop of length "<<length<<endl;
		}
	}
	return 0;
} 
