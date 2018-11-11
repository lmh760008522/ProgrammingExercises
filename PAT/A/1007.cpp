#include<stdio.h>
int a[10000];
int main(){
	int n;
	int i,j;
	int max=-1;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	
	int begin, end;
	/* 
	for(i=0;i<n;i++){//若有非负数，则找到第一个非负数 
		if(a[i]>=0){
			begin=i;
			break;
		}
	}
	*/
	
	int sum=0;
	for(i=0 ; i<n ;i++){
		sum=0;
		/*
		原来写的：
		sum=a[i];
		for(j=i+1;j<n;j++){
			sum+=a[j];
		*/ 
		for(j=i;j<n;j++){
			sum+=a[j];
			if(max<sum){
				begin=i;
				end=j;
				max=sum;
				//printf("%d %d\n",begin ,end);
			}
		}
	} 
	if(max<0){//全为负数 
		printf("0 %d %d",a[0],a[n-1]);
	}else{
		printf("%d %d %d",max,a[begin],a[end]);
	}
	
	return 0;
}


/*
#include <iostream>
#include <vector>
using namespace std;
int main() {
    int n;
    scanf("%d", &n);
    vector<int> v(n);
    int leftindex = 0, rightindex = n - 1, sum = -1, temp = 0, tempindex = 0;
    for (int i = 0; i < n; i++) {
        scanf("%d", &v[i]);
        temp = temp + v[i];
        if (temp < 0) {
            temp = 0;
            tempindex = i + 1;
        } else if (temp > sum) {
            sum = temp;
            leftindex = tempindex;
            rightindex = i;
        }
    }
    if (sum < 0) sum = 0;
    printf("%d %d %d", sum, v[leftindex], v[rightindex]);
    return 0;
}
*/
