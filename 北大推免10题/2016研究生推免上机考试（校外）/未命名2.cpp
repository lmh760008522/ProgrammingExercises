#include<cstdio>
#include<cstring>
int main(){
	char a[100],b[100];
	gets(a);
	gets(b);
	strlwr(a);
	strlwr(b);
	puts(a);
	puts(b);
	for(int i=0,j=0;i<strlen(a) && j<strlen(b); ){
		if(a[i]==' '){
			i++;
			continue;
		}
		if(b[j]==' '){
			j++;
			continue;
		}
		if(a[i]!=b[j]){
			//printf("a[%d]:%c b[%d]%c\n",i,strlwr(&a[i]),j,strlwr(&a[i]));
			printf("NO\n");
			return 0;
		}
		i++;j++;
	}
	printf("YES\n");
	return 0;
}
