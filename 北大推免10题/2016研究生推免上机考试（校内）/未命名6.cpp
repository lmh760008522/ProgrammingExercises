#include<iostream>
#include<cstring>
#include<cstdio>
#include<cmath>
using namespace std;
#define N 1005

int n;
double rate,f[N][2];

void clear()
{
    memset(f,0,sizeof(f));
}
double cut(double x)
{
    int a=floor(x*100);
    return (double)a/(100.0);
}
int main()
{
    while (~scanf("%d",&n))
    {
        if (!n) break;
        clear();
        f[0][0]=0,f[0][1]=1000.00;
        for (int i=1;i<=n;++i)
        {
            scanf("%lf",&rate);
            f[i][0]=max(f[i-1][0],cut(f[i-1][1]*0.97/rate));
            f[i][1]=max(f[i-1][1],cut(f[i-1][0]*0.97*rate));
        }
        printf("%0.2lf\n",f[n][1]);
    }
}
