#include<cstdio>
int main(){
	int n,m;
	int a[101][101];
	scanf("%d %d",&n,&m);
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			scanf("%d",&a[i][j]);
		}
	}
	for(int j=0;j<n;j++){
		for(int i=m-1;i>=0;i--){
			printf("%d ",a[i][j]);
		}
		printf("\n");
	}
	return 0;
}
