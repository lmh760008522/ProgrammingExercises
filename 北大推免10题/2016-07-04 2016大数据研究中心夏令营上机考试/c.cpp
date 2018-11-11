#include<cstdio>
int main(){
	int n;
	scanf("%d",&n);
	int a[11][11];
	a[0][0]=1;
	int x=0,y=0;
	int num=2;
	while( num <= n*n ){
		y++;
		while(y!=-1){
			a[x][y]=num++;
			x++;y--;
		}
		x++;
		while(x!=-1){
			a[x][y]=num++;
			x--;y++;
		}
	}
	return 0;
}
