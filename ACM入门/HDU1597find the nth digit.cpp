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
		/*sum�����ò��ã�������n-count 
		int i = 1;
	    while(n > i) {
	        // ÿ�μ�ȥ��i֮��=ǰi��֮�ͣ���n>i��n�ڵ�i���в���n�Ѿ�����ȥ��֮ǰi-1��ĺ�
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
