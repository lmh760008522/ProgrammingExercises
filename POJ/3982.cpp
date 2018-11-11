#include<iostream>
#include<cstring>
using namespace std;

int main(){
	char a[1000],b[1000],c[1000];
	char ans[1000];
	cin>>a>>b>>c;
	strrev(a);
	strrev(b);
	strrev(c);
	memset(ans,'0',sizeof(ans));
	int count=4;
	while(count<=99){
	for(int i=0;i<strlen(a) || i<strlen(b);i++){
		if(i<strlen(a) && i<strlen(b)){
			ans[i]-='0';
			ans[i]+=(a[i]-'0')+(b[i]-'0');
			ans[i+1]+=ans[i]/10;
			ans[i]=ans[i]%10;
			ans[i]+='0';
		}
		if(i>=strlen(a) && i<strlen(b)){
			ans[i]-='0';
			ans[i]+=(b[i]-'0');
			ans[i+1]+=ans[i]/10;
			ans[i]=ans[i]%10;
			ans[i]+='0';
		}
		if(i>=strlen(b) && i<strlen(a)){
			ans[i]-='0';
			ans[i]+=(a[i]-'0');
			ans[i+1]+=ans[i]/10;
			ans[i]=ans[i]%10;
			ans[i]+='0';
		}
	}
	for(int i=0;i<strlen(c);i++){
		ans[i]-='0';
		ans[i]+=(c[i]-'0');
		ans[i+1]+=ans[i]/10;
		ans[i]=ans[i]%10;
		ans[i]+='0';
	}
	strcpy(a,b);
	strcpy(b,c);
	strcpy(c,ans);
	memset(ans,'0',sizeof(ans));
	count++;
	}
	int i;
	for(i=99;ans[i]=='0';i--);
	for( ; i>=0;i--){
		cout<<ans[i];
	}
	return 0;
}
