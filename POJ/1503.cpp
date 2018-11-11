#include<iostream>
#include<cstring>
#include<string>
using namespace std;
char ans[105];
char c[100];
int main(){
	cin>>c;
	memset(ans,'0',sizeof(ans));
	int j;
	while( strcmp(c,"0") ){
		j=0;
		for(int i=strlen(c)-1;i>=0;i--){
			ans[j]-='0';
			ans[j]+=c[i]-'0';
			ans[j+1]+=ans[j]/10;
			ans[j]=ans[j]%10;
			ans[j]+='0';
			j++;
		}
		cin>>c;
	}
	for(int i=j-1;i>=0;i--){
		cout<<ans[i];
	}
	return 0;
}
