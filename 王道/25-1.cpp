#include<cstdio>

int main(){
	int n,m;
	int hash[201]={0};
	int duzhe[201];
	scanf("%d %d",&n,&m);
	for(int i=0;i<n;i++){
		scanf("%d",&duzhe[i]);
		hash[ duzhe[i] ]++;
	}
	for(int i=0;i<n;i++){
		if( hash[ duzhe[i]]<=1){
			printf("BeiJu\n");
		}else{
			printf("%d\n", hash[ duzhe[i]]-1);
		}
	}
	return 0;
} 
