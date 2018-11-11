#include<iostream>
#include<cstring>
#include<string.h>
using namespace std;
char a[40];
char b[40];
int ans[100];
int main(){
	cin>>a;
	cin>>b;
	strrev(a);
	strrev(b);
	for(int i=0;i<strlen(a);i++){
		for(int j=0;j<strlen(b);j++){
			ans[i+j]+=(a[i]-'0')*(b[j]-'0');
		}
	}
	for(int i=0;i<strlen(a)+strlen(b)-1;i++){
		ans[i+1]+=ans[i]/10;
		ans[i]=ans[i]%10;
	}
	for(int i=strlen(a)+strlen(b)-2;i>=0;i--){
		cout<<ans[i];
	}
	return 0;
}
