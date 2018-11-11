#include<cstdio>
int ans[100001];
void init(){
	ans[0]=0;
	for(int i=1;i<100000;i++){
		ans[i]=ans[i-1]^i;
	}
}
int main(){
	int t;
	scanf("%d",&t);
	init();
	while(t-- > 0){
		int n;
		scanf("%d",&n);
		printf("%d\n",ans[n]);
	}
	return 0;
}
