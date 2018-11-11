#include<cstdio>
int main(){
	int n;
	scanf("%d",&n);
	int a[21];
	a[0]=0;
	a[1]=1;
	a[2]=2;
	for(int i=3;i<=n;i++){
		a[i]=a[i-1]+a[i-2];
	}
	printf("%d\n",a[n]);
	return 0;
} 
