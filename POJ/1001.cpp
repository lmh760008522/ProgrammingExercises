#include<iostream>
#include<cstring>
using namespace std;
int main(){
	int n;
	char s[6];
	while( cin>>s>>n ){
		int wei=0;
		char ans[500];
		char ss[5];
		int j=0;
		for(int i=0;i<strlen(s);i++){
			if(s[i]=='.'){//找到小数点 
				wei=strlen(s)-1-i;
				continue;
			}
			ans[strlen(s)-2-j]=s[i];
			ss[strlen(s)-2-j]=s[i];
			j++;
		}
		for(int i=1;i<=n;i++){//高精度计算 
			for(int k=0;k<strlen(s)-1;k++){
				for(int x=0; x<strlen(ans);x++){
					ans[x+k]+=ss[k]*ans[x];
				}
			}
		}
		for(int i=0;i<strlen(ans);i++){//处理进位 
			ans[i+1]=ans[i]/10;
			ans[i]=ans[i]%10;
		}
		for(int i=strlen(ans)-1;i>=0;i--){
			cout<<ans[i]+'0';
			if(i==wei){
				cout<<'.';
			}
		}
		cout<<endl;
	}
	return 0;
} 
