#include<stdio.h>

int a_sum(int jz, int x){
	int sum = 0;
	while( x!=0 ){
		sum += x%jz;
		x = x/jz;
	}
	return sum;
}

int main(){
	int x;
	while( scanf("%d", &x) !=EOF){
		if(x==0){
			break;
		}
		int y = x;
		int sum10 = 0;
		while( x!=0 ){
			sum10 += x%10;
			x = x/10;
		}
		
		int jz[4];
		
	}
	return 0;
} 

/*
 
#include <stdio.h>
 
// ����֮�ͣ���10���Ƶ�valתΪbase���ƣ����Ը�λ���
int digitsum(int val, int base)
{
    int sum = 0;
    while(val) {
        sum += val % base;
        val /= base;
    }
 
    return sum;
}
 
int main(void)
{
    int n, sum, skyflag, i;
    int scale[] = {16, 12};
 
    while(scanf("%d", &n) != EOF) {
        // �ж���������;
        if(n == 0)
            break;
 
        // �����λ֮��
        sum = digitsum(n, 10);
 
        // Sky���ж�
        skyflag = 1;
        int len = sizeof(scale) / sizeof(int);
        for(i=0; i<len; i++)
            if(digitsum(n, scale[i]) != sum) {
                skyflag = 0;
                break;
            }
 
        // ������
        if(skyflag)
            printf("%d is a Sky Number.\n", n);
        else
            printf("%d is not a Sky Number.\n", n);
    }
 
    return 0;
}
*/
