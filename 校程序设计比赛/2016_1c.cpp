//�鲢����
/*
���룺�����һ��Ϊһ��T(T <= 6)��ʾ����������ÿ�����ݰ�������n(n����, 1<=n<=100000)���Լ�n������(������������ÿ������Ӧ��ƻ������)
���������ÿ���������n����������i��������ʾ��i�����ұ�ƻ���������ٵ��˵ĸ����� 
*/ 
#include <cstdio>
#include <cstring>
int const MAX = 1e5 + 5;
int const INF = 0x7FFFFFFF;
int n, a[MAX], res[MAX];

struct DATA
{
    int val, idx;
}d[MAX], a1[MAX], a2[MAX];
    
void merge_sort(int l, int mid, int r, DATA *d) 
{
    int len1 = mid - l;
    int len2 = r - mid;
    for(int i = 0; i < len1; i++)
        a1[i] = d[i + l]; 
    a1[len1].val = INF;
    for(int i = 0; i < len2; i++) 
        a2[i] = d[i + mid]; 
    a2[len2].val = INF;
    int i = 0, j = 0, k = l, tmp = 0;
    while(i < len1 || j < len2) 
    {
        if(a1[i].val <= a2[j].val) 
        {
            res[a1[i].idx] += tmp;
            d[k ++] = a1[i ++];         
        }
        else 
        {
            if(a1[i].val != INF) 
                tmp ++;
            d[k ++] = a2[j ++];         
        }
    }
}

void Merge(int l, int r, DATA *d) 
{
    if(l == r - 1) 
        return; 
    int mid = (l + r) >> 1;
    Merge(l, mid, d);
    Merge(mid, r, d);
    merge_sort(l, mid, r, d);
}

int main()
{
    int T;
    scanf("%d", &T);
    while(T --)
    {
        memset(res, 0, sizeof(res));
        scanf("%d", &n);
        for(int i = 0; i < n; i++)
            scanf("%d", &a[i]);
        for(int i = 0; i < n; i++) 
        {
            d[i].val = a[i]; 
            d[i].idx = i;
        }
        Merge(0, n, d);
        for(int i = 0; i < n; i++)
            printf("%d ", res[i]);
        printf("\n");
    }
}
