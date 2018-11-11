#include<cstdio>
#include<string.h>
int main(){
	char s[85];
	int a[26]={0};
	int max=0;
	for(int i=0;i<4;i++){
		gets(s);
		for(int j=0;j<strlen(s);j++){
			if(s[j]<65 || s[j]>90){
				continue;
			}
			a[ s[j] - 65]++;
			if(a[ s[j] - 65] > max){
				max=a[ s[j] - 65];
			}
		}
	}
	for(int i=max;i>0;i--){
		for(int j=0;j<26;j++){
			if(a[j]>=i){
				printf("*");
			}else{
				printf(" ");
			}
		}
		printf("\n");
	}
	for(int i=0;i<26;i++){
		printf("%c",i+65);
	}
	return 0;
}
