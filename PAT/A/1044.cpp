/*
1.如果sum[i](只从开始到第i个累加和)<m,那么它的字数列也会小于，则不用考虑。
2.如果sum[i](只从开始到第i个累加和)>m,那么我们循环减掉前面的，直到它等于m，你就找到答案了。
3.如果找不到，可在上述第二步中记录一个最小值。
*/ 

#include<iostream>
#include<cstdio>
using namespace std;
int main(int argc, char *argv[])
{
    int n,m,sum[100000+5]={0},tem,first=0,mindiff = 100000000+5;
    bool isFind = false;
    scanf("%d %d",&n,&m);
    for (int i = 1; i <= n; ++i) {
        scanf("%d",&tem);
        sum[i]=sum[i-1]+tem;
        //如果``sum[i](只从开始到第i个累加和)>m``,那么我们循环减掉前面的，直到它等于`m`，你就找到答案了。
        while (sum[i] - sum[first]>m) {
            mindiff = min(mindiff,sum[i]-sum[first]);
            first++;
        }
        if (sum[i] - sum[first] == m) {
            printf("%d-%d\n",first+1,i);
            isFind = true;
        }
    }
    //如果找不到，可在上述第二步中记录一个最小值。然后再类似第二部求解。
    if (!isFind) {
        int j=0;
        for (int i = 1; i <= n; ++i) {
            while (sum[i] - sum[j]>mindiff) {
                j++;
            }
            if (sum[i] - sum[j] == mindiff) {
                printf("%d-%d\n",j+1,i);
            }
        }
    }
    return 0;
}
