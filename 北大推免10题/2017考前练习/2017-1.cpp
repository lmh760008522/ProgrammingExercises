#include<cstdio>
#include<cstring>
int main(){
	int n;
	scanf("%d\n",&n);
	char s[201];
	gets(s);
	for(int i=0;i<n;i++){
		for(int j=0;j<strlen(s)/n;j++){
			if(j%2==0){
				printf("%c",s[i+j*n]);
			}else{
				printf("%c",s[i+j*n+(n-i-1)]);
			}
		}
	}
	return 0;
}
