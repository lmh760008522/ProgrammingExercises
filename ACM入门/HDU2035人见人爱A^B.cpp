#include<stdio.h>
int main(){
	int a,b;
	while( scanf("%d %d", &a, &b) != EOF){
		if( a==0 && b==0){
			break;
		}
		int ans = 1;
		a = a%1000;
		while(b>=1){
			ans *=a;
			ans = ans%1000;
			b --;
			//printf("%d:%d\n", b, ans);
		}
		printf("%d\n", ans);
	}
	return 0;
} 
