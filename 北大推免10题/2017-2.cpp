#include<cstdio>
#include<cstring>
#include <ctype.h>

int main(){
	char s[1001];
	gets(s);
	for(int i=0;i<strlen(s);i++){
		s[i] = tolower(s[i]);
	}
	char temp=s[0];
	int len=1;
	for(int i=1;i<strlen(s);i++){
		if(s[i]==s[i-1]){
			len++;
		}else{
			printf("(%c,%d)",temp,len);
			temp=s[i];
			len=1;
		}
	}
	printf("(%c,%d)",temp,len);
	return 0;
}
