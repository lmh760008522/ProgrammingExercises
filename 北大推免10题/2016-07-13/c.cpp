#include<cstdio>
int main(){
	int r,c;
	scanf("%d %d",&r,&c);
	int a[101][101];
	for(int i=0;i<r;i++){
		for(int j=0;j<c;j++){
			scanf("%d",&a[i][j]);
		}
	}
	for(int i=0;i<c;i++){
		int x=0,y=i;
		while(y!=-1 && x<r){
			printf("%d\n",a[x][y]);
			x++;y--;
		}
	}
	if(r!=c){
		for(int i=1;i<r;i++){
			int x=i,y=c-1;
			while(y!=-1 && x<r){
				printf("%d\n",a[x][y]);
				x++;y--;
			}
		}
	}
//	}else if(r<c){
//		for(int i=1;i<r;i++){
//			int x=i,y=c-1;
//			while(y!=-1 && x<r){
//				printf("%d\n",a[x][y]);
//				x++;y--;
//			}
//		}
//	}
	return 0;
}
