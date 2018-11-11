#include<cstdio>
int main(){
	int h;
	scanf("%d",&h);
	for(int i=0;i<h;i++){
		for(int j=0;j<(h-1-i)*2;j++){
			printf(" ");
		}
		for(int j=0;j<h+i*2;j++){
			printf("*");
		}
		printf("\n");
	} 
	return 0;
}
