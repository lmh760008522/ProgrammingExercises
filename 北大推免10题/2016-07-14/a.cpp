#include<cstdio>
int main(){
	int n,m;
	scanf("%d %d",&n,&m);
	int ans=0;
	for(int i=0;i<n;i++){
		int t;
		scanf("%d",&t);
		if(t==m){
			ans++;
		}
	}
	printf("%d\n",ans);
	return 0;
} 
