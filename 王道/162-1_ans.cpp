#include <stdio.h>
#include <stdlib.h>
int maxnum(int x,int y)
{
    return x>y?x:y;
}
int main()
{
    int n,i,j,a[101],dp1[101],dp2[101],max;

    while(scanf("%d",&n)!=EOF)
    {
        for(i=0;i<n;i++)
            scanf("%d",&a[i]);

        for(i=0;i<n;i++)
        {
            dp1[i]=0;
            dp2[i]=0;
        }

        //找出以i为结尾的最长递增子序列
        for(i=0;i<n;i++)
        {
            dp1[i]=1;
            for(j=0;j<i;j++)
                if(a[i]>a[j])
                    dp1[i]=maxnum(dp1[i],dp1[j]+1);
        }
        //找出以i为开头的最长递减子序列（逆序即为递增）
        for(i=n-1;i>=0;i--)
        {
            dp2[i]=1;
            for(j=n-1;j>i;j--)
                if(a[i]>a[j])
                    dp2[i]=maxnum(dp2[i],dp2[j]+1);
        }

        //判断以i为最高身高的最长满足序列长度（注意i在dp1和dp2中算了两遍，最后要减去）
        max=1;
        for(i=0;i<n;i++)
        {
            if(max<(dp1[i]+dp2[i]))
                max=dp1[i]+dp2[i];
        }

        //总人数减去最长序列即为最少人数
        printf("%d\n",n-max+1);
    }
    return 0;
}
