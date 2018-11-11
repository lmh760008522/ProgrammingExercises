#include<iostream>
#include<cstring>
#include<cmath>
using namespace std;
int main(){
	char c[100];
	cin>>c;
	while(c[0]!='0'){
		int len=strlen(c);
		long long ans=0;
		for(int i=0;i<strlen(c);i++){
			ans+=(c[i]-'0')*(pow(2,len)-1);
			len--;
		}
		cout<<ans<<endl;
		cin>>c;
	}
	return 0;
}
