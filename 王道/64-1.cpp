#include<cstdio>
#include<cmath>
int main(){
	int a,b,k;
	scanf("%d %d %d",&a,&b,&k);
	while(!(a==0 && b==0) ){
		int ans=pow(10,k);
		if(a%ans == b%ans){
			printf("-1\n");
		}else{
			printf("%d\n",a+b);
		}	
		scanf("%d %d %d",&a,&b,&k);
	}
	return 0;
}
