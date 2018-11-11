#include<cstdio>
#include<cstring>
int main(){
	char s[202],ans[202]="";
	gets(s);
	for(int i=0,j=0; i<strlen(s)-1; i++){
		if(s[i]==' ' && s[i+1]==' '){
			continue;
		}else{
			ans[j++] = s[i];
		}
	}
	puts(ans);
	return 0;
}
