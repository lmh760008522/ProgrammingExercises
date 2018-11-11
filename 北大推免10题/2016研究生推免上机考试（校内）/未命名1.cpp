#include<cstdio>
int main(){
	int n;
	scanf("%d",&n);
	int a[1001],b[1001];
	for(int i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	for(int i=0;i<n;i++){
		scanf("%d",&b[i]);
	}
	int ans=0;
	for(int i=0;i<n;i++){
		ans+=a[i]*b[i];
	}
	printf("%d\n",ans);
	return 0;
} 
