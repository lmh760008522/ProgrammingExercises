#include <cstdio>
int a[55];
int sum[55];

int main()
{
    a[0] = 0;
    for(int i = 1; i <= 55; i++)
    {
        a[i] = a[i - 1] ^ i;
        printf("a[%d] = %d\n", i, a[i]);
    }
    sum[0] = 0;
    for(int i = 1; i <= 55; i++)
        sum[i] = sum[i - 1] ^ a[i];
    printf("sum[5] = %d\n", sum[5]);
    for(int j = 0; j < 50; j++)
        printf("i = 0 j = %d ans = %d\n", j, sum[0] ^ sum[j]);         
}
