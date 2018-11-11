#include<cstdio>
int ans[100000000];
void init(){
	ans[0]=0;
	for(int i=1;i<100000;i++){
		ans[i]=ans[i-1]^i;
		//ans[i]=ans[i]^ans[i-1];
	}
}
int main(){
	int t;
	scanf("%d",&t);
	init();
	while(t-- > 0){
		int l,r;
		scanf("%d %d",&l ,&r);
		//printf("%d\n",  );
	}
	return 0;
}
