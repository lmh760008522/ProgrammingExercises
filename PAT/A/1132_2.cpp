//even number ż�� 
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
		//ע��a*b���Ϊ0��ʱ����ȡ�࣬����ḡ�����
		if(aa * bb != 0 && zz % (aa*bb) == 0 ){
			printf("Yes\n");
		}else{
			printf("No\n");
		}
	}
	return 0;
}
