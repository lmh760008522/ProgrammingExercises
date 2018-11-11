#include<cstdio>
int main(){
	int m,n;
	scanf("%d %d",&m,&n);
	int ans=0,i;
	for( i=m; i<n; i++){
		if(i%17==0){
			ans+=i;
			break;
		}
	}
	for(int j=i+17;j<=n;j+=17){
		ans+=j;
	}
	printf("%d\n",ans);
	return 0;
} 
