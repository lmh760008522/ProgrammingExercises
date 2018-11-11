#include<stdio.h>
#include<math.h>
#include <malloc.h>
#include <stdlib.h>
#include<algorithm>
#include<iostream>
using namespace std;
int a[1001];

bool cmp(int a,int b){
	return a>b;
}
int main(){
	int num;
	scanf("%d",&num);
	int i=0;
	while(i<num){
		cin>>a[i];
		i++;	
	}
	sort(a,a+num,cmp);
	
	double n,m;	
	for(n=floor(sqrt(num)); n>0; n--){
		if(num%int(n)==0){
			m=num/n;//列，大 
			break;
		}
	}

	int **ans=(int**)malloc(sizeof(int*)*m);
	for(i=0;i<m;i++){
		ans[i]=(int*)malloc(sizeof(int)*n);
	}
	
	//printf("%lf %lf %lf\n",m, n ,(n+1)/2);
	
	double q;//圈数 
	int p=0;//指向原来数组 
	int k;//列
	int h;//行 
	for(q=1;q<=(n+1)/2;q++){
		h=q-1;
		for(k=q-1; k<n-q&&p<num; k++){
			ans[h][k]=a[p++];
		}//结束后，k=n-q+1 
		for( ;h<m-q&&p<num;h++){
			ans[h][k]=a[p++];
		}//结束后，h=m-q+1 
		for( ;k>q-1&&p<num;k--){
			ans[h][k]=a[p++];
		}//结束后，k=q-1
		for( ;h>q-1&&p<num;h--){
			ans[h][k]=a[p++];
		}
	}
	if(m==n){
		ans[h][k]=a[p];
	}
	
	//打印 
	for( i=0;i<m;i++){
		for(int j=0;j<n;j++){
			printf("%d",ans[i][j]);
			if(j!=n-1){
				printf(" ");
			}
		}
		printf("\n");
	}
	
	//释放空间 
	for (i = 0; i < m; ++i)  
    {  
      free((void*)ans[i]);  
    }  
	free((void*)ans);
	return 0;
} 

