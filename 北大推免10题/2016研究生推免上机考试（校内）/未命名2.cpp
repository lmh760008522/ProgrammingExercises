#include<cstdio>
#include<cstring>
int main(){
	char me[51];
	gets(me);
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		char a[51],b[51],c[51];
		scanf("%s %s %s",a,b,c);
		//printf("%s %s %d",me,c);
		if(strcmp(me,c)==0){
			printf("%s ",a);
			for(int j=0;j<strlen(b);j++){
				if(b[j]>='a' && b[j]<='z'){
					b[j]-=32;
				}else if(b[j]>='A' && b[j]<='Z'){
					b[j]+=32;
				}
				printf("%c",b[j]);
			}
			printf("\n");
		}
	}
	return 0;
}
