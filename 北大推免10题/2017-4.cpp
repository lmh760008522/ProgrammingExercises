#include<cstdio>
int a[101];
int dpl[101];
int dpr[101];
int ans[101];
int max(int a ,int b){
	return a > b ? a : b;
}
int main(){
	int k;
	scanf("%d",&k);
	while(k-- >0){
		int n;
		scanf("%d",&n);
		for(int i=0;i<n;i++){
			scanf("%d",&a[i]);
		}
		for(int i=0;i<n;i++){
			dpl[i]=1;
			for(int j=0;j<i;j++){
				if(a[i]>a[j]){
					dpl[i]=max(dpl[i],dpl[j]+1);
					//printf("?");
				}
			}
		} /*
		for(int i=0;i<n;i++){
			printf("%d ",dpl[i]);
		}
		printf("\n");*/
		
		for(int i=n-1;i>=0;i--){
			dpr[i]=1;
			for(int j=n-1;j>i;j--){
				if(a[i]>a[j]){
					dpr[i]=max(dpr[i],dpr[j]+1);
				}
			}
		} 
		/*
		for(int i=0;i<n;i++){
			printf("%d ",dpr[i]);
		}
		printf("\n");
		*/
		for(int i=0;i<n;i++){
			ans[i]=max(dpl[i],dpr[i]);
		}
		int max=0;
		for(int i=0;i<n;i++){
			if(max<ans[i]){
				max=ans[i];
			}
		}
		printf("%d\n",max);
	}	
	return 0;
}
