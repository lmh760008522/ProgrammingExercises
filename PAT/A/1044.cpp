/*
1.���sum[i](ֻ�ӿ�ʼ����i���ۼӺ�)<m,��ô����������Ҳ��С�ڣ����ÿ��ǡ�
2.���sum[i](ֻ�ӿ�ʼ����i���ۼӺ�)>m,��ô����ѭ������ǰ��ģ�ֱ��������m������ҵ����ˡ�
3.����Ҳ��������������ڶ����м�¼һ����Сֵ��
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
        //���``sum[i](ֻ�ӿ�ʼ����i���ۼӺ�)>m``,��ô����ѭ������ǰ��ģ�ֱ��������`m`������ҵ����ˡ�
        while (sum[i] - sum[first]>m) {
            mindiff = min(mindiff,sum[i]-sum[first]);
            first++;
        }
        if (sum[i] - sum[first] == m) {
            printf("%d-%d\n",first+1,i);
            isFind = true;
        }
    }
    //����Ҳ��������������ڶ����м�¼һ����Сֵ��Ȼ�������Ƶڶ�����⡣
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
