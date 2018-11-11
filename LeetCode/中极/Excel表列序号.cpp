#include<cstdio>
#include<cstring>
int main(){
	char s[100];
	gets(s);
	int ans=0;
	for(int i=0;i<strlen(s);i++){
		ans*=26;
		ans+=s[i]-64;
	}
	printf("%d",ans);
	return 0;
}
