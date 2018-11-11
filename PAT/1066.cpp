#include<stdio.h>
#include<stdlib.h>
#include<iostream>
using namespace std;
int main(){
	int m,n,a,b,x;
	int **box;
	int i,j;
	scanf("%d %d %d %d %d",&m,&n,&a,&b,&x);
	box=(int**)malloc(sizeof(int*)*m);
	for(i=0;i<m;i++){
		box[i]=(int*)malloc(sizeof(int)*n);
		for(j=0;j<n;j++){
			cin>>box[i][j];
			//getchar();
			if(box[i][j]<=b&&box[i][j]>=a){
				box[i][j]=x;
			}
		}
	}
	for(i=0;i<m;i++){
		for(j=0;j<n-1;j++){
			if(box[i][j]<10){
				printf("00%d ",box[i][j]);
			}else if(box[i][j]<=99&&box[i][j]>=10){
				printf("0%d ",box[i][j]);
			}else{
				printf("%d ",box[i][j]);
			}
		}
		if(box[i][j]<10){
			printf("00%d",box[i][j]);
		}else if(box[i][j]<=99&&box[i][j]>=10){
			printf("0%d",box[i][j]);
		}else{
			printf("%d",box[i][j]);
		}
		printf("\n");
	}
	for(i=0;i<m;i++){
		free(box[i]);
	}
	free(box);
	return 0;
} 
