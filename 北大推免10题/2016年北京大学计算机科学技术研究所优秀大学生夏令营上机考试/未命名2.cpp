#include<cstdio>
#include<cstring>
int main(){
	char s[201];
	char maxlen[201],minlen[201];
	
	gets(s);
	int min=999,max=0;
	int len=0,left=0;
	for(int i=0;s[i]!='\0';i++){
		if(s[i]==',' || s[i]==' '){
			if(len < min){
				min=len;
				strncpy(minlen,s+left,len);
				minlen[len]='\0';
			}
			if(len > max){
				max=len;
				strncpy(maxlen,s+left,len);
				maxlen[len]='\0';
			}
			len=0;
			left=i+1;
		}else{
			len++;
		}
	}
	printf("%d\n",len);
	puts(maxlen);
	puts(minlen);
	return 0;
}
