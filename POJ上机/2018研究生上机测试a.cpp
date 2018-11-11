#include<cstdio>
#include<cstring>
#include<string>
#include<windows.h>
int judge(char *s){
	int i,j;
	int len=0;
	for(i=0, j=strlen(s)-1; i<=j ; i++, j--){
		if(i!=j){
			len=len+s[i]-'0'+s[j]-'0';
		}else{
			len+=s[i]-'0';
		}
		if(s[i]!=s[j]){
			return 0;
		}
	} 
	return len;
}
int main(){
	int n;
	scanf("%d\n",&n);
	int ans=0;
	while(n-- >0){
		char s[18];
		int l=0;
		gets(s);
		if(l=judge(s)){
			if( judge( itoa(l,s,10))){
				ans++;
			}
		}
	}
	printf("%d",ans);
	return 0;
}
