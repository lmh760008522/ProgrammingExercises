/* HDU1877 ��һ�� A+B */
//��Ҫע��һ�㣬Ҫ��ȷ�����Ϊ0�����
#include <stdio.h>
 
void reverse(char s[], int len)
{
    int i,j;
    int c;
 
    for(i=(s[0]=='-'?1:0),j=len-1; i<j;i++,j--)
    {
        c = s[i];
        s[i] = s[j];
        s[j] = c;
    }
}
 
void convert(int n, int base, char *t)
{
    char *p = t;
 
    // ����ֵΪ0�����
    if(n == 0)
        *p++ = '0';
 
    while(n) {
        *p = n % base;
        if(*p >= 10)
            *p = *p - 10 + 'A';
        else
            *p = *p + '0';
        n /= base;
        p++;
    }
    *p = '\0';
 
    reverse(t, p-t);
}
 
int main(void)
{
    int m, a, b;
    char t[64];
 
    while(scanf("%d", &m) != EOF) {
        // �ж���������
        if(m == 0)
            break;
 
        // ����A��B
        scanf("%d%d", &a, &b);
 
        // ����ת��
        convert(a+b, m, t);
 
        // ������
        printf("%s\n", t);
    }
 
    return 0;
}

