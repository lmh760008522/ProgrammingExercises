/* HDU1877 又一版 A+B */
//需要注意一点，要正确处理和为0的情况
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
 
    // 处理值为0的情况
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
        // 判定结束条件
        if(m == 0)
            break;
 
        // 读入A和B
        scanf("%d%d", &a, &b);
 
        // 进制转换
        convert(a+b, m, t);
 
        // 输出结果
        printf("%s\n", t);
    }
 
    return 0;
}

