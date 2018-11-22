#include<stdio.h>
int main(){
	int k;
	scanf("%d", &k);
	int pailie[9] = {9,1,2,3,4,5,6,7,8};
	for(int i=0; i<k; i++){
		int n;
		scanf("%d", &n);
		int count = 1, sum = 0; 
		while(n>sum){
			sum+=count;
			count++;
		}
		/*sum的设置不好，可以用n-count 
		int i = 1;
	    while(n > i) {
	        // 每次减去的i之和=前i项之和，当n>i则n在第i项中并且n已经被减去了之前i-1项的和
	        n -= i;     
	        i++;
	    }
		*/ 
		count--;
		sum -= count;
		n -= sum;
		n = n%9;
		printf("%d\n", pailie[n]);
	}
	return 0;
} 
