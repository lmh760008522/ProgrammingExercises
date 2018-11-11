#include<stdio.h>
#include<algorithm>
#include<vector>
using namespace std;
int num[100000];
int main(){
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&num[i]);
	}
	
	if(n%2 == 0){
		printf("0 ");
	}else{
		printf("1 ");
	}
	
	sort(num,num+n);
	
	int sum1=0,sum2=0;
	for(int i=0;i<n;i++){
		if(i<n/2){
			sum1+=num[i];
		}else{
			sum2+=num[i];
		}
	}
	printf("%d",sum2-sum1);
	return 0;
}
