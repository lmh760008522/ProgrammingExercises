#include<stdio.h>
int main(){
	int n;
	scanf("%d", &n);
	
	for(int i=0; i<n; i++){
		int ah,am,as,bh,bm,bs;
		scanf("%d %d %d %d %d %d", &ah, &am, &as, &bh, &bm, &bs);
		int c = 0;//��λ
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
ע��ͨ���� 
 
#include <stdio.h>
 
#define MAXN 3
#define R 60
 
int main(void)
{
    int n, timea[MAXN], timeb[MAXN], i;
 
    scanf("%d", &n);
    while(n--) {
        // ��������ʱ�䣨�±��С������ʱ���룩
        for(i=0; i<MAXN; i++)
            scanf("%d", &timea[i]);
        for(i=0; i<MAXN; i++)
            scanf("%d", &timeb[i]);
 
        // ʱ�����
        for(i=MAXN-1; i>0; i--) {
            timea[i] += timeb[i];       // ��λ��ӣ��������timea��
            timea[i-1] += timea[i] / R; // ���λ��λ��R���ƣ�
            timea[i] %= R;              // ��λ������R���ƣ�
        }
        timea[0] += timeb[0];
 
        // ������
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
