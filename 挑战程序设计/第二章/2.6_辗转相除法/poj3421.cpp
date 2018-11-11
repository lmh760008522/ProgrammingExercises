/*
题意简述：输入正整数x，求x的因子组成的满足任意前一项都能整除后一项的序列的最大长度，以及所有不同序列的个数。
问题分析：
首先要对x进行因子分解。这样可以得到总的因子个数c，不同的因子为f1,f2,...,fn其次方数分别为e1,e2,...,en。那么，不同序列的个数为c！/(e1!e2!......en!)。
程序说明：
数组factorial[]，若factorial[i]=k则k=i!，即每个元素存放其下标的阶乘值。初始化将阶乘算出来打表，避免重复计算。
那个常量N取22是应为22!还能够存储在unsigned long long类型变量中，再大就已经无法存储了。
变量fcount存储x因子的数量，变量ecount存储各个因子的次方数（重复次数）。
*/
/*
将x进行质因数分解，X-factor Chains中（第因一项永为1，所以不计）第i项就是将质因数进行排列后前i项的积。所以length为质因数的个数。numbeu为质因数全排列的种数。相同质因数之间的排列要去重。
*/
#include <iostream>
using namespace std;
typedef unsigned long long ULL;

const int N = 22;
ULL factorial[N+1] = {1};

void init(int n)
{
    for(int i=1; i<=n; i++)
        factorial[i] = factorial[i - 1] * i;
}

void solve(ULL x)
{
    ULL fcount=0, denominator=1;
    for(ULL i=2; i*i<=x; i++) {
        if(x % i == 0) {
            int ecount = 0;
            while(x % i == 0) {
                ecount++;
                x /= i;
            }
            fcount += ecount;
            denominator *= factorial[ecount];
        }
    }
    if(x > 1)
        fcount += 1;

   cout << fcount << " " << factorial[fcount] / denominator << endl;
}

int main()
{
    init(N);
    ULL x;
    while(cin >> x)
        solve(x);

    return 0;
}
