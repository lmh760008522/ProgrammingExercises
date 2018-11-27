//even number 偶数 
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main(){
	int n;
	scanf("%d", &n);
	for(int i=0;i<n;i++){
		char z[100];
		scanf("%s", z);
		char a[50], b[50];
		strncpy(a, z, strlen(z)/2);
		strncpy(b, z+strlen(z)/2, strlen(z)/2);
		int zz = atoi(z);
		int aa = atoi(a);
		int bb = atoi(b);
		//printf("%s %d %s %d", a,aa,b,bb);
		//注意a*b如果为0的时候不能取余，否则会浮点错误
		if(aa * bb != 0 && zz % (aa*bb) == 0 ){
			printf("Yes\n");
		}else{
			printf("No\n");
		}
	}
	return 0;
}
