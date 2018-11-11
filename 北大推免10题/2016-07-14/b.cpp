#include<cstdio>
#include<cstring>
int main(){
	char s[201];
	char maxl[101],minl[101];
	int max=0,min=999;
	gets(s);
	int left=0,len=0;
	for(int i=0;s[i]!='\0';i++){
		if(s[i]==' ' || s[i]==','){
			if(max<len){
				max=len;
				strncpy(maxl,s+left,len);
				maxl[len]='\0';
			}
			if(min>len){
				min=len;
				strncpy(minl,s+left,len);
				minl[len]='\0';
			}
			left=i+1;
			len=0;
		}else{
			len++;
		}
	}
	puts(maxl);
	puts(minl);
	return 0;
}
