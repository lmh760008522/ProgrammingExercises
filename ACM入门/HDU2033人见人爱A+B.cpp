#include<stdio.h>
int main(){
	int n;
	scanf("%d", &n);
	
	for(int i=0; i<n; i++){
		int ah,am,as,bh,bm,bs;
		scanf("%d %d %d %d %d %d", &ah, &am, &as, &bh, &bm, &bs);
		int c = 0;//进位
		int cs = (as + bs + c)%60;
		c = (as + bs + c)/60;
		int cm = (am + bm + c)%60;
		c = (am + bm + c)/60;
		int ch = ah + bh + c;
		printf("%d %d %d\n", ch, cm, cs);
	}
	return 0;
} 


/*
注意通用性 
 
#include <stdio.h>
 
#define MAXN 3
#define R 60
 
int main(void)
{
    int n, timea[MAXN], timeb[MAXN], i;
 
    scanf("%d", &n);
    while(n--) {
        // 输入两组时间（下标从小到大是时分秒）
        for(i=0; i<MAXN; i++)
            scanf("%d", &timea[i]);
        for(i=0; i<MAXN; i++)
            scanf("%d", &timeb[i]);
 
        // 时间相加
        for(i=MAXN-1; i>0; i--) {
            timea[i] += timeb[i];       // 低位相加（结果放在timea）
            timea[i-1] += timea[i] / R; // 向高位进位（R进制）
            timea[i] %= R;              // 低位得数（R进制）
        }
        timea[0] += timeb[0];
 
        // 输出结果
        for(i=0; i<MAXN; i++) {
            if(i != 0)
                printf(" ");
            printf("%d", timea[i]);
        }
        printf("\n");
    }
 
    return 0;
}

*/
