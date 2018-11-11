#include<cstdio>
int main(){
	int ll,m;
	scanf("%d %d",&ll,&m);
	int ans=0;
	int l=0,r=-1;
	for(int i=0;i<m;i++){
		int a,b;
		scanf("%d %d", &a, &b);
		if( a>r){
			ans+=r-l+1;
			l=a;
			r=b;
			printf("%d \n",ans);
		}else{
			r=b;
		}
	}
	ans+=r-l+1;
	printf("%d \n",ans);
	printf("%d",ll+1-ans);
	return 0;
} 
