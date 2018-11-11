/*
抽屉原理，又叫鸽巢原理
题意：
    给出N个数，问其中是否存在M个数使其满足M个数的和是N的倍数，如果有多组解，
    随意输出一组即可。若不存在，输出 0。
题解：
    首先必须声明的一点是本题是一定是有解的。原理根据抽屉原理：
    因为有n个数，对n个数取余，如果余数中没有出现0，根据鸽巢原理，一定有两个数的余数相同，
如果余数出现0，自然就是n的倍数。也就是说，n个数中一定存在一些数的和是n的倍数。
本题的思路是从第一个数开始一次求得前 i（i <= N）项的和关于N的余数sum，并依次记录相应余数的存在状态，
如果sum == 0；则从第一项到第i项的和即满足题意。如果求得的 sum 在前边已经出现过，假设在第j（j<i）项出现
过相同的 sum 值，则从第 j+1 项到第i项的和一定满足题意。
*/
//代码一：
#include <cstdio>
#include <cstring>
#include <iostream>
 
using namespace std;
 
const int MAX = 10001;
int mod[MAX], num[MAX];
int sum;
 
void print(int begin, int end)
{
    printf("%d\n", end - begin + 1);
    while(begin <= end)
        printf("%d\n", num[begin++]);
}
 
int main()
{
    int n;
    bool flag = false;
    int begin, end;
    while(~scanf("%d", &n))
    {
        memset(mod, -1, sizeof(mod));
        sum = 0;
        for(int i = 1; i <= n; ++i)
        {
            scanf("%d", &num[i]);
            if(flag)
                continue;
            sum = (sum + num[i]) % n;
            if(sum == 0)
            {
               // print(1, i);
                begin = 1;
                end = i;
                flag = true;
                continue;
            }
            if(mod[sum] != -1)
            {
               // print(sum + 1, i);
                begin = sum + 1;
                end = i;
                flag = true;
                continue;
            }
            mod[sum] = i;     //mod数组用来记录出现余数为sum时位置，即前i项和除以N余数为sum
        }
        print(begin, end);
    }
    return 0;
}
