#include<cstdio>
#include<cmath>
int main(){
	int n;
	scanf("%d",&n);
	int a[21][21]={0};
	a[0][n-1]=1;
	int leftx=0,lefty=n-1;
	for(int i=2;i<=pow(2*n-1,2);i++){
		int x=(leftx-1+2*n-1)%(2*n-1);
		int y=(lefty+1)%(2*n-1);
		if(a[x][y]!=0){
			x=(leftx+1)%5;
			y=lefty;
		}
		a[x][y]=i;
		leftx=x;
		lefty=y;
	}
	for(int i=0;i<2*n-1;i++){
		for(int j=0;j<2*n-1;j++){
			printf("%d  ",a[i][j]);
		}
		printf("\n");
	}
	return 0;
}
