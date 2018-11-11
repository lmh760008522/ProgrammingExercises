#include<cstdio>
#include<string.h>
int city[1005];
int findroot(int x){
	if(city[x]==-1){
		return x;
	}else{
		int temp=findroot(city[x]);
		city[x]=temp;
		return temp;
	}
}
int main(){
	int n,m;
	
	scanf("%d %d",&n,&m);
	while(n!=0){
		memset(city,-1,sizeof(city));
		for(int i=0;i<m;i++){
			int a,b;
			scanf("%d %d",&a,&b);
			a=findroot(a);
			b=findroot(b);
			if(a!=b){
				city[a]=b;
			}
		}
		int ans=0;
		for(int i=1;i<=n;i++){
			if(city[i]==-1){
				ans++;
			}
		}
		printf("%d\n",ans-1);
		
		scanf("%d %d",&n,&m);
	}
	return 0;
}
