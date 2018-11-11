#include<stdio.h>
//youwenti
int mi[11] = {1,2,4,8,16,32,64,128,256,512,1024};

int main(){
	int n;
	scanf("%d", &n);
	
	int i=0,j=10;
	while(i<j){
		mid = (i+j)/2;
		if(mi[mid] < n && mid+1 != j){
			i = mid;
		}else if( mi[mid] > n && mid+1 != j){
			j = mid;
		}else{
			i = mid;
			break;
		}
	}
	
	int count = mi[i+1] - mi[i];
	int sum = 0;
	for(int i=0; i<n; i++){
		int len;
		scanf("%d",len);
		sum += (i+1)*len;
		count--;
		if(count == 0){
			i--;
		}
	}
	return 0;
} 
