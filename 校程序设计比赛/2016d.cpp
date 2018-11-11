//¸ñÀ×Âë 
#include<stdio.h>
#include<math.h>
int main(){
	int t;
	int n,k;
	int i;
	scanf("%d",&t);
	while(t--){
		scanf("%d %d",&n,&k);
		for(i=n;i>0;i--){
			printf("%d", (int)((k+pow(2,i-1)-1)/pow(2,i))%2);
		}
		printf("\n");
	}
	return 0;
} 
