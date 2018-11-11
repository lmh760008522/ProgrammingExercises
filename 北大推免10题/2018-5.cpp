#include<cstdio>
int main(){
	int n;
	scanf("%d",&n);
	long long ans[51];
	ans[1]=1;
	ans[2]=2;
	for(int i=3;i<51;i++){
		ans[i] = ans[i-1] + ans[i-2];
	}
	while(n-- >0){
		int a,b;
		scanf("%d %d",&a,&b);
		printf("%lld\n",ans[b-a]);
	}
	return 0;
}
