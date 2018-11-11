#include<stdio.h>
int main(){
	int n, k;
	scanf("%d %d", &n, &k);
	int a[1005] = {0};
	int count = 0, p = 0, num = 1;
	while(count < n-1){
		if(a[p%n] == 1){
			p++;
			continue;
		}
		if( num%10==k || num%k==0 ){
			a[p%n]=1;
			count++;
		}
		p++;
		num++;
	}
	for(int i = 0; i < n; i++){
		if(a[i] == 0){
			printf("%d", i+1);
			break;
		}
	}
	return 0;
}
