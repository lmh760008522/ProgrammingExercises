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

        //�ҳ���iΪ��β�������������
        for(i=0;i<n;i++)
        {
            dp1[i]=1;
            for(j=0;j<i;j++)
                if(a[i]>a[j])
                    dp1[i]=maxnum(dp1[i],dp1[j]+1);
        }
        //�ҳ���iΪ��ͷ����ݼ������У�����Ϊ������
        for(i=n-1;i>=0;i--)
        {
            dp2[i]=1;
            for(j=n-1;j>i;j--)
                if(a[i]>a[j])
                    dp2[i]=maxnum(dp2[i],dp2[j]+1);
        }

        //�ж���iΪ�����ߵ���������г��ȣ�ע��i��dp1��dp2���������飬���Ҫ��ȥ��
        max=1;
        for(i=0;i<n;i++)
        {
            if(max<(dp1[i]+dp2[i]))
                max=dp1[i]+dp2[i];
        }

        //��������ȥ����м�Ϊ��������
        printf("%d\n",n-max+1);
    }
    return 0;
}
