#include<cstdio>
int main(){
	long long m,a,b;
	scanf("%d %lld %lld",&m,&a,&b);
	while(m!=0){
		a=a+b;
		int ans[100];
		int size=0;
		do{
			ans[size++]=a%m;
			a=a/m;
		}while(a!=0);
		for(int i=size-1;i>=0;i--){
			printf("%d",ans[i]);
		}
		printf("\n");
		scanf("%d %d %d",&m,&a,&b);
	}
	return 0;
}
