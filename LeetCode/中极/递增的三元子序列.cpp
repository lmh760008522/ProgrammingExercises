#include<cstdio>
#define inf 9999
int main(){
	int a[5]={5,1,2,4,3};//124
	//int a[5]={5,1,4,2,3};//123
	//int a[5]={2,4,1,3,5};//123
	//int a[5]={1,5,2,4,3};//123
	//int a[5]={4,5,1,2,3};//123
	//int a[5]={2,3,1,5,4};//235 
	int x=inf,y=inf;
	for(int i=0;i<5;i++){
		if(x>=a[i]) x=a[i];
		else if(y>=a[i]) y=a[i];
		else{
			printf("true");
			return 0;
		} 
	}
	printf("false");
	return 0;
}
