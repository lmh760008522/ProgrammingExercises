#include<stdio.h>
int main(){
	int t;
	for(int i=0; i<t; i++){
		char c[105];
		int n;
		scanf("%s %n", c, &n);
		int t=0;
		while(c[t]!='.'){
			t++;
		}
		printf("%c\n", c[t+n]);
	}
	return 0;
}

/* 
�Ż���
�������Ҫע���һ���ǣ���������С�����ֻ��mλ�������n>mʱ�����nλΪ0��

  ������������������������⡣С����ǰ�ĸ�λ�Ͳ���Ҫ�洢�ˣ�������������Ҫ������ࡣ 
 
#include <stdio.h>
 
int main(void)
{
    int t, count, n;
    char s[10], c;
 
    scanf("%d", &t);
    getchar();
    while(t--) {
        // ����С����֮ǰ���ַ�
        while((c=getchar()) != '.');
 
        // С����֮����ַ���������s�У�������С������λ��
        count = 0;
        while((c=getchar()) != ' ')
            s[count++] = c;
 
        // ����n
        scanf("%d", &n);
        getchar();
 
        // ������
        if(n>count)
            printf("0\n");
        else
            printf("%c\n", s[n-1]);
    }
 
    return 0;
}

*/
