/*
����ԭ���ֽи볲ԭ��
���⣺
    ����N�������������Ƿ����M����ʹ������M�����ĺ���N�ı���������ж���⣬
    �������һ�鼴�ɡ��������ڣ���� 0��
��⣺
    ���ȱ���������һ���Ǳ�����һ�����н�ġ�ԭ����ݳ���ԭ��
    ��Ϊ��n��������n����ȡ�࣬���������û�г���0�����ݸ볲ԭ��һ������������������ͬ��
�����������0����Ȼ����n�ı�����Ҳ����˵��n������һ������һЩ���ĺ���n�ı�����
�����˼·�Ǵӵ�һ������ʼһ�����ǰ i��i <= N����ĺ͹���N������sum�������μ�¼��Ӧ�����Ĵ���״̬��
���sum == 0����ӵ�һ���i��ĺͼ��������⡣�����õ� sum ��ǰ���Ѿ����ֹ��������ڵ�j��j<i�������
����ͬ�� sum ֵ����ӵ� j+1 ���i��ĺ�һ���������⡣
*/
//����һ��
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
            mod[sum] = i;     //mod����������¼��������Ϊsumʱλ�ã���ǰi��ͳ���N����Ϊsum
        }
        print(begin, end);
    }
    return 0;
}
